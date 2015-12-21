/*
 * ImagePopup.cpp
 *
 *  Created on: Aug 11, 2015
 *      Author: awg
 */

#include "ImagePopup.h"

ImagePopup::ImagePopup(QWidget * canvas, ImageCanvas * image_canvas, QWidget * parent) : QWidget(parent),
	ui(new Ui::widget_image_popup), widget_canvas(canvas), image_canvas(image_canvas), parent(parent) {
	ui->setupUi(this);
	ui->widget_image->setLayout(canvas->layout());
    old_size = ui->widget_image->size();
    image_canvas->setMaximumSize(16777215,16777215);
    image_canvas->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	connect(ui->button_quit, SIGNAL(clicked()),this, SLOT(close()));
	connect(ui->button_zoom_in, SIGNAL(clicked()), this, SLOT(ZoomIn()));
	connect(ui->button_zoom_out, SIGNAL(clicked()), this, SLOT(ZoomOut()));
	connect(ui->button_zoom_fit_best, SIGNAL(clicked()), this, SLOT(ZoomToFullExtent()));
	connect(ui->button_zoom_original, SIGNAL(clicked()), this, SLOT(ZoomOriginal()));
	connect(ui->button_save,SIGNAL(clicked()),image_canvas,SLOT(SaveImage()));

	map_pan_tool = new QgsMapToolPan(image_canvas);
	image_canvas->setMapTool(map_pan_tool);
}

ImagePopup::~ImagePopup() {
	image_canvas->unsetMapTool(map_pan_tool);
	delete map_pan_tool;
    image_canvas->setMaximumSize(old_size);
    image_canvas->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}

void ImagePopup::closeEvent(QCloseEvent * event) {
	Q_UNUSED(event);
	widget_canvas->setLayout(ui->widget_image->layout());
}
