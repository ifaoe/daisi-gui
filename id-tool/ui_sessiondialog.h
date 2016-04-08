/********************************************************************************
** Form generated from reading UI file 'sessiondialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SESSIONDIALOG_H
#define UI_SESSIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dlgModeSelect
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *gbxSource;
    QVBoxLayout *verticalLayout_2;
    QComboBox *cmbSource;
    QGroupBox *gbxDatabase;
    QVBoxLayout *verticalLayout_3;
    QComboBox *cmbDatabase;
    QWidget *wdgButtons;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnYes;
    QPushButton *btnNo;

    void setupUi(QDialog *dlgModeSelect)
    {
        if (dlgModeSelect->objectName().isEmpty())
            dlgModeSelect->setObjectName(QString::fromUtf8("dlgModeSelect"));
        dlgModeSelect->resize(523, 208);
        verticalLayout = new QVBoxLayout(dlgModeSelect);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gbxSource = new QGroupBox(dlgModeSelect);
        gbxSource->setObjectName(QString::fromUtf8("gbxSource"));
        verticalLayout_2 = new QVBoxLayout(gbxSource);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cmbSource = new QComboBox(gbxSource);
        cmbSource->setObjectName(QString::fromUtf8("cmbSource"));

        verticalLayout_2->addWidget(cmbSource);


        verticalLayout->addWidget(gbxSource);

        gbxDatabase = new QGroupBox(dlgModeSelect);
        gbxDatabase->setObjectName(QString::fromUtf8("gbxDatabase"));
        verticalLayout_3 = new QVBoxLayout(gbxDatabase);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        cmbDatabase = new QComboBox(gbxDatabase);
        cmbDatabase->setObjectName(QString::fromUtf8("cmbDatabase"));

        verticalLayout_3->addWidget(cmbDatabase);


        verticalLayout->addWidget(gbxDatabase);

        wdgButtons = new QWidget(dlgModeSelect);
        wdgButtons->setObjectName(QString::fromUtf8("wdgButtons"));
        horizontalLayout = new QHBoxLayout(wdgButtons);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(302, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnYes = new QPushButton(wdgButtons);
        btnYes->setObjectName(QString::fromUtf8("btnYes"));

        horizontalLayout->addWidget(btnYes);

        btnNo = new QPushButton(wdgButtons);
        btnNo->setObjectName(QString::fromUtf8("btnNo"));

        horizontalLayout->addWidget(btnNo);


        verticalLayout->addWidget(wdgButtons);


        retranslateUi(dlgModeSelect);

        QMetaObject::connectSlotsByName(dlgModeSelect);
    } // setupUi

    void retranslateUi(QDialog *dlgModeSelect)
    {
        dlgModeSelect->setWindowTitle(QApplication::translate("dlgModeSelect", "Sitzungsauswahl", 0, QApplication::UnicodeUTF8));
        gbxSource->setTitle(QApplication::translate("dlgModeSelect", "Datenquelle", 0, QApplication::UnicodeUTF8));
        gbxDatabase->setTitle(QApplication::translate("dlgModeSelect", "Datenbank", 0, QApplication::UnicodeUTF8));
        btnYes->setText(QApplication::translate("dlgModeSelect", "Ok", 0, QApplication::UnicodeUTF8));
        btnNo->setText(QApplication::translate("dlgModeSelect", "Abbrechen", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgModeSelect: public Ui_dlgModeSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SESSIONDIALOG_H
