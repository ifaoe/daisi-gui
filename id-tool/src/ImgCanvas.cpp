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

#include "ImgCanvas.h"
#include <qgsmultibandcolorrenderer.h>
#include <QFileDialog>
#include <QNetworkAccessManager>
#include <math.h>
#include <QMessageBox>
#include <qgsgeometry.h>
#include <qgsvectordataprovider.h>
#include <QSqlRecord>
#include <QMenu>
#include <QSqlQuery>
#include <QSqlError>

ImgCanvas::ImgCanvas(QWidget *parent, Ui::MainWindow *mUi, ConfigHandler *cfg, DatabaseHandler *db)
    : QgsMapCanvas(parent),ui(mUi), cfg(cfg), db(db) {
    // TODO Auto-generated constructor stub

    enableAntiAliasing(true);
    setParallelRenderingEnabled( true );
    setCanvasColor(QColor(0, 0, 0));
    freeze(false);
    setCachingEnabled(true);
    setCacheMode(QgsMapCanvas::CacheBackground);

    setMapUnits(QGis::Meters);
    layerStack = new QgsLayerStack(this);

    qgsEmitPointTool = new QgsMapToolEmitPoint(this);
    qgsMapPanTool = new QgsMapToolPan(this);
    networkManager = new QNetworkAccessManager(this);
    measurement_dialog = new QMessageBox;
    measurement_dialog->setText(QString::fromUtf8("Messung läuft."));
    measurement_dialog->setWindowModality(Qt::NonModal);
    measurement_dialog->setModal(false);
    measurement_dialog->setWindowFlags( measurement_dialog->windowFlags() | Qt::WindowStaysOnTopHint );
    /*
     * TODO: Hack to fix the stupid messagebox size
     */
    QSpacerItem* horizontalSpacer = new QSpacerItem(400, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layout = (QGridLayout*)measurement_dialog->layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());

    setMapTool(qgsMapPanTool);

    connect(ui->toolbutton_toggle_marks, SIGNAL(clicked()), this, SLOT(handleHideObjectMarkers()));
    connect(ui->toolbutton_zoom_in,SIGNAL(clicked()),this,SLOT(HandleZoomIn()));
    connect(ui->toolbutton_zoom_out,SIGNAL(clicked()),this,SLOT(HandleZoomOut()));
    connect(ui->toolbutton_zoom_full,SIGNAL(clicked()),this,SLOT(HandleZoomFullExtent()));
    connect(qgsEmitPointTool, SIGNAL(canvasClicked(QgsPoint,Qt::MouseButton)), this, SLOT(handleRightClick(QgsPoint,Qt::MouseButton)));
}

ImgCanvas::~ImgCanvas() {
    // TODO Auto-generated destructor stub
    delete qgsEmitPointTool;
    delete layerStack;
}

