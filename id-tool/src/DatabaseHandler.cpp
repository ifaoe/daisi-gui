//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "DatabaseHandler.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include <QHeaderView>
#include <QDateTime>

DatabaseHandler::DatabaseHandler(ConfigHandler *cfgArg) :config(cfgArg) {
    // TODO Auto-generated constructor stub
    db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase("QPSQL");

    if (!db->isValid()) {
        qFatal("Database invalid: QPSQL");
    }
}

DatabaseHandler::~DatabaseHandler() {
    // TODO Auto-generated destructor stub
    db->close();
    delete db;
}

bool DatabaseHandler::OpenDatabase() {
	if (db->isOpen()) {
		db->close();
	}

    db->setHostName(config->dbHost());
    db->setDatabaseName(config->dbName());
    db->setPort(config->dbPort());
    db->setUserName(config->dbUser());
    db->setPassword(config->dbPassword());
    qDebug() << "Opening Database " + db->databaseName()+ " on Host " + db->hostName() + ".";
    if (!db->open()) {
        qFatal("Could not open Database");
    }
    return true;
}

QStringList DatabaseHandler::getLocationList() {
    qDebug() << "Getting location list from database";
    QStringList location_list;
    QString query_string = "SELECT distinct location FROM projects ORDER BY location";
    qDebug() << query_string;
    QSqlQuery query(query_string);
    while(query.next())
        location_list.append(query.value(0).toString());
    return location_list;
}

QStringList DatabaseHandler::getSessionList(const QString & location) {
    qDebug() << "Getting session list from database.";
    QStringList sessionList;
    QString qstr = "SELECT project_id FROM projects WHERE location='%1' AND id_status>0 ORDER BY project_id";
    qDebug() << qstr;
    QSqlQuery query(qstr.arg(location));
    while(query.next()) {
        sessionList.append(query.value(0).toString());
    }
    if (sessionList.empty()) {
        qFatal("Session list is empty.");
    }
    return sessionList;
}

bool DatabaseHandler::getSpeciesList(const QString & type, QComboBox * cmb_box) {
	qDebug() << "Populating species list for " << type;
    QSqlQuery query;
    query.prepare("SELECT euring_code, name_de, name_lat FROM daisi_dev.bird_view_taxa WHERE type=:type AND version=:version ORDER BY seaflag DESC, name_de");
    query.bindValue(":type", type);
    query.bindValue(":version", session_version);
    if (!query.exec())
        qDebug() << query.lastError().text();
	QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, "EURING Code");
    model->setHeaderData(1, Qt::Horizontal, "Deutscher Name");
    model->setHeaderData(2, Qt::Horizontal, "Wissenschaftlicher Name");
	cmb_box->setModel(model);
    cmb_box->setModelColumn(1);
	QTableView * view = new QTableView;
	cmb_box->setView(view);
	view->verticalHeader()->hide();
	view->resizeColumnsToContents();
	view->setSelectionMode(QAbstractItemView::SingleSelection);
	view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setMinimumWidth(view->horizontalHeader()->length());

	return true;
}

CensorSqlTableModel * DatabaseHandler::getObjectModel() {
	CensorSqlTableModel * model = new CensorSqlTableModel;
	model->setCensorCountColumn(6);
	model->setCensorMax(7);
    model->setTable("daisi_dev.bird_view_objects");
	model->setHeaderData(0, Qt::Horizontal, QString("Projekt"));
	model->setHeaderData(0, Qt::Horizontal, QString("session"), 101);
	model->setHeaderData(1, Qt::Horizontal, QString("Objekt ID"));
	model->setHeaderData(1, Qt::Horizontal, QString("rcns_id"), 101);
	model->setHeaderData(2, Qt::Horizontal, QString("Kamera"));
	model->setHeaderData(2, Qt::Horizontal, QString("cam"), 101);
	model->setHeaderData(3, Qt::Horizontal, QString("Bildnummer"));
	model->setHeaderData(3, Qt::Horizontal, QString("img"), 101);
	model->setHeaderData(4, Qt::Horizontal, QString("Sortierung"));
	model->setHeaderData(4, Qt::Horizontal, QString("pre_tp"), 101);
	model->setHeaderData(5, Qt::Horizontal, QString("Bestimmungen"));
	model->setHeaderData(5, Qt::Horizontal, QString("type_list"), 101);
	return model;
}

