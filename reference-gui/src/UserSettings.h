/*
 * UserSettings.h
 *
 *  Created on: Aug 12, 2015
 *      Author: awg
 */

#ifndef SRC_USERSETTINGS_H_
#define SRC_USERSETTINGS_H_

#include <QSettings>
#include <QStringList>
#include <QPoint>
#include <QSize>

class UserSettings : public QSettings{
public:

	void setVisibleColumns(QStringList columns);
	QStringList getVisibleColumns();
	void setAppPosition(QPoint pos);
	QPoint getAppPosition();
	void setAppSize(QSize size);
	QSize getAppSize();
	void setAppMaximized(bool max);
	bool getAppMaximized();
    QString dbHost();
    QString dbName();
    int dbPort();
    QString dbUser();
    QString dbPassword();
    QString location();
    void setLocation(const QString & location);
    int getRedChannel();
    int getGreenChannel();
    int getBlueChannel();
};

#endif /* SRC_USERSETTINGS_H_ */
