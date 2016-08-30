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

#ifndef CONFIGHANDLER_H_
#define CONFIGHANDLER_H_

#include <QSettings>
#include <QDebug>

struct DatabaseInfo {
	QString id = "local";
	QString host = "localhost";
	int port = 5432;
	QString name = "daisi";
	QString password = "18ifaoe184";
	QString user = "daisi";
};

class ConfigHandler : public QSettings{
public:
    void AddDatabase(const QString & host, int port, const QString & name,const QString & user, const QString & password);
	void setUser(const QString & user_name) { user = user_name; }
	QString getUser() {return user;}
	void setAppPosition(QPoint pos);
	QPoint getAppPosition();
	void setAppSize(QSize size);
	QSize getAppSize();
    void setAdmin(bool permission);
    bool getAdmin();
	void setAppMaximized(bool max);
	bool getAppMaximized();
    QString dbHost();
    QString dbName();
    int dbPort();
    QString dbUser();
    QString dbPassword();
	void setSessionName(const QString & session);
	QString getPreferredSession();
    void setLocation(const QString & location);
    QString location();
    void setSystemUser(const QString & login) { system_user = login; }
    QString getSystemUser() { return system_user; }
    int getRedChannel();
    int getGreenChannel();
    int getBlueChannel();
private:
    QString user;
    QString system_user;
};

#endif /* CONFIGHANDLER_H_ */
