/*
 * DatabaseHandler.h
 *
 *  Created on: Jul 22, 2015
 *      Author: awg
 */

#ifndef DATABASEHANDLER_H_
#define DATABASEHANDLER_H_

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QComboBox>
#include "UserSettings.h"

class DatabaseHandler {
public:
	DatabaseHandler(UserSettings * cfg);
	virtual ~DatabaseHandler();
	bool OpenDatabase();
	QString GetImageLocation(const QString & session, const QString & cam, const QString & img);
	QSqlTableModel * getObjectModel();
	void GetFilterOptions(QComboBox * box, const QString & type);
	QStringList GetSessionList();
	bool isOpen() { return db->isOpen(); }
private:
	UserSettings * config = 0;
	QSqlDatabase * db = 0;
};

#endif /* DATABASEHANDLER_H_ */
