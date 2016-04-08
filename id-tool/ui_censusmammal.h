/********************************************************************************
** Form generated from reading UI file 'censusmammal.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENSUSMAMMAL_H
#define UI_CENSUSMAMMAL_H

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
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CensusMammal
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupbox_name;
    QHBoxLayout *horizontalLayout_11;
    QComboBox *combobox_name;
    QGroupBox *groupbox_confidence;
    QHBoxLayout *horizontalLayout;
    QToolButton *button_confidence_1;
    QToolButton *button_confidence_2;
    QToolButton *button_confidence_3;
    QToolButton *button_confidence_4;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_10;
    QGroupBox *groupbox_behaviour;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *button_behaviour_swim;
    QToolButton *button_behaviour_fly;
    QGroupBox *groupbox_age;
    QGridLayout *gridLayout;
    QToolButton *button_age_juvenile;
    QToolButton *button_age_adult;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupbox_sex;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *button_male;
    QToolButton *button_female;
    QGroupBox *group_box_plumage;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *combobox_plumage;
    QGroupBox *groupbox_measurement;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *button_length;
    QLabel *label_length;
    QToolButton *button_width;
    QLabel *label_width;
    QGroupBox *groupbox_stuk4;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *button_stuk4_assoziations;
    QLabel *label_stuk4_assoziations;
    QToolButton *button_stuk4_behaviour;
    QLabel *label_stuk4_behaviour;
    QGroupBox *groupbox_groups;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *button_family;
    QLabel *label_family;
    QToolButton *button_group;
    QLabel *label_group;
    QGroupBox *groubbox_remarks;
    QHBoxLayout *horizontalLayout_9;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QFrame *CensusMammal)
    {
        if (CensusMammal->objectName().isEmpty())
            CensusMammal->setObjectName(QString::fromUtf8("CensusMammal"));
        CensusMammal->resize(621, 841);
        CensusMammal->setFrameShape(QFrame::StyledPanel);
        CensusMammal->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(CensusMammal);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupbox_name = new QGroupBox(CensusMammal);
        groupbox_name->setObjectName(QString::fromUtf8("groupbox_name"));
        horizontalLayout_11 = new QHBoxLayout(groupbox_name);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        combobox_name = new QComboBox(groupbox_name);
        combobox_name->setObjectName(QString::fromUtf8("combobox_name"));

        horizontalLayout_11->addWidget(combobox_name);


        verticalLayout->addWidget(groupbox_name);

        groupbox_confidence = new QGroupBox(CensusMammal);
        groupbox_confidence->setObjectName(QString::fromUtf8("groupbox_confidence"));
        groupbox_confidence->setFlat(false);
        horizontalLayout = new QHBoxLayout(groupbox_confidence);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 6, 6, 6);
        button_confidence_1 = new QToolButton(groupbox_confidence);
        button_confidence_1->setObjectName(QString::fromUtf8("button_confidence_1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button_confidence_1->sizePolicy().hasHeightForWidth());
        button_confidence_1->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(button_confidence_1);

        button_confidence_2 = new QToolButton(groupbox_confidence);
        button_confidence_2->setObjectName(QString::fromUtf8("button_confidence_2"));
        sizePolicy.setHeightForWidth(button_confidence_2->sizePolicy().hasHeightForWidth());
        button_confidence_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(button_confidence_2);

        button_confidence_3 = new QToolButton(groupbox_confidence);
        button_confidence_3->setObjectName(QString::fromUtf8("button_confidence_3"));
        sizePolicy.setHeightForWidth(button_confidence_3->sizePolicy().hasHeightForWidth());
        button_confidence_3->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(button_confidence_3);

        button_confidence_4 = new QToolButton(groupbox_confidence);
        button_confidence_4->setObjectName(QString::fromUtf8("button_confidence_4"));
        sizePolicy.setHeightForWidth(button_confidence_4->sizePolicy().hasHeightForWidth());
        button_confidence_4->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(button_confidence_4);


        verticalLayout->addWidget(groupbox_confidence);

        widget_2 = new QWidget(CensusMammal);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_10 = new QHBoxLayout(widget_2);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        groupbox_behaviour = new QGroupBox(widget_2);
        groupbox_behaviour->setObjectName(QString::fromUtf8("groupbox_behaviour"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupbox_behaviour->sizePolicy().hasHeightForWidth());
        groupbox_behaviour->setSizePolicy(sizePolicy1);
        groupbox_behaviour->setCheckable(true);
        groupbox_behaviour->setChecked(true);
        horizontalLayout_2 = new QHBoxLayout(groupbox_behaviour);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        button_behaviour_swim = new QToolButton(groupbox_behaviour);
        button_behaviour_swim->setObjectName(QString::fromUtf8("button_behaviour_swim"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(button_behaviour_swim->sizePolicy().hasHeightForWidth());
        button_behaviour_swim->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(button_behaviour_swim);

        button_behaviour_fly = new QToolButton(groupbox_behaviour);
        button_behaviour_fly->setObjectName(QString::fromUtf8("button_behaviour_fly"));
        sizePolicy2.setHeightForWidth(button_behaviour_fly->sizePolicy().hasHeightForWidth());
        button_behaviour_fly->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(button_behaviour_fly);


        horizontalLayout_10->addWidget(groupbox_behaviour);

        groupbox_age = new QGroupBox(widget_2);
        groupbox_age->setObjectName(QString::fromUtf8("groupbox_age"));
        sizePolicy1.setHeightForWidth(groupbox_age->sizePolicy().hasHeightForWidth());
        groupbox_age->setSizePolicy(sizePolicy1);
        groupbox_age->setCheckable(true);
        groupbox_age->setChecked(false);
        gridLayout = new QGridLayout(groupbox_age);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        button_age_juvenile = new QToolButton(groupbox_age);
        button_age_juvenile->setObjectName(QString::fromUtf8("button_age_juvenile"));
        sizePolicy2.setHeightForWidth(button_age_juvenile->sizePolicy().hasHeightForWidth());
        button_age_juvenile->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(button_age_juvenile, 0, 1, 1, 1);

        button_age_adult = new QToolButton(groupbox_age);
        button_age_adult->setObjectName(QString::fromUtf8("button_age_adult"));
        sizePolicy2.setHeightForWidth(button_age_adult->sizePolicy().hasHeightForWidth());
        button_age_adult->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(button_age_adult, 0, 0, 1, 1);


        horizontalLayout_10->addWidget(groupbox_age);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(CensusMammal);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupbox_sex = new QGroupBox(widget);
        groupbox_sex->setObjectName(QString::fromUtf8("groupbox_sex"));
        groupbox_sex->setCheckable(true);
        groupbox_sex->setChecked(false);
        horizontalLayout_3 = new QHBoxLayout(groupbox_sex);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(6, 6, 6, 6);
        button_male = new QToolButton(groupbox_sex);
        button_male->setObjectName(QString::fromUtf8("button_male"));
        sizePolicy.setHeightForWidth(button_male->sizePolicy().hasHeightForWidth());
        button_male->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(button_male);

        button_female = new QToolButton(groupbox_sex);
        button_female->setObjectName(QString::fromUtf8("button_female"));
        sizePolicy.setHeightForWidth(button_female->sizePolicy().hasHeightForWidth());
        button_female->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(button_female);


        horizontalLayout_4->addWidget(groupbox_sex);

        group_box_plumage = new QGroupBox(widget);
        group_box_plumage->setObjectName(QString::fromUtf8("group_box_plumage"));
        group_box_plumage->setCheckable(true);
        group_box_plumage->setChecked(false);
        horizontalLayout_5 = new QHBoxLayout(group_box_plumage);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        combobox_plumage = new QComboBox(group_box_plumage);
        combobox_plumage->setObjectName(QString::fromUtf8("combobox_plumage"));

        horizontalLayout_5->addWidget(combobox_plumage);


        horizontalLayout_4->addWidget(group_box_plumage);


        verticalLayout->addWidget(widget);

        groupbox_measurement = new QGroupBox(CensusMammal);
        groupbox_measurement->setObjectName(QString::fromUtf8("groupbox_measurement"));
        horizontalLayout_6 = new QHBoxLayout(groupbox_measurement);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        button_length = new QToolButton(groupbox_measurement);
        button_length->setObjectName(QString::fromUtf8("button_length"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("measure");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        button_length->setIcon(icon);

        horizontalLayout_6->addWidget(button_length);

        label_length = new QLabel(groupbox_measurement);
        label_length->setObjectName(QString::fromUtf8("label_length"));

        horizontalLayout_6->addWidget(label_length);

        button_width = new QToolButton(groupbox_measurement);
        button_width->setObjectName(QString::fromUtf8("button_width"));
        button_width->setIcon(icon);

        horizontalLayout_6->addWidget(button_width);

        label_width = new QLabel(groupbox_measurement);
        label_width->setObjectName(QString::fromUtf8("label_width"));

        horizontalLayout_6->addWidget(label_width);


        verticalLayout->addWidget(groupbox_measurement);

        groupbox_stuk4 = new QGroupBox(CensusMammal);
        groupbox_stuk4->setObjectName(QString::fromUtf8("groupbox_stuk4"));
        horizontalLayout_7 = new QHBoxLayout(groupbox_stuk4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        button_stuk4_assoziations = new QToolButton(groupbox_stuk4);
        button_stuk4_assoziations->setObjectName(QString::fromUtf8("button_stuk4_assoziations"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("view-list-text");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        button_stuk4_assoziations->setIcon(icon1);

        horizontalLayout_7->addWidget(button_stuk4_assoziations);

        label_stuk4_assoziations = new QLabel(groupbox_stuk4);
        label_stuk4_assoziations->setObjectName(QString::fromUtf8("label_stuk4_assoziations"));

        horizontalLayout_7->addWidget(label_stuk4_assoziations);

        button_stuk4_behaviour = new QToolButton(groupbox_stuk4);
        button_stuk4_behaviour->setObjectName(QString::fromUtf8("button_stuk4_behaviour"));
        button_stuk4_behaviour->setIcon(icon1);

        horizontalLayout_7->addWidget(button_stuk4_behaviour);

        label_stuk4_behaviour = new QLabel(groupbox_stuk4);
        label_stuk4_behaviour->setObjectName(QString::fromUtf8("label_stuk4_behaviour"));

        horizontalLayout_7->addWidget(label_stuk4_behaviour);


        verticalLayout->addWidget(groupbox_stuk4);

        groupbox_groups = new QGroupBox(CensusMammal);
        groupbox_groups->setObjectName(QString::fromUtf8("groupbox_groups"));
        horizontalLayout_8 = new QHBoxLayout(groupbox_groups);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        button_family = new QToolButton(groupbox_groups);
        button_family->setObjectName(QString::fromUtf8("button_family"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("object-group");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        button_family->setIcon(icon2);

        horizontalLayout_8->addWidget(button_family);

        label_family = new QLabel(groupbox_groups);
        label_family->setObjectName(QString::fromUtf8("label_family"));

        horizontalLayout_8->addWidget(label_family);

        button_group = new QToolButton(groupbox_groups);
        button_group->setObjectName(QString::fromUtf8("button_group"));
        button_group->setIcon(icon2);

        horizontalLayout_8->addWidget(button_group);

        label_group = new QLabel(groupbox_groups);
        label_group->setObjectName(QString::fromUtf8("label_group"));

        horizontalLayout_8->addWidget(label_group);


        verticalLayout->addWidget(groupbox_groups);

        groubbox_remarks = new QGroupBox(CensusMammal);
        groubbox_remarks->setObjectName(QString::fromUtf8("groubbox_remarks"));
        horizontalLayout_9 = new QHBoxLayout(groubbox_remarks);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        plainTextEdit = new QPlainTextEdit(groubbox_remarks);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout_9->addWidget(plainTextEdit);


        verticalLayout->addWidget(groubbox_remarks);


        retranslateUi(CensusMammal);

        QMetaObject::connectSlotsByName(CensusMammal);
    } // setupUi

    void retranslateUi(QFrame *CensusMammal)
    {
        CensusMammal->setWindowTitle(QApplication::translate("CensusMammal", "Frame", 0, QApplication::UnicodeUTF8));
        groupbox_name->setTitle(QApplication::translate("CensusMammal", "Name des Objektes", 0, QApplication::UnicodeUTF8));
        groupbox_confidence->setTitle(QApplication::translate("CensusMammal", "Bestimmungssicherheit", 0, QApplication::UnicodeUTF8));
        button_confidence_1->setText(QApplication::translate("CensusMammal", "sicher", 0, QApplication::UnicodeUTF8));
        button_confidence_1->setProperty("dbvalue", QVariant(QApplication::translate("CensusMammal", "1", 0, QApplication::UnicodeUTF8)));
        button_confidence_2->setText(QApplication::translate("CensusMammal", "sehr wahrscheinlich", 0, QApplication::UnicodeUTF8));
        button_confidence_2->setProperty("dbvalue", QVariant(QApplication::translate("CensusMammal", "2", 0, QApplication::UnicodeUTF8)));
        button_confidence_3->setText(QApplication::translate("CensusMammal", "m\303\266glich", 0, QApplication::UnicodeUTF8));
        button_confidence_3->setProperty("dbvalue", QVariant(QApplication::translate("CensusMammal", "3", 0, QApplication::UnicodeUTF8)));
        button_confidence_4->setText(QApplication::translate("CensusMammal", "potenziell", 0, QApplication::UnicodeUTF8));
        button_confidence_4->setProperty("dbvalue", QVariant(QApplication::translate("CensusMammal", "4", 0, QApplication::UnicodeUTF8)));
        groupbox_behaviour->setTitle(QApplication::translate("CensusMammal", "&Verhalten", 0, QApplication::UnicodeUTF8));
        button_behaviour_swim->setText(QApplication::translate("CensusMammal", "durchbricht \n"
"Oberfl\303\244che", 0, QApplication::UnicodeUTF8));
        button_behaviour_swim->setProperty("dbvalue", QVariant(QApplication::translate("CensusMammal", "OW", 0, QApplication::UnicodeUTF8)));
        button_behaviour_fly->setText(QApplication::translate("CensusMammal", "unterhalb der\n"
"Oberfl\303\244che", 0, QApplication::UnicodeUTF8));
        button_behaviour_fly->setProperty("dbvalue", QVariant(QApplication::translate("CensusMammal", "UW", 0, QApplication::UnicodeUTF8)));
        groupbox_age->setTitle(QApplication::translate("CensusMammal", "Alter", 0, QApplication::UnicodeUTF8));
        button_age_juvenile->setText(QApplication::translate("CensusMammal", "juvenil", 0, QApplication::UnicodeUTF8));
        button_age_juvenile->setProperty("dbvalue", QVariant(QApplication::translate("CensusMammal", "JUV", 0, QApplication::UnicodeUTF8)));
        button_age_adult->setText(QApplication::translate("CensusMammal", "adult", 0, QApplication::UnicodeUTF8));
        button_age_adult->setProperty("dbvalue", QVariant(QApplication::translate("CensusMammal", "ADU", 0, QApplication::UnicodeUTF8)));
        groupbox_sex->setTitle(QApplication::translate("CensusMammal", "&Geschlecht", 0, QApplication::UnicodeUTF8));
        button_male->setText(QApplication::translate("CensusMammal", "m\303\244nnlich", 0, QApplication::UnicodeUTF8));
        button_male->setProperty("dbvalue", QVariant(QApplication::translate("CensusMammal", "M", 0, QApplication::UnicodeUTF8)));
        button_female->setText(QApplication::translate("CensusMammal", "weiblich", 0, QApplication::UnicodeUTF8));
        button_female->setProperty("dbvalue", QVariant(QApplication::translate("CensusMammal", "F", 0, QApplication::UnicodeUTF8)));
        group_box_plumage->setTitle(QApplication::translate("CensusMammal", "Gefieder", 0, QApplication::UnicodeUTF8));
        groupbox_measurement->setTitle(QApplication::translate("CensusMammal", "Messungen", 0, QApplication::UnicodeUTF8));
        button_length->setText(QApplication::translate("CensusMammal", "L\303\244nge", 0, QApplication::UnicodeUTF8));
        label_length->setText(QString());
        button_width->setText(QApplication::translate("CensusMammal", "Breite", 0, QApplication::UnicodeUTF8));
        label_width->setText(QString());
        groupbox_stuk4->setTitle(QApplication::translate("CensusMammal", "Stuk4 Codes", 0, QApplication::UnicodeUTF8));
        button_stuk4_assoziations->setText(QApplication::translate("CensusMammal", "Assoziationen", 0, QApplication::UnicodeUTF8));
        label_stuk4_assoziations->setText(QString());
        button_stuk4_behaviour->setText(QApplication::translate("CensusMammal", "Verhalten", 0, QApplication::UnicodeUTF8));
        label_stuk4_behaviour->setText(QString());
        groupbox_groups->setTitle(QApplication::translate("CensusMammal", "Gruppenbestimmung", 0, QApplication::UnicodeUTF8));
        button_family->setText(QApplication::translate("CensusMammal", "Familie", 0, QApplication::UnicodeUTF8));
        label_family->setText(QString());
        button_group->setText(QApplication::translate("CensusMammal", "Gruppe", 0, QApplication::UnicodeUTF8));
        label_group->setText(QString());
        groubbox_remarks->setTitle(QApplication::translate("CensusMammal", "Bemerkung", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CensusMammal: public Ui_CensusMammal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENSUSMAMMAL_H