bool DatabaseHandler::GetAnthroObjectList(QComboBox * combo_box) {
    qDebug() << "Gettings list of anthropogenic objects from database.";
    QSqlQuery query;
    query.prepare("SELECT anthro_object, description_de FROM census_anthro_objects WHERE version=:version AND anthro_object>0 ORDER BY description_de");
    query.bindValue(":version", session_version);
    if (!query.exec())
        qDebug() << query.lastError().text();
	while (query.next()) {
		combo_box->addItem(query.value(1).toString(), query.value(0));
	}
	return true;
}

QStringList DatabaseHandler::getUserList(int objId) {
    qDebug() << "Getting user list from database. For id " << objId;
    QStringList userList;
    QString qstr = "SELECT DISTINCT usr, censor FROM census WHERE rcns_id=%1 AND mark_delete IS NULL ORDER BY censor";
    QSqlQuery query(qstr.arg(objId));
    qDebug() << query.executedQuery();
    if (query.size() == -1) return userList;
    while(query.next()) {
        userList.append(query.value(0).toString());
    }
    return userList;
}

QString DatabaseHandler::getProjectPath(QString session) {
    qDebug() << "Getting session path list from database.";
    QSqlQuery query("SELECT path FROM projects WHERE project_id='" + session + "' AND location='" + config->location() + "'");
    if (query.size() == -1) return "/net";
    while(query.next()) {
        return query.value(0).toString();
    }
    return "/net";
}

QSqlQuery * DatabaseHandler::getObjectResult(QString session, QString user, QString filter, QString order) {
    // get object data for population of object list
    qDebug() << "Gettings object data for session: " + session;
    QString otbl = QString("SELECT rc.rcns_id, rc.tp as pre_tp, rc.cam, rc.img, max(c.censor) as mc,"
            " count(*) as cnt, string_agg(c.tp, ', ' ORDER BY c.fcns_id) as otp,"
            " max(case when c.usr='%1' then 1 else 0 end) FROM raw_census as rc LEFT JOIN census"
            " as c ON rc.rcns_id=c.rcns_id WHERE (censor>0 OR censor IS NULL) AND rc.session='%2'"
            " GROUP BY rc.rcns_id, rc.tp, rc.cam, rc.img").arg(user, session);
    QString utbl = QString("SELECT rcns_id, tp, censor FROM census where usr='%1'").arg(user);
    QString qstr = QString("SELECT * FROM (%1) as ot LEFT JOIN (%2) as ut ON ot.rcns_id=ut.rcns_id WHERE %3 %4")
    		.arg(otbl).arg(utbl).arg(filter).arg(order);
    qDebug() << qstr;
    QSqlQuery * query = new QSqlQuery(qstr);
    return query;
}

census * DatabaseHandler::getRawObjectData(QString objId, QString usr) {
    qDebug() << "Getting raw object data for object ID: " << objId;
    QString qstr = "SELECT rcns_id, session, epsg, cam, img, tp, px, py, ux, uy, lx, ly, tp FROM raw_census WHERE rcns_id=" + objId;
    qDebug() << qstr;
    QSqlQuery * query = new QSqlQuery(qstr);
    census *obj = new census;
    if(!query->next()) {
        qDebug() << "No data found for object ID: " << objId;
        return obj;
    }
    obj->id = query->value(0).toInt();
    obj->session = query->value(1).toString();
    obj->epsg = query->value(2).toString();
    obj->camera = query->value(3).toString();
    obj->image = query->value(4).toString();
    obj->px = query->value(6).toInt();
    obj->py = query->value(7).toInt();
    obj->ux = query->value(8).toDouble();
    obj->uy = query->value(9).toDouble();
    obj->lx = query->value(10).toDouble();
    obj->ly = query->value(11).toDouble();
    obj->usr = usr;
    obj->type = query->value(12).toString();
    delete query;
    qDebug() << "Getting object specific data for ID: " << objId;
    qstr =    "SELECT tp, name, confidence, beh, age, gen, dir, rem, censor, imgqual, length, width"
            ", stuk4_beh, stuk4_ass, group_objects, family_group,id_code,age_year,plumage, censor"
            " FROM census WHERE rcns_id=" + objId + " AND usr='" + usr + "'";
    qDebug() << qstr;
    // if there is already an entry in census db-table,
    // initialize census structure with these values
    query = new QSqlQuery(qstr);
    if (query->next()) {
        obj->type = query->value(0).toString();
        obj->name = query->value(1).toString();
        obj->confidence = query->value(2).toInt();
        obj->behavior = query->value(3).toString();
        obj->age = query->value(4).toString();
        obj->gender = query->value(5).toString();
        if (!query->value(6).isNull())
        	obj->direction = query->value(6).toInt();
        obj->remarks = query->value(7).toString();
        obj->censor = query->value(8).toInt();
        obj->imageQuality = query->value(9).toInt();
        obj->length = query->value(10).toDouble();
        obj->span = query->value(11).toDouble();
        obj->stuk4_beh = query->value(12).toString().remove(QRegExp("[{}]")).split(",");
        obj->stuk4_ass = query->value(13).toString().remove(QRegExp("[{}]")).split(",");
        obj->group = query->value(14).toString().remove(QRegExp("[{}]")).split(",");
        obj->family = query->value(15).toString().remove(QRegExp("[{}]")).split(",");
        obj->code = query->value(16).toString();
        if (!query->value(17).isNull())
        	obj->age_year = query->value(17).toInt();
        if (!query->value(18).toString().isEmpty())
        	obj->plumage = query->value(18).toString();
        obj->censor = query->value(19).toInt();
    }
    delete query;
    return obj;
}

