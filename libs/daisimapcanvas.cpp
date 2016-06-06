#include "daisimapcanvas.h"
#include <qgsmaplayerregistry.h>
#include <qgsrasterdataprovider.h>
#include <qgsmultibandcolorrenderer.h>

#include <QMessageBox>

DaisiMapCanvas::DaisiMapCanvas() {
    // Initialize MapCanvas
    enableAntiAliasing(true);
    setParallelRenderingEnabled( true );
    setCanvasColor(QColor(0, 0, 0));
    freeze(false);

    // Initialize Map Tools
    emit_point_tool = new QgsMapToolEmitPoint(this);
    pan_tool = new QgsMapToolPan(this);

    // Layer Registry singleton
    QgsMapLayerRegistry::instance();

    // Koordinatensystem Parameter
    // Momentan Geokoordinaten
    // TODO: UTM?
    crs_4326.createFromSrid(4326);
    setMapUnits(QGis::Meters);
}

/*
 * Öffnen eines Bildes als RasterLayer
 */
bool DaisiMapCanvas::openImage(const QString &path) {
    // Falls ein Bild bereits geladen ist, löschen des Objektes und entfernen aus Layer
    if (image_layer == 0) {
        QgsMapLayerRegistry::instance()->removeMapLayer(image_layer->id());
        delete image_layer;
        image_layer = 0;
    }

    QFileInfo file( path );
    if (!file.exists()) {
        qDebug() << "File " << path << " does not exist.";
        return false;
    }

    image_layer = new QgsRasterLayer(file.filePath(), file.fileName());
    if (!image_layer->isValid()) {
        qDebug() << "Raster Layer is not valid.";
        delete image_layer;
        image_layer = 0;
        return false;
    }

    /*
     * Ersetzen des originalen QGis Raster Renderes durch eine eigne Implementation um die QGis-"Optimierungen" der
     * Farbbänder zu umgehen.
     */

    QgsRasterDataProvider * image_provider = image_layer->dataProvider();

    QgsContrastEnhancement* contrast_enhance_red = new QgsContrastEnhancement(QGis::UInt16);
    contrast_enhance_red->setMinimumValue(color_red_min);
    contrast_enhance_red->setMaximumValue(color_red_max);
    contrast_enhance_red->setContrastEnhancementAlgorithm (
            QgsContrastEnhancement::StretchToMinimumMaximum);

    QgsContrastEnhancement* contrast_enhance_green = new QgsContrastEnhancement(QGis::UInt16);
    contrast_enhance_green->setMinimumValue(color_green_min);
    contrast_enhance_green->setMaximumValue(color_green_max);
    contrast_enhance_green->setContrastEnhancementAlgorithm (
            QgsContrastEnhancement::StretchToMinimumMaximum);

    QgsContrastEnhancement* contrast_enhance_blue = new QgsContrastEnhancement(QGis::UInt16);
    contrast_enhance_blue->setMinimumValue(color_blue_min);
    contrast_enhance_blue->setMaximumValue(color_blue_max);
    contrast_enhance_blue->setContrastEnhancementAlgorithm (
            QgsContrastEnhancement::StretchToMinimumMaximum);

    QgsMultiBandColorRenderer* renderer = new QgsMultiBandColorRenderer( image_provider,
        color_red_band, color_green_band, color_blue_band,
        contrast_enhance_red, contrast_enhance_green, contrast_enhance_blue);

    image_layer->setRenderer(renderer);


    /*
     * Extraktion des zugrundeliegenden UTM Koordinatensystems aus GEOTIFF und Definition der entsprechenden Hin- und
     * Rücktransformationen
     */
    crs_utm = image_provider->crs();
    crs_4326_to_utm.setSourceCrs(crs_4326);
    crs_4326_to_utm.setDestCRS(crs_utm);
    crs_utm_to_4326.setSourceCrs(crs_utm);
    crs_utm_to_4326.setDestCRS(crs_4326);

    QgsMapLayerRegistry::instance()->addMapLayer(image_layer);
    refreshLayerSet();

    return true;
}

bool DaisiMapCanvas::addVectorLayer(const QString &layer_name, const QString & layer_type) {
    if (vector_layers.contains(layer_name)) {
        qDebug() << "Layer " << layer_name << " is already in the layer set. Aborting.";
        return false;
    }

    /*
     * Vector Layer Parameter setzen
     */
    QString layer_properties = "%1?crs=epsg%2";
    QgsVectorLayer * layer =
            new QgsVectorLayer(layer_properties.arg(layer_type).arg(crs_utm.srsid()), layer_name, "memory");

    // Wenn etwas schiefläuft abbrechen
    if (!layer->isValid()) {
        delete layer;
        return false;
    }

    vector_layers[layer_name] = layer;
    vector_layer_order.append(layer_name);

    QgsMapLayerRegistry::instance()->addMapLayer(layer);
    refreshLayerSet();
    return true;
}

/*
 * Automatisch alle vorhandenen Layer in ein LayerSet überführen und dann an den MapCanvas senden
 */
void DaisiMapCanvas::refreshLayerSet() {
    QList<QgsMapCanvasLayer> layer_set;
    layer_set.append(image_layer);
    for (int i=0; i<vector_layer_order.size(); i++)
        layer_set.append(vector_layers[vector_layer_order[i]]);
    setLayerSet(layer_set);
}

void DaisiMapCanvas::addMapMarker(const QString &id_name, MapCanvasMarker * marker) {
    if (map_markers.contains(id_name)) {
        qDebug() << "Map marker with id: " << id_name << " already exists.";
        return;
    }
    map_markers[id_name] = marker;
}

MapCanvasMarker * DaisiMapCanvas::getMapMarker(const QString &id_name) {
    return map_markers[id_name];
}

void DaisiMapCanvas::removeMapMarker(const QString &id_name) {
    delete map_markers[id_name];
    map_markers.remove(id_name);
}

/*
 * public slots
 */

void DaisiMapCanvas::zoomIn() {
    QgsMapCanvas::zoomIn();
}

void DaisiMapCanvas::zoomOut() {
    QgsMapCanvas::zoomOut();
}

void DaisiMapCanvas::zoomScale(double scale) {
    QgsMapCanvas::zoomScale(scale);
}

