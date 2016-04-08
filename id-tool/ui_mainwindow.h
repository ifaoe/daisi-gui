/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "../libs/QCollapsibleToolbox.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *wdgImg;
    QFrame *frame_toolbar;
    QGridLayout *gridLayout_2;
    QToolButton *toolbutton_toggle_marks;
    QToolButton *toolbutton_zoom_original;
    QToolButton *toolbutton_zoom_out;
    QToolButton *toolbutton_zoom_in;
    QToolButton *toolbutton_zoom_full;
    QToolButton *toolbutton_take_measurement;
    QToolButton *toolbutton_map_view;
    QSpacerItem *verticalSpacer;
    QCollapsibleToolbox *toolbox_widget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(922, 640);
        MainWindow->setMinimumSize(QSize(0, 640));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        wdgImg = new QWidget(centralWidget);
        wdgImg->setObjectName(QString::fromUtf8("wdgImg"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wdgImg->sizePolicy().hasHeightForWidth());
        wdgImg->setSizePolicy(sizePolicy);
        wdgImg->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(wdgImg, 0, 1, 1, 1);

        frame_toolbar = new QFrame(centralWidget);
        frame_toolbar->setObjectName(QString::fromUtf8("frame_toolbar"));
        gridLayout_2 = new QGridLayout(frame_toolbar);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        toolbutton_toggle_marks = new QToolButton(frame_toolbar);
        toolbutton_toggle_marks->setObjectName(QString::fromUtf8("toolbutton_toggle_marks"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("flag-green");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        toolbutton_toggle_marks->setIcon(icon);
        toolbutton_toggle_marks->setIconSize(QSize(32, 32));
        toolbutton_toggle_marks->setCheckable(true);
        toolbutton_toggle_marks->setChecked(false);

        gridLayout_2->addWidget(toolbutton_toggle_marks, 5, 0, 1, 1);

        toolbutton_zoom_original = new QToolButton(frame_toolbar);
        toolbutton_zoom_original->setObjectName(QString::fromUtf8("toolbutton_zoom_original"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("zoom-original");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        toolbutton_zoom_original->setIcon(icon1);
        toolbutton_zoom_original->setIconSize(QSize(32, 32));
        toolbutton_zoom_original->setCheckable(false);
        toolbutton_zoom_original->setChecked(false);

        gridLayout_2->addWidget(toolbutton_zoom_original, 0, 0, 1, 1);

        toolbutton_zoom_out = new QToolButton(frame_toolbar);
        toolbutton_zoom_out->setObjectName(QString::fromUtf8("toolbutton_zoom_out"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("zoom-out");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        toolbutton_zoom_out->setIcon(icon2);
        toolbutton_zoom_out->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(toolbutton_zoom_out, 3, 0, 1, 1);

        toolbutton_zoom_in = new QToolButton(frame_toolbar);
        toolbutton_zoom_in->setObjectName(QString::fromUtf8("toolbutton_zoom_in"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("zoom-in");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        toolbutton_zoom_in->setIcon(icon3);
        toolbutton_zoom_in->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(toolbutton_zoom_in, 2, 0, 1, 1);

        toolbutton_zoom_full = new QToolButton(frame_toolbar);
        toolbutton_zoom_full->setObjectName(QString::fromUtf8("toolbutton_zoom_full"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("zoom-fit-best");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        toolbutton_zoom_full->setIcon(icon4);
        toolbutton_zoom_full->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(toolbutton_zoom_full, 1, 0, 1, 1);

        toolbutton_take_measurement = new QToolButton(frame_toolbar);
        toolbutton_take_measurement->setObjectName(QString::fromUtf8("toolbutton_take_measurement"));
        QIcon icon5;
        iconThemeName = QString::fromUtf8("measure");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        toolbutton_take_measurement->setIcon(icon5);
        toolbutton_take_measurement->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(toolbutton_take_measurement, 6, 0, 1, 1);

        toolbutton_map_view = new QToolButton(frame_toolbar);
        toolbutton_map_view->setObjectName(QString::fromUtf8("toolbutton_map_view"));
        QIcon icon6;
        iconThemeName = QString::fromUtf8("internet-web-browser");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        toolbutton_map_view->setIcon(icon6);
        toolbutton_map_view->setIconSize(QSize(32, 32));
        toolbutton_map_view->setCheckable(true);

        gridLayout_2->addWidget(toolbutton_map_view, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 0, 1, 1);


        gridLayout->addWidget(frame_toolbar, 0, 2, 1, 1);

        toolbox_widget = new QCollapsibleToolbox(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        toolbox_widget->setHeaderItem(__qtreewidgetitem);
        toolbox_widget->setObjectName(QString::fromUtf8("toolbox_widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolbox_widget->sizePolicy().hasHeightForWidth());
        toolbox_widget->setSizePolicy(sizePolicy1);
        toolbox_widget->setMinimumSize(QSize(500, 0));
        toolbox_widget->setMaximumSize(QSize(500, 16777215));
        toolbox_widget->setAutoFillBackground(false);
        toolbox_widget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        toolbox_widget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        toolbox_widget->setRootIsDecorated(false);
        toolbox_widget->header()->setVisible(false);

        gridLayout->addWidget(toolbox_widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolbutton_toggle_marks->setToolTip(QApplication::translate("MainWindow", "Markierungen ein-/ausblenden", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolbutton_toggle_marks->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolbutton_zoom_original->setToolTip(QApplication::translate("MainWindow", "1:1 Zoom", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolbutton_zoom_original->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolbutton_zoom_out->setToolTip(QApplication::translate("MainWindow", "Rauszoomen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolbutton_zoom_out->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolbutton_zoom_in->setToolTip(QApplication::translate("MainWindow", "Reinzoomen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolbutton_zoom_in->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolbutton_zoom_full->setToolTip(QApplication::translate("MainWindow", "Zoom volles Bild", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolbutton_zoom_full->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolbutton_take_measurement->setToolTip(QApplication::translate("MainWindow", "Messung durchf\303\274hren", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolbutton_take_measurement->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolbutton_map_view->setToolTip(QApplication::translate("MainWindow", "Kartenansicht", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolbutton_map_view->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