bool DatabaseHandler::writeCensus(census * obj) {
    qDebug() << "Writing object data to database.";
    QSqlTableModel table;
    table.setTable("census");
    table.setFilter("rcns_id=" + QString::number(obj->id) + " AND usr='" + obj->usr + "'");
    table.select();
    // get record structure from db
    QSqlRecord record(table.record());
    // initialize record with census-structure values
    setRecordTable(&record, obj);

    // insert or update records in db
    if (table.rowCount() == 0) { //INSERT
        qDebug() << "Insert!";
        record.setValue("time_create", QDateTime::currentDateTime());
        // remove first entry of record
        // auto increment of id is handled by postgres
        record.remove(0);
        bool done = table.insertRecord(-1,record);
        qDebug() << table.lastError();
        return done;
    } else { //UPDATE
        qDebug() << "Update!";
        // Don't overwrite time_create with NULL
        record.remove(record.indexOf("time_create"));
        record.setValue("fcns_id",table.record(0).value(0).toInt());
        bool check = true;
        check = check && table.setRecord(0, record);
        check = check && table.submitAll();
        qDebug() << table.lastError();
        return check;
    }
    return true;
}

/*
 * translate values from census struct into a QSqlRecord which can be written
 * directly to DB
 */
void DatabaseHandler::setRecordTable(QSqlRecord * record, census * obj) {
    record->setValue("rcns_id",obj->id);

    if (obj->age.isNull()) record->setNull("age");
    else record->setValue("age",obj->age);

    if (obj->age_year>0) record->setValue("age_year",obj->age_year);
    else record->setNull("age_years");

    if (obj->behavior.isEmpty()) record->setNull("beh");
    else record->setValue("beh",obj->behavior);

    if (obj->gender.isEmpty()) record->setNull("gen");
    else record->setValue("gen",obj->gender);

    if (obj->name.isEmpty()) record->setNull("name");
    else record->setValue("name",obj->name);

    if (obj->code.isEmpty()) record->setNull("id_code");
    else record->setValue("id_code", obj->code);

    record->setValue("tp",obj->type);
    record->setValue("confidence",obj->confidence);

    if (obj->remarks.isEmpty()) record->setNull("rem");
    else record->setValue("rem",obj->remarks.replace('"', " "));

    record->setValue("usr",obj->usr);

    if (obj->direction >= 0) record->setValue("dir", obj->direction);
    else record->setNull("dir");

    record->setValue("censor", obj->censor);

    record->setValue("imgqual", obj->imageQuality);

    if (obj->length >0) record->setValue("length", obj->length);
    else record->setNull("length");

    if (obj->span > 0) record->setValue("width", obj->span);
    else record->setNull("width");

    if (obj->log.isEmpty()) record->setNull("log");
    else record->setValue("log", obj->log);

    if (obj->plumage.isEmpty()) record->setNull("plumage");
    else record->setValue("plumage",obj->plumage);

    record->setValue("stuk4_beh", "{"+obj->stuk4_beh.join(",")+"}");
    record->setValue("stuk4_ass", "{"+obj->stuk4_ass.join(",")+"}");
    record->setValue("group_objects", "{"+obj->group.join(",")+"}");
    record->setValue("family_group", "{"+obj->family.join(",")+"}");

    record->setValue("time_modify", QDateTime::currentDateTime());

    record->setValue("version", session_version);
}

