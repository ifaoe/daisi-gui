/********************************************************************************
** Form generated from reading UI file 'censusbird.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENSUSBIRD_H
#define UI_CENSUSBIRD_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CensusBird
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupbox_name;
    QHBoxLayout *horizontalLayout_10;
    QComboBox *combobox_name;
    QGroupBox *groupbox_confidence;
    QHBoxLayout *horizontalLayout;
    QToolButton *button_confidence_1;
    QToolButton *button_confidence_2;
    QToolButton *button_confidence_3;
    QToolButton *button_confidence_4;
    QGroupBox *groupbox_behaviour;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *button_behaviour_swim;
    QToolButton *button_behaviour_fly;
    QToolButton *button_behaviour_dive;
    QGroupBox *groupbox_age;
    QGridLayout *gridLayout;
    QToolButton *button_age_adult;
    QToolButton *button_age_juvenile;
    QToolButton *button_age_immature;
    QComboBox *combobox_age_years;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupbox_sex;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *button_male;
    QToolButton *button_female;
    QGroupBox *groupbox_plumage;
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
    QPlainTextEdit *text_remarks;
    QSpacerItem *verticalSpacer;
    QButtonGroup *buttongroup_age;
    QButtonGroup *buttongroup_sex;
    QButtonGroup *buttongroup_confidence;
    QButtonGroup *buttongroup_behaviour;

    void setupUi(QFrame *CensusBird)
    {
        if (CensusBird->objectName().isEmpty())
            CensusBird->setObjectName(QString::fromUtf8("CensusBird"));
        CensusBird->resize(525, 809);
        CensusBird->setFrameShape(QFrame::StyledPanel);
        CensusBird->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(CensusBird);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupbox_name = new QGroupBox(CensusBird);
        groupbox_name->setObjectName(QString::fromUtf8("groupbox_name"));
        horizontalLayout_10 = new QHBoxLayout(groupbox_name);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        combobox_name = new QComboBox(groupbox_name);
        combobox_name->setObjectName(QString::fromUtf8("combobox_name"));

        horizontalLayout_10->addWidget(combobox_name);


        verticalLayout->addWidget(groupbox_name);

        groupbox_confidence = new QGroupBox(CensusBird);
        groupbox_confidence->setObjectName(QString::fromUtf8("groupbox_confidence"));
        groupbox_confidence->setFlat(false);
        horizontalLayout = new QHBoxLayout(groupbox_confidence);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 6, 6, 6);
        button_confidence_1 = new QToolButton(groupbox_confidence);
        buttongroup_confidence = new QButtonGroup(CensusBird);
        buttongroup_confidence->setObjectName(QString::fromUtf8("buttongroup_confidence"));
        buttongroup_confidence->addButton(button_confidence_1);
        button_confidence_1->setObjectName(QString::fromUtf8("button_confidence_1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button_confidence_1->sizePolicy().hasHeightForWidth());
        button_confidence_1->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(button_confidence_1);

        button_confidence_2 = new QToolButton(groupbox_confidence);
        buttongroup_confidence->addButton(button_confidence_2);
        button_confidence_2->setObjectName(QString::fromUtf8("button_confidence_2"));
        sizePolicy.setHeightForWidth(button_confidence_2->sizePolicy().hasHeightForWidth());
        button_confidence_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(button_confidence_2);

        button_confidence_3 = new QToolButton(groupbox_confidence);
        buttongroup_confidence->addButton(button_confidence_3);
        button_confidence_3->setObjectName(QString::fromUtf8("button_confidence_3"));
        sizePolicy.setHeightForWidth(button_confidence_3->sizePolicy().hasHeightForWidth());
        button_confidence_3->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(button_confidence_3);

        button_confidence_4 = new QToolButton(groupbox_confidence);
        buttongroup_confidence->addButton(button_confidence_4);
        button_confidence_4->setObjectName(QString::fromUtf8("button_confidence_4"));
        sizePolicy.setHeightForWidth(button_confidence_4->sizePolicy().hasHeightForWidth());
        button_confidence_4->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(button_confidence_4);


        verticalLayout->addWidget(groupbox_confidence);

        groupbox_behaviour = new QGroupBox(CensusBird);
        groupbox_behaviour->setObjectName(QString::fromUtf8("groupbox_behaviour"));
        horizontalLayout_2 = new QHBoxLayout(groupbox_behaviour);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        button_behaviour_swim = new QToolButton(groupbox_behaviour);
        buttongroup_behaviour = new QButtonGroup(CensusBird);
        buttongroup_behaviour->setObjectName(QString::fromUtf8("buttongroup_behaviour"));
        buttongroup_behaviour->addButton(button_behaviour_swim);
        button_behaviour_swim->setObjectName(QString::fromUtf8("button_behaviour_swim"));
        sizePolicy.setHeightForWidth(button_behaviour_swim->sizePolicy().hasHeightForWidth());
        button_behaviour_swim->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(button_behaviour_swim);

        button_behaviour_fly = new QToolButton(groupbox_behaviour);
        buttongroup_behaviour->addButton(button_behaviour_fly);
        button_behaviour_fly->setObjectName(QString::fromUtf8("button_behaviour_fly"));
        sizePolicy.setHeightForWidth(button_behaviour_fly->sizePolicy().hasHeightForWidth());
        button_behaviour_fly->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(button_behaviour_fly);

        button_behaviour_dive = new QToolButton(groupbox_behaviour);
        buttongroup_behaviour->addButton(button_behaviour_dive);
        button_behaviour_dive->setObjectName(QString::fromUtf8("button_behaviour_dive"));
        sizePolicy.setHeightForWidth(button_behaviour_dive->sizePolicy().hasHeightForWidth());
        button_behaviour_dive->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(button_behaviour_dive);


        verticalLayout->addWidget(groupbox_behaviour);

        groupbox_age = new QGroupBox(CensusBird);
        groupbox_age->setObjectName(QString::fromUtf8("groupbox_age"));
        groupbox_age->setCheckable(true);
        gridLayout = new QGridLayout(groupbox_age);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        button_age_adult = new QToolButton(groupbox_age);
        buttongroup_age = new QButtonGroup(CensusBird);
        buttongroup_age->setObjectName(QString::fromUtf8("buttongroup_age"));
        buttongroup_age->addButton(button_age_adult);
        button_age_adult->setObjectName(QString::fromUtf8("button_age_adult"));
        sizePolicy.setHeightForWidth(button_age_adult->sizePolicy().hasHeightForWidth());
        button_age_adult->setSizePolicy(sizePolicy);

        gridLayout->addWidget(button_age_adult, 0, 0, 1, 1);

        button_age_juvenile = new QToolButton(groupbox_age);
        buttongroup_age->addButton(button_age_juvenile);
        button_age_juvenile->setObjectName(QString::fromUtf8("button_age_juvenile"));
        sizePolicy.setHeightForWidth(button_age_juvenile->sizePolicy().hasHeightForWidth());
        button_age_juvenile->setSizePolicy(sizePolicy);

        gridLayout->addWidget(button_age_juvenile, 0, 2, 1, 1);

        button_age_immature = new QToolButton(groupbox_age);
        buttongroup_age->addButton(button_age_immature);
        button_age_immature->setObjectName(QString::fromUtf8("button_age_immature"));
        sizePolicy.setHeightForWidth(button_age_immature->sizePolicy().hasHeightForWidth());
        button_age_immature->setSizePolicy(sizePolicy);

        gridLayout->addWidget(button_age_immature, 0, 1, 1, 1);

        combobox_age_years = new QComboBox(groupbox_age);
        combobox_age_years->setObjectName(QString::fromUtf8("combobox_age_years"));

        gridLayout->addWidget(combobox_age_years, 1, 0, 1, 3);


        verticalLayout->addWidget(groupbox_age);

        widget = new QWidget(CensusBird);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupbox_sex = new QGroupBox(widget);
        groupbox_sex->setObjectName(QString::fromUtf8("groupbox_sex"));
        groupbox_sex->setCheckable(true);
        horizontalLayout_3 = new QHBoxLayout(groupbox_sex);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(6, 6, 6, 6);
        button_male = new QToolButton(groupbox_sex);
        buttongroup_sex = new QButtonGroup(CensusBird);
        buttongroup_sex->setObjectName(QString::fromUtf8("buttongroup_sex"));
        buttongroup_sex->addButton(button_male);
        button_male->setObjectName(QString::fromUtf8("button_male"));
        sizePolicy.setHeightForWidth(button_male->sizePolicy().hasHeightForWidth());
        button_male->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(button_male);

        button_female = new QToolButton(groupbox_sex);
        buttongroup_sex->addButton(button_female);
        button_female->setObjectName(QString::fromUtf8("button_female"));
        sizePolicy.setHeightForWidth(button_female->sizePolicy().hasHeightForWidth());
        button_female->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(button_female);


        horizontalLayout_4->addWidget(groupbox_sex);

        groupbox_plumage = new QGroupBox(widget);
        groupbox_plumage->setObjectName(QString::fromUtf8("groupbox_plumage"));
        groupbox_plumage->setCheckable(true);
        horizontalLayout_5 = new QHBoxLayout(groupbox_plumage);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        combobox_plumage = new QComboBox(groupbox_plumage);
        combobox_plumage->setObjectName(QString::fromUtf8("combobox_plumage"));

        horizontalLayout_5->addWidget(combobox_plumage);


        horizontalLayout_4->addWidget(groupbox_plumage);


        verticalLayout->addWidget(widget);

        groupbox_measurement = new QGroupBox(CensusBird);
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

        groupbox_stuk4 = new QGroupBox(CensusBird);
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

        groupbox_groups = new QGroupBox(CensusBird);
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

        groubbox_remarks = new QGroupBox(CensusBird);
        groubbox_remarks->setObjectName(QString::fromUtf8("groubbox_remarks"));
        horizontalLayout_9 = new QHBoxLayout(groubbox_remarks);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        text_remarks = new QPlainTextEdit(groubbox_remarks);
        text_remarks->setObjectName(QString::fromUtf8("text_remarks"));

        horizontalLayout_9->addWidget(text_remarks);


        verticalLayout->addWidget(groubbox_remarks);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(CensusBird);

        QMetaObject::connectSlotsByName(CensusBird);
    } // setupUi

    void retranslateUi(QFrame *CensusBird)
    {
        CensusBird->setWindowTitle(QApplication::translate("CensusBird", "Frame", 0, QApplication::UnicodeUTF8));
        groupbox_name->setTitle(QApplication::translate("CensusBird", "Name des Objektes", 0, QApplication::UnicodeUTF8));
        groupbox_confidence->setTitle(QApplication::translate("CensusBird", "Bestimmungssicherheit", 0, QApplication::UnicodeUTF8));
        button_confidence_1->setText(QApplication::translate("CensusBird", "sicher", 0, QApplication::UnicodeUTF8));
        button_confidence_1->setProperty("dbvalue", QVariant(QApplication::translate("CensusBird", "1", 0, QApplication::UnicodeUTF8)));
        button_confidence_2->setText(QApplication::translate("CensusBird", "sehr wahrscheinlich", 0, QApplication::UnicodeUTF8));
        button_confidence_2->setProperty("dbvalue", QVariant(QApplication::translate("CensusBird", "2", 0, QApplication::UnicodeUTF8)));
        button_confidence_3->setText(QApplication::translate("CensusBird", "m\303\266glich", 0, QApplication::UnicodeUTF8));
        button_confidence_3->setProperty("dbvalue", QVariant(QApplication::translate("CensusBird", "3", 0, QApplication::UnicodeUTF8)));
        button_confidence_4->setText(QApplication::translate("CensusBird", "potenziell", 0, QApplication::UnicodeUTF8));
        button_confidence_4->setProperty("dbvalue", QVariant(QApplication::translate("CensusBird", "4", 0, QApplication::UnicodeUTF8)));
        groupbox_behaviour->setTitle(QApplication::translate("CensusBird", "Verhalten", 0, QApplication::UnicodeUTF8));
        button_behaviour_swim->setText(QApplication::translate("CensusBird", "schwimmend", 0, QApplication::UnicodeUTF8));
        button_behaviour_swim->setProperty("dbvalue", QVariant(QApplication::translate("CensusBird", "SWIM", 0, QApplication::UnicodeUTF8)));
        button_behaviour_fly->setText(QApplication::translate("CensusBird", "fliegend", 0, QApplication::UnicodeUTF8));
        button_behaviour_fly->setProperty("dbvalue", QVariant(QApplication::translate("CensusBird", "FLY", 0, QApplication::UnicodeUTF8)));
        button_behaviour_dive->setText(QApplication::translate("CensusBird", "tauchend", 0, QApplication::UnicodeUTF8));
        button_behaviour_dive->setProperty("dbvalue", QVariant(QApplication::translate("CensusBird", "DIVE", 0, QApplication::UnicodeUTF8)));
        groupbox_age->setTitle(QApplication::translate("CensusBird", "Alter", 0, QApplication::UnicodeUTF8));
        button_age_adult->setText(QApplication::translate("CensusBird", "adult", 0, QApplication::UnicodeUTF8));
        button_age_adult->setProperty("dbvalue", QVariant(QApplication::translate("CensusBird", "ADU", 0, QApplication::UnicodeUTF8)));
        button_age_juvenile->setText(QApplication::translate("CensusBird", "juvenil", 0, QApplication::UnicodeUTF8));
        button_age_juvenile->setProperty("dbvalue", QVariant(QApplication::translate("CensusBird", "JUV", 0, QApplication::UnicodeUTF8)));
        button_age_immature->setText(QApplication::translate("CensusBird", "immatur", 0, QApplication::UnicodeUTF8));
        button_age_immature->setProperty("dbvalue", QVariant(QApplication::translate("CensusBird", "IMM", 0, QApplication::UnicodeUTF8)));
        groupbox_sex->setTitle(QApplication::translate("CensusBird", "Geschlecht", 0, QApplication::UnicodeUTF8));
        button_male->setText(QApplication::translate("CensusBird", "m\303\244nnlich", 0, QApplication::UnicodeUTF8));
        button_male->setProperty("dbvalue", QVariant(QApplication::translate("CensusBird", "M", 0, QApplication::UnicodeUTF8)));
        button_female->setText(QApplication::translate("CensusBird", "weiblich", 0, QApplication::UnicodeUTF8));
        button_female->setProperty("dbvalue", QVariant(QApplication::translate("CensusBird", "F", 0, QApplication::UnicodeUTF8)));
        groupbox_plumage->setTitle(QApplication::translate("CensusBird", "Gefieder", 0, QApplication::UnicodeUTF8));
        groupbox_measurement->setTitle(QApplication::translate("CensusBird", "Messungen", 0, QApplication::UnicodeUTF8));
        button_length->setText(QApplication::translate("CensusBird", "L\303\244nge", 0, QApplication::UnicodeUTF8));
        label_length->setText(QString());
        button_width->setText(QApplication::translate("CensusBird", "Breite", 0, QApplication::UnicodeUTF8));
        label_width->setText(QString());
        groupbox_stuk4->setTitle(QApplication::translate("CensusBird", "Stuk4 Codes", 0, QApplication::UnicodeUTF8));
        button_stuk4_assoziations->setText(QApplication::translate("CensusBird", "Assoziationen", 0, QApplication::UnicodeUTF8));
        label_stuk4_assoziations->setText(QString());
        button_stuk4_behaviour->setText(QApplication::translate("CensusBird", "Verhalten", 0, QApplication::UnicodeUTF8));
        label_stuk4_behaviour->setText(QString());
        groupbox_groups->setTitle(QApplication::translate("CensusBird", "Gruppenbestimmung", 0, QApplication::UnicodeUTF8));
        button_family->setText(QApplication::translate("CensusBird", "Familie", 0, QApplication::UnicodeUTF8));
        label_family->setText(QString());
        button_group->setText(QApplication::translate("CensusBird", "Gruppe", 0, QApplication::UnicodeUTF8));
        label_group->setText(QString());
        groubbox_remarks->setTitle(QApplication::translate("CensusBird", "Bemerkung", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CensusBird: public Ui_CensusBird {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENSUSBIRD_H
