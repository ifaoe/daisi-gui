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
	bool SaveCode(QString type);
	QSqlDatabase * GetDatabase() {return db;}
    QSqlSortModel * getPropertyTable();
	QString GetPropertyProgress(QString type);
private:
    ConfigHandler * config = 0;
	QSqlDatabase * db = 0;
};

#endif /* DATABASEHANDLER_H_ */
