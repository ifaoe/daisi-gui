/*
 * UserSettings.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: awg
 */

#include "UserSettings.h"
#include <QFile>
#include <QDebug>


/*
 * get and set
 */

void UserSettings::setVisibleColumns(QStringList columns) {
	setValue("Census/columns_visible", columns);
}

QStringList UserSettings::getVisibleColumns() {
	QStringList default_columns = QStringList() << "rcns_id" << "name" <<"id_code" << "confidence" <<"beh" << "age" <<
			"age_year" << "gen" << "plumage" << "dir" << "imgqual" << "length" << "width" << "stuk4_ass" << "stuk4_beh";
	return value("Census/columns_visible", default_columns).toStringList();
}

void UserSettings::setAppSize(QSize size) {
	setValue("MainWindow/size",size);
}

QSize UserSettings::getAppSize() {
	return value("MainWindow/size",QSize(800,600)).toSize();
}

void UserSettings::setAppPosition(QPoint pos) {
	setValue("MainWindow/position",pos);
}

QPoint UserSettings::getAppPosition() {
	return value("MainWindow/position",QPoint(50,50)).toPoint();
}

void UserSettings::setAppMaximized(bool max) {
	setValue("MainWindow/maximized",max);
}

bool UserSettings::getAppMaximized() {
	return value("MainWindow/maximized",false).toBool();
}

int UserSettings::getRedChannel() {
    return value("QGis/red_channel",1).toInt();
}

int UserSettings::getGreenChannel() {
    return value("QGis/green_channel",2).toInt();
}

int UserSettings::getBlueChannel() {
    return value("QGis/blue_channel",3).toInt();
}

QString UserSettings::dbHost() {
    return value("database/host", "192.168.118.35").toString();
}

int UserSettings::dbPort() {
    return value("database/port", 5432).toInt();
}

QString UserSettings::dbName() {
    return value("database/name", "daisi").toString();
}

QString UserSettings::dbUser() {
    return value("database/user", "daisi").toString();
}

QString UserSettings::dbPassword() {
    return value("database/password", "18ifaoe184").toString();
}

QString UserSettings::location() {
    return value("location", QString()).toString();
}

void UserSettings::setLocation(const QString & location) {
    setValue("location", location);
}
