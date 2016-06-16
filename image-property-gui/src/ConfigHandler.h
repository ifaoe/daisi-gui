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

class ConfigHandler : public QSettings{
public:
    void InitSettings();
    void setUser(const QString & user_name) { user = user_name; }
    QString getUser() {return user;}
    void setAppPosition(QPoint pos);
    QPoint getAppPosition();
    void setAppSize(QSize size);
    QSize getAppSize();
    void setAppMaximized(bool max);
    bool getAppMaximized();
    void setPreferredDatabase(const QString & database);
    QString getPreferredDatabase();
    void setSessionName(const QString & session);
    QString getPreferredSession();
    QStringList getDatabaseList();
    QString getSystemUser();
    QString dbHost();
    QString dbName();
    int dbPort();
    QString dbUser();
    QString dbPassword();
    void setVersion(const QString & version) { version_p = version; }
    QString version() {return version_p;}
private:
    QString user;
    QString version_p;
};

#endif /* CONFIGHANDLER_H_ */
