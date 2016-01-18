/*
 * MeasurementDialog.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: awg
 */

#include "MeasurementDialog.h"
#include <QPushButton>

MeasurementDialog::MeasurementDialog()
: dlg(new Ui::dlgMeasurement) {
    dlg->setupUi(this);
    connect(dlg->btbMeasurement,SIGNAL(accepted()), this, SLOT(handleAccept()));
    connect(dlg->btbMeasurement,SIGNAL(rejected()), this, SLOT(handleReject()));
    setWindowFlags(windowFlags()|Qt::WindowStaysOnTopHint);
    setWindowModality(Qt::NonModal);
    setModal(false);
}

MeasurementDialog::~MeasurementDialog() {
    // TODO Auto-generated destructor stub
}

void MeasurementDialog::updateStatusMessage(QString text) {
    dlg->lblMeasurementStatus->setText(text);
}

void MeasurementDialog::updateInfoMessage(QString text) {
    dlg->lblMeasurementInfo->setText(text);
}

void MeasurementDialog::handleAccept() {
    running=false;
    close();
}

void MeasurementDialog::handleReject() {
    running=false;
    close();
}

void MeasurementDialog::startMeasurement(bool no_save = true) {
    if (running) return;
    running = true;
    updateStatusMessage(QString::fromUtf8("Messung läuft."));
    updateInfoMessage(QString::fromUtf8("Bitte Messpunkte setzen."));

    if (no_save)
        dlg->btbMeasurement->button(QDialogButtonBox::Save)->hide();
    else
        dlg->btbMeasurement->button(QDialogButtonBox::Save)->show();
    show();
}

void MeasurementDialog::closeEvent(QCloseEvent * e) {
    e->ignore();
}
