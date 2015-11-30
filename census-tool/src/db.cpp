#include "db.h"
#include <iostream>
#include <iostream>
#include <QHeaderView>

Db::Db(ConfigHandler *aConfig) : config(aConfig)
{
    db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase("QPSQL");

    if (!db->isValid()) {
        qFatal("Database invalid: QPSQL");
    }
}

bool Db::OpenDatabase() {
	if (config->getPreferredDatabase().isEmpty())
		return false;

	if (db->isOpen()) {
		db->close();
	}

	DatabaseInfo info = config->getDatabaseInfo(config->getPreferredDatabase());
	if (info.id.isEmpty())
		return false;
    db->setHostName(info.host);
    db->setDatabaseName(info.name);
    db->setPort(info.port);
    db->setUserName(info.user);
    db->setPassword(info.password);
    qDebug() << "Opening Database " + db->databaseName()+ " on Host " + db->hostName() + ".";
    if (!db->open()) {
        qFatal("Could not open Database");
    }
    return true;
}

// -------------------------------------------------------
QgsGeometry* Db::readImageEnvelope(const QString cam,
                                  const QString image) {

    QgsGeometry* geom = 0;
    QString query = config->replaceProjectSettings(ACFG_SQL_QRY_READ_IMGENV.arg(cam).arg(image));
    QSqlQuery req;
    if ( ! req.exec(query) ) {
//        out->error(req.lastError().text());
    	qDebug() << req.lastError().text();
        return 0;
    }
    while (req.next()) {
        QString bb = req.value(0).toString();
        QString sb = req.value(1).toString();
        QString c1 = req.value(2).toString();
        QString c2 = req.value(3).toString();
        QString env = ""; QString cfg = "";
        if (cam.compare("1")==0) { cfg = c1; } else { cfg = c2; }
        if (cfg.compare("SB")==0) { env = sb; } else { env = bb; }
        geom = QgsGeometry::fromWkt(env);
    }
    return geom;

}

// -------------------------------------------------------
QgsGeometry* Db::readValidPolygon(const QString cam, const QString image) {

    QgsGeometry* geom = 0;
    QString query = config->replaceProjectSettings(ACFG_SQL_QRY_READ_VALIDPOLY).arg(cam).arg(image);
    QSqlQuery req;
    qDebug() << query;
    if ( ! req.exec(query) ) {
    	qDebug() << req.lastError().text();
        return 0;
    }
    if (req.next()) {
        geom = QgsGeometry::fromWkt(req.value(0).toString());
    }
    return geom;

}

// -------------------------------------------------------
bool Db::readRawImageTile(const QString &cam, const QString &file, const QString &usr, int &id, QString &ux, QString &uy,
		QString &w, QString &h, QString &tmWhen, QString &tmSeen) {
    QString query =
    		config->replaceProjectSettings(ACFG_SQL_QRY_READ_RIMAGE_TILE.arg(cam).arg(file).arg(usr));
    qDebug() << query;
    QSqlQuery req;
    id =-1; tmWhen = ""; tmSeen = "";
    if ( ! req.exec(query) ) {
    	qDebug() << req.lastError().text();
        return false;
    }
    if (! req.next()) return true;
    id = req.value(0).toInt();
    ux = req.value(1).toString();
    uy = req.value(2).toString();
    w  = req.value(3).toString();
    h  = req.value(4).toString();
    tmWhen = req.value(5).toString();
    tmSeen = req.value(6).toString();
    return true;

}

// -------------------------------------------------------
bool Db::readRawImage(const QString &cam, const QString &file, const QString &usr,  int &id, QString &tmWhen, QString &tmSeen) {
    QString query =
    		config->replaceProjectSettings(ACFG_SQL_QRY_READ_RIMAGE.arg(cam).arg(file).arg(usr));
    qDebug() << query;
    QSqlQuery req;
    id =-1; tmWhen = ""; tmSeen = "";
    if ( ! req.exec(query) ) {
    	qDebug() << req.lastError().text();
        return false;
    }
    if (! req.next()) return true;
    id = req.value(0).toInt();
    tmWhen = req.value(1).toString();
    tmSeen = req.value(2).toString();
    return true;
}


