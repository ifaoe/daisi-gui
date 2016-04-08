/********************************************************************************
** Form generated from reading UI file 'widget_census_shared.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_CENSUS_SHARED_H
#define UI_WIDGET_CENSUS_SHARED_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget_census_shared
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupbox_stuk4_codes;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolbutton_behaviour_codes;
    QLabel *lblStuk4Beh;
    QToolButton *toolbutton_association_codes;
    QLabel *lblStuk4Ass;
    QGroupBox *groupbox_group_ids;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolbutton_group_ids;
    QLabel *lblGroupObjects;
    QToolButton *toolbutton_family_ids;
    QLabel *lblFamily;

    void setupUi(QWidget *widget_census_shared)
    {
        if (widget_census_shared->objectName().isEmpty())
            widget_census_shared->setObjectName(QString::fromUtf8("widget_census_shared"));
        widget_census_shared->resize(433, 136);
        verticalLayout = new QVBoxLayout(widget_census_shared);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupbox_stuk4_codes = new QGroupBox(widget_census_shared);
        groupbox_stuk4_codes->setObjectName(QString::fromUtf8("groupbox_stuk4_codes"));
        groupbox_stuk4_codes->setCheckable(true);
        groupbox_stuk4_codes->setChecked(false);
        horizontalLayout = new QHBoxLayout(groupbox_stuk4_codes);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        toolbutton_behaviour_codes = new QToolButton(groupbox_stuk4_codes);
        toolbutton_behaviour_codes->setObjectName(QString::fromUtf8("toolbutton_behaviour_codes"));

        horizontalLayout->addWidget(toolbutton_behaviour_codes);

        lblStuk4Beh = new QLabel(groupbox_stuk4_codes);
        lblStuk4Beh->setObjectName(QString::fromUtf8("lblStuk4Beh"));

        horizontalLayout->addWidget(lblStuk4Beh);

        toolbutton_association_codes = new QToolButton(groupbox_stuk4_codes);
        toolbutton_association_codes->setObjectName(QString::fromUtf8("toolbutton_association_codes"));

        horizontalLayout->addWidget(toolbutton_association_codes);

        lblStuk4Ass = new QLabel(groupbox_stuk4_codes);
        lblStuk4Ass->setObjectName(QString::fromUtf8("lblStuk4Ass"));

        horizontalLayout->addWidget(lblStuk4Ass);


        verticalLayout->addWidget(groupbox_stuk4_codes);

        groupbox_group_ids = new QGroupBox(widget_census_shared);
        groupbox_group_ids->setObjectName(QString::fromUtf8("groupbox_group_ids"));
        groupbox_group_ids->setCheckable(true);
        groupbox_group_ids->setChecked(false);
        horizontalLayout_2 = new QHBoxLayout(groupbox_group_ids);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        toolbutton_group_ids = new QToolButton(groupbox_group_ids);
        toolbutton_group_ids->setObjectName(QString::fromUtf8("toolbutton_group_ids"));

        horizontalLayout_2->addWidget(toolbutton_group_ids);

        lblGroupObjects = new QLabel(groupbox_group_ids);
        lblGroupObjects->setObjectName(QString::fromUtf8("lblGroupObjects"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblGroupObjects->sizePolicy().hasHeightForWidth());
        lblGroupObjects->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lblGroupObjects);

        toolbutton_family_ids = new QToolButton(groupbox_group_ids);
        toolbutton_family_ids->setObjectName(QString::fromUtf8("toolbutton_family_ids"));

        horizontalLayout_2->addWidget(toolbutton_family_ids);

        lblFamily = new QLabel(groupbox_group_ids);
        lblFamily->setObjectName(QString::fromUtf8("lblFamily"));
        sizePolicy.setHeightForWidth(lblFamily->sizePolicy().hasHeightForWidth());
        lblFamily->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lblFamily);


        verticalLayout->addWidget(groupbox_group_ids);


        retranslateUi(widget_census_shared);

        QMetaObject::connectSlotsByName(widget_census_shared);
    } // setupUi

    void retranslateUi(QWidget *widget_census_shared)
    {
        widget_census_shared->setWindowTitle(QApplication::translate("widget_census_shared", "Form", 0, QApplication::UnicodeUTF8));
        groupbox_stuk4_codes->setTitle(QApplication::translate("widget_census_shared", "StUK4 Codes", 0, QApplication::UnicodeUTF8));
        toolbutton_behaviour_codes->setText(QApplication::translate("widget_census_shared", "...", 0, QApplication::UnicodeUTF8));
        lblStuk4Beh->setText(QApplication::translate("widget_census_shared", "Verhalten:", 0, QApplication::UnicodeUTF8));
        toolbutton_association_codes->setText(QApplication::translate("widget_census_shared", "...", 0, QApplication::UnicodeUTF8));
        lblStuk4Ass->setText(QApplication::translate("widget_census_shared", "Assoz.:", 0, QApplication::UnicodeUTF8));
        groupbox_group_ids->setTitle(QApplication::translate("widget_census_shared", "Gruppenbestimmung", 0, QApplication::UnicodeUTF8));
        toolbutton_group_ids->setText(QApplication::translate("widget_census_shared", "...", 0, QApplication::UnicodeUTF8));
        lblGroupObjects->setText(QApplication::translate("widget_census_shared", "Gruppe:", 0, QApplication::UnicodeUTF8));
        toolbutton_family_ids->setText(QApplication::translate("widget_census_shared", "...", 0, QApplication::UnicodeUTF8));
        lblFamily->setText(QApplication::translate("widget_census_shared", "Familie:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class widget_census_shared: public Ui_widget_census_shared {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_CENSUS_SHARED_H
