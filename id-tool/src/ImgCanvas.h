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

#ifndef IMGCANVAS_H_
#define IMGCANVAS_H_

#include <QDebug>
#include <QObject>
#include <QWidget>
#include <QNetworkReply>
#include <QMessageBox>
#include <qgis.h>
#include <qgsmapcanvas.h>
#include <qgsrasterlayer.h>
#include <qgsvectorlayer.h>
#include <qgsrasterdataprovider.h>
#include <qgsproviderregistry.h>
#include <qgsmaptoolemitpoint.h>
#include <qgsmaptoolpan.h>
#include <qgsgeometry.h>
#include "QgsLayerStack.h"
#include "ConfigHandler.h"
#include "DatabaseHandler.h"
#include "ui_mainwindow.h"
#include "census.hpp"
#include <qgslabel.h>
#include <qgslabelattributes.h>
#include <qgsfield.h>
#include "mapmarker.h"

class MeasurementDialog;

class ImgCanvas: public QgsMapCanvas {
    Q_OBJECT
public:
    ImgCanvas(QWidget *parent, Ui::MainWindow *mUi, ConfigHandler * cfg, DatabaseHandler *db);
    virtual ~ImgCanvas();
    bool loadObject(census * obj);
    void centerOnPixelPosition(int x, int y, double scale);
    void centerOnWorldPosition(double ux, double uy, double scale);
    QgsPoint calcWorldPosition(int x, int y);
    QgsPoint calcPixelPosition(const QgsPoint & pos);
    QgsRasterLayer * getImageLayer();
    void setRasterBrightness(int value);
    void setRasterContrast(int value);
    void beginMeasurement(int type);
    double getCurrentMeasurement();
private:
    QgsLayerStack * layerStack = 0;
    Ui::MainWindow *ui = 0;
    ConfigHandler *cfg = 0;
    DatabaseHandler *db = 0;
    QgsRasterLayer * imgLayer = 0;
    QgsVectorLayer * poly_layer = 0;
    QgsRasterDataProvider* imgProvider = 0;


    QgsMapToolEmitPoint *qgsEmitPointTool = 0;
    QgsMapToolPan * qgsMapPanTool = 0;

    QgsCoordinateReferenceSystem crs_utm;
    QgsCoordinateReferenceSystem crs_geo = QgsCoordinateReferenceSystem(4326);
    QgsCoordinateTransform geo2utm;
    QgsCoordinateTransform utm2geo;

    QNetworkAccessManager* networkManager = 0;

    QSqlTableModel * objModel = 0;

    QString curSession = "";
    QString curCam = "";
    QString curImg = "";

    QMessageBox * measurement_dialog = 0;
    QPoint measure_position = QPoint();
    QgsPolyline msmList;
    std::vector<MapCanvasMarker*> msmMarkers;
    std::vector<MapCanvasMarker*> objMarkers;
    int measurement_type = 0;
    bool measurement_running = false;
    void populateObjectLayer(census * obj);
    void refreshMapMarkers();
private slots:
    void handleCanvasClicked(const QgsPoint & point);
    void handleHideObjectMarkers();
    void HandleZoomIn() {zoomIn();}
    void HandleZoomOut() {zoomOut();}
    void HandleZoomFullExtent() {zoomToFullExtent();}
    void endMeasurement(QAbstractButton * button);
    void handleRightClick(const QgsPoint & point, Qt::MouseButton button);
public slots:
    void activatePanMode();
    void activatePointMode();
    void showPolyLayer(bool visible);
signals:
    void measurementDone(int type, double size);
};

#endif /* IMGCANVAS_H_ */
