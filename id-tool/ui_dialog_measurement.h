/********************************************************************************
** Form generated from reading UI file 'dialog_measurement.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_MEASUREMENT_H
#define UI_DIALOG_MEASUREMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_dlgMeasurement
{
public:
    QGridLayout *gridLayout;
    QLabel *lblMeasurementInfo;
    QLabel *lblMeasurementStatus;
    QDialogButtonBox *btbMeasurement;

    void setupUi(QDialog *dlgMeasurement)
    {
        if (dlgMeasurement->objectName().isEmpty())
            dlgMeasurement->setObjectName(QString::fromUtf8("dlgMeasurement"));
        dlgMeasurement->resize(392, 108);
        gridLayout = new QGridLayout(dlgMeasurement);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblMeasurementInfo = new QLabel(dlgMeasurement);
        lblMeasurementInfo->setObjectName(QString::fromUtf8("lblMeasurementInfo"));

        gridLayout->addWidget(lblMeasurementInfo, 1, 0, 1, 1);

        lblMeasurementStatus = new QLabel(dlgMeasurement);
        lblMeasurementStatus->setObjectName(QString::fromUtf8("lblMeasurementStatus"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        lblMeasurementStatus->setFont(font);

        gridLayout->addWidget(lblMeasurementStatus, 0, 0, 1, 1);

        btbMeasurement = new QDialogButtonBox(dlgMeasurement);
        btbMeasurement->setObjectName(QString::fromUtf8("btbMeasurement"));
        btbMeasurement->setOrientation(Qt::Horizontal);
        btbMeasurement->setStandardButtons(QDialogButtonBox::Abort|QDialogButtonBox::Save);

        gridLayout->addWidget(btbMeasurement, 2, 0, 1, 1);


        retranslateUi(dlgMeasurement);
        QObject::connect(btbMeasurement, SIGNAL(accepted()), dlgMeasurement, SLOT(accept()));
        QObject::connect(btbMeasurement, SIGNAL(rejected()), dlgMeasurement, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgMeasurement);
    } // setupUi

    void retranslateUi(QDialog *dlgMeasurement)
    {
        dlgMeasurement->setWindowTitle(QApplication::translate("dlgMeasurement", "L\303\244ngenmessung", 0, QApplication::UnicodeUTF8));
        lblMeasurementInfo->setText(QString());
        lblMeasurementStatus->setText(QApplication::translate("dlgMeasurement", "Messung l\303\244uft", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgMeasurement: public Ui_dlgMeasurement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_MEASUREMENT_H