/*
 * get map of viewed objects in census table for a specific user
 */
QMap<int, int> DatabaseHandler::getObjectDone(QString usr, QString session) {
    qDebug() << "Getting viewed object list from database for user" << usr << " and session " << session;
    QMap <int, int> objMap;
    QString keys = "census.rcns_id, census.censor";
    QString qstr = "SELECT " + keys + " FROM census JOIN raw_census on " +
            "census.rcns_id=raw_census.rcns_id WHERE raw_census.session='" + session +
            "' AND census.usr='" + usr + "'";
    QSqlQuery query(qstr);
    if (query.size() == -1) return objMap;
    while(query.next()) {
        objMap[query.value(0).toInt()] = query.value(1).toInt();
    }
    return objMap;
}

/*
 * get map of completed objects for all users
 */
QMap<int, int> DatabaseHandler::getObjectFinal(QString session) {
    qDebug() << "Getting viewed object list from database.";
    QMap <int, int> objMap;
    QSqlQuery query("SELECT census.rcns_id, census.censor FROM census JOIN raw_census ON census.rcns_id=raw_census.rcns_id WHERE raw_census.session='" + session + "' AND census.censor=2");
    if (query.size() == -1) return objMap;
    while(query.next()) {
        objMap[query.value(0).toInt()] = query.value(1).toInt();
    }
    return objMap;
}

census * DatabaseHandler::getCensusData(QString objId) {
    qDebug() << "Getting object specific query for ID: " << objId;
    QString qstr = "SELECT tp, name, confidence, beh, age, gen, dir, rem, censor, imgqual FROM census WHERE rcns_id=" + objId +
            " AND usr!='" + config->getUser() + "' AND censor=1";
    qDebug() << qstr;
    // if there is already an entry in census db-table,
    // initialize census structure with these values
    QSqlQuery * query = new QSqlQuery(qstr);
    if (query->size() != 1) {
        delete query;
        return 0;
    }
    census * obj = new census;
    if (query->next()) {
        obj->type = query->value(0).toString();
        obj->name = query->value(1).toString();
        obj->confidence = query->value(2).toInt();
        obj->behavior = query->value(3).toString();
        obj->age = query->value(4).toString();
        obj->gender = query->value(5).toString();
        obj->direction = query->value(6).toInt();
        obj->remarks = query->value(7).toString();
        obj->censor = query->value(8).toInt();
        obj->imageQuality = query->value(9).toInt();
    }
    delete query;
    return obj;
}

int DatabaseHandler::getMaxCensor(QString objId) {
    QString qstr = "SELECT max(censor) FROM census WHERE rcns_id=" + objId;
//    qDebug() << qstr;
    QSqlQuery * query = new QSqlQuery(qstr);
    if (query->next()) {
            return query->value(0).toInt();
    }
    return 0;
}

int DatabaseHandler::getMaxCensor(QString objId, QString usr) {
    QString qstr = "SELECT max(censor) FROM census WHERE rcns_id=" + objId + " AND usr!='" + usr +"'";
//    qDebug() << qstr;
    QSqlQuery * query = new QSqlQuery(qstr);
    if (query->next()) {
            return query->value(0).toInt();
    }
    return 0;
}

int DatabaseHandler::getCensorCount(QString objId, QString censor) {
    QString qstr = "SELECT count(usr) FROM census WHERE rcns_id=" + objId + " AND censor=" + censor;
//    qDebug() << qstr;
    QSqlQuery * query = new QSqlQuery(qstr);
    if (query->next()) {
            return query->value(0).toInt();
    }
    return 0;
}

int DatabaseHandler::getCensorCount(QString objId, QString censor, QString usr) {
    QString qstr = "SELECT count(usr) FROM census WHERE rcns_id=" + objId + " AND censor=" + censor
            + " AND usr!='" + usr + "'";
//    qDebug() << qstr;
    QSqlQuery * query = new QSqlQuery(qstr);
    if (query->next()) {
            return query->value(0).toInt();
    }
    return 0;
}

QMap<int, QString> DatabaseHandler::getUserCensus(QString usr, QString session) {
    qDebug() << "Getting map of user census." << endl;
    QMap<int, QString> cmap;
    QString keys = "c.rcns_id, c.tp";
    QString qstr = "SELECT "+ keys +" FROM census as c JOIN raw_census as rc " +
            "on c.rcns_id=rc.rcns_id WHERE c.usr='" + usr + "' AND rc.session='" + session + "'";
    qDebug() << qstr;
    QSqlQuery query(qstr);
    while(query.next()) {
        cmap[query.value(0).toInt()] = query.value(1).toString();
    }
    return cmap;
}

