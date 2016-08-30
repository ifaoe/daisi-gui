/*
 * DatabaseHandler.h
 *
 *  Created on: Jul 22, 2015
 *      Author: awg
 */

#ifndef DATABASEHANDLER_H_
#define DATABASEHANDLER_H_

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QComboBox>
#include "ConfigHandler.h"
#include "qsqlsortmodel.h"

class DatabaseHandler {
public:
    DatabaseHandler(ConfigHandler * config);
	virtual ~DatabaseHandler();
	void OpenDatabase();
	QStringList GetProjectList();
	QStringList GetProjectCams();
	QStringList GetProjectTracs();
	void GetStuk4Codes(QString type, QComboBox * combo_box);
    QSqlQueryModel * getIceCodes();
    QSqlQueryModel * getGlareCodes();
    QSqlQueryModel * getSeastateCodes();
    QSqlQueryModel * getTurbidityCodes();
    QSqlQueryModel * getClarityCodes();
	QSqlDatabase * GetDatabase() {return db;}
    QSqlSortModel * getPropertyTable();
	QString GetPropertyProgress(QString type);
    QString getSessionVersion(const QString & session);

    bool checkUsername(const QString & login);
    bool checkPassword(const QString & login, const QString & password);
    bool changePassword(const QString & login, const QString & password);
private:
    ConfigHandler * config = 0;
	QSqlDatabase * db = 0;
};

#endif /* DATABASEHANDLER_H_ */
