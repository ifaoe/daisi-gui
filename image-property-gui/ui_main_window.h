/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

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
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionProject_laden;
    QAction *actionBeeden;
    QAction *actionMit_Server_verbinden;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *fram_input;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_glare;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_glare;
    QPushButton *pushButton_save_glare;
    QGroupBox *groupBox_seastate;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_seastate;
    QPushButton *pushButton_save_seastate;
    QGroupBox *groupBox_turbidity;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox_turbidity;
    QPushButton *pushButton_save_turbidity;
    QGroupBox *groupBox_clarity;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox_clarity;
    QPushButton *pushButton_save_clarity;
    QGroupBox *groupBox_ice;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox_ice;
    QPushButton *pushButton_save_ice;
    QSpacerItem *verticalSpacer;
    QPlainTextEdit *plainTextEdit_remarks;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_save_remarks;
    QWidget *data_widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *session_widget;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *combo_server;
    QComboBox *combo_session;
    QTableView *tableView_image_properties;
    QStatusBar *statusbar;
    QButtonGroup *buttonGroup_save_type;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(886, 745);
        actionProject_laden = new QAction(MainWindow);
        actionProject_laden->setObjectName(QString::fromUtf8("actionProject_laden"));
        actionProject_laden->setEnabled(false);
        actionBeeden = new QAction(MainWindow);
        actionBeeden->setObjectName(QString::fromUtf8("actionBeeden"));
        actionMit_Server_verbinden = new QAction(MainWindow);
        actionMit_Server_verbinden->setObjectName(QString::fromUtf8("actionMit_Server_verbinden"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        fram_input = new QFrame(centralwidget);
        fram_input->setObjectName(QString::fromUtf8("fram_input"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fram_input->sizePolicy().hasHeightForWidth());
        fram_input->setSizePolicy(sizePolicy);
        fram_input->setMinimumSize(QSize(300, 0));
        fram_input->setFrameShape(QFrame::NoFrame);
        fram_input->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(fram_input);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_glare = new QGroupBox(fram_input);
        groupBox_glare->setObjectName(QString::fromUtf8("groupBox_glare"));
        horizontalLayout = new QHBoxLayout(groupBox_glare);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox_glare = new QComboBox(groupBox_glare);
        comboBox_glare->setObjectName(QString::fromUtf8("comboBox_glare"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_glare->sizePolicy().hasHeightForWidth());
        comboBox_glare->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(comboBox_glare);

        pushButton_save_glare = new QPushButton(groupBox_glare);
        buttonGroup_save_type = new QButtonGroup(MainWindow);
        buttonGroup_save_type->setObjectName(QString::fromUtf8("buttonGroup_save_type"));
        buttonGroup_save_type->addButton(pushButton_save_glare);
        pushButton_save_glare->setObjectName(QString::fromUtf8("pushButton_save_glare"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("document-save")));
        pushButton_save_glare->setIcon(icon);

        horizontalLayout->addWidget(pushButton_save_glare);


        verticalLayout->addWidget(groupBox_glare);

        groupBox_seastate = new QGroupBox(fram_input);
        groupBox_seastate->setObjectName(QString::fromUtf8("groupBox_seastate"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_seastate);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboBox_seastate = new QComboBox(groupBox_seastate);
        comboBox_seastate->setObjectName(QString::fromUtf8("comboBox_seastate"));
        sizePolicy1.setHeightForWidth(comboBox_seastate->sizePolicy().hasHeightForWidth());
        comboBox_seastate->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(comboBox_seastate);

        pushButton_save_seastate = new QPushButton(groupBox_seastate);
        buttonGroup_save_type->addButton(pushButton_save_seastate);
        pushButton_save_seastate->setObjectName(QString::fromUtf8("pushButton_save_seastate"));
        pushButton_save_seastate->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_save_seastate);


        verticalLayout->addWidget(groupBox_seastate);

        groupBox_turbidity = new QGroupBox(fram_input);
        groupBox_turbidity->setObjectName(QString::fromUtf8("groupBox_turbidity"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_turbidity);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBox_turbidity = new QComboBox(groupBox_turbidity);
        comboBox_turbidity->setObjectName(QString::fromUtf8("comboBox_turbidity"));
        sizePolicy1.setHeightForWidth(comboBox_turbidity->sizePolicy().hasHeightForWidth());
        comboBox_turbidity->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(comboBox_turbidity);

        pushButton_save_turbidity = new QPushButton(groupBox_turbidity);
        buttonGroup_save_type->addButton(pushButton_save_turbidity);
        pushButton_save_turbidity->setObjectName(QString::fromUtf8("pushButton_save_turbidity"));
        pushButton_save_turbidity->setIcon(icon);

        horizontalLayout_3->addWidget(pushButton_save_turbidity);


        verticalLayout->addWidget(groupBox_turbidity);

        groupBox_clarity = new QGroupBox(fram_input);
        groupBox_clarity->setObjectName(QString::fromUtf8("groupBox_clarity"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_clarity);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        comboBox_clarity = new QComboBox(groupBox_clarity);
        comboBox_clarity->setObjectName(QString::fromUtf8("comboBox_clarity"));
        sizePolicy1.setHeightForWidth(comboBox_clarity->sizePolicy().hasHeightForWidth());
        comboBox_clarity->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(comboBox_clarity);

        pushButton_save_clarity = new QPushButton(groupBox_clarity);
        buttonGroup_save_type->addButton(pushButton_save_clarity);
        pushButton_save_clarity->setObjectName(QString::fromUtf8("pushButton_save_clarity"));
        pushButton_save_clarity->setIcon(icon);

        horizontalLayout_4->addWidget(pushButton_save_clarity);


        verticalLayout->addWidget(groupBox_clarity);

        groupBox_ice = new QGroupBox(fram_input);
        groupBox_ice->setObjectName(QString::fromUtf8("groupBox_ice"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_ice);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        comboBox_ice = new QComboBox(groupBox_ice);
        comboBox_ice->setObjectName(QString::fromUtf8("comboBox_ice"));
        sizePolicy1.setHeightForWidth(comboBox_ice->sizePolicy().hasHeightForWidth());
        comboBox_ice->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(comboBox_ice);

        pushButton_save_ice = new QPushButton(groupBox_ice);
        buttonGroup_save_type->addButton(pushButton_save_ice);
        pushButton_save_ice->setObjectName(QString::fromUtf8("pushButton_save_ice"));
        pushButton_save_ice->setIcon(icon);

        horizontalLayout_5->addWidget(pushButton_save_ice);


        verticalLayout->addWidget(groupBox_ice);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        plainTextEdit_remarks = new QPlainTextEdit(fram_input);
        plainTextEdit_remarks->setObjectName(QString::fromUtf8("plainTextEdit_remarks"));

        verticalLayout->addWidget(plainTextEdit_remarks);

        widget = new QWidget(fram_input);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pushButton_save_remarks = new QPushButton(widget);
        buttonGroup_save_type->addButton(pushButton_save_remarks);
        pushButton_save_remarks->setObjectName(QString::fromUtf8("pushButton_save_remarks"));
        pushButton_save_remarks->setIcon(icon);

        horizontalLayout_6->addWidget(pushButton_save_remarks);


        verticalLayout->addWidget(widget);


        gridLayout->addWidget(fram_input, 0, 1, 2, 1);

        data_widget = new QWidget(centralwidget);
        data_widget->setObjectName(QString::fromUtf8("data_widget"));
        verticalLayout_2 = new QVBoxLayout(data_widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        session_widget = new QWidget(data_widget);
        session_widget->setObjectName(QString::fromUtf8("session_widget"));
        horizontalLayout_7 = new QHBoxLayout(session_widget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        combo_server = new QComboBox(session_widget);
        combo_server->setObjectName(QString::fromUtf8("combo_server"));

        horizontalLayout_7->addWidget(combo_server);

        combo_session = new QComboBox(session_widget);
        combo_session->setObjectName(QString::fromUtf8("combo_session"));

        horizontalLayout_7->addWidget(combo_session);


        verticalLayout_2->addWidget(session_widget);

        tableView_image_properties = new QTableView(data_widget);
        tableView_image_properties->setObjectName(QString::fromUtf8("tableView_image_properties"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableView_image_properties->sizePolicy().hasHeightForWidth());
        tableView_image_properties->setSizePolicy(sizePolicy2);
        tableView_image_properties->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableView_image_properties->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView_image_properties->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_image_properties->setAlternatingRowColors(true);
        tableView_image_properties->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView_image_properties->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(tableView_image_properties);


        gridLayout->addWidget(data_widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionProject_laden->setText(QApplication::translate("MainWindow", "&Project laden", 0, QApplication::UnicodeUTF8));
        actionBeeden->setText(QApplication::translate("MainWindow", "&Beenden", 0, QApplication::UnicodeUTF8));
        actionMit_Server_verbinden->setText(QApplication::translate("MainWindow", "&Mit Server verbinden", 0, QApplication::UnicodeUTF8));
        groupBox_glare->setTitle(QApplication::translate("MainWindow", "Glare", 0, QApplication::UnicodeUTF8));
        pushButton_save_glare->setText(QApplication::translate("MainWindow", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_save_glare->setProperty("dbvalue", QVariant(QApplication::translate("MainWindow", "glare_key", 0, QApplication::UnicodeUTF8)));
        groupBox_seastate->setTitle(QApplication::translate("MainWindow", "Seastate", 0, QApplication::UnicodeUTF8));
        pushButton_save_seastate->setText(QApplication::translate("MainWindow", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_save_seastate->setProperty("dbvalue", QVariant(QApplication::translate("MainWindow", "seastate", 0, QApplication::UnicodeUTF8)));
        groupBox_turbidity->setTitle(QApplication::translate("MainWindow", "Turbidity", 0, QApplication::UnicodeUTF8));
        pushButton_save_turbidity->setText(QApplication::translate("MainWindow", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_save_turbidity->setProperty("dbvalue", QVariant(QApplication::translate("MainWindow", "turbidity", 0, QApplication::UnicodeUTF8)));
        groupBox_clarity->setTitle(QApplication::translate("MainWindow", "Clarity", 0, QApplication::UnicodeUTF8));
        pushButton_save_clarity->setText(QApplication::translate("MainWindow", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_save_clarity->setProperty("dbvalue", QVariant(QApplication::translate("MainWindow", "clarity", 0, QApplication::UnicodeUTF8)));
        groupBox_ice->setTitle(QApplication::translate("MainWindow", "Ice", 0, QApplication::UnicodeUTF8));
        pushButton_save_ice->setText(QApplication::translate("MainWindow", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_save_ice->setProperty("dbvalue", QVariant(QApplication::translate("MainWindow", "ice", 0, QApplication::UnicodeUTF8)));
        pushButton_save_remarks->setText(QApplication::translate("MainWindow", "Speichern", 0, QApplication::UnicodeUTF8));
        pushButton_save_remarks->setProperty("dbvalue", QVariant(QApplication::translate("MainWindow", "remarks", 0, QApplication::UnicodeUTF8)));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
