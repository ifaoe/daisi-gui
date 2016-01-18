/*
 * MeasurementDialog.h
 *
 *  Created on: Jun 9, 2015
 *      Author: awg
 */

#ifndef MEASUREMENTDIALOG_H_
#define MEASUREMENTDIALOG_H_
#include "ui_dialog_measurement.h"
#include "census.hpp"
#include <QCloseEvent>

class ImgCanvas;


class MeasurementDialog : public QDialog {
    Q_OBJECT;
public:
    MeasurementDialog();
    virtual ~MeasurementDialog();
    void updateStatusMessage(QString text);
    void updateInfoMessage(QString text);
    void startMeasurement(bool no_save);
private:
    void closeEvent(QCloseEvent *e);
    double * value = 0;
    bool running = false;
    Ui::dlgMeasurement * dlg = 0;
private slots:
    void handleAccept();
    void handleReject();
signals:
    void acceptMeasurement();
};

#endif /* MEASUREMENTDIALOG_H_ */