bool ImgCanvas::loadObject(census * obj) {
    endMeasurement(0);
    // check if still same image
    if (curSession == obj->session && curCam == obj->camera && curImg == obj->image) {
        centerOnWorldPosition(obj->ux, obj->uy, 1.0);
        return true;
    }

    if(imgLayer) {
        layerStack->removeMapLayer("image");
    }
    this->refresh();

    QString image_path = db->sessionPath();
    QString file = image_path + "/cam" + obj->camera + "/geo/" + obj->image + ".tif";
    qDebug() << "Loading file " << file;

    QFileInfo info(file);
    if ( !info.isFile() || !info.isReadable() ) {
           qDebug() << "Error: Invalid Filepath: " << file;
           QMessageBox *imgerror= new QMessageBox();
           imgerror->setText("Fehler beim Laden des Bildes.");
           imgerror->addButton(trUtf8("Abbrechen"), QMessageBox::NoRole);
           imgerror->exec();
           delete imgerror;
           return false;
    } else {
        qDebug() << "Success.";
    }

    curSession = obj->session;
    curCam = obj->camera;
    curImg = obj->image;



    QString basePath = info.filePath();
    QString baseName = info.fileName();

    imgLayer = new QgsRasterLayer(basePath,baseName);
    if ( !imgLayer->isValid() ) {
        qDebug() << "Warning: Imagelayer is invalid!";

        QMessageBox *imgerror= new QMessageBox();
        imgerror->setText("Fehler beim Laden des Bildes.");
        imgerror->addButton(trUtf8("Abbrechen"), QMessageBox::NoRole);
        imgerror->exec();
        delete imgerror;
        return false;
    }
    imgProvider = imgLayer->dataProvider();

    crs_utm = imgLayer->crs();
    utm2geo.setSourceCrs(crs_utm);
    utm2geo.setDestCRS(crs_geo);

    geo2utm.setSourceCrs(crs_geo);
    geo2utm.setDestCRS(crs_utm);

    /*
     * No Data Values deaktivieren.
     * Verursachen Probleme in Bezug auf georeferenzierte JPEGs oder JPEG komprimierte TIFFs
     */
    for ( int bandNo = 1; bandNo <= imgProvider->bandCount(); bandNo++ )
        imgProvider->setUseSrcNoDataValue( bandNo, false );

    QgsContrastEnhancement* qgsContrastEnhRed = new QgsContrastEnhancement(imgProvider->dataType(cfg->getRedChannel()));
//    qgsContrastEnhRed->setMinimumValue(0);
//    qgsContrastEnhRed->setMaximumValue(pow(2, 8*qgsImgProvider->dataTypeSize(config->getRedChannel())));
//    qgsContrastEnhRed->setContrastEnhancementAlgorithm(QgsContrastEnhancement::StretchToMinimumMaximum);

    QgsContrastEnhancement* qgsContrastEnhGreen = new QgsContrastEnhancement(imgProvider->dataType(cfg->getGreenChannel()));
//    qgsContrastEnhGreen->setMinimumValue(0);
//    qgsContrastEnhGreen->setMaximumValue(pow(2, 8*qgsImgProvider->dataTypeSize(config->getGreenChannel())));
//    qgsContrastEnhGreen->setContrastEnhancementAlgorithm(QgsContrastEnhancement::StretchToMinimumMaximum);

    QgsContrastEnhancement* qgsContrastEnhBlue = new QgsContrastEnhancement(imgProvider->dataType(cfg->getBlueChannel()));
//    qgsContrastEnhBlue->setMinimumValue(0);
//    qgsContrastEnhBlue->setMaximumValue(pow(2, 8*qgsImgProvider->dataTypeSize(config->getBlueChannel())));
//    qgsContrastEnhBlue->setContrastEnhancementAlgorithm(QgsContrastEnhancement::StretchToMinimumMaximum);

    QgsMultiBandColorRenderer* renderer = new QgsMultiBandColorRenderer( imgProvider, 1, 2, 3,
                qgsContrastEnhRed, qgsContrastEnhGreen, qgsContrastEnhBlue);

    imgLayer->setRenderer( renderer );

    layerStack->addMapLayer("image", imgLayer, 100);
    setExtent(fullExtent());
    centerOnWorldPosition(obj->ux, obj->uy, 1.0);

    objModel = db->getImageObjects(obj);

    refreshMapMarkers();

//    for (uint i=0; i<objMarkers.size(); i++)
//    {
//        delete objMarkers[i];
//    }
//    objMarkers.clear();

//    // TODO: Add markers if object change not only image change

//    for (int i=0; i<objModel->rowCount(); i++) {
//        int id = objModel->record(i).value(0).toInt();
//        double ux = objModel->record(i).value(2).toDouble();
//        double uy = objModel->record(i).value(3).toDouble();
//        int mcen = objModel->record(i).value(4).toInt();
//        int ccen = objModel->record(i).value(5).toInt();

//        MapCanvasMarker * marker = new MapCanvasMarker(this);
//        marker->setCenter(QgsPoint(ux,uy));
//        marker->setIconType(MapCanvasMarker::ICON_CIRCLE);
//        marker->setIconSize(5);
//        marker->setDrawWidth(1);
//        marker->setIconColor(Qt::black);
//        marker->setFill(true);
//        marker->setText(QString::number(id));
//        marker->setTextColor(Qt::red);
//        marker->setTextWidth(2);
//        marker->setTextOffset(15,15);

//        if (mcen == 2) {
//            marker->setFillColor(Qt::darkGreen);
//        } else if (mcen == 1) {
//            if (ccen > 1)
//                marker->setFillColor(Qt::darkRed);
//            else
//                marker->setFillColor(Qt::darkGray);
//        } else {
//            marker->setFillColor(Qt::gray);
//        }

//        objMarkers.push_back(marker);

//        marker = new QgsMapMarker(this);
//        marker->setCenter(QgsPoint(ux,uy));
//        marker->setIconType(QgsMapMarker::ICON_CIRCLE);
//        marker->setPenWidth(1);
//        marker->setIconSize(3);
//        marker->setColor(Qt::black);
//
//        objMarkers.push_back(marker);
//    }
    return true;
}

