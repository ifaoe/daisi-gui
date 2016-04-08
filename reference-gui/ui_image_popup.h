/********************************************************************************
** Form generated from reading UI file 'image_popup.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGE_POPUP_H
#define UI_IMAGE_POPUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget_image_popup
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_image;
    QFrame *toolbar;
    QGridLayout *gridLayout_2;
    QToolButton *button_zoom_out;
    QToolButton *button_zoom_in;
    QToolButton *button_zoom_original;
    QToolButton *button_zoom_fit_best;
    QToolButton *button_save;
    QSpacerItem *verticalSpacer;
    QToolButton *button_quit;

    void setupUi(QWidget *widget_image_popup)
    {
        if (widget_image_popup->objectName().isEmpty())
            widget_image_popup->setObjectName(QString::fromUtf8("widget_image_popup"));
        widget_image_popup->setWindowModality(Qt::WindowModal);
        widget_image_popup->resize(587, 410);
        gridLayout = new QGridLayout(widget_image_popup);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_image = new QWidget(widget_image_popup);
        widget_image->setObjectName(QString::fromUtf8("widget_image"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_image->sizePolicy().hasHeightForWidth());
        widget_image->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widget_image, 0, 0, 3, 1);

        toolbar = new QFrame(widget_image_popup);
        toolbar->setObjectName(QString::fromUtf8("toolbar"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolbar->sizePolicy().hasHeightForWidth());
        toolbar->setSizePolicy(sizePolicy1);
        toolbar->setFrameShape(QFrame::StyledPanel);
        toolbar->setFrameShadow(QFrame::Plain);
        gridLayout_2 = new QGridLayout(toolbar);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        button_zoom_out = new QToolButton(toolbar);
        button_zoom_out->setObjectName(QString::fromUtf8("button_zoom_out"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("zoom-out")));
        button_zoom_out->setIcon(icon);

        gridLayout_2->addWidget(button_zoom_out, 1, 1, 1, 1);

        button_zoom_in = new QToolButton(toolbar);
        button_zoom_in->setObjectName(QString::fromUtf8("button_zoom_in"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("zoom-in")));
        button_zoom_in->setIcon(icon1);

        gridLayout_2->addWidget(button_zoom_in, 0, 1, 1, 1);

        button_zoom_original = new QToolButton(toolbar);
        button_zoom_original->setObjectName(QString::fromUtf8("button_zoom_original"));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("zoom-original")));
        button_zoom_original->setIcon(icon2);

        gridLayout_2->addWidget(button_zoom_original, 3, 1, 1, 1);

        button_zoom_fit_best = new QToolButton(toolbar);
        button_zoom_fit_best->setObjectName(QString::fromUtf8("button_zoom_fit_best"));
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("zoom-fit-best")));
        button_zoom_fit_best->setIcon(icon3);

        gridLayout_2->addWidget(button_zoom_fit_best, 2, 1, 1, 1);

        button_save = new QToolButton(toolbar);
        button_save->setObjectName(QString::fromUtf8("button_save"));
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("document-save")));
        button_save->setIcon(icon4);

        gridLayout_2->addWidget(button_save, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 5, 1, 1, 1);

        button_quit = new QToolButton(toolbar);
        button_quit->setObjectName(QString::fromUtf8("button_quit"));
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("window-close")));
        button_quit->setIcon(icon5);

        gridLayout_2->addWidget(button_quit, 6, 1, 1, 1);


        gridLayout->addWidget(toolbar, 0, 1, 3, 1);


        retranslateUi(widget_image_popup);

        QMetaObject::connectSlotsByName(widget_image_popup);
    } // setupUi

    void retranslateUi(QWidget *widget_image_popup)
    {
        widget_image_popup->setWindowTitle(QApplication::translate("widget_image_popup", "Bildansicht", 0, QApplication::UnicodeUTF8));
        button_zoom_out->setText(QApplication::translate("widget_image_popup", "...", 0, QApplication::UnicodeUTF8));
        button_zoom_in->setText(QApplication::translate("widget_image_popup", "...", 0, QApplication::UnicodeUTF8));
        button_zoom_original->setText(QApplication::translate("widget_image_popup", "...", 0, QApplication::UnicodeUTF8));
        button_zoom_fit_best->setText(QApplication::translate("widget_image_popup", "...", 0, QApplication::UnicodeUTF8));
        button_save->setText(QApplication::translate("widget_image_popup", "...", 0, QApplication::UnicodeUTF8));
        button_quit->setText(QApplication::translate("widget_image_popup", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class widget_image_popup: public Ui_widget_image_popup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGE_POPUP_H
