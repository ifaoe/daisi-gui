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

#ifndef DATABASEHANDLER_H_
#define DATABASEHANDLER_H_

#include <QSqlDatabase>
#include <QStringList>
#include <QComboBox>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include "ConfigHandler.h"
#include "census.hpp"
#include "CensorSqlTableModel.h"

class DatabaseHandler {
public:
    DatabaseHandler(ConfigHandler *cfg);
    virtual ~DatabaseHandler();
    bool OpenDatabase();
    QStringList getSessionList(const QString & location);
    QSqlQuery * getObjectResult(QString session, QString user, QString filter="", QString order="");
    census * getRawObjectData(QString objId, QString usr);
    bool getSpeciesList(const QString & type, QComboBox * combo_box);
    QStringList getUserList(int objId);
    census * getCensusData(QString objId);
    bool writeCensus(census * obj);
    QString getProjectPath(QString session);
//    void revisitObject(QString objId);
    QMap<int, int> getObjectDone(QString usr, QString session);
    QMap<int, int> getObjectFinal(QString session);
    int getMaxCensor(QString ObjId);
    int getMaxCensor(QString objId, QString usr);
    int getCensorCount(QString ObjId, QString censor);
    int getCensorCount(QString ObjId, QString censor, QString usr);
    QMap<int, QString> getUserCensus(QString usr, QString session);
    QMap<int, QString> getFinalCensus(QString session);
    void deleteCensusData(QString objId, QString usr);
    bool getSessionActive(const QString & session);
    bool GetAnthroObjectList(QComboBox * cmb);
    QSqlQueryModel * getStuk4Behaviour();
    QSqlQueryModel * getStuk4Associations();
    QSqlQueryModel * getCloseObjects(census * obj);
    QSqlQueryModel * getImageObjects(census * obj);
    QStringList getFlightInfoList(QString cam, QString flight, QString img);
    void GetBirdAgeClasses(QComboBox * cmb_box);
    void GetMiscObjects(QComboBox * cmb_box);
    void GetBirdPlumageClasses(QComboBox * cmb_box);
    int getCensusCount(const QString & session, const QString & user,
    		const QString & having_filter = "TRUE", const QString & where_filter = "TRUE");
    CensorSqlTableModel * getObjectModel();
    QStringList getLocationList();

    QString sessionName();
    QString sessionPath();
    QString sessionVersion();
    void refreshSessionProperties(const QString & name);
private:
    QSqlDatabase *db;
    ConfigHandler *config;

    QString session_name;
    QString session_path;
    QString session_version;

    void setRecordTable(QSqlRecord * record, census * obj);
};


#endif /* DATABASEHANDLER_H_ */
