/*
 * GIS Map Canvas
 */
#ifndef DAISIMAPCANVAS_H
#define DAISIMAPCANVAS_H

#include <qgsmapcanvas.h>
#include <qgsmaptoolemitpoint.h>
#include <qgsmaptoolpan.h>
#include <qgsrasterlayer.h>
#include <qgsvectorlayer.h>
#include <mapmarker.h>

#include <QPixmap>


class DaisiMapCanvas : public QgsMapCanvas
{

public:
    DaisiMapCanvas();
    bool openImage(const QString & path);
    void closeImage();
    void addMapMarker(const QString & id_name, MapCanvasMarker * marker);
    MapCanvasMarker * getMapMarker(const QString & id_name);
    void removeMapMarker(const QString & id_name);
    void setMapMarkerSelection(const QString & id_name, bool selected);
    void deselectAllMapMarker();
    void setLayerTransparency(const QString & layer_name, int value);
    bool addVectorLayer(const QString & layer_name, const QString & layer_type);
    void removeLayer(const QString & layer_name);
    void addGeometry(const QString & layer_name, const QString & id_name, const QString & wkt_string);
    void removeGeometry(const QString & layer_name, const QString & id_name);
    void hideFeature(const QString & id_name);
    QStringList getLayerList();
    QStringList getFeatureList(const QString & layer_name);
    QStringList getMarkerList(const QString & layer_name);
    QPixmap getCurrentPixmap();
    void setColorBandLimits(int red_min, int red_max, int green_min, int green_max, int blue_min, int blue_max);
    void setColorBandMapping(int red_band, int blue_band, int green_band);
    void setSelectionDistance(double distance);
private:
    QgsMapToolEmitPoint * emit_point_tool;
    QgsMapToolPan * pan_tool;

    QgsRasterLayer * image_layer = 0;
    QMap<QString, QgsVectorLayer*> vector_layers;
    QStringList vector_layer_order;

    QgsCoordinateReferenceSystem crs_4326;
    QgsCoordinateReferenceSystem crs_utm;

    QgsCoordinateTransform crs_4326_to_utm;
    QgsCoordinateTransform crs_utm_to_4326;

    int color_red_min = 0;
    int color_red_max = 65535;
    int color_green_min = 0;
    int color_green_max = 65535;
    int color_blue_min = 0;
    int color_blue_max = 65535;

    int color_red_band = 1;
    int color_green_band = 2;
    int color_blue_band = 3;

    double selection_distance = 0.5;

    QMap<QString, MapCanvasMarker*> map_markers;
    QMap<QString, QPointF> map_marker_positions;

    void refreshLayerSet();
signals:
    void canvasClicked(const QPoint & point);
    // void markerClicked(const QString & layer_name, const QString & id_name); // Vielleicht auch nicht
    void featureClicked(const QString & id_name);
public slots:
    void zoomIn();
    void zoomOut();
    void zoomFullExtent();
    void zoomScale(double scale);
    void zoomCenter(QPoint center, double scale);
};

#endif // DAISIMAPCANVAS_H
