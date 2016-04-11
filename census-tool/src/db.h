#ifndef DB_H
#define DB_H

#include <QPlainTextEdit>
#include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QWidgetItem>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QStringListModel>
#include <qgsvectorlayer.h>
#include <qgsvectordataprovider.h>
#include <qgsfield.h>
#include <qgsgeometry.h>
#include <qgspoint.h>
#include <qgsfeature.h>
#include "ConfigHandler.h"
#include <ctime>
#include "sqlreadytablemodel.h"
#include "qsqlextendedtablemodel.h"
#include <QSqlTableModel>

typedef struct std::tm time_struct;

struct project {
	QString project_id = "";
	QString flight_id = "";
	int utmSector = 32;
	QString path = "";
};

class Database {
public:
    explicit Database(ConfigHandler *config);

    bool OpenDatabase();

    QStringList getLocationList();

    void UpdateObjectQuery(const QString cam, const QString img, QSqlQueryModel * model);

    bool deleteRawCensus(int id, const QString & cam, const QString & img, const QString & usr);

    bool writeImageDone(const int imgRdy, const int id);

    bool writeRawCensus(const QString type,
            const int epsg,
            const QString cam,
            const QString img,
            const QString user,
            const QString session,
			  const QString px, const QString py,
			  const QString ux, const QString uy,
			  const QString lx, const QString ly);

    bool writeRawImage(const bool insert, const int id,
                       const quint8 epsg, const  QString cam, const QString file,
                       const QString usr, const QString session,
                       const QString tmWhen, const QString tmSeen);

    bool writeRawImageTile(    const bool insert, const int id,
                               const quint8 epsg, const QString cam, const QString file,
                               const QString usr, const QString session,
                               const QString x, const QString y,
                               const QString w, const QString h,
                               const QString tmWhen, const QString tmSeen);

    bool readRawImage(const QString &cam, const QString &file, const QString &usr, int &id, QString &tmWhen, QString &tmSeen);

    bool readRawImageTile(const QString &cam, const QString &file, const QString &usr, int &id, QString &ux, QString &uy,
    		QString &w, QString &h, QString &tmWhen, QString &tmSeen);

    QgsGeometry* readImageEnvelope(const QString cam, const QString image);
    QgsGeometry* readValidPolygon(const QString cam, const QString image);

    QStringList getSessionList();

    QStringList getSessionParameters(const QString & session);

    SqlReadyTableModel * getImageView();

    QSqlExtendedTableModel * getObjectView();

private:
    ConfigHandler *config;
    QString uri;
    QSqlDatabase  *db = 0;
};

#endif // DB_H
