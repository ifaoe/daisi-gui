#include "mapgeometry.h"

mapgeometry::mapgeometry(const QString &wkt_string) {
    geometry = new QgsGeometry;
    geometry->fromWkt(wkt_string);
}

void mapgeometry::setOutlineColor(QColor color) {
    color_outline = color;
}

void mapgeometry::setFillColor(QColor color) {
    color_fill = color;
}