QMap<int, QString> DatabaseHandler::getFinalCensus(QString session) {
    qDebug() << "Getting map of user census." << endl;
    QMap<int, QString> cmap;
    QString keys = "c.rcns_id, c.tp";
    QString qstr = "SELECT "+ keys +" FROM census as c JOIN raw_census as rc " +
            "on c.rcns_id=rc.rcns_id WHERE rc.session='" + session + "' AND c.censor=2";
    qDebug() << qstr;
    QSqlQuery query(qstr);
    while(query.next()) {
        cmap[query.value(0).toInt()] = query.value(1).toString();
    }
    return cmap;
}

void DatabaseHandler::GetBirdAgeClasses(QComboBox * cmb_box) {
	cmb_box->clear();
	cmb_box->addItem("",-1);
	qDebug() << "Getting bird age classes from database";
    QSqlQuery query;
    query.prepare("SELECT age_year, description_de FROM daisi_dev.bird_view_age_years WHERE type='BIRD' AND version=:version ORDER BY age_year");
    query.bindValue(":version", session_version);
    if (!query.exec())
        qDebug() << query.lastError().text();
	while (query.next()) {
        cmb_box->addItem(query.value(1).toString(), query.value(0));
	}
}

void DatabaseHandler::GetMiscObjects(QComboBox * combo_box) {
    QSqlQuery query;
    query.prepare("SELECT abiotic_object, description_de FROM census_abiotic_objects WHERE version=:version AND abiotic_object>0 ORDER BY description_de");
    query.bindValue(":version", session_version);
    if (!query.exec())
        qDebug() << query.lastError().text();
    while (query.next()) {
        combo_box->addItem(query.value(1).toString(), query.value(0));
    }
}

void DatabaseHandler::GetBirdPlumageClasses(QComboBox * cmb_box) {
    cmb_box->clear();
    cmb_box->addItem("",-1);
    qDebug() << "Getting bird plumage classes from database";
    QSqlQuery query;
    query.prepare("SELECT plumage, description_de FROM census_plumages WHERE version=:version ORDER BY plumage");
    query.bindValue(":version", session_version);
    if (!query.exec())
        qDebug() << query.lastError().text();
    while (query.next()) {
        cmb_box->addItem(query.value(1).toString(), query.value(0));
    }
}

void DatabaseHandler::deleteCensusData(QString objId, QString usr) {
    qDebug() << "Delete data from user: " + usr + " ID: " + objId + "." << endl;
    QString qstr = "UPDATE census set mark_delete=true, delete_hint='By user request. ' || delete_hint WHERE rcns_id=" + objId + " AND usr='" + usr + "'";
    qDebug() << qstr;
    QSqlQuery query(qstr);
    query.exec();
}

bool DatabaseHandler::getSessionActive(const QString & session) {
    QString qstr = "SELECT active FROM projects WHERE project_id='" + session + "'";
    QSqlQuery query(qstr);
    if(query.next()) {
        if ((query.value(0).toInt() > 0) && (query.value(0).toInt() < 3))
            return true;
        else
            return false;
    } else {
        return false;
    }
}

QSqlQueryModel * DatabaseHandler::getStuk4Behaviour() {
    QSqlQueryModel * model = new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT behaviour, class_de, description_de FROM daisi_dev.bird_view_behaviours WHERE version=:version AND behaviour>0"
                  " ORDER BY type, class_de, behaviour");
    query.bindValue(":version", session_version);
    if (!query.exec())
        qDebug() << query.lastError().text();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, "Code");
    model->setHeaderData(1, Qt::Horizontal, "Kategorie");
    model->setHeaderData(2, Qt::Horizontal, "Beschreibung");
    return model;
}

QSqlQueryModel * DatabaseHandler::getStuk4Associations() {
    QSqlQueryModel * model = new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT association, class_de, description_de FROM daisi_dev.bird_view_associations WHERE version=:version AND association>0"
                  " ORDER BY type, class_de, association");
    query.bindValue(":version", session_version);
    if (!query.exec())
        qDebug() << query.lastError().text();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, "Code");
    model->setHeaderData(1, Qt::Horizontal, "Kategorie");
    model->setHeaderData(2, Qt::Horizontal, "Beschreibung");
    return model;
 }