// -------------------------------------------------------
bool Db::writeRawImageTile(const bool insert, const int id,
                           const quint8 epsg, const QString cam, const QString file,
                           const QString usr, const QString session,
                           const QString x, const QString y,
                           const QString w, const QString h,
                           const QString tmWhen, const QString tmSeen) {
  QString lstr;
  if (insert) {
    lstr = "INSERT INTO raw_tiles "
           "(epsg, cam, img, usr, session, tm_when, tm_seen, ux, uy, w, h) VALUES "
           "(%1, '%2', '%3', '%4', '%5', '%6', '%7', '%9', '%10', '%11', '%12');";
    lstr = lstr.arg(epsg).arg(cam).arg(file).arg(usr)
           .arg(session).arg("").arg("").arg(x).arg(y).arg(w).arg(h);
  } else {
      lstr = "UPDATE raw_tiles SET "
             "epsg = %1, cam = '%2', "
             "usr = '%3', session = '%4', "
             "tm_when = '%5', tm_seen = '%6', "
             "ux = '%7', uy = '%8', w = '%9', h = '%10' "
             "WHERE rtls_id = %11;";
      lstr = lstr.arg(epsg).arg(cam).arg(usr).arg(session)
             .arg(tmWhen).arg(tmSeen).arg(x).arg(y).arg(w).arg(h).arg(id);
  }

  QSqlQuery write;
  if (!write.exec(lstr)) {
//      out->error(write.lastError().text());
	  qDebug() << write.lastError().text();
      return false;
  }
  return true;
}


// -------------------------------------------------------
bool Db::writeRawImage(const bool insert, const int id,
                       const quint8 epsg, const QString cam, const QString file,
                       const QString usr, const QString session,
                       const QString tmWhen, const QString tmSeen) {
  QString lstr;
  qDebug() << "Save: " << session;
  if (insert) {
    lstr = "INSERT INTO raw_images "
           "(epsg, cam, img, usr, session, tm_when, tm_seen) VALUES "
           "(%1, '%2', '%3', '%4', '%5', '%6', '%7');";
    lstr = lstr.arg(epsg).arg(cam).arg(file).arg(usr).arg(session).arg("").arg("");
  } else {
      lstr = "UPDATE raw_images SET "
             "epsg = %1, cam = '%2', img = '%3', "
             "usr = '%4', session = '%5', "
             "tm_when = '%6', tm_seen = '%7' WHERE rimg_id = %8;";
      lstr = lstr.arg(epsg).arg(cam).arg(file).arg(usr).arg(session)
             .arg(tmWhen).arg(tmSeen).arg(id);
  }

  QSqlQuery write;
  if (!write.exec(lstr)) {
//      out->error(write.lastError().text());
	  qDebug() << write.lastError().text();
      return false;
  }
  return true;
}

// -------------------------------------------------------
bool Db::writeRawCensus(const QString type,
                      const int epsg,
                      const QString cam,
                      const QString img,
                      const QString user,
                      const QString session,
					  const QString px, const QString py,
					  const QString ux, const QString uy,
					  const QString lx, const QString ly) {
	Q_UNUSED(type);

	QString lstr = "INSERT INTO raw_census "
			  "( tp, px, py, ux, uy, lx, ly, epsg, cam, img, usr, session ) "
			  " values ('%1',%2, %3, %4, %5, %6, %7, %8, "
			  "'%9', '%10' , '%11', '%12' );";
   lstr = lstr.arg(type).arg(px).arg(py).arg(ux).arg(uy).arg(lx).arg(ly)
		   .arg(epsg).arg(cam).arg(img).arg(user).arg(session);
   qDebug() << lstr;
	QSqlQuery write;
	if (!write.exec(lstr)) {
		qDebug() << write.lastError().text();
		return false;
	}


    return true;
}

// -------------------------------------------------------
bool Db::deleteRawCensus(int id, const QString & cam, const QString & img, const QString & user) {
    QString query = config->replaceProjectSettings(ACFG_SQL_QRY_DEL_RCENSUS
            .arg(id).arg(cam).arg(img));
    qDebug() << query;
    QSqlQuery req;
    if ( ! req.exec(query) ) {

    	qDebug() << req.lastError().text();
        return false;
    }
    return true;

}