void ImgCanvas::refreshMapMarkers() {
    for (uint i=0; i<objMarkers.size(); i++)
    {
        delete objMarkers[i];
    }
    objMarkers.clear();

    if (!objModel->select())
        qDebug() << objModel->lastError().text();
    for (int i=0; i<objModel->rowCount(); i++) {
        int id = objModel->record(i).value(0).toInt();
        double ux = objModel->record(i).value(2).toDouble();
        double uy = objModel->record(i).value(3).toDouble();
        int mcen = objModel->record(i).value(4).toInt();
        int ccen = objModel->record(i).value(5).toInt();

        MapCanvasMarker * marker = new MapCanvasMarker(this);
        marker->setCenter(QgsPoint(ux,uy));
        marker->setIconType(MapCanvasMarker::ICON_CIRCLE);
        marker->setIconSize(5);
        marker->setDrawWidth(1);
        marker->setIconColor(Qt::black);
        marker->setFill(true);
        marker->setText(QString::number(id));
        marker->setTextColor(Qt::red);
        marker->setTextWidth(2);
        marker->setTextOffset(15,15);

        if (mcen == 2) {
            marker->setFillColor(Qt::darkGreen);
        } else if (mcen == 1) {
            if (ccen > 1)
                marker->setFillColor(Qt::darkRed);
            else
                marker->setFillColor(Qt::darkGray);
        } else {
            marker->setFillColor(Qt::gray);
        }

        objMarkers.push_back(marker);
    }
    handleHideObjectMarkers();
}

void ImgCanvas::centerOnPixelPosition(int x, int y, double scale) {
    double w = scale*this->width()/2;
    double h = scale*this->height()/2;
    QgsPoint min = calcWorldPosition(x-w, y+h);
    QgsPoint max = calcWorldPosition(x+w, y-h);
    QgsRectangle view(min, max);
    this->setExtent(view);
    this->refresh();
}

void ImgCanvas::centerOnWorldPosition(double ux, double uy, double scale) {
    if (!imgLayer->isValid()) return;
    double w = scale*this->width()/2*imgLayer->rasterUnitsPerPixelX();
    double h = scale*this->height()/2*imgLayer->rasterUnitsPerPixelY();
    QgsPoint min(ux-w, uy-h);
    QgsPoint max(ux+w, uy+h);
    QgsRectangle view(min, max);
    this->setExtent(view);
    this->refresh();
}

QgsPoint ImgCanvas::calcWorldPosition(int x, int y) {
    qDebug() << "Calculating world position for (" << x << y << ")";
    double wx,wy;
    wx = this->fullExtent().xMinimum() + double(x)*imgLayer->rasterUnitsPerPixelX();
    wy = this->fullExtent().yMaximum() - double(y)*imgLayer->rasterUnitsPerPixelY();
    return QgsPoint(wx,wy);
}

QgsPoint ImgCanvas::calcPixelPosition(const QgsPoint & pos ) {
        double utm_min_x = imgLayer->extent().xMinimum();
        double utm_min_y = imgLayer->extent().yMinimum();

        return QgsPoint (
                    floor(abs(pos.x() - utm_min_x)/imgLayer->rasterUnitsPerPixelX()),
                    floor(abs(pos.y() - utm_min_y)/imgLayer->rasterUnitsPerPixelY())
                    );
}

/*
 * Handle clicks on the map canvas with regards to the measurement tool
 */
void ImgCanvas::handleCanvasClicked(const QgsPoint & point) {
    msmList.push_back(point);
    MapCanvasMarker * vmarker = new MapCanvasMarker(this);
    vmarker->setIconType(MapCanvasMarker::ICON_CROSS);
    vmarker->setCenter(point);
    vmarker->setIconSize(9);
    vmarker->setPenWidth(2);
    msmMarkers.push_back( vmarker );

    if (msmList.size() > 1) {
        measurement_dialog->setInformativeText(
                    QString::fromUtf8("Momentane Länge: %1").arg(QgsGeometry::fromPolyline(msmList)->length()) );
    }
}

QgsRasterLayer * ImgCanvas::getImageLayer() { return imgLayer; }

