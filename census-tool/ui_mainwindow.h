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
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *wdtMain;
    QHBoxLayout *horizontalLayout_4;
    QWidget *wdgTopMain;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tbxTasks;
    QWidget *tbxTasksPage1;
    QVBoxLayout *verticalLayout_7;
    QWidget *wdgImageTable;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QComboBox *cmbSession;
    QCheckBox *chbNotReady;
    QTableView *image_table;
    QWidget *tbxTasksPage2;
    QVBoxLayout *verticalLayout_8;
    QFrame *wgdMapInfo;
    QVBoxLayout *verticalLayout_4;
    QWidget *wdgMapTabButtons;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *btnPrevTile;
    QToolButton *btnNextTile;
    QToolButton *btnMapZoomExtent;
    QToolButton *btnMapZoom1by1;
    QToolButton *btnMapPan;
    QToolButton *btnMapDigitize;
    QToolButton *btnMapSelect;
    QToolButton *btnMapRmObj;
    QWidget *wdgOverview;
    QLabel *lblPixel;
    QLabel *lblUTM;
    QLabel *lblScale;
    QLabel *lblMode;
    QFrame *gbxLyrSelect;
    QGridLayout *gridLayout;
    QRadioButton *rbVS;
    QRadioButton *rbVF;
    QCheckBox *chbHideMarker;
    QRadioButton *rbMM;
    QRadioButton *rbUFO;
    QRadioButton *rbTR;
    QRadioButton *rbAN;
    QTableView *tbwObjects;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QToolButton *option_server;
    QSpacerItem *verticalSpacer;
    QToolButton *option_admin;
    QFrame *frmMap;
    QVBoxLayout *verticalLayout;
    QWidget *wdgMap;
    QStatusBar *statusBar;
    QButtonGroup *button_group_types;
    QButtonGroup *btgMapMode;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1248, 805);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setBaseSize(QSize(800, 600));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        wdtMain = new QWidget(centralWidget);
        wdtMain->setObjectName(QString::fromUtf8("wdtMain"));
        horizontalLayout_4 = new QHBoxLayout(wdtMain);
        horizontalLayout_4->setSpacing(1);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(1, 1, 1, 1);
        wdgTopMain = new QWidget(wdtMain);
        wdgTopMain->setObjectName(QString::fromUtf8("wdgTopMain"));
        wdgTopMain->setMinimumSize(QSize(250, 100));
        wdgTopMain->setMaximumSize(QSize(250, 16777215));
        verticalLayout_3 = new QVBoxLayout(wdgTopMain);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tbxTasks = new QTabWidget(wdgTopMain);
        tbxTasks->setObjectName(QString::fromUtf8("tbxTasks"));
        tbxTasks->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tbxTasks->sizePolicy().hasHeightForWidth());
        tbxTasks->setSizePolicy(sizePolicy1);
        tbxTasks->setMinimumSize(QSize(250, 300));
        tbxTasks->setMaximumSize(QSize(250, 100000));
        tbxTasks->setLayoutDirection(Qt::LeftToRight);
        tbxTasks->setAutoFillBackground(false);
        tbxTasks->setStyleSheet(QString::fromUtf8("/*QToolBox::tab {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border-radius: 3px;\n"
"    color: darkgray;\n"
"}\n"
"\n"
"QToolBox::tab:selected { \n"
"    font: italic;\n"
"    color: black;\n"
"}*/"));
        tbxTasksPage1 = new QWidget();
        tbxTasksPage1->setObjectName(QString::fromUtf8("tbxTasksPage1"));
        verticalLayout_7 = new QVBoxLayout(tbxTasksPage1);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        wdgImageTable = new QWidget(tbxTasksPage1);
        wdgImageTable->setObjectName(QString::fromUtf8("wdgImageTable"));
        verticalLayout_5 = new QVBoxLayout(wdgImageTable);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(wdgImageTable);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        cmbSession = new QComboBox(frame);
        cmbSession->setObjectName(QString::fromUtf8("cmbSession"));

        gridLayout_2->addWidget(cmbSession, 0, 0, 1, 1);


        verticalLayout_5->addWidget(frame);

        chbNotReady = new QCheckBox(wdgImageTable);
        chbNotReady->setObjectName(QString::fromUtf8("chbNotReady"));

        verticalLayout_5->addWidget(chbNotReady);

        image_table = new QTableView(wdgImageTable);
        image_table->setObjectName(QString::fromUtf8("image_table"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(11);
        image_table->setFont(font);
        image_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        image_table->setAlternatingRowColors(true);
        image_table->setSelectionMode(QAbstractItemView::SingleSelection);
        image_table->setSelectionBehavior(QAbstractItemView::SelectRows);
        image_table->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        image_table->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        image_table->setGridStyle(Qt::SolidLine);
        image_table->horizontalHeader()->setStretchLastSection(true);
        image_table->verticalHeader()->setVisible(false);

        verticalLayout_5->addWidget(image_table);


        verticalLayout_7->addWidget(wdgImageTable);

        tbxTasks->addTab(tbxTasksPage1, QString());
        tbxTasksPage2 = new QWidget();
        tbxTasksPage2->setObjectName(QString::fromUtf8("tbxTasksPage2"));
        verticalLayout_8 = new QVBoxLayout(tbxTasksPage2);
        verticalLayout_8->setSpacing(2);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(2, 2, 2, 2);
        wgdMapInfo = new QFrame(tbxTasksPage2);
        wgdMapInfo->setObjectName(QString::fromUtf8("wgdMapInfo"));
        wgdMapInfo->setMaximumSize(QSize(249, 360));
        verticalLayout_4 = new QVBoxLayout(wgdMapInfo);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        wdgMapTabButtons = new QWidget(wgdMapInfo);
        wdgMapTabButtons->setObjectName(QString::fromUtf8("wdgMapTabButtons"));
        horizontalLayout_2 = new QHBoxLayout(wdgMapTabButtons);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnPrevTile = new QToolButton(wdgMapTabButtons);
        btnPrevTile->setObjectName(QString::fromUtf8("btnPrevTile"));
        btnPrevTile->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnPrevTile->sizePolicy().hasHeightForWidth());
        btnPrevTile->setSizePolicy(sizePolicy2);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("arrow-left")));
        btnPrevTile->setIcon(icon);

        horizontalLayout_2->addWidget(btnPrevTile);

        btnNextTile = new QToolButton(wdgMapTabButtons);
        btnNextTile->setObjectName(QString::fromUtf8("btnNextTile"));
        btnNextTile->setEnabled(true);
        sizePolicy2.setHeightForWidth(btnNextTile->sizePolicy().hasHeightForWidth());
        btnNextTile->setSizePolicy(sizePolicy2);
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("arrow-right")));
        btnNextTile->setIcon(icon1);

        horizontalLayout_2->addWidget(btnNextTile);

        btnMapZoomExtent = new QToolButton(wdgMapTabButtons);
        btnMapZoomExtent->setObjectName(QString::fromUtf8("btnMapZoomExtent"));
        sizePolicy2.setHeightForWidth(btnMapZoomExtent->sizePolicy().hasHeightForWidth());
        btnMapZoomExtent->setSizePolicy(sizePolicy2);
        btnMapZoomExtent->setMinimumSize(QSize(0, 0));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("zoom-fit-best")));
        btnMapZoomExtent->setIcon(icon2);

        horizontalLayout_2->addWidget(btnMapZoomExtent);

        btnMapZoom1by1 = new QToolButton(wdgMapTabButtons);
        btnMapZoom1by1->setObjectName(QString::fromUtf8("btnMapZoom1by1"));
        sizePolicy2.setHeightForWidth(btnMapZoom1by1->sizePolicy().hasHeightForWidth());
        btnMapZoom1by1->setSizePolicy(sizePolicy2);
        btnMapZoom1by1->setMinimumSize(QSize(0, 0));
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("zoom-original")));
        btnMapZoom1by1->setIcon(icon3);

        horizontalLayout_2->addWidget(btnMapZoom1by1);

        btnMapPan = new QToolButton(wdgMapTabButtons);
        btgMapMode = new QButtonGroup(MainWindow);
        btgMapMode->setObjectName(QString::fromUtf8("btgMapMode"));
        btgMapMode->addButton(btnMapPan);
        btnMapPan->setObjectName(QString::fromUtf8("btnMapPan"));
        sizePolicy2.setHeightForWidth(btnMapPan->sizePolicy().hasHeightForWidth());
        btnMapPan->setSizePolicy(sizePolicy2);
        btnMapPan->setMinimumSize(QSize(0, 0));
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("transform-move")));
        btnMapPan->setIcon(icon4);
        btnMapPan->setCheckable(true);

        horizontalLayout_2->addWidget(btnMapPan);

        btnMapDigitize = new QToolButton(wdgMapTabButtons);
        btgMapMode->addButton(btnMapDigitize);
        btnMapDigitize->setObjectName(QString::fromUtf8("btnMapDigitize"));
        sizePolicy2.setHeightForWidth(btnMapDigitize->sizePolicy().hasHeightForWidth());
        btnMapDigitize->setSizePolicy(sizePolicy2);
        btnMapDigitize->setMinimumSize(QSize(0, 0));
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("format-add-node")));
        btnMapDigitize->setIcon(icon5);
        btnMapDigitize->setCheckable(true);

        horizontalLayout_2->addWidget(btnMapDigitize);

        btnMapSelect = new QToolButton(wdgMapTabButtons);
        btgMapMode->addButton(btnMapSelect);
        btnMapSelect->setObjectName(QString::fromUtf8("btnMapSelect"));
        sizePolicy2.setHeightForWidth(btnMapSelect->sizePolicy().hasHeightForWidth());
        btnMapSelect->setSizePolicy(sizePolicy2);
        btnMapSelect->setMinimumSize(QSize(0, 0));
        QIcon icon6(QIcon::fromTheme(QString::fromUtf8("edit-node")));
        btnMapSelect->setIcon(icon6);
        btnMapSelect->setCheckable(true);

        horizontalLayout_2->addWidget(btnMapSelect);

        btnMapRmObj = new QToolButton(wdgMapTabButtons);
        btnMapRmObj->setObjectName(QString::fromUtf8("btnMapRmObj"));
        btnMapRmObj->setEnabled(false);
        sizePolicy2.setHeightForWidth(btnMapRmObj->sizePolicy().hasHeightForWidth());
        btnMapRmObj->setSizePolicy(sizePolicy2);
        btnMapRmObj->setMinimumSize(QSize(0, 0));
        QIcon icon7(QIcon::fromTheme(QString::fromUtf8("format-remove-node")));
        btnMapRmObj->setIcon(icon7);

        horizontalLayout_2->addWidget(btnMapRmObj);


        verticalLayout_4->addWidget(wdgMapTabButtons);

        wdgOverview = new QWidget(wgdMapInfo);
        wdgOverview->setObjectName(QString::fromUtf8("wdgOverview"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(wdgOverview->sizePolicy().hasHeightForWidth());
        wdgOverview->setSizePolicy(sizePolicy3);
        wdgOverview->setMinimumSize(QSize(240, 240));
        wdgOverview->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_4->addWidget(wdgOverview);

        lblPixel = new QLabel(wgdMapInfo);
        lblPixel->setObjectName(QString::fromUtf8("lblPixel"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lblPixel->sizePolicy().hasHeightForWidth());
        lblPixel->setSizePolicy(sizePolicy4);
        lblPixel->setMinimumSize(QSize(180, 0));
        lblPixel->setMaximumSize(QSize(240, 16777215));
        QFont font1;
        font1.setPointSize(8);
        lblPixel->setFont(font1);
        lblPixel->setTextFormat(Qt::PlainText);

        verticalLayout_4->addWidget(lblPixel);

        lblUTM = new QLabel(wgdMapInfo);
        lblUTM->setObjectName(QString::fromUtf8("lblUTM"));
        sizePolicy4.setHeightForWidth(lblUTM->sizePolicy().hasHeightForWidth());
        lblUTM->setSizePolicy(sizePolicy4);
        lblUTM->setFont(font1);

        verticalLayout_4->addWidget(lblUTM);

        lblScale = new QLabel(wgdMapInfo);
        lblScale->setObjectName(QString::fromUtf8("lblScale"));
        lblScale->setMaximumSize(QSize(245, 16777215));
        lblScale->setFont(font1);
        lblScale->setTextFormat(Qt::RichText);

        verticalLayout_4->addWidget(lblScale);

        lblMode = new QLabel(wgdMapInfo);
        lblMode->setObjectName(QString::fromUtf8("lblMode"));
        lblMode->setMaximumSize(QSize(240, 16777215));
        lblMode->setFont(font1);

        verticalLayout_4->addWidget(lblMode);


        verticalLayout_8->addWidget(wgdMapInfo);

        gbxLyrSelect = new QFrame(tbxTasksPage2);
        gbxLyrSelect->setObjectName(QString::fromUtf8("gbxLyrSelect"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(gbxLyrSelect->sizePolicy().hasHeightForWidth());
        gbxLyrSelect->setSizePolicy(sizePolicy5);
        gbxLyrSelect->setMaximumSize(QSize(245, 16777215));
        gridLayout = new QGridLayout(gbxLyrSelect);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        rbVS = new QRadioButton(gbxLyrSelect);
        button_group_types = new QButtonGroup(MainWindow);
        button_group_types->setObjectName(QString::fromUtf8("button_group_types"));
        button_group_types->addButton(rbVS);
        rbVS->setObjectName(QString::fromUtf8("rbVS"));
        rbVS->setChecked(true);

        gridLayout->addWidget(rbVS, 3, 0, 1, 1);

        rbVF = new QRadioButton(gbxLyrSelect);
        button_group_types->addButton(rbVF);
        rbVF->setObjectName(QString::fromUtf8("rbVF"));

        gridLayout->addWidget(rbVF, 4, 0, 1, 1);

        chbHideMarker = new QCheckBox(gbxLyrSelect);
        chbHideMarker->setObjectName(QString::fromUtf8("chbHideMarker"));

        gridLayout->addWidget(chbHideMarker, 1, 0, 1, 2);

        rbMM = new QRadioButton(gbxLyrSelect);
        button_group_types->addButton(rbMM);
        rbMM->setObjectName(QString::fromUtf8("rbMM"));

        gridLayout->addWidget(rbMM, 5, 0, 1, 1);

        rbUFO = new QRadioButton(gbxLyrSelect);
        button_group_types->addButton(rbUFO);
        rbUFO->setObjectName(QString::fromUtf8("rbUFO"));

        gridLayout->addWidget(rbUFO, 4, 1, 1, 1);

        rbTR = new QRadioButton(gbxLyrSelect);
        button_group_types->addButton(rbTR);
        rbTR->setObjectName(QString::fromUtf8("rbTR"));

        gridLayout->addWidget(rbTR, 5, 1, 1, 1);

        rbAN = new QRadioButton(gbxLyrSelect);
        button_group_types->addButton(rbAN);
        rbAN->setObjectName(QString::fromUtf8("rbAN"));

        gridLayout->addWidget(rbAN, 3, 1, 1, 1);


        verticalLayout_8->addWidget(gbxLyrSelect);

        tbwObjects = new QTableView(tbxTasksPage2);
        tbwObjects->setObjectName(QString::fromUtf8("tbwObjects"));
        tbwObjects->setStyleSheet(QString::fromUtf8(""));
        tbwObjects->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbwObjects->setAlternatingRowColors(true);
        tbwObjects->setSelectionMode(QAbstractItemView::SingleSelection);
        tbwObjects->setSelectionBehavior(QAbstractItemView::SelectRows);
        tbwObjects->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tbwObjects->horizontalHeader()->setStretchLastSection(true);
        tbwObjects->verticalHeader()->setVisible(false);

        verticalLayout_8->addWidget(tbwObjects);

        tbxTasks->addTab(tbxTasksPage2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        option_server = new QToolButton(tab);
        option_server->setObjectName(QString::fromUtf8("option_server"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(option_server->sizePolicy().hasHeightForWidth());
        option_server->setSizePolicy(sizePolicy6);
        QIcon icon8;
        QString iconThemeName = QString::fromUtf8("server-database");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        option_server->setIcon(icon8);
        option_server->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_3->addWidget(option_server, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 0, 1, 1);

        option_admin = new QToolButton(tab);
        option_admin->setObjectName(QString::fromUtf8("option_admin"));
        sizePolicy6.setHeightForWidth(option_admin->sizePolicy().hasHeightForWidth());
        option_admin->setSizePolicy(sizePolicy6);
        QIcon icon9;
        iconThemeName = QString::fromUtf8("object-locked");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        option_admin->setIcon(icon9);
        option_admin->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_3->addWidget(option_admin, 1, 0, 1, 1);

        tbxTasks->addTab(tab, QString());

        verticalLayout_3->addWidget(tbxTasks);


        horizontalLayout_4->addWidget(wdgTopMain);

        frmMap = new QFrame(wdtMain);
        frmMap->setObjectName(QString::fromUtf8("frmMap"));
        sizePolicy2.setHeightForWidth(frmMap->sizePolicy().hasHeightForWidth());
        frmMap->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Courier 10 Pitch"));
        font2.setPointSize(10);
        frmMap->setFont(font2);
        frmMap->setFrameShape(QFrame::Panel);
        frmMap->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(frmMap);
        verticalLayout->setSpacing(1);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        wdgMap = new QWidget(frmMap);
        wdgMap->setObjectName(QString::fromUtf8("wdgMap"));
        sizePolicy1.setHeightForWidth(wdgMap->sizePolicy().hasHeightForWidth());
        wdgMap->setSizePolicy(sizePolicy1);
        wdgMap->setMinimumSize(QSize(400, 400));
        wdgMap->setLayoutDirection(Qt::LeftToRight);
        wdgMap->setAutoFillBackground(false);

        verticalLayout->addWidget(wdgMap);


        horizontalLayout_4->addWidget(frmMap);


        horizontalLayout->addWidget(wdtMain);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tbxTasks->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        chbNotReady->setText(QApplication::translate("MainWindow", "unmarkierte Bilder anzeigen", 0, QApplication::UnicodeUTF8));
        tbxTasks->setTabText(tbxTasks->indexOf(tbxTasksPage1), QApplication::translate("MainWindow", "Bilddateien", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnPrevTile->setToolTip(QApplication::translate("MainWindow", "vorherige Kachel", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnPrevTile->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnNextTile->setToolTip(QApplication::translate("MainWindow", "n\303\244chste Kachel", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnNextTile->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMapZoomExtent->setToolTip(QApplication::translate("MainWindow", "Gesamtdarstellung", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnMapZoomExtent->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMapZoom1by1->setToolTip(QApplication::translate("MainWindow", "Zoom 1:1", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnMapZoom1by1->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnMapPan->setToolTip(QApplication::translate("MainWindow", "In der Karte bewegen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnMapPan->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMapDigitize->setToolTip(QApplication::translate("MainWindow", "Objekte digitalisieren", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnMapDigitize->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMapSelect->setToolTip(QApplication::translate("MainWindow", "Objekt ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnMapSelect->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMapRmObj->setToolTip(QApplication::translate("MainWindow", "Objekt l\303\266schen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnMapRmObj->setText(QString());
        lblPixel->setText(QApplication::translate("MainWindow", "Position:  ------ ------ ", 0, QApplication::UnicodeUTF8));
        lblUTM->setText(QApplication::translate("MainWindow", "UTM ----------.-- ---------.-- m", 0, QApplication::UnicodeUTF8));
        lblScale->setText(QApplication::translate("MainWindow", "Skale ----- -----", 0, QApplication::UnicodeUTF8));
        lblMode->setText(QApplication::translate("MainWindow", "Mode", 0, QApplication::UnicodeUTF8));
        rbVS->setText(QApplication::translate("MainWindow", "Vo&gel sw.", 0, QApplication::UnicodeUTF8));
        rbVS->setProperty("dbvalue", QVariant(QApplication::translate("MainWindow", "VS", 0, QApplication::UnicodeUTF8)));
        rbVF->setText(QApplication::translate("MainWindow", "&Vogel fl.", 0, QApplication::UnicodeUTF8));
        rbVF->setProperty("dbvalue", QVariant(QApplication::translate("MainWindow", "VF", 0, QApplication::UnicodeUTF8)));
        chbHideMarker->setText(QApplication::translate("MainWindow", "Markierung ausblenden", 0, QApplication::UnicodeUTF8));
        rbMM->setText(QApplication::translate("MainWindow", "Meeress&\303\244uger", 0, QApplication::UnicodeUTF8));
        rbMM->setProperty("dbvalue", QVariant(QApplication::translate("MainWindow", "MM", 0, QApplication::UnicodeUTF8)));
        rbUFO->setText(QApplication::translate("MainWindow", "&unbekannt", 0, QApplication::UnicodeUTF8));
        rbUFO->setProperty("dbvalue", QVariant(QApplication::translate("MainWindow", "UO", 0, QApplication::UnicodeUTF8)));
        rbTR->setText(QApplication::translate("MainWindow", "M&\303\274ll", 0, QApplication::UnicodeUTF8));
        rbTR->setProperty("dbvalue", QVariant(QApplication::translate("MainWindow", "TR", 0, QApplication::UnicodeUTF8)));
        rbAN->setText(QApplication::translate("MainWindow", "an&thropogen", 0, QApplication::UnicodeUTF8));
        rbAN->setProperty("dbvalue", QVariant(QApplication::translate("MainWindow", "AN", 0, QApplication::UnicodeUTF8)));
        tbxTasks->setTabText(tbxTasks->indexOf(tbxTasksPage2), QApplication::translate("MainWindow", "Dateneingabe", 0, QApplication::UnicodeUTF8));
        option_server->setText(QApplication::translate("MainWindow", "Server w\303\244hlen", 0, QApplication::UnicodeUTF8));
        option_admin->setText(QApplication::translate("MainWindow", "Admin Zugang freischalten", 0, QApplication::UnicodeUTF8));
        tbxTasks->setTabText(tbxTasks->indexOf(tab), QApplication::translate("MainWindow", "Optionen", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
