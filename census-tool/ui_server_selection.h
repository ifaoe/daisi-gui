/********************************************************************************
** Form generated from reading UI file 'server_selection.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_SELECTION_H
#define UI_SERVER_SELECTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerSelection
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QComboBox *server_box;
    QToolButton *new_button;
    QToolButton *delete_button;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ServerSelection)
    {
        if (ServerSelection->objectName().isEmpty())
            ServerSelection->setObjectName(QString::fromUtf8("ServerSelection"));
        ServerSelection->resize(640, 111);
        ServerSelection->setMinimumSize(QSize(640, 0));
        verticalLayout = new QVBoxLayout(ServerSelection);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(ServerSelection);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        server_box = new QComboBox(widget);
        server_box->setObjectName(QString::fromUtf8("server_box"));

        gridLayout->addWidget(server_box, 0, 0, 1, 1);

        new_button = new QToolButton(widget);
        new_button->setObjectName(QString::fromUtf8("new_button"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("gtk-new")));
        new_button->setIcon(icon);

        gridLayout->addWidget(new_button, 0, 1, 1, 1);

        delete_button = new QToolButton(widget);
        delete_button->setObjectName(QString::fromUtf8("delete_button"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("gtk-delete")));
        delete_button->setIcon(icon1);

        gridLayout->addWidget(delete_button, 0, 2, 1, 1);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(ServerSelection);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ServerSelection);
        QObject::connect(buttonBox, SIGNAL(accepted()), ServerSelection, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ServerSelection, SLOT(reject()));

        QMetaObject::connectSlotsByName(ServerSelection);
    } // setupUi

    void retranslateUi(QDialog *ServerSelection)
    {
        ServerSelection->setWindowTitle(QApplication::translate("ServerSelection", "Serverauswahl", 0, QApplication::UnicodeUTF8));
        new_button->setText(QApplication::translate("ServerSelection", "A", 0, QApplication::UnicodeUTF8));
        delete_button->setText(QApplication::translate("ServerSelection", "D", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ServerSelection: public Ui_ServerSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_SELECTION_H
