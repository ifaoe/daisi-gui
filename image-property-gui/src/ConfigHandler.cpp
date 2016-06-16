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

#include "ConfigHandler.h"
#include <QFile>
#include <QSize>
#include <QPoint>
#include <QStringList>

void ConfigHandler::InitSettings() {
    user = QString(getenv("USER"));
}


QString ConfigHandler::getSystemUser() {
    return QString(getenv("USER"));
}

void ConfigHandler::setSessionName(const QString & session) {
    setValue("session", session);
}

QString ConfigHandler::getPreferredSession() {
    return value("session","").toString();
}

void ConfigHandler::setAppSize(QSize size) {
    setValue("MainWindow/size",size);
}

QSize ConfigHandler::getAppSize() {
    return value("MainWindow/size",QSize(800,600)).toSize();
}

void ConfigHandler::setAppPosition(QPoint pos) {
    setValue("MainWindow/position",pos);
}

QPoint ConfigHandler::getAppPosition() {
    return value("MainWindow/position",QPoint(50,50)).toPoint();
}

void ConfigHandler::setAppMaximized(bool max) {
    setValue("MainWindow/maximized",max);
}

bool ConfigHandler::getAppMaximized() {
    return value("MainWindow/maximized",false).toBool();
}

QStringList ConfigHandler::getDatabaseList() {
    beginGroup("Database");
    QStringList children = childGroups();
    endGroup();
    return children;
}

QString ConfigHandler::dbHost() {
    return value("database/host", "192.168.118.35").toString();
}

int ConfigHandler::dbPort() {
    return value("database/port", 5432).toInt();
}

QString ConfigHandler::dbName() {
    return value("database/name", "daisi").toString();
}

QString ConfigHandler::dbUser() {
    return value("database/user", "daisi").toString();
}

QString ConfigHandler::dbPassword() {
    return value("database/password", "18ifaoe184").toString();
}
