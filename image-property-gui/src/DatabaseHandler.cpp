/*
 * DatabaseHandler.cpp
 *
 *  Created on: Jul 22, 2015
 *      Author: awg
 */

#include "DatabaseHandler.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

using namespace std;

DatabaseHandler::DatabaseHandler(ConfigHandler * config) : config(config){
	// TODO Auto-generated constructor stub
    db = new QSqlDatabase();
	*db = QSqlDatabase::addDatabase("QPSQL");
    if (!db->isValid()) {
        qFatal("Database invalid: QPSQL");
    }

}

void DatabaseHandler::OpenDatabase() {
    db->setHostName(config->dbHost());
    db->setDatabaseName(config->dbName());
    db->setPort(config->dbPort());
    db->setUserName(config->dbUser());
    db->setPassword(config->dbPassword());
    qDebug() << "Opening Database " + db->databaseName()+ " on Host " + db->hostName() + ".";
    if (!db->open()) {
        qFatal("Could not open Database");
    }
}

DatabaseHandler::~DatabaseHandler() {
	// TODO Auto-generated destructor stub
	db->close();
}

QSqlSortModel * DatabaseHandler::getPropertyTable() {
    qDebug() << "Calling  DatabaseHandler::getPropertyTable()";
    QSqlSortModel * model = new QSqlSortModel;
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("images");
    return model;
}

QStringList DatabaseHandler::GetProjectList() {
	QStringList return_list;
	qDebug() << "Calling DatabaseHandler::GetProjectList()";
    QString query_string = "SELECT distinct session FROM images ORDER BY session";
	qDebug() << query_string;
	QSqlQuery query(query_string);
	while (query.next())
		return_list.append(query.value(0).toString());
	return return_list;
}

QStringList DatabaseHandler::GetProjectCams() {
	QStringList return_list;
	return_list.append("");
	qDebug() << "Calling DatabaseHandler::GetProjectCams";
    QString query_string = "SELECT distinct camera FROM images WHERE session='%1' ORDER BY camera";
	qDebug() << query_string;
    QSqlQuery query(query_string.arg(config->getPreferredSession()));
	while (query.next())
		return_list.append(query.value(0).toString());
	return return_list;
}

QStringList DatabaseHandler::GetProjectTracs() {
	QStringList return_list;
	return_list.append("");
	qDebug() << "Calling DatabaseHandler::GetProjectTracs";
    QString query_string = "SELECT distinct transect FROM images WHERE session='%1' ORDER BY transect";
	qDebug() << query_string;
    QSqlQuery query(query_string.arg(config->getPreferredSession()));
	while (query.next())
		return_list.append(query.value(0).toString());
	return return_list;
}

void DatabaseHandler::GetStuk4Codes(QString type, QComboBox * combo_box) {
	combo_box->clear();
	combo_box->addItem("",QVariant());
	qDebug() << "Calling DatabaseHandler::GetStuk4Codes";
	QString query_string = "SELECT code, description FROM stuk4_codes where type='%1'";
	qDebug() << query_string.arg(type);
	QSqlQuery query(query_string.arg(type));
	while (query.next()) {
		combo_box->addItem( query.value(0).toString() + " - " + query.value(1).toString(),
				query.value(0));
	}
}

QString DatabaseHandler::getSessionVersion(const QString &session) {
    QSqlQuery query;
    query.prepare("SELECT distinct version FROM projects WHERE flight_id=:session");
    query.bindValue(":session", session);
    if (!query.exec()) {
        qDebug() << "Error while getting version: " << query.lastError() .text();
    }
    if (query.next()) {
        return query.value(0).toString();
    }
    return QString();
}

