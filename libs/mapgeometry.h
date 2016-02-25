#ifndef MAPGEOMETRY_H
#define MAPGEOMETRY_H

#include <QObject>
#include <QColor>
#include <qgsgeometry.h>

class mapgeometry
{
public:
    mapgeometry(const QString & wkt);
    void fromWkt(const QString & wkt);
    void setOutlineColor(QColor color);
    void setFillColor(QColor color);
private:
    QgsGeometry * geometry;
    QColor color_outline = Qt::black;
    QColor color_fill = Qt::black;
signals:

public slots:
};

#endif // MAPGEOMETRY_H
