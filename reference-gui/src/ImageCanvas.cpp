/*
 * ImageCanvas.cpp
 *
 *  Created on: Aug 7, 2015
 *      Author: awg
 */

#include "ImageCanvas.h"
#include <qgsmultibandcolorrenderer.h>
#include <qgsmaplayerregistry.h>
#include <QFileDialog>
#include <qgsmapcanvasmap.h>

ImageCanvas::ImageCanvas(DatabaseHandler * db, QWidget * parent) : QgsMapCanvas(parent),  parent(parent), db(db)  {
//	sizePolicy().setHeightForWidth(true);
	QSizePolicy policy;
	policy.setHorizontalPolicy(QSizePolicy::Expanding);
	policy.setVerticalPolicy(QSizePolicy::Preferred);
	policy.setHeightForWidth(true);
	setSizePolicy(policy);
	setBaseSize(240,240);
	enableAntiAliasing(true);
	setParallelRenderingEnabled( true );
	setCanvasColor(QColor(0, 0, 0));
	freeze(false);
	setCachingEnabled(true);
	setCacheMode(QgsMapCanvas::CacheBackground);
	setMapUnits(QGis::Meters);

	provider_registry = QgsProviderRegistry::instance();
	layer_registry = QgsMapLayerRegistry::instance();

}

ImageCanvas::~ImageCanvas() {
	// TODO Auto-generated destructor stub
}

bool ImageCanvas::LoadObject(const QString & session, const QString & cam, const QString & img, const double & ux,
		const double & uy) {
	if ((current_session == session) && (current_cam == cam) && (current_img == img)) {
		CenterOnWorldPosition(ux, uy, 1.0);
		return true;
	}

	UnloadObject();

	QFileInfo image_file(db->GetImageLocation(session, cam, img));
	if(!image_file.isFile() || !image_file.isReadable())
		return false;

	image_layer = new QgsRasterLayer(image_file.filePath(),image_file.fileName());
	connect(image_layer,SIGNAL(progressUpdate(int)),this,SLOT(ShowProgress(int)));
	image_layer->setLayerName("image");
    image_provider = image_layer->dataProvider();
    if (!image_layer->isValid())
    	return false;

    /*
     * No Data Values deaktivieren.
     * Verursachen Probleme in Bezug auf georeferenzierte JPEGs oder JPEG komprimierte TIFFs
     */
    for ( int bandNo = 1; bandNo <= image_provider->bandCount(); bandNo++ )
        image_provider->setUseSrcNoDataValue( bandNo, false );

    QgsContrastEnhancement* qgsContrastEnhRed = new QgsContrastEnhancement(image_provider->dataType(1));
//    qgsContrastEnhRed->setMinimumValue(0);
//    qgsContrastEnhRed->setMaximumValue(pow(2, 8*qgsImgProvider->dataTypeSize(config->getRedChannel())));
//    qgsContrastEnhRed->setContrastEnhancementAlgorithm(QgsContrastEnhancement::StretchToMinimumMaximum);

    QgsContrastEnhancement* qgsContrastEnhGreen = new QgsContrastEnhancement(image_provider->dataType(2));
//    qgsContrastEnhGreen->setMinimumValue(0);
//    qgsContrastEnhGreen->setMaximumValue(pow(2, 8*qgsImgProvider->dataTypeSize(config->getGreenChannel())));
//    qgsContrastEnhGreen->setContrastEnhancementAlgorithm(QgsContrastEnhancement::StretchToMinimumMaximum);

    QgsContrastEnhancement* qgsContrastEnhBlue = new QgsContrastEnhancement(image_provider->dataType(3));
//    qgsContrastEnhBlue->setMinimumValue(0);
//    qgsContrastEnhBlue->setMaximumValue(pow(2, 8*qgsImgProvider->dataTypeSize(config->getBlueChannel())));
//    qgsContrastEnhBlue->setContrastEnhancementAlgorithm(QgsContrastEnhancement::StretchToMinimumMaximum);

    QgsMultiBandColorRenderer* renderer = new QgsMultiBandColorRenderer( image_provider, 1, 2, 3,
                qgsContrastEnhRed, qgsContrastEnhGreen, qgsContrastEnhBlue);

    image_layer->setRenderer( renderer );

    layer_registry->addMapLayer(image_layer);

    QList<QgsMapCanvasLayer> layer_set;
    layer_set.append(image_layer);
	setLayerSet(layer_set);

	CenterOnWorldPosition(ux, uy, 1.0);

	current_session = session;
	current_cam = cam;
	current_img = img;

	return true;
}

void ImageCanvas::UnloadObject() {
	if (image_layer != 0) {
		layer_registry->removeMapLayer(image_layer->id());
		image_layer = 0;
		refresh();
	}
}

void ImageCanvas::CenterOnWorldPosition(const double & ux, const double & uy, const double & scale) {
    if (!image_layer->isValid()) return;
    double w = scale*this->width()/2*image_layer->rasterUnitsPerPixelX();
    double h = scale*this->height()/2*image_layer->rasterUnitsPerPixelY();
    QgsPoint min(ux-w, uy-h);
    QgsPoint max(ux+w, uy+h);
    QgsRectangle view(min, max);
    setExtent(view);
    refresh();
}

void ImageCanvas::SaveImage() {
	QDir default_path = QDir::home();
	QFileInfo save_file = QFileInfo(QFileDialog::getSaveFileName(this,tr("Aktuellen Ausschnitt speichern..."),
			default_path.absoluteFilePath("Ausschnitt.jpg"), 	tr("Images (*.png *.xpm *.jpg *.tiff *.tif *.jpeg)")));
	map()->contentImage().save(save_file.filePath(),save_file.suffix().toStdString().c_str());
}

//void ImageCanvas::resizeEvent(QResizeEvent * event) {
////	Q_UNUSED(event);
//	this->QgsMapCanvas::resizeEvent(event);
////	this->setBaseSize(parent->size());
////	this->setFixedSize(parent->width(),parent->width());
////	this->QWidget::resizeEvent(event);
//	refresh();
//}

int ImageCanvas::heightForWidth( int w) const {
	return w;
}
