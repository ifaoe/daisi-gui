/*
 * DatabaseHandler.cpp
 *
 *  Created on: Jul 22, 2015
 *      Author: awg
 */

#include "DatabaseHandler.h"
#include <QSqlQuery>
#include <QDebug>
#include <iostream>
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
    DatabaseInfo db_info = config->getDatabaseInfo(config->getPreferredDatabase());
    db->setHostName(db_info.host);
    db->setDatabaseName(db_info.name);
    db->setPort(db_info.port);
    db->setUserName(db_info.user);
    db->setPassword(db_info.password);
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

bool DatabaseHandler::SaveCode(QString type) {
	Q_UNUSED(type);
	return true;
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
    qDebug() << query_string.arg(type).arg(config->getPreferredSession());
    cout <<  query_string.arg(type).arg(config->getPreferredSession()).toStdString() << endl;
    QSqlQuery query(query_string.arg(type).arg(config->getPreferredSession()));
	if (query.next()) {
		current = query.value(0).toString();
		total = query.value(1).toString();
	}
	return_string = current + "\t/" + total;
	return return_string;
}