// -------------------------------------------------------
bool Db::writeImageDone(const int imgRdy, const int id) {
  QString lstr;

  lstr = "UPDATE raw_images SET rdy = %1 WHERE rimg_id = %2;";
  lstr = lstr.arg(imgRdy).arg(id);

  QSqlQuery write;
  if (!write.exec(lstr)) {
	  qDebug() << write.lastError().text();
      return false;
  }
  return true;
}

// -------------------------------------------------------
void Db::UpdateObjectQuery(const QString cam, const QString img, QSqlQueryModel * model) {
    QString query;
    if (!config->getProjectId().startsWith("Testdatensatz") || config->getAdmin())
    	query = config->replaceProjectSettings(ACFG_SQL_QRY_READ_RCENSUS_ADMIN.arg(cam).arg(img));
    else
    	query = config->replaceProjectSettings(ACFG_SQL_QRY_READ_RCENSUS.arg(cam).arg(img).arg(config->getUser()));
    qDebug() << query;
    model->setQuery(query);
    return;
}

QStringList Db::getSessionList() {
    QStringList sessionlist;
    QString query;
    if (config->getAdmin())
        query = config->replaceProjectSettings("SELECT project_id FROM projects where active>0 ORDER BY project_id");
    else
        query = config->replaceProjectSettings("SELECT project_id FROM projects where active=1 ORDER BY project_id");
    qDebug() << query;
    QSqlQuery req;
    if ( ! req.exec(query) ) {
    	qDebug() << req.lastError().text();
        return sessionlist;
    }
    while (req.next()) {
        sessionlist.append(QString(req.value(0).toString()));
    }
    return sessionlist;
}

QStringList Db::getSessionParameters(const QString & session) {
    QStringList return_list;
    QString query =
            "SELECT flight_id, utm_sector, path FROM "
            "projects where project_id='" + session + "'";
    qDebug() << query;
    QSqlQuery req;
    if ( ! req.exec(query) ) {
    	qDebug() << req.lastError().text();
        return return_list;
    }
    if(req.next())
        for (int i=0; i<3; i++)
            return_list.append(QString(req.value(i).toString()));
    return return_list;
}

SqlReadyTableModel * Db::getImageView() {
    SqlReadyTableModel * model = new SqlReadyTableModel;
    model->setTable("daisi_bird_census_images");
    model->setHeaderData(model->fieldIndex("session"), Qt::Horizontal,"Projekt", Qt::DisplayRole);
    model->setHeaderData(model->fieldIndex("trc"), Qt::Horizontal,"Trc", Qt::DisplayRole);
    model->setHeaderData(model->fieldIndex("cam"), Qt::Horizontal,"Cam", Qt::DisplayRole);
    model->setHeaderData(model->fieldIndex("img"), Qt::Horizontal,"Bild", Qt::DisplayRole);
    model->setHeaderData(model->fieldIndex("examined"), Qt::Horizontal,"Status", Qt::DisplayRole);
    return model;
}

QSqlExtendedTableModel * Db::getObjectView() {
    QSqlExtendedTableModel * model = new QSqlExtendedTableModel;
    model->setTable("daisi_bird_census_objects");
    model->setHeaderData(model->fieldIndex("tp"), Qt::Horizontal, "Typ", Qt::DisplayRole);
    model->setHeaderData(model->fieldIndex("usr"), Qt::Horizontal, "Nutzer", Qt::DisplayRole);
    model->setHeaderData(model->fieldIndex("rcns_id"), Qt::Horizontal, "Objekt ID", Qt::DisplayRole);
    model->setHeaderData(model->fieldIndex("ux"), Qt::Horizontal, "UTM X", Qt::DisplayRole);
    model->setHeaderData(model->fieldIndex("uy"), Qt::Horizontal, "UTM Y", Qt::DisplayRole);
    model->setHeaderData(model->fieldIndex("session"), Qt::Horizontal, "Projekt", Qt::DisplayRole);
    model->setHeaderData(model->fieldIndex("cam"), Qt::Horizontal, "Kamera", Qt::DisplayRole);
    model->setHeaderData(model->fieldIndex("img"), Qt::Horizontal, "Bildnummer", Qt::DisplayRole);
    return model;
}
