/********************************************************************************
** Form generated from reading UI file 'server_settings.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_SETTINGS_H
#define UI_SERVER_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerSettings
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QLineEdit *host_name;
    QLabel *label_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *host_ip;
    QLabel *label_3;
    QLineEdit *host_port;
    QLabel *label_2;
    QLineEdit *database_name;
    QLabel *label_4;
    QLineEdit *datanase_user;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *database_password_check;
    QLineEdit *database_password;
    QDialogButtonBox *add_server;

    void setupUi(QDialog *ServerSettings)
    {
        if (ServerSettings->objectName().isEmpty())
            ServerSettings->setObjectName(QString::fromUtf8("ServerSettings"));
        ServerSettings->resize(640, 265);
        ServerSettings->setMinimumSize(QSize(640, 0));
        gridLayout = new QGridLayout(ServerSettings);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        widget_2 = new QWidget(ServerSettings);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        host_name = new QLineEdit(widget_2);
        host_name->setObjectName(QString::fromUtf8("host_name"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(host_name->sizePolicy().hasHeightForWidth());
        host_name->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(host_name, 0, 1, 1, 1);

        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setTextFormat(Qt::AutoText);
        label_7->setScaledContents(false);

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(ServerSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        host_ip = new QLineEdit(groupBox);
        host_ip->setObjectName(QString::fromUtf8("host_ip"));

        gridLayout_2->addWidget(host_ip, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        host_port = new QLineEdit(groupBox);
        host_port->setObjectName(QString::fromUtf8("host_port"));

        gridLayout_2->addWidget(host_port, 0, 3, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        database_name = new QLineEdit(groupBox);
        database_name->setObjectName(QString::fromUtf8("database_name"));

        gridLayout_2->addWidget(database_name, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 2, 1, 1);

        datanase_user = new QLineEdit(groupBox);
        datanase_user->setObjectName(QString::fromUtf8("datanase_user"));
        datanase_user->setEchoMode(QLineEdit::Normal);

        gridLayout_2->addWidget(datanase_user, 1, 3, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 2, 2, 1, 1);

        database_password_check = new QLineEdit(groupBox);
        database_password_check->setObjectName(QString::fromUtf8("database_password_check"));
        database_password_check->setEnabled(false);
        database_password_check->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(database_password_check, 2, 3, 1, 1);

        database_password = new QLineEdit(groupBox);
        database_password->setObjectName(QString::fromUtf8("database_password"));
        database_password->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(database_password, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 2);

        add_server = new QDialogButtonBox(ServerSettings);
        add_server->setObjectName(QString::fromUtf8("add_server"));
        add_server->setOrientation(Qt::Horizontal);
        add_server->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        gridLayout->addWidget(add_server, 4, 0, 1, 1);


        retranslateUi(ServerSettings);
        QObject::connect(add_server, SIGNAL(rejected()), ServerSettings, SLOT(reject()));
        QObject::connect(add_server, SIGNAL(accepted()), ServerSettings, SLOT(accept()));

        QMetaObject::connectSlotsByName(ServerSettings);
    } // setupUi

    void retranslateUi(QDialog *ServerSettings)
    {
        ServerSettings->setWindowTitle(QApplication::translate("ServerSettings", "Server hinzuf\303\274gen", 0, QApplication::UnicodeUTF8));
        host_name->setText(QApplication::translate("ServerSettings", "Default", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ServerSettings", "Servername:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ServerSettings", "Verbindungsdetails", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ServerSettings", "Host:", 0, QApplication::UnicodeUTF8));
        host_ip->setText(QApplication::translate("ServerSettings", "localhost", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ServerSettings", "Name:", 0, QApplication::UnicodeUTF8));
        host_port->setText(QApplication::translate("ServerSettings", "5432", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ServerSettings", "Port:", 0, QApplication::UnicodeUTF8));
        database_name->setText(QApplication::translate("ServerSettings", "daisi", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ServerSettings", "Nutzer:", 0, QApplication::UnicodeUTF8));
        datanase_user->setText(QApplication::translate("ServerSettings", "daisi", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ServerSettings", "Passwort:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ServerSettings", "Passwort best\303\244tigen:", 0, QApplication::UnicodeUTF8));
        database_password_check->setText(QApplication::translate("ServerSettings", "18ifaoe184", 0, QApplication::UnicodeUTF8));
        database_password->setText(QApplication::translate("ServerSettings", "18ifaoe184", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ServerSettings: public Ui_ServerSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_SETTINGS_H