QSqlQueryModel * DatabaseHandler::getCloseObjects(census * obj) {
    QSqlQueryModel * model = new QSqlQueryModel;
    QString qstr = "SELECT sync_id FROM sync_utm32 WHERE cam" + obj->camera + "_id='"
            + obj->image + "'";
    QSqlQuery query(qstr);
    int sync_id;
    if (query.next())
        sync_id = query.value(0).toInt();
    else {
        qDebug() << qstr;
        return model;
    }



    query.clear();

    QStringList sidList = QStringList() << QString::number(sync_id-1) << QString::number(sync_id)
                                        << QString::number(sync_id+1);
    qstr = "SELECT cam, img FROM image_properties WHERE sync_id IN (" +sidList.join(",")+ ")";
    query.exec(qstr);

    QStringList condList;
    while(query.next()) {
        condList.append("(cam='" + query.value(0).toString()
                    + "' AND img='" +query.value(1).toString()+ "')");
    }
    /*
     * TODO: Add distance comparison
     */
    qstr = "SELECT rcns_id, cam, img, ux, uy, tp, "
            "ST_Distance( (SELECT ST_SetSRID(ST_Point(ux,uy),32632) FROM raw_census "
            "where rcns_id=" + QString::number(obj->id) + ") "
            ", ST_SetSRID(ST_Point(ux,uy),32632) ) as dist FROM raw_census "
            "WHERE (" + condList.join(" OR ") + ") AND rcns_id!=" + QString::number(obj->id) +
            " AND session='" + obj->session + "' ORDER BY dist";
    qDebug() << qstr;
    model->setQuery(qstr);
    model->setHeaderData(0, Qt::Horizontal, "Object Id");
    model->setHeaderData(1, Qt::Horizontal, "Kamera");
    model->setHeaderData(2, Qt::Horizontal, "Bildnummer");
    model->setHeaderData(3, Qt::Horizontal, "UTM X");
    model->setHeaderData(4, Qt::Horizontal, "UTM Y");
    model->setHeaderData(5, Qt::Horizontal, "Vorsortierung");
    model->setHeaderData(6, Qt::Horizontal, "Entfernung in m");
    return model;
}

QSqlQueryModel * DatabaseHandler::getImageObjects(census * obj) {
    QSqlQueryModel * model = new QSqlQueryModel;
    QString qstr = "SELECT rcns_id, tp, ux, uy, max(censor), count(*) FROM view_census WHERE cam='" +
            obj->camera + "' AND img='" + obj->image + "' AND session='"
            + obj->session + "' AND (censor>0 OR censor IS NULL) GROUP BY rcns_id, tp, ux, uy ORDER BY rcns_id";
    qDebug() << qstr;
    model->setQuery(qstr);
    model->setHeaderData(0, Qt::Horizontal, "Objekt Id");
    model->setHeaderData(1, Qt::Horizontal, "Typ");
    model->setHeaderData(2, Qt::Horizontal, "UTM X");
    model->setHeaderData(3, Qt::Horizontal, "UTM Y");
    model->setHeaderData(4, Qt::Horizontal, "Highest censor");
    model->setHeaderData(5, Qt::Horizontal, "Censor count");
    return model;
}

int DatabaseHandler::getCensusCount(const QString & session, const QString & user,
		const QString & having_filter, const QString & where_filter) {
	QString query_string = "SELECT count(*) FROM "
			"( SELECT max(censor) as mc, count(censor) as cnt FROM view_census "
			"WHERE session='%1' AND (usr like '%2' OR usr IS NULL) AND %3"
			" GROUP BY rcns_id) as tmp where %4";
	QSqlQuery query(query_string.arg(session).arg(user).arg(where_filter).arg(having_filter));
	qDebug() << query_string.arg(session).arg(user).arg(where_filter).arg(having_filter);
	if (query.next())
		return query.value(0).toInt();
	return 0;
}

void DatabaseHandler::refreshSessionProperties(const QString &name) {
    QSqlQuery query;
    query.prepare("SELECT path, version FROM projects WHERE project_id=:session_name");
    query.bindValue(":session_name", name);
    query.exec();
    if (query.next()) {
        session_name = name;
        session_path = query.value(0).toString();
        session_version = query.value(1).toString();
    }

}

QString DatabaseHandler::sessionName() {
    return session_name;
}

QString DatabaseHandler::sessionPath() {
    return session_path;
}

QString DatabaseHandler::sessionVersion() {
    return session_version;
}
