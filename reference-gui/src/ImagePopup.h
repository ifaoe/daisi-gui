/*
 * ImagePopup.h
 *
 *  Created on: Aug 11, 2015
 *      Author: awg
 */

#ifndef SRC_IMAGEPOPUP_H_
#define SRC_IMAGEPOPUP_H_

#include <QDialog>
#include "ui_image_popup.h"
#include "ImageCanvas.h"
#include <qgsmaptoolpan.h>

class ImagePopup : public QWidget {
	Q_OBJECT
public:
	ImagePopup(QWidget * canvas, ImageCanvas * iamge_canvas, QWidget * parent = 0);
	virtual ~ImagePopup();
private:
	Ui::widget_image_popup * ui;
	QWidget * widget_canvas;
	ImageCanvas * image_canvas;
	QWidget * parent;
	QList<QToolButton*> buttons;
	QgsMapToolPan * map_pan_tool;
    QSize old_size;
private slots:
	void ZoomIn() { image_canvas->zoomIn(); }
	void ZoomOut() { image_canvas->zoomOut(); }
	void ZoomToFullExtent() { image_canvas->zoomToFullExtent(); }
	void ZoomOriginal() { image_canvas->zoomScale(1.0); }
	void closeEvent(QCloseEvent * event);
};

#endif /* SRC_IMAGEPOPUP_H_ */
