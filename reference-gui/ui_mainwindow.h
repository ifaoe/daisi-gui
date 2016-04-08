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
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSpalten;
    QAction *actionMit_Server_verbinden;
    QAction *actionSession_w_hlen;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget_table;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupbox_session;
    QHBoxLayout *horizontalLayout;
    QComboBox *combo_session;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_types;
    QTableView *table_view_objects;
    QWidget *widget_side;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget_image;
    QWidget *widget_image_buttons;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *button_save_image;
    QToolButton *button_image_popup;
    QSpacerItem *verticalSpacer;
    QTableWidget *info_table;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QMenu *menuSitzung;
    QMenu *menuEinstellungen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(826, 828);
        actionSpalten = new QAction(MainWindow);
        actionSpalten->setObjectName(QString::fromUtf8("actionSpalten"));
        actionMit_Server_verbinden = new QAction(MainWindow);
        actionMit_Server_verbinden->setObjectName(QString::fromUtf8("actionMit_Server_verbinden"));
        actionSession_w_hlen = new QAction(MainWindow);
        actionSession_w_hlen->setObjectName(QString::fromUtf8("actionSession_w_hlen"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_table = new QWidget(centralwidget);
        widget_table->setObjectName(QString::fromUtf8("widget_table"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_table->sizePolicy().hasHeightForWidth());
        widget_table->setSizePolicy(sizePolicy);
        widget_table->setMinimumSize(QSize(480, 0));
        verticalLayout_3 = new QVBoxLayout(widget_table);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupbox_session = new QGroupBox(widget_table);
        groupbox_session->setObjectName(QString::fromUtf8("groupbox_session"));
        horizontalLayout = new QHBoxLayout(groupbox_session);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        combo_session = new QComboBox(groupbox_session);
        combo_session->setObjectName(QString::fromUtf8("combo_session"));
        combo_session->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(combo_session);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(groupbox_session);

        widget_types = new QWidget(widget_table);
        widget_types->setObjectName(QString::fromUtf8("widget_types"));

        verticalLayout_3->addWidget(widget_types);

        table_view_objects = new QTableView(widget_table);
        table_view_objects->setObjectName(QString::fromUtf8("table_view_objects"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(table_view_objects->sizePolicy().hasHeightForWidth());
        table_view_objects->setSizePolicy(sizePolicy1);
        table_view_objects->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        table_view_objects->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_view_objects->setAlternatingRowColors(true);
        table_view_objects->horizontalHeader()->setVisible(true);
        table_view_objects->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(table_view_objects);

        groupbox_session->raise();
        table_view_objects->raise();
        widget_types->raise();

        gridLayout->addWidget(widget_table, 0, 0, 1, 1);

        widget_side = new QWidget(centralwidget);
        widget_side->setObjectName(QString::fromUtf8("widget_side"));
        widget_side->setMaximumSize(QSize(268, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget_side);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_3 = new QFrame(widget_side);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy2);
        frame_3->setMinimumSize(QSize(0, 0));
        frame_3->setMaximumSize(QSize(16777215, 16777215));
        frame_3->setBaseSize(QSize(0, 0));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_image = new QWidget(frame_3);
        widget_image->setObjectName(QString::fromUtf8("widget_image"));
        sizePolicy2.setHeightForWidth(widget_image->sizePolicy().hasHeightForWidth());
        widget_image->setSizePolicy(sizePolicy2);
        widget_image->setMinimumSize(QSize(256, 256));
        widget_image->setMaximumSize(QSize(256, 256));
        widget_image->setSizeIncrement(QSize(0, 0));

        verticalLayout->addWidget(widget_image);

        widget_image_buttons = new QWidget(frame_3);
        widget_image_buttons->setObjectName(QString::fromUtf8("widget_image_buttons"));
        horizontalLayout_2 = new QHBoxLayout(widget_image_buttons);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        button_save_image = new QToolButton(widget_image_buttons);
        button_save_image->setObjectName(QString::fromUtf8("button_save_image"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        button_save_image->setIcon(icon);

        horizontalLayout_2->addWidget(button_save_image);

        button_image_popup = new QToolButton(widget_image_buttons);
        button_image_popup->setObjectName(QString::fromUtf8("button_image_popup"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("view-fullscreen");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        button_image_popup->setIcon(icon1);

        horizontalLayout_2->addWidget(button_image_popup);


        verticalLayout->addWidget(widget_image_buttons);


        verticalLayout_2->addWidget(frame_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        info_table = new QTableWidget(widget_side);
        if (info_table->columnCount() < 1)
            info_table->setColumnCount(1);
        if (info_table->rowCount() < 5)
            info_table->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        info_table->setVerticalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        info_table->setVerticalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        info_table->setVerticalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        info_table->setVerticalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        info_table->setVerticalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        info_table->setItem(0, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        info_table->setItem(1, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        info_table->setItem(2, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        info_table->setItem(3, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        info_table->setItem(4, 0, __qtablewidgetitem9);
        info_table->setObjectName(QString::fromUtf8("info_table"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(info_table->sizePolicy().hasHeightForWidth());
        info_table->setSizePolicy(sizePolicy3);
        info_table->setColumnCount(1);
        info_table->horizontalHeader()->setVisible(false);
        info_table->horizontalHeader()->setStretchLastSection(true);
        info_table->verticalHeader()->setVisible(true);

        verticalLayout_2->addWidget(info_table);

        plainTextEdit = new QPlainTextEdit(widget_side);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        sizePolicy2.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy2);
        plainTextEdit->setMinimumSize(QSize(50, 0));

        verticalLayout_2->addWidget(plainTextEdit);


        gridLayout->addWidget(widget_side, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 826, 29));
        menuSitzung = new QMenu(menubar);
        menuSitzung->setObjectName(QString::fromUtf8("menuSitzung"));
        menuEinstellungen = new QMenu(menubar);
        menuEinstellungen->setObjectName(QString::fromUtf8("menuEinstellungen"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSitzung->menuAction());
        menubar->addAction(menuEinstellungen->menuAction());
        menuSitzung->addAction(actionMit_Server_verbinden);
        menuEinstellungen->addAction(actionSpalten);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSpalten->setText(QApplication::translate("MainWindow", "&Spalten", 0, QApplication::UnicodeUTF8));
        actionMit_Server_verbinden->setText(QApplication::translate("MainWindow", "&Mit Server verbinden", 0, QApplication::UnicodeUTF8));
        actionSession_w_hlen->setText(QApplication::translate("MainWindow", "Session w\303\244hlen", 0, QApplication::UnicodeUTF8));
        groupbox_session->setTitle(QApplication::translate("MainWindow", "Projekt", 0, QApplication::UnicodeUTF8));
        button_save_image->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        button_image_popup->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = info_table->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Projekt", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = info_table->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "UTM X", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = info_table->verticalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "UTM Y", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = info_table->verticalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Longitude", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = info_table->verticalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Latitude", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = info_table->isSortingEnabled();
        info_table->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem5 = info_table->item(0, 0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = info_table->item(1, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = info_table->item(2, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = info_table->item(3, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = info_table->item(4, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        info_table->setSortingEnabled(__sortingEnabled);

        menuSitzung->setTitle(QApplication::translate("MainWindow", "Sit&zung", 0, QApplication::UnicodeUTF8));
        menuEinstellungen->setTitle(QApplication::translate("MainWindow", "Einste&llungen", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
