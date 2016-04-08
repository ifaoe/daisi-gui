/********************************************************************************
** Form generated from reading UI file 'widget_sessions.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SESSIONS_H
#define UI_WIDGET_SESSIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_wdgSessions
{
public:
    QGridLayout *gridLayout;
    QComboBox *cmbSession;
    QComboBox *combo_location;

    void setupUi(QFrame *wdgSessions)
    {
        if (wdgSessions->objectName().isEmpty())
            wdgSessions->setObjectName(QString::fromUtf8("wdgSessions"));
        wdgSessions->resize(526, 88);
        wdgSessions->setFrameShape(QFrame::StyledPanel);
        wdgSessions->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(wdgSessions);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cmbSession = new QComboBox(wdgSessions);
        cmbSession->setObjectName(QString::fromUtf8("cmbSession"));
        cmbSession->setEnabled(false);

        gridLayout->addWidget(cmbSession, 1, 1, 1, 1);

        combo_location = new QComboBox(wdgSessions);
        combo_location->setObjectName(QString::fromUtf8("combo_location"));

        gridLayout->addWidget(combo_location, 0, 1, 1, 1);


        retranslateUi(wdgSessions);

        QMetaObject::connectSlotsByName(wdgSessions);
    } // setupUi

    void retranslateUi(QFrame *wdgSessions)
    {
        wdgSessions->setWindowTitle(QApplication::translate("wdgSessions", "Frame", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wdgSessions: public Ui_wdgSessions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SESSIONS_H
