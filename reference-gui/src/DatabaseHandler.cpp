/*
 * DatabaseHandler.cpp
 *
 *  Created on: Jul 22, 2015
 *      Author: awg
 */

#include "DatabaseHandler.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>

DatabaseHandler::DatabaseHandler(UserSettings * cfg) : config(cfg){
	// TODO Auto-generated constructor stub

    db = new QSqlDatabase();
	*db = QSqlDatabase::addDatabase("QPSQL");
	if (!db->isValid()) {
		qFatal("Database invalid: QPSQL");
	}
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

DatabaseHandler::~DatabaseHandler() {
	// TODO Auto-generated destructor stub
	db->close();
}

QString DatabaseHandler::GetImageLocation(const QString & session, const QString & cam, const QString & img) {
    QSqlQuery query;
    query.prepare("SELECT path FROM projects WHERE project_id=:project AND location=:location");
    query.bindValue(":project", session);
    query.bindValue(":location", config->location());
    if (!query.exec()) {
        QMessageBox::critical(0,"Database error", query.lastError().text());
    }
	if (query.next())
		return 	query.value(0).toString() + QString("/cam%1/geo/%2.tif").arg(cam).arg(img);
	return QString();
}

void DatabaseHandler::GetFilterOptions(QComboBox * box, const QString & type) {
	box->clear();
	box->addItem("-",QString("%"));
	QString query_string = "SELECT DISTINCT %1 FROM view_census WHERE censor = 2 AND confidence<4 AND tp like '%2' ORDER BY %1";
	QSqlQuery query(query_string.arg(box->property("column").toString()).arg(type));
	while(query.next())
			box->addItem(query.value(0).toString(),query.value(0));
}

QStringList DatabaseHandler::getLocationList() {
    QSqlQuery query;
    query.prepare("SELECT DISTINCT location FROM projects ORDER BY location");
    if (!query.exec()) {
       QMessageBox::critical(0, "Database Error", query.lastError().text());
       exit(EXIT_FAILURE);
    }
    QStringList locations;
    while(query.next())
        locations.append(query.value(0).toString());
    return locations;
}

QStringList DatabaseHandler::GetSessionList() {
	QStringList return_list;
	return_list.append(QString());
	QString query_string = "SELECT DISTINCT session FROM raw_census ORDER BY session";
	QSqlQuery query(query_string);
	while (query.next())
		return_list.append(query.value(0).toString());
	return return_list;
}

QSqlTableModel * DatabaseHandler::getObjectModel() {
	QSqlTableModel * model = new QSqlTableModel;
	model->setTable("view_census");
	return model;
}