void ImgCanvas::beginMeasurement(int type) {
    measurement_type = type;
    if (type == 0)
        measurement_dialog->setStandardButtons(QMessageBox::Cancel);
    else
        measurement_dialog->setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    measurement_dialog->setInformativeText(QString::fromUtf8("Bitte Messpunkte setzen."));
    measurement_dialog->show();

    msmList.clear();
    setMapTool(qgsEmitPointTool);
    connect(qgsEmitPointTool, SIGNAL( canvasClicked(const QgsPoint &, Qt::MouseButton) ),
            this, SLOT( handleCanvasClicked(const QgsPoint &)));
    connect(measurement_dialog, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(endMeasurement(QAbstractButton*)));
}

void ImgCanvas::endMeasurement(QAbstractButton * button = 0) {
    setMapTool(qgsMapPanTool);
    disconnect(qgsEmitPointTool, SIGNAL( canvasClicked(const QgsPoint &, Qt::MouseButton) ),
            this, SLOT( handleCanvasClicked(const QgsPoint &)));
    if (button != 0) {
        if (measurement_dialog->buttonRole(button) ==  QMessageBox::AcceptRole)
            emit measurementDone(measurement_type, QgsGeometry::fromPolyline(msmList)->length());
        else if (measurement_dialog->buttonRole(button) ==  QMessageBox::RejectRole)
            emit measurementDone(measurement_type, -1.0);
    }
    msmList.clear();
    for (uint i=0; i<msmMarkers.size(); i++)
        delete msmMarkers[i];
    msmMarkers.clear();
//    disconnect(measurement_dialog);
//    delete measurement_dialog;
    measurement_type = 0;
}

void ImgCanvas::setRasterBrightness(int value) {
    QgsRasterLayer * rlyr = static_cast<QgsRasterLayer*>(layerStack->getMapLayer("image"));
    if (rlyr == NULL) return;
    rlyr->brightnessFilter()->setBrightness(value);
    rlyr->triggerRepaint();
}

void ImgCanvas::setRasterContrast(int value) {
    QgsRasterLayer * rlyr = static_cast<QgsRasterLayer*>(layerStack->getMapLayer("image"));
    if (rlyr == NULL) return;
    rlyr->brightnessFilter()->setContrast(value);
    rlyr->triggerRepaint();
}

double ImgCanvas::getCurrentMeasurement() {
    return QgsGeometry::fromPolyline(msmList)->length();
}

void ImgCanvas::handleHideObjectMarkers() {
    if (ui->toolbutton_toggle_marks->isChecked()){
        for (uint i=0; i<objMarkers.size(); i++)
            objMarkers[i]->show();
    } else {
        for (uint i=0; i<objMarkers.size(); i++)
            objMarkers[i]->hide();
    }
    refresh();
}

void ImgCanvas::handleRightClick(const QgsPoint & point_utm, Qt::MouseButton button) {
    if (button != Qt::LeftButton)
            return;
    if (imgLayer == 0 || !imgLayer->isValid())
        return;

    QMenu type_context_menu(tr("Typauswahl"), this);
    QAction *vf_action = type_context_menu.addAction(trUtf8("Vogel fliegend"));
    vf_action->setData("VF");
    QAction *vs_action = type_context_menu.addAction(trUtf8("Vogel schwimmend"));
    vs_action->setData("VS");
    QAction *mm_action = type_context_menu.addAction(trUtf8("Meeressäuger"));
    mm_action->setData("MM");
    QAction *an_action = type_context_menu.addAction(trUtf8("Anthropogenes Objekt"));
    an_action->setData("AN");
    QAction *tr_action = type_context_menu.addAction(trUtf8("Müll"));
    tr_action->setData("TR");
    QAction *uo_action = type_context_menu.addAction(trUtf8("Unbekannt"));
    uo_action->setData("UO");
    QAction *action = type_context_menu.exec(QCursor::pos());

    if (action == 0)
        return;

    QgsPoint point_pixel = calcPixelPosition(point_utm);
    QgsPoint point_geo = utm2geo.transform(point_utm);
    db->insertScreeningObject(curSession, curCam, curImg, cfg->getSystemUser(), action->data().toString(),
                              point_utm.x(), point_utm.y(), point_geo.x(), point_geo.y(), point_pixel.x(), point_pixel.y(),
                              crs_utm.postgisSrid()-32600);
    qDebug() << crs_utm.postgisSrid();
    objModel->select();
    refreshMapMarkers();
}

void ImgCanvas::activatePanMode() {
    setMapTool(qgsMapPanTool);
}

void ImgCanvas::activateMarkMode() {
    setMapTool(qgsEmitPointTool);
}