QString DatabaseHandler::GetPropertyProgress(QString type) {
	QString return_string = "";
	QString total = "";
	QString current = "";
	qDebug() << "Calling DatabaseHandler::GetPropertyProgress";
	QString query_string = "SELECT t1.current,t2.total FROM "
            "(SELECT count(%1) as current FROM images WHERE session='%2' AND (%1 IS NOT NULL OR cast(%1 as text)='')) as t1 "
			"JOIN "
            "(SELECT count(1) as total FROM images WHERE session='%2') as t2 "
			" ON TRUE";
    QSqlQuery query(query_string.arg(type).arg(config->getPreferredSession()));
	if (query.next()) {
		current = query.value(0).toString();
		total = query.value(1).toString();
    } else {
        qDebug() << query.lastError().text();
    }
	return_string = current + "\t/" + total;
	return return_string;
}

QSqlQueryModel * DatabaseHandler::getIceCodes() {
    qDebug() << "Getting ice codes...";
    QSqlQueryModel * model = new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT ice, description_de FROM meta_ice WHERE version=:version");
    query.bindValue(":version", config->version());
    if (!query.exec()) {
        qDebug() << query.lastError().text();
        return NULL;
    }
    model->setQuery(query);
    return model;
}

QSqlQueryModel * DatabaseHandler::getGlareCodes() {
    qDebug() << "Getting glare codes...";
    QSqlQueryModel * model = new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT glare, description_de, remarks_de FROM meta_glare WHERE version=:version");
    query.bindValue(":version", config->version());
    if (!query.exec()) {
        qDebug() << query.lastError().text();
        return NULL;
    }
    model->setQuery(query);
    return model;
}

QSqlQueryModel * DatabaseHandler::getTurbidityCodes() {
    qDebug() << "Getting turbidity codes...";
    QSqlQueryModel * model = new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT turbidity, description_de, remarks_de FROM meta_turbidity WHERE version=:version");
    query.bindValue(":version", config->version());
    if (!query.exec()) {
        qDebug() << query.lastError().text();
        return NULL;
    }
    model->setQuery(query);
    return model;
}

QSqlQueryModel * DatabaseHandler::getClarityCodes() {
    qDebug() << "Getting clarity codes...";
    QSqlQueryModel * model = new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT clarity, description_de, remarks_de FROM meta_clarity WHERE version=:version");
    query.bindValue(":version", config->version());
    if (!query.exec()) {
        qDebug() << query.lastError().text();
        return NULL;
    }
    model->setQuery(query);
    return model;
}

QSqlQueryModel * DatabaseHandler::getSeastateCodes() {
    qDebug() << "Getting seastate codes...";
    QSqlQueryModel * model = new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT seastate, description_de FROM meta_seastate WHERE version=:version");
    query.bindValue(":version", config->version());
    if (!query.exec()) {
        qDebug() << query.lastError().text();
        return NULL;
    }
    model->setQuery(query);
    return model;
}

bool DatabaseHandler::checkUsername(const QString & login) {
    QSqlQuery query;
    query.prepare("SELECT exists(SELECT TRUE FROM users JOIN user_groups USING(user_id) JOIN groups USING(group_id) "
                  "WHERE login=:login AND group_name='daisi-staff')");
    query.bindValue(":login", login);
    if (!query.exec()) {
        QMessageBox::critical(0, "Datenbankfehler", query.lastError().text());
        exit(1);
    }
    if (query.next())
        return query.value(0).toBool();
    return false;
}

bool DatabaseHandler::checkPassword(const QString &login, const QString &password) {
    QSqlQuery query;
    query.prepare("SELECT password_hash = crypt(:password,password_hash) FROM users WHERE login=:login");
    query.bindValue(":password", password);
    query.bindValue(":login", login);
    if (!query.exec()) {
        QMessageBox::critical(0, "Datenbankfehler", query.lastError().text());
        exit(1);
    }
    if (query.next())
        return query.value(0).toBool();
    return false;
}

bool DatabaseHandler::changePassword(const QString &login, const QString &password) {
    QSqlQuery query;
    query.prepare("UPDATE users SET password_hash = crypt(:password,gen_salt('bf')) WHERE login=:login");
    query.bindValue(":password", password);
    query.bindValue(":login", login);
    if (!query.exec()) {
        QMessageBox::critical(0, "Datenbankfehler", query.lastError().text());
        exit(1);
    }
    return true;
}
