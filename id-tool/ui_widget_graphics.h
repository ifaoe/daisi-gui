/********************************************************************************
** Form generated from reading UI file 'widget_graphics.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_GRAPHICS_H
#define UI_WIDGET_GRAPHICS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_wdgGraphics
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *gbxBrightness;
    QGridLayout *gridLayout;
    QSlider *sldBrightness;
    QPushButton *btnBrightnessReset;
    QGroupBox *gbxContrast;
    QGridLayout *gridLayout_2;
    QSlider *sldContrast;
    QPushButton *btnContrastReset;
    QCheckBox *chbImgQuality;

    void setupUi(QFrame *wdgGraphics)
    {
        if (wdgGraphics->objectName().isEmpty())
            wdgGraphics->setObjectName(QString::fromUtf8("wdgGraphics"));
        wdgGraphics->resize(454, 160);
        wdgGraphics->setFrameShape(QFrame::NoFrame);
        wdgGraphics->setFrameShadow(QFrame::Sunken);
        gridLayout_3 = new QGridLayout(wdgGraphics);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gbxBrightness = new QGroupBox(wdgGraphics);
        gbxBrightness->setObjectName(QString::fromUtf8("gbxBrightness"));
        gridLayout = new QGridLayout(gbxBrightness);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        sldBrightness = new QSlider(gbxBrightness);
        sldBrightness->setObjectName(QString::fromUtf8("sldBrightness"));
        sldBrightness->setMinimum(-255);
        sldBrightness->setMaximum(255);
        sldBrightness->setValue(0);
        sldBrightness->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sldBrightness, 0, 1, 1, 1);

        btnBrightnessReset = new QPushButton(gbxBrightness);
        btnBrightnessReset->setObjectName(QString::fromUtf8("btnBrightnessReset"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnBrightnessReset->sizePolicy().hasHeightForWidth());
        btnBrightnessReset->setSizePolicy(sizePolicy);
        btnBrightnessReset->setMinimumSize(QSize(25, 25));
        btnBrightnessReset->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(btnBrightnessReset, 0, 2, 1, 1);


        gridLayout_3->addWidget(gbxBrightness, 0, 0, 1, 1);

        gbxContrast = new QGroupBox(wdgGraphics);
        gbxContrast->setObjectName(QString::fromUtf8("gbxContrast"));
        gridLayout_2 = new QGridLayout(gbxContrast);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, -1, -1, 0);
        sldContrast = new QSlider(gbxContrast);
        sldContrast->setObjectName(QString::fromUtf8("sldContrast"));
        sldContrast->setMinimum(-100);
        sldContrast->setMaximum(100);
        sldContrast->setValue(0);
        sldContrast->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(sldContrast, 0, 1, 1, 1);

        btnContrastReset = new QPushButton(gbxContrast);
        btnContrastReset->setObjectName(QString::fromUtf8("btnContrastReset"));
        btnContrastReset->setMinimumSize(QSize(25, 25));
        btnContrastReset->setMaximumSize(QSize(25, 25));
        btnContrastReset->setCheckable(false);
        btnContrastReset->setChecked(false);
        btnContrastReset->setFlat(false);

        gridLayout_2->addWidget(btnContrastReset, 0, 2, 1, 1);


        gridLayout_3->addWidget(gbxContrast, 1, 0, 1, 1);

        chbImgQuality = new QCheckBox(wdgGraphics);
        chbImgQuality->setObjectName(QString::fromUtf8("chbImgQuality"));

        gridLayout_3->addWidget(chbImgQuality, 2, 0, 1, 1);


        retranslateUi(wdgGraphics);

        QMetaObject::connectSlotsByName(wdgGraphics);
    } // setupUi

    void retranslateUi(QFrame *wdgGraphics)
    {
        wdgGraphics->setWindowTitle(QApplication::translate("wdgGraphics", "Frame", 0, QApplication::UnicodeUTF8));
        gbxBrightness->setTitle(QApplication::translate("wdgGraphics", "Helligkeit", 0, QApplication::UnicodeUTF8));
        btnBrightnessReset->setText(QApplication::translate("wdgGraphics", "X", 0, QApplication::UnicodeUTF8));
        gbxContrast->setTitle(QApplication::translate("wdgGraphics", "Kontrast", 0, QApplication::UnicodeUTF8));
        btnContrastReset->setText(QApplication::translate("wdgGraphics", "X", 0, QApplication::UnicodeUTF8));
        chbImgQuality->setText(QApplication::translate("wdgGraphics", "Hohe Qualit\303\244t (Beispielbild)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wdgGraphics: public Ui_wdgGraphics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_GRAPHICS_H
