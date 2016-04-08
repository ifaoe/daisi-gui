/********************************************************************************
** Form generated from reading UI file 'widget_census.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_CENSUS_H
#define UI_WIDGET_CENSUS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CensusWidget
{
public:
    QVBoxLayout *verticalLayout_6;
    QFrame *user_frame;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *cmbUsers;
    QToolButton *button_user_select;
    QToolButton *button_user_switch;
    QToolButton *button_user_default;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chbSaveCensus;
    QLabel *label_user_status;
    QTabWidget *wdgTabTypes;
    QWidget *tabBird;
    QGridLayout *gridLayout_4;
    QGroupBox *group_box_plumage;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *combo_box_plumage;
    QGroupBox *gbxBirdAge;
    QGridLayout *gridLayout_6;
    QToolButton *rbBirdAgeImmat;
    QToolButton *rbBirdAgeAdult;
    QToolButton *rbBirdAgeJuv;
    QComboBox *cmb_bird_age;
    QGroupBox *gbxBirdBehavior;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *rbBirdBehaveFly;
    QToolButton *rbBirdBehaveSwim;
    QToolButton *rbBirdBehaveDive;
    QGroupBox *gbxBirdGender;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *rbBirdMale;
    QToolButton *rbBirdFemale;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *cmbBird;
    QGroupBox *gbxBirdQuality;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *rbBirdQual1;
    QToolButton *rbBirdQual2;
    QToolButton *rbBirdQual3;
    QToolButton *rbBirdQual4;
    QWidget *tabMammal;
    QVBoxLayout *layout_mammal_census;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_11;
    QComboBox *cmbMammal;
    QGroupBox *gbxMammalQuality;
    QHBoxLayout *horizontalLayout_12;
    QToolButton *rbMammalQual1;
    QToolButton *rbMammalQual2;
    QToolButton *rbMammalQual3;
    QToolButton *rbMammalQual4;
    QGroupBox *gbxMammalBehaviour;
    QHBoxLayout *horizontalLayout_13;
    QToolButton *rbMammalBehaveOver;
    QToolButton *rbMammalBehaveUnder;
    QToolButton *radio_button_not_visible;
    QGroupBox *gbxMammalAge;
    QHBoxLayout *horizontalLayout_14;
    QToolButton *rbMammalAgeAdult;
    QToolButton *rbMammalAgeJuv;
    QSpacerItem *verticalSpacer;
    QWidget *tabAnthro;
    QVBoxLayout *verticalLayout_11;
    QGroupBox *gbxAnthroName;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *cmbAnthroName;
    QGroupBox *gbxAnthroQuality;
    QHBoxLayout *horizontalLayout_17;
    QToolButton *rbAnthroQual1;
    QToolButton *rbAnthroQual2;
    QToolButton *rbAnthroQual3;
    QToolButton *rbAnthroQual4;
    QSpacerItem *verticalSpacer_4;
    QWidget *tab_misc;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *gbx_misc_name;
    QHBoxLayout *horizontalLayout;
    QComboBox *cmb_misc_name;
    QGroupBox *gbx_misc_qual;
    QHBoxLayout *horizontalLayout_18;
    QToolButton *rbutton_misc_qual_1;
    QToolButton *rbutton_misc_qual_2;
    QToolButton *rbutton_misc_qual_3;
    QToolButton *rbutton_misc_qual_4;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_nosight;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *gbxNoSightQuality;
    QHBoxLayout *horizontalLayout_19;
    QToolButton *rbNoSightQual1;
    QToolButton *rbNoSightQual2;
    QToolButton *rbNoSightQual3;
    QToolButton *rbNoSightQual4;
    QSpacerItem *verticalSpacer_5;
    QFrame *frame_shared;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupbox_size;
    QHBoxLayout *horizontalLayout_10;
    QToolButton *button_width;
    QLabel *label;
    QLabel *label_width;
    QToolButton *button_length;
    QLabel *label_2;
    QLabel *label_length;
    QGroupBox *groupbox_stuk4;
    QHBoxLayout *horizontalLayout_16;
    QToolButton *toolbutton_behaviour;
    QLabel *label_behaviour;
    QLabel *text_behaviour;
    QToolButton *toolbutton_associations;
    QLabel *label_associations;
    QLabel *text_associations;
    QGroupBox *groupbox_group_ids;
    QHBoxLayout *horizontalLayout_9;
    QToolButton *toolbutton_family;
    QLabel *label_family;
    QLabel *text_family;
    QCheckBox *checkbox_image_quality;
    QFrame *frame_remarks;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *textedit_remarks;
    QFrame *frame_save;
    QGridLayout *gridLayout_3;
    QPushButton *btnSave;
    QPushButton *btnDelete;
    QButtonGroup *buttongroup_bird_sex;
    QButtonGroup *buttongroup_mammal_confidence;
    QButtonGroup *buttongroup_nosight_confidence;
    QButtonGroup *buttongroup_anthro_confidence;
    QButtonGroup *buttongroup_bird_behaviour;
    QButtonGroup *buttongroup_mammal_behaviour;
    QButtonGroup *buttongroup_misc_confidence;
    QButtonGroup *buttongroup_mammal_age;
    QButtonGroup *buttongroup_bird_confidence;
    QButtonGroup *buttongroup_bird_age;

    void setupUi(QFrame *CensusWidget)
    {
        if (CensusWidget->objectName().isEmpty())
            CensusWidget->setObjectName(QString::fromUtf8("CensusWidget"));
        CensusWidget->resize(481, 854);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CensusWidget->sizePolicy().hasHeightForWidth());
        CensusWidget->setSizePolicy(sizePolicy);
        CensusWidget->setMaximumSize(QSize(481, 16777215));
        CensusWidget->setFrameShape(QFrame::StyledPanel);
        CensusWidget->setFrameShadow(QFrame::Sunken);
        verticalLayout_6 = new QVBoxLayout(CensusWidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        user_frame = new QFrame(CensusWidget);
        user_frame->setObjectName(QString::fromUtf8("user_frame"));
        user_frame->setFrameShape(QFrame::NoFrame);
        user_frame->setFrameShadow(QFrame::Plain);
        verticalLayout_7 = new QVBoxLayout(user_frame);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(user_frame);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        cmbUsers = new QComboBox(frame);
        cmbUsers->setObjectName(QString::fromUtf8("cmbUsers"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmbUsers->sizePolicy().hasHeightForWidth());
        cmbUsers->setSizePolicy(sizePolicy1);
        cmbUsers->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_3->addWidget(cmbUsers);

        button_user_select = new QToolButton(frame);
        button_user_select->setObjectName(QString::fromUtf8("button_user_select"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("dialog-ok");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        button_user_select->setIcon(icon);

        horizontalLayout_3->addWidget(button_user_select);

        button_user_switch = new QToolButton(frame);
        button_user_switch->setObjectName(QString::fromUtf8("button_user_switch"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("security-high");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        button_user_switch->setIcon(icon1);

        horizontalLayout_3->addWidget(button_user_switch);

        button_user_default = new QToolButton(frame);
        button_user_default->setObjectName(QString::fromUtf8("button_user_default"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("security-low");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        button_user_default->setIcon(icon2);

        horizontalLayout_3->addWidget(button_user_default);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        chbSaveCensus = new QCheckBox(frame);
        chbSaveCensus->setObjectName(QString::fromUtf8("chbSaveCensus"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(chbSaveCensus->sizePolicy().hasHeightForWidth());
        chbSaveCensus->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(chbSaveCensus);


        verticalLayout_7->addWidget(frame);

        label_user_status = new QLabel(user_frame);
        label_user_status->setObjectName(QString::fromUtf8("label_user_status"));

        verticalLayout_7->addWidget(label_user_status);


        verticalLayout_6->addWidget(user_frame);

        wdgTabTypes = new QTabWidget(CensusWidget);
        wdgTabTypes->setObjectName(QString::fromUtf8("wdgTabTypes"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(wdgTabTypes->sizePolicy().hasHeightForWidth());
        wdgTabTypes->setSizePolicy(sizePolicy3);
        wdgTabTypes->setMinimumSize(QSize(0, 0));
        wdgTabTypes->setMaximumSize(QSize(16777215, 750));
        wdgTabTypes->setAutoFillBackground(true);
        wdgTabTypes->setTabShape(QTabWidget::Rounded);
        tabBird = new QWidget();
        tabBird->setObjectName(QString::fromUtf8("tabBird"));
        sizePolicy3.setHeightForWidth(tabBird->sizePolicy().hasHeightForWidth());
        tabBird->setSizePolicy(sizePolicy3);
        tabBird->setAutoFillBackground(true);
        gridLayout_4 = new QGridLayout(tabBird);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        group_box_plumage = new QGroupBox(tabBird);
        group_box_plumage->setObjectName(QString::fromUtf8("group_box_plumage"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(group_box_plumage->sizePolicy().hasHeightForWidth());
        group_box_plumage->setSizePolicy(sizePolicy4);
        group_box_plumage->setCheckable(true);
        group_box_plumage->setChecked(false);
        horizontalLayout_4 = new QHBoxLayout(group_box_plumage);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(6, -1, 6, 6);
        combo_box_plumage = new QComboBox(group_box_plumage);
        combo_box_plumage->setObjectName(QString::fromUtf8("combo_box_plumage"));

        horizontalLayout_4->addWidget(combo_box_plumage);


        gridLayout_4->addWidget(group_box_plumage, 4, 1, 1, 1);

        gbxBirdAge = new QGroupBox(tabBird);
        gbxBirdAge->setObjectName(QString::fromUtf8("gbxBirdAge"));
        gbxBirdAge->setMinimumSize(QSize(0, 0));
        gbxBirdAge->setCheckable(true);
        gbxBirdAge->setChecked(false);
        gridLayout_6 = new QGridLayout(gbxBirdAge);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(0);
        gridLayout_6->setVerticalSpacing(3);
        gridLayout_6->setContentsMargins(-1, -1, -1, 6);
        rbBirdAgeImmat = new QToolButton(gbxBirdAge);
        buttongroup_bird_age = new QButtonGroup(CensusWidget);
        buttongroup_bird_age->setObjectName(QString::fromUtf8("buttongroup_bird_age"));
        buttongroup_bird_age->addButton(rbBirdAgeImmat);
        rbBirdAgeImmat->setObjectName(QString::fromUtf8("rbBirdAgeImmat"));
        sizePolicy.setHeightForWidth(rbBirdAgeImmat->sizePolicy().hasHeightForWidth());
        rbBirdAgeImmat->setSizePolicy(sizePolicy);
        rbBirdAgeImmat->setCheckable(true);
        rbBirdAgeImmat->setAutoExclusive(true);

        gridLayout_6->addWidget(rbBirdAgeImmat, 0, 1, 1, 1);

        rbBirdAgeAdult = new QToolButton(gbxBirdAge);
        buttongroup_bird_age->addButton(rbBirdAgeAdult);
        rbBirdAgeAdult->setObjectName(QString::fromUtf8("rbBirdAgeAdult"));
        sizePolicy.setHeightForWidth(rbBirdAgeAdult->sizePolicy().hasHeightForWidth());
        rbBirdAgeAdult->setSizePolicy(sizePolicy);
        rbBirdAgeAdult->setCheckable(true);
        rbBirdAgeAdult->setChecked(true);
        rbBirdAgeAdult->setAutoExclusive(true);

        gridLayout_6->addWidget(rbBirdAgeAdult, 0, 0, 1, 1);

        rbBirdAgeJuv = new QToolButton(gbxBirdAge);
        buttongroup_bird_age->addButton(rbBirdAgeJuv);
        rbBirdAgeJuv->setObjectName(QString::fromUtf8("rbBirdAgeJuv"));
        sizePolicy.setHeightForWidth(rbBirdAgeJuv->sizePolicy().hasHeightForWidth());
        rbBirdAgeJuv->setSizePolicy(sizePolicy);
        rbBirdAgeJuv->setCheckable(true);
        rbBirdAgeJuv->setAutoExclusive(true);

        gridLayout_6->addWidget(rbBirdAgeJuv, 0, 2, 1, 1);

        cmb_bird_age = new QComboBox(gbxBirdAge);
        cmb_bird_age->setObjectName(QString::fromUtf8("cmb_bird_age"));

        gridLayout_6->addWidget(cmb_bird_age, 1, 0, 1, 3);


        gridLayout_4->addWidget(gbxBirdAge, 3, 0, 1, 2);

        gbxBirdBehavior = new QGroupBox(tabBird);
        gbxBirdBehavior->setObjectName(QString::fromUtf8("gbxBirdBehavior"));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(gbxBirdBehavior->sizePolicy().hasHeightForWidth());
        gbxBirdBehavior->setSizePolicy(sizePolicy5);
        gbxBirdBehavior->setMinimumSize(QSize(0, 0));
        gbxBirdBehavior->setCheckable(false);
        horizontalLayout_6 = new QHBoxLayout(gbxBirdBehavior);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, -1, 6);
        rbBirdBehaveFly = new QToolButton(gbxBirdBehavior);
        buttongroup_bird_behaviour = new QButtonGroup(CensusWidget);
        buttongroup_bird_behaviour->setObjectName(QString::fromUtf8("buttongroup_bird_behaviour"));
        buttongroup_bird_behaviour->addButton(rbBirdBehaveFly);
        rbBirdBehaveFly->setObjectName(QString::fromUtf8("rbBirdBehaveFly"));
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(1);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(rbBirdBehaveFly->sizePolicy().hasHeightForWidth());
        rbBirdBehaveFly->setSizePolicy(sizePolicy6);
        rbBirdBehaveFly->setCheckable(true);
        rbBirdBehaveFly->setChecked(true);
        rbBirdBehaveFly->setAutoExclusive(true);

        horizontalLayout_6->addWidget(rbBirdBehaveFly);

        rbBirdBehaveSwim = new QToolButton(gbxBirdBehavior);
        buttongroup_bird_behaviour->addButton(rbBirdBehaveSwim);
        rbBirdBehaveSwim->setObjectName(QString::fromUtf8("rbBirdBehaveSwim"));
        sizePolicy6.setHeightForWidth(rbBirdBehaveSwim->sizePolicy().hasHeightForWidth());
        rbBirdBehaveSwim->setSizePolicy(sizePolicy6);
        rbBirdBehaveSwim->setCheckable(true);
        rbBirdBehaveSwim->setAutoExclusive(true);

        horizontalLayout_6->addWidget(rbBirdBehaveSwim);

        rbBirdBehaveDive = new QToolButton(gbxBirdBehavior);
        buttongroup_bird_behaviour->addButton(rbBirdBehaveDive);
        rbBirdBehaveDive->setObjectName(QString::fromUtf8("rbBirdBehaveDive"));
        sizePolicy2.setHeightForWidth(rbBirdBehaveDive->sizePolicy().hasHeightForWidth());
        rbBirdBehaveDive->setSizePolicy(sizePolicy2);
        rbBirdBehaveDive->setCheckable(true);
        rbBirdBehaveDive->setAutoExclusive(true);

        horizontalLayout_6->addWidget(rbBirdBehaveDive);


        gridLayout_4->addWidget(gbxBirdBehavior, 2, 0, 1, 2);

        gbxBirdGender = new QGroupBox(tabBird);
        gbxBirdGender->setObjectName(QString::fromUtf8("gbxBirdGender"));
        sizePolicy6.setHeightForWidth(gbxBirdGender->sizePolicy().hasHeightForWidth());
        gbxBirdGender->setSizePolicy(sizePolicy6);
        gbxBirdGender->setAutoFillBackground(false);
        gbxBirdGender->setFlat(false);
        gbxBirdGender->setCheckable(true);
        gbxBirdGender->setChecked(false);
        horizontalLayout_5 = new QHBoxLayout(gbxBirdGender);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 6);
        rbBirdMale = new QToolButton(gbxBirdGender);
        buttongroup_bird_sex = new QButtonGroup(CensusWidget);
        buttongroup_bird_sex->setObjectName(QString::fromUtf8("buttongroup_bird_sex"));
        buttongroup_bird_sex->addButton(rbBirdMale);
        rbBirdMale->setObjectName(QString::fromUtf8("rbBirdMale"));
        sizePolicy.setHeightForWidth(rbBirdMale->sizePolicy().hasHeightForWidth());
        rbBirdMale->setSizePolicy(sizePolicy);
        rbBirdMale->setCheckable(true);
        rbBirdMale->setChecked(true);
        rbBirdMale->setAutoExclusive(true);

        horizontalLayout_5->addWidget(rbBirdMale);

        rbBirdFemale = new QToolButton(gbxBirdGender);
        buttongroup_bird_sex->addButton(rbBirdFemale);
        rbBirdFemale->setObjectName(QString::fromUtf8("rbBirdFemale"));
        sizePolicy.setHeightForWidth(rbBirdFemale->sizePolicy().hasHeightForWidth());
        rbBirdFemale->setSizePolicy(sizePolicy);
        rbBirdFemale->setCheckable(true);
        rbBirdFemale->setAutoExclusive(true);

        horizontalLayout_5->addWidget(rbBirdFemale);


        gridLayout_4->addWidget(gbxBirdGender, 4, 0, 1, 1);

        groupBox_2 = new QGroupBox(tabBird);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_8 = new QHBoxLayout(groupBox_2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        cmbBird = new QComboBox(groupBox_2);
        cmbBird->setObjectName(QString::fromUtf8("cmbBird"));
        cmbBird->setEditable(false);

        horizontalLayout_8->addWidget(cmbBird);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 2);

        gbxBirdQuality = new QGroupBox(tabBird);
        gbxBirdQuality->setObjectName(QString::fromUtf8("gbxBirdQuality"));
        horizontalLayout_7 = new QHBoxLayout(gbxBirdQuality);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, -1, -1, 6);
        rbBirdQual1 = new QToolButton(gbxBirdQuality);
        buttongroup_bird_confidence = new QButtonGroup(CensusWidget);
        buttongroup_bird_confidence->setObjectName(QString::fromUtf8("buttongroup_bird_confidence"));
        buttongroup_bird_confidence->addButton(rbBirdQual1);
        rbBirdQual1->setObjectName(QString::fromUtf8("rbBirdQual1"));
        sizePolicy.setHeightForWidth(rbBirdQual1->sizePolicy().hasHeightForWidth());
        rbBirdQual1->setSizePolicy(sizePolicy);
        rbBirdQual1->setCheckable(true);
        rbBirdQual1->setChecked(true);
        rbBirdQual1->setAutoExclusive(true);

        horizontalLayout_7->addWidget(rbBirdQual1);

        rbBirdQual2 = new QToolButton(gbxBirdQuality);
        buttongroup_bird_confidence->addButton(rbBirdQual2);
        rbBirdQual2->setObjectName(QString::fromUtf8("rbBirdQual2"));
        sizePolicy.setHeightForWidth(rbBirdQual2->sizePolicy().hasHeightForWidth());
        rbBirdQual2->setSizePolicy(sizePolicy);
        rbBirdQual2->setCheckable(true);
        rbBirdQual2->setAutoExclusive(true);

        horizontalLayout_7->addWidget(rbBirdQual2);

        rbBirdQual3 = new QToolButton(gbxBirdQuality);
        buttongroup_bird_confidence->addButton(rbBirdQual3);
        rbBirdQual3->setObjectName(QString::fromUtf8("rbBirdQual3"));
        sizePolicy.setHeightForWidth(rbBirdQual3->sizePolicy().hasHeightForWidth());
        rbBirdQual3->setSizePolicy(sizePolicy);
        rbBirdQual3->setCheckable(true);
        rbBirdQual3->setAutoExclusive(true);

        horizontalLayout_7->addWidget(rbBirdQual3);

        rbBirdQual4 = new QToolButton(gbxBirdQuality);
        buttongroup_bird_confidence->addButton(rbBirdQual4);
        rbBirdQual4->setObjectName(QString::fromUtf8("rbBirdQual4"));
        sizePolicy.setHeightForWidth(rbBirdQual4->sizePolicy().hasHeightForWidth());
        rbBirdQual4->setSizePolicy(sizePolicy);
        rbBirdQual4->setCheckable(true);
        rbBirdQual4->setAutoExclusive(true);

        horizontalLayout_7->addWidget(rbBirdQual4);


        gridLayout_4->addWidget(gbxBirdQuality, 1, 0, 1, 2);

        wdgTabTypes->addTab(tabBird, QString());
        tabMammal = new QWidget();
        tabMammal->setObjectName(QString::fromUtf8("tabMammal"));
        sizePolicy3.setHeightForWidth(tabMammal->sizePolicy().hasHeightForWidth());
        tabMammal->setSizePolicy(sizePolicy3);
        tabMammal->setAutoFillBackground(true);
        layout_mammal_census = new QVBoxLayout(tabMammal);
        layout_mammal_census->setSpacing(0);
        layout_mammal_census->setObjectName(QString::fromUtf8("layout_mammal_census"));
        groupBox = new QGroupBox(tabMammal);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_11 = new QHBoxLayout(groupBox);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        cmbMammal = new QComboBox(groupBox);
        cmbMammal->setObjectName(QString::fromUtf8("cmbMammal"));
        cmbMammal->setEditable(false);

        horizontalLayout_11->addWidget(cmbMammal);


        layout_mammal_census->addWidget(groupBox);

        gbxMammalQuality = new QGroupBox(tabMammal);
        gbxMammalQuality->setObjectName(QString::fromUtf8("gbxMammalQuality"));
        horizontalLayout_12 = new QHBoxLayout(gbxMammalQuality);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(-1, -1, -1, 6);
        rbMammalQual1 = new QToolButton(gbxMammalQuality);
        buttongroup_mammal_confidence = new QButtonGroup(CensusWidget);
        buttongroup_mammal_confidence->setObjectName(QString::fromUtf8("buttongroup_mammal_confidence"));
        buttongroup_mammal_confidence->addButton(rbMammalQual1);
        rbMammalQual1->setObjectName(QString::fromUtf8("rbMammalQual1"));
        sizePolicy.setHeightForWidth(rbMammalQual1->sizePolicy().hasHeightForWidth());
        rbMammalQual1->setSizePolicy(sizePolicy);
        rbMammalQual1->setCheckable(true);
        rbMammalQual1->setChecked(true);
        rbMammalQual1->setAutoExclusive(true);

        horizontalLayout_12->addWidget(rbMammalQual1);

        rbMammalQual2 = new QToolButton(gbxMammalQuality);
        buttongroup_mammal_confidence->addButton(rbMammalQual2);
        rbMammalQual2->setObjectName(QString::fromUtf8("rbMammalQual2"));
        sizePolicy.setHeightForWidth(rbMammalQual2->sizePolicy().hasHeightForWidth());
        rbMammalQual2->setSizePolicy(sizePolicy);
        rbMammalQual2->setCheckable(true);
        rbMammalQual2->setAutoExclusive(true);

        horizontalLayout_12->addWidget(rbMammalQual2);

        rbMammalQual3 = new QToolButton(gbxMammalQuality);
        buttongroup_mammal_confidence->addButton(rbMammalQual3);
        rbMammalQual3->setObjectName(QString::fromUtf8("rbMammalQual3"));
        sizePolicy.setHeightForWidth(rbMammalQual3->sizePolicy().hasHeightForWidth());
        rbMammalQual3->setSizePolicy(sizePolicy);
        rbMammalQual3->setCheckable(true);
        rbMammalQual3->setAutoExclusive(true);

        horizontalLayout_12->addWidget(rbMammalQual3);

        rbMammalQual4 = new QToolButton(gbxMammalQuality);
        buttongroup_mammal_confidence->addButton(rbMammalQual4);
        rbMammalQual4->setObjectName(QString::fromUtf8("rbMammalQual4"));
        sizePolicy.setHeightForWidth(rbMammalQual4->sizePolicy().hasHeightForWidth());
        rbMammalQual4->setSizePolicy(sizePolicy);
        rbMammalQual4->setCheckable(true);
        rbMammalQual4->setAutoExclusive(true);

        horizontalLayout_12->addWidget(rbMammalQual4);


        layout_mammal_census->addWidget(gbxMammalQuality);

        gbxMammalBehaviour = new QGroupBox(tabMammal);
        gbxMammalBehaviour->setObjectName(QString::fromUtf8("gbxMammalBehaviour"));
        gbxMammalBehaviour->setCheckable(false);
        gbxMammalBehaviour->setChecked(false);
        horizontalLayout_13 = new QHBoxLayout(gbxMammalBehaviour);
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(-1, -1, -1, 6);
        rbMammalBehaveOver = new QToolButton(gbxMammalBehaviour);
        buttongroup_mammal_behaviour = new QButtonGroup(CensusWidget);
        buttongroup_mammal_behaviour->setObjectName(QString::fromUtf8("buttongroup_mammal_behaviour"));
        buttongroup_mammal_behaviour->addButton(rbMammalBehaveOver);
        rbMammalBehaveOver->setObjectName(QString::fromUtf8("rbMammalBehaveOver"));
        sizePolicy.setHeightForWidth(rbMammalBehaveOver->sizePolicy().hasHeightForWidth());
        rbMammalBehaveOver->setSizePolicy(sizePolicy);
        rbMammalBehaveOver->setCheckable(true);
        rbMammalBehaveOver->setChecked(true);
        rbMammalBehaveOver->setAutoExclusive(true);

        horizontalLayout_13->addWidget(rbMammalBehaveOver);

        rbMammalBehaveUnder = new QToolButton(gbxMammalBehaviour);
        buttongroup_mammal_behaviour->addButton(rbMammalBehaveUnder);
        rbMammalBehaveUnder->setObjectName(QString::fromUtf8("rbMammalBehaveUnder"));
        sizePolicy.setHeightForWidth(rbMammalBehaveUnder->sizePolicy().hasHeightForWidth());
        rbMammalBehaveUnder->setSizePolicy(sizePolicy);
        rbMammalBehaveUnder->setCheckable(true);
        rbMammalBehaveUnder->setAutoExclusive(true);

        horizontalLayout_13->addWidget(rbMammalBehaveUnder);

        radio_button_not_visible = new QToolButton(gbxMammalBehaviour);
        buttongroup_mammal_behaviour->addButton(radio_button_not_visible);
        radio_button_not_visible->setObjectName(QString::fromUtf8("radio_button_not_visible"));
        sizePolicy.setHeightForWidth(radio_button_not_visible->sizePolicy().hasHeightForWidth());
        radio_button_not_visible->setSizePolicy(sizePolicy);
        radio_button_not_visible->setCheckable(true);
        radio_button_not_visible->setAutoExclusive(true);

        horizontalLayout_13->addWidget(radio_button_not_visible);


        layout_mammal_census->addWidget(gbxMammalBehaviour);

        gbxMammalAge = new QGroupBox(tabMammal);
        gbxMammalAge->setObjectName(QString::fromUtf8("gbxMammalAge"));
        gbxMammalAge->setCheckable(true);
        gbxMammalAge->setChecked(false);
        horizontalLayout_14 = new QHBoxLayout(gbxMammalAge);
        horizontalLayout_14->setSpacing(0);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(-1, -1, -1, 6);
        rbMammalAgeAdult = new QToolButton(gbxMammalAge);
        buttongroup_mammal_age = new QButtonGroup(CensusWidget);
        buttongroup_mammal_age->setObjectName(QString::fromUtf8("buttongroup_mammal_age"));
        buttongroup_mammal_age->addButton(rbMammalAgeAdult);
        rbMammalAgeAdult->setObjectName(QString::fromUtf8("rbMammalAgeAdult"));
        sizePolicy.setHeightForWidth(rbMammalAgeAdult->sizePolicy().hasHeightForWidth());
        rbMammalAgeAdult->setSizePolicy(sizePolicy);
        rbMammalAgeAdult->setCheckable(true);
        rbMammalAgeAdult->setChecked(true);
        rbMammalAgeAdult->setAutoExclusive(true);

        horizontalLayout_14->addWidget(rbMammalAgeAdult);

        rbMammalAgeJuv = new QToolButton(gbxMammalAge);
        buttongroup_mammal_age->addButton(rbMammalAgeJuv);
        rbMammalAgeJuv->setObjectName(QString::fromUtf8("rbMammalAgeJuv"));
        sizePolicy.setHeightForWidth(rbMammalAgeJuv->sizePolicy().hasHeightForWidth());
        rbMammalAgeJuv->setSizePolicy(sizePolicy);
        rbMammalAgeJuv->setCheckable(true);
        rbMammalAgeJuv->setAutoExclusive(true);

        horizontalLayout_14->addWidget(rbMammalAgeJuv);


        layout_mammal_census->addWidget(gbxMammalAge);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layout_mammal_census->addItem(verticalSpacer);

        wdgTabTypes->addTab(tabMammal, QString());
        tabAnthro = new QWidget();
        tabAnthro->setObjectName(QString::fromUtf8("tabAnthro"));
        sizePolicy3.setHeightForWidth(tabAnthro->sizePolicy().hasHeightForWidth());
        tabAnthro->setSizePolicy(sizePolicy3);
        tabAnthro->setAutoFillBackground(true);
        verticalLayout_11 = new QVBoxLayout(tabAnthro);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        gbxAnthroName = new QGroupBox(tabAnthro);
        gbxAnthroName->setObjectName(QString::fromUtf8("gbxAnthroName"));
        horizontalLayout_2 = new QHBoxLayout(gbxAnthroName);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cmbAnthroName = new QComboBox(gbxAnthroName);
        cmbAnthroName->setObjectName(QString::fromUtf8("cmbAnthroName"));

        horizontalLayout_2->addWidget(cmbAnthroName);


        verticalLayout_11->addWidget(gbxAnthroName);

        gbxAnthroQuality = new QGroupBox(tabAnthro);
        gbxAnthroQuality->setObjectName(QString::fromUtf8("gbxAnthroQuality"));
        horizontalLayout_17 = new QHBoxLayout(gbxAnthroQuality);
        horizontalLayout_17->setSpacing(0);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        rbAnthroQual1 = new QToolButton(gbxAnthroQuality);
        buttongroup_anthro_confidence = new QButtonGroup(CensusWidget);
        buttongroup_anthro_confidence->setObjectName(QString::fromUtf8("buttongroup_anthro_confidence"));
        buttongroup_anthro_confidence->addButton(rbAnthroQual1);
        rbAnthroQual1->setObjectName(QString::fromUtf8("rbAnthroQual1"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(rbAnthroQual1->sizePolicy().hasHeightForWidth());
        rbAnthroQual1->setSizePolicy(sizePolicy7);
        rbAnthroQual1->setCheckable(true);
        rbAnthroQual1->setChecked(true);
        rbAnthroQual1->setAutoExclusive(true);

        horizontalLayout_17->addWidget(rbAnthroQual1);

        rbAnthroQual2 = new QToolButton(gbxAnthroQuality);
        buttongroup_anthro_confidence->addButton(rbAnthroQual2);
        rbAnthroQual2->setObjectName(QString::fromUtf8("rbAnthroQual2"));
        sizePolicy7.setHeightForWidth(rbAnthroQual2->sizePolicy().hasHeightForWidth());
        rbAnthroQual2->setSizePolicy(sizePolicy7);
        rbAnthroQual2->setCheckable(true);
        rbAnthroQual2->setAutoExclusive(true);

        horizontalLayout_17->addWidget(rbAnthroQual2);

        rbAnthroQual3 = new QToolButton(gbxAnthroQuality);
        buttongroup_anthro_confidence->addButton(rbAnthroQual3);
        rbAnthroQual3->setObjectName(QString::fromUtf8("rbAnthroQual3"));
        sizePolicy7.setHeightForWidth(rbAnthroQual3->sizePolicy().hasHeightForWidth());
        rbAnthroQual3->setSizePolicy(sizePolicy7);
        rbAnthroQual3->setCheckable(true);
        rbAnthroQual3->setAutoExclusive(true);

        horizontalLayout_17->addWidget(rbAnthroQual3);

        rbAnthroQual4 = new QToolButton(gbxAnthroQuality);
        buttongroup_anthro_confidence->addButton(rbAnthroQual4);
        rbAnthroQual4->setObjectName(QString::fromUtf8("rbAnthroQual4"));
        sizePolicy7.setHeightForWidth(rbAnthroQual4->sizePolicy().hasHeightForWidth());
        rbAnthroQual4->setSizePolicy(sizePolicy7);
        rbAnthroQual4->setCheckable(true);
        rbAnthroQual4->setAutoExclusive(true);

        horizontalLayout_17->addWidget(rbAnthroQual4);


        verticalLayout_11->addWidget(gbxAnthroQuality);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_4);

        wdgTabTypes->addTab(tabAnthro, QString());
        tab_misc = new QWidget();
        tab_misc->setObjectName(QString::fromUtf8("tab_misc"));
        tab_misc->setAutoFillBackground(true);
        verticalLayout_3 = new QVBoxLayout(tab_misc);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gbx_misc_name = new QGroupBox(tab_misc);
        gbx_misc_name->setObjectName(QString::fromUtf8("gbx_misc_name"));
        horizontalLayout = new QHBoxLayout(gbx_misc_name);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cmb_misc_name = new QComboBox(gbx_misc_name);
        cmb_misc_name->setObjectName(QString::fromUtf8("cmb_misc_name"));

        horizontalLayout->addWidget(cmb_misc_name);


        verticalLayout_3->addWidget(gbx_misc_name);

        gbx_misc_qual = new QGroupBox(tab_misc);
        gbx_misc_qual->setObjectName(QString::fromUtf8("gbx_misc_qual"));
        horizontalLayout_18 = new QHBoxLayout(gbx_misc_qual);
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        rbutton_misc_qual_1 = new QToolButton(gbx_misc_qual);
        buttongroup_misc_confidence = new QButtonGroup(CensusWidget);
        buttongroup_misc_confidence->setObjectName(QString::fromUtf8("buttongroup_misc_confidence"));
        buttongroup_misc_confidence->addButton(rbutton_misc_qual_1);
        rbutton_misc_qual_1->setObjectName(QString::fromUtf8("rbutton_misc_qual_1"));
        sizePolicy7.setHeightForWidth(rbutton_misc_qual_1->sizePolicy().hasHeightForWidth());
        rbutton_misc_qual_1->setSizePolicy(sizePolicy7);
        rbutton_misc_qual_1->setCheckable(true);
        rbutton_misc_qual_1->setChecked(true);
        rbutton_misc_qual_1->setAutoExclusive(true);

        horizontalLayout_18->addWidget(rbutton_misc_qual_1);

        rbutton_misc_qual_2 = new QToolButton(gbx_misc_qual);
        buttongroup_misc_confidence->addButton(rbutton_misc_qual_2);
        rbutton_misc_qual_2->setObjectName(QString::fromUtf8("rbutton_misc_qual_2"));
        sizePolicy7.setHeightForWidth(rbutton_misc_qual_2->sizePolicy().hasHeightForWidth());
        rbutton_misc_qual_2->setSizePolicy(sizePolicy7);
        rbutton_misc_qual_2->setCheckable(true);
        rbutton_misc_qual_2->setAutoExclusive(true);

        horizontalLayout_18->addWidget(rbutton_misc_qual_2);

        rbutton_misc_qual_3 = new QToolButton(gbx_misc_qual);
        buttongroup_misc_confidence->addButton(rbutton_misc_qual_3);
        rbutton_misc_qual_3->setObjectName(QString::fromUtf8("rbutton_misc_qual_3"));
        sizePolicy7.setHeightForWidth(rbutton_misc_qual_3->sizePolicy().hasHeightForWidth());
        rbutton_misc_qual_3->setSizePolicy(sizePolicy7);
        rbutton_misc_qual_3->setCheckable(true);
        rbutton_misc_qual_3->setAutoExclusive(true);

        horizontalLayout_18->addWidget(rbutton_misc_qual_3);

        rbutton_misc_qual_4 = new QToolButton(gbx_misc_qual);
        buttongroup_misc_confidence->addButton(rbutton_misc_qual_4);
        rbutton_misc_qual_4->setObjectName(QString::fromUtf8("rbutton_misc_qual_4"));
        sizePolicy7.setHeightForWidth(rbutton_misc_qual_4->sizePolicy().hasHeightForWidth());
        rbutton_misc_qual_4->setSizePolicy(sizePolicy7);
        rbutton_misc_qual_4->setCheckable(true);
        rbutton_misc_qual_4->setAutoExclusive(true);

        horizontalLayout_18->addWidget(rbutton_misc_qual_4);


        verticalLayout_3->addWidget(gbx_misc_qual);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        wdgTabTypes->addTab(tab_misc, QString());
        tab_nosight = new QWidget();
        tab_nosight->setObjectName(QString::fromUtf8("tab_nosight"));
        tab_nosight->setAutoFillBackground(true);
        verticalLayout_4 = new QVBoxLayout(tab_nosight);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gbxNoSightQuality = new QGroupBox(tab_nosight);
        gbxNoSightQuality->setObjectName(QString::fromUtf8("gbxNoSightQuality"));
        horizontalLayout_19 = new QHBoxLayout(gbxNoSightQuality);
        horizontalLayout_19->setSpacing(0);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        rbNoSightQual1 = new QToolButton(gbxNoSightQuality);
        buttongroup_nosight_confidence = new QButtonGroup(CensusWidget);
        buttongroup_nosight_confidence->setObjectName(QString::fromUtf8("buttongroup_nosight_confidence"));
        buttongroup_nosight_confidence->addButton(rbNoSightQual1);
        rbNoSightQual1->setObjectName(QString::fromUtf8("rbNoSightQual1"));
        sizePolicy7.setHeightForWidth(rbNoSightQual1->sizePolicy().hasHeightForWidth());
        rbNoSightQual1->setSizePolicy(sizePolicy7);
        rbNoSightQual1->setCheckable(true);
        rbNoSightQual1->setChecked(true);
        rbNoSightQual1->setAutoExclusive(true);

        horizontalLayout_19->addWidget(rbNoSightQual1);

        rbNoSightQual2 = new QToolButton(gbxNoSightQuality);
        buttongroup_nosight_confidence->addButton(rbNoSightQual2);
        rbNoSightQual2->setObjectName(QString::fromUtf8("rbNoSightQual2"));
        sizePolicy7.setHeightForWidth(rbNoSightQual2->sizePolicy().hasHeightForWidth());
        rbNoSightQual2->setSizePolicy(sizePolicy7);
        rbNoSightQual2->setCheckable(true);
        rbNoSightQual2->setAutoExclusive(true);

        horizontalLayout_19->addWidget(rbNoSightQual2);

        rbNoSightQual3 = new QToolButton(gbxNoSightQuality);
        buttongroup_nosight_confidence->addButton(rbNoSightQual3);
        rbNoSightQual3->setObjectName(QString::fromUtf8("rbNoSightQual3"));
        sizePolicy7.setHeightForWidth(rbNoSightQual3->sizePolicy().hasHeightForWidth());
        rbNoSightQual3->setSizePolicy(sizePolicy7);
        rbNoSightQual3->setCheckable(true);
        rbNoSightQual3->setAutoExclusive(true);

        horizontalLayout_19->addWidget(rbNoSightQual3);

        rbNoSightQual4 = new QToolButton(gbxNoSightQuality);
        buttongroup_nosight_confidence->addButton(rbNoSightQual4);
        rbNoSightQual4->setObjectName(QString::fromUtf8("rbNoSightQual4"));
        sizePolicy7.setHeightForWidth(rbNoSightQual4->sizePolicy().hasHeightForWidth());
        rbNoSightQual4->setSizePolicy(sizePolicy7);
        rbNoSightQual4->setCheckable(true);
        rbNoSightQual4->setAutoExclusive(true);

        horizontalLayout_19->addWidget(rbNoSightQual4);


        verticalLayout_4->addWidget(gbxNoSightQuality);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        wdgTabTypes->addTab(tab_nosight, QString());

        verticalLayout_6->addWidget(wdgTabTypes);

        frame_shared = new QFrame(CensusWidget);
        frame_shared->setObjectName(QString::fromUtf8("frame_shared"));
        sizePolicy.setHeightForWidth(frame_shared->sizePolicy().hasHeightForWidth());
        frame_shared->setSizePolicy(sizePolicy);
        frame_shared->setFrameShape(QFrame::StyledPanel);
        frame_shared->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_shared);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        groupbox_size = new QGroupBox(frame_shared);
        groupbox_size->setObjectName(QString::fromUtf8("groupbox_size"));
        horizontalLayout_10 = new QHBoxLayout(groupbox_size);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(6, -1, 6, 6);
        button_width = new QToolButton(groupbox_size);
        button_width->setObjectName(QString::fromUtf8("button_width"));
        QSizePolicy sizePolicy8(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(button_width->sizePolicy().hasHeightForWidth());
        button_width->setSizePolicy(sizePolicy8);
        button_width->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("measure");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        button_width->setIcon(icon3);

        horizontalLayout_10->addWidget(button_width);

        label = new QLabel(groupbox_size);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_10->addWidget(label);

        label_width = new QLabel(groupbox_size);
        label_width->setObjectName(QString::fromUtf8("label_width"));

        horizontalLayout_10->addWidget(label_width);

        button_length = new QToolButton(groupbox_size);
        button_length->setObjectName(QString::fromUtf8("button_length"));
        button_length->setIcon(icon3);

        horizontalLayout_10->addWidget(button_length);

        label_2 = new QLabel(groupbox_size);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_10->addWidget(label_2);

        label_length = new QLabel(groupbox_size);
        label_length->setObjectName(QString::fromUtf8("label_length"));

        horizontalLayout_10->addWidget(label_length);


        verticalLayout->addWidget(groupbox_size);

        groupbox_stuk4 = new QGroupBox(frame_shared);
        groupbox_stuk4->setObjectName(QString::fromUtf8("groupbox_stuk4"));
        groupbox_stuk4->setCheckable(false);
        groupbox_stuk4->setChecked(false);
        horizontalLayout_16 = new QHBoxLayout(groupbox_stuk4);
        horizontalLayout_16->setSpacing(0);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(6, -1, 6, 6);
        toolbutton_behaviour = new QToolButton(groupbox_stuk4);
        toolbutton_behaviour->setObjectName(QString::fromUtf8("toolbutton_behaviour"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("view-list-text");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        toolbutton_behaviour->setIcon(icon4);

        horizontalLayout_16->addWidget(toolbutton_behaviour);

        label_behaviour = new QLabel(groupbox_stuk4);
        label_behaviour->setObjectName(QString::fromUtf8("label_behaviour"));
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(2);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(label_behaviour->sizePolicy().hasHeightForWidth());
        label_behaviour->setSizePolicy(sizePolicy9);

        horizontalLayout_16->addWidget(label_behaviour);

        text_behaviour = new QLabel(groupbox_stuk4);
        text_behaviour->setObjectName(QString::fromUtf8("text_behaviour"));
        QSizePolicy sizePolicy10(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy10.setHorizontalStretch(3);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(text_behaviour->sizePolicy().hasHeightForWidth());
        text_behaviour->setSizePolicy(sizePolicy10);

        horizontalLayout_16->addWidget(text_behaviour);

        toolbutton_associations = new QToolButton(groupbox_stuk4);
        toolbutton_associations->setObjectName(QString::fromUtf8("toolbutton_associations"));
        toolbutton_associations->setIcon(icon4);

        horizontalLayout_16->addWidget(toolbutton_associations);

        label_associations = new QLabel(groupbox_stuk4);
        label_associations->setObjectName(QString::fromUtf8("label_associations"));
        sizePolicy9.setHeightForWidth(label_associations->sizePolicy().hasHeightForWidth());
        label_associations->setSizePolicy(sizePolicy9);

        horizontalLayout_16->addWidget(label_associations);

        text_associations = new QLabel(groupbox_stuk4);
        text_associations->setObjectName(QString::fromUtf8("text_associations"));
        sizePolicy10.setHeightForWidth(text_associations->sizePolicy().hasHeightForWidth());
        text_associations->setSizePolicy(sizePolicy10);

        horizontalLayout_16->addWidget(text_associations);


        verticalLayout->addWidget(groupbox_stuk4);

        groupbox_group_ids = new QGroupBox(frame_shared);
        groupbox_group_ids->setObjectName(QString::fromUtf8("groupbox_group_ids"));
        groupbox_group_ids->setCheckable(false);
        groupbox_group_ids->setChecked(false);
        horizontalLayout_9 = new QHBoxLayout(groupbox_group_ids);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(6, -1, 6, 6);
        toolbutton_family = new QToolButton(groupbox_group_ids);
        toolbutton_family->setObjectName(QString::fromUtf8("toolbutton_family"));
        toolbutton_family->setIcon(icon4);

        horizontalLayout_9->addWidget(toolbutton_family);

        label_family = new QLabel(groupbox_group_ids);
        label_family->setObjectName(QString::fromUtf8("label_family"));
        sizePolicy.setHeightForWidth(label_family->sizePolicy().hasHeightForWidth());
        label_family->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(label_family);

        text_family = new QLabel(groupbox_group_ids);
        text_family->setObjectName(QString::fromUtf8("text_family"));
        QSizePolicy sizePolicy11(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(text_family->sizePolicy().hasHeightForWidth());
        text_family->setSizePolicy(sizePolicy11);

        horizontalLayout_9->addWidget(text_family);


        verticalLayout->addWidget(groupbox_group_ids);

        checkbox_image_quality = new QCheckBox(frame_shared);
        checkbox_image_quality->setObjectName(QString::fromUtf8("checkbox_image_quality"));

        verticalLayout->addWidget(checkbox_image_quality);


        verticalLayout_6->addWidget(frame_shared);

        frame_remarks = new QFrame(CensusWidget);
        frame_remarks->setObjectName(QString::fromUtf8("frame_remarks"));
        sizePolicy7.setHeightForWidth(frame_remarks->sizePolicy().hasHeightForWidth());
        frame_remarks->setSizePolicy(sizePolicy7);
        frame_remarks->setMinimumSize(QSize(0, 65));
        frame_remarks->setMaximumSize(QSize(16777215, 65));
        frame_remarks->setFrameShape(QFrame::StyledPanel);
        frame_remarks->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_remarks);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textedit_remarks = new QPlainTextEdit(frame_remarks);
        textedit_remarks->setObjectName(QString::fromUtf8("textedit_remarks"));
        QSizePolicy sizePolicy12(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(textedit_remarks->sizePolicy().hasHeightForWidth());
        textedit_remarks->setSizePolicy(sizePolicy12);
        textedit_remarks->setMinimumSize(QSize(0, 0));
        textedit_remarks->setMaximumSize(QSize(16777215, 16777215));
        textedit_remarks->setFrameShape(QFrame::Box);
        textedit_remarks->setFrameShadow(QFrame::Sunken);
        textedit_remarks->setBackgroundVisible(false);

        verticalLayout_2->addWidget(textedit_remarks);


        verticalLayout_6->addWidget(frame_remarks);

        frame_save = new QFrame(CensusWidget);
        frame_save->setObjectName(QString::fromUtf8("frame_save"));
        sizePolicy.setHeightForWidth(frame_save->sizePolicy().hasHeightForWidth());
        frame_save->setSizePolicy(sizePolicy);
        frame_save->setFrameShape(QFrame::StyledPanel);
        frame_save->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_save);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btnSave = new QPushButton(frame_save);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        QIcon icon5;
        iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        btnSave->setIcon(icon5);

        gridLayout_3->addWidget(btnSave, 2, 1, 1, 1);

        btnDelete = new QPushButton(frame_save);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setEnabled(false);
        QIcon icon6;
        iconThemeName = QString::fromUtf8("edit-delete");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        btnDelete->setIcon(icon6);
        btnDelete->setCheckable(false);
        btnDelete->setFlat(false);

        gridLayout_3->addWidget(btnDelete, 2, 0, 1, 1);


        verticalLayout_6->addWidget(frame_save);


        retranslateUi(CensusWidget);

        wdgTabTypes->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CensusWidget);
    } // setupUi

    void retranslateUi(QFrame *CensusWidget)
    {
        CensusWidget->setWindowTitle(QApplication::translate("CensusWidget", "Frame", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_user_select->setToolTip(QApplication::translate("CensusWidget", "Endbestimmungen \303\274bernehmen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_user_select->setText(QApplication::translate("CensusWidget", "OK", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_user_switch->setToolTip(QApplication::translate("CensusWidget", "Zum Nutzer Wechseln", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_user_switch->setText(QString());
#ifndef QT_NO_TOOLTIP
        button_user_default->setToolTip(QApplication::translate("CensusWidget", "Zum Standardnutzer wechseln", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        button_user_default->setText(QString());
        chbSaveCensus->setText(QApplication::translate("CensusWidget", "Bestimmung merken", 0, QApplication::UnicodeUTF8));
        label_user_status->setText(QString());
        tabBird->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "BIRD", 0, QApplication::UnicodeUTF8)));
        group_box_plumage->setTitle(QApplication::translate("CensusWidget", "Gefieder", 0, QApplication::UnicodeUTF8));
        gbxBirdAge->setTitle(QApplication::translate("CensusWidget", "Alter", 0, QApplication::UnicodeUTF8));
        rbBirdAgeImmat->setText(QApplication::translate("CensusWidget", "immatur", "IM", QApplication::UnicodeUTF8));
        rbBirdAgeImmat->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "IMM", 0, QApplication::UnicodeUTF8)));
        rbBirdAgeAdult->setText(QApplication::translate("CensusWidget", "ad&ult", "AD", QApplication::UnicodeUTF8));
        rbBirdAgeAdult->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "ADU", 0, QApplication::UnicodeUTF8)));
        rbBirdAgeJuv->setText(QApplication::translate("CensusWidget", "&juvenil", "JU", QApplication::UnicodeUTF8));
        rbBirdAgeJuv->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "JUV", 0, QApplication::UnicodeUTF8)));
        gbxBirdBehavior->setTitle(QApplication::translate("CensusWidget", "Verhalten", 0, QApplication::UnicodeUTF8));
        rbBirdBehaveFly->setText(QApplication::translate("CensusWidget", "f&liegend", "F", QApplication::UnicodeUTF8));
        rbBirdBehaveFly->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "FLY", 0, QApplication::UnicodeUTF8)));
        rbBirdBehaveSwim->setText(QApplication::translate("CensusWidget", "schwimmend", "S", QApplication::UnicodeUTF8));
        rbBirdBehaveSwim->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "SWIM", 0, QApplication::UnicodeUTF8)));
        rbBirdBehaveDive->setText(QApplication::translate("CensusWidget", "&tauchend", 0, QApplication::UnicodeUTF8));
        rbBirdBehaveDive->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "DIVE", 0, QApplication::UnicodeUTF8)));
        gbxBirdGender->setTitle(QApplication::translate("CensusWidget", "&Geschlecht", 0, QApplication::UnicodeUTF8));
        rbBirdMale->setText(QApplication::translate("CensusWidget", "m&\303\244nnlich", "M", QApplication::UnicodeUTF8));
        rbBirdMale->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "M", 0, QApplication::UnicodeUTF8)));
        rbBirdFemale->setText(QApplication::translate("CensusWidget", "weiblich", "F", QApplication::UnicodeUTF8));
        rbBirdFemale->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "F", 0, QApplication::UnicodeUTF8)));
        groupBox_2->setTitle(QApplication::translate("CensusWidget", "Art des Objektes", 0, QApplication::UnicodeUTF8));
        gbxBirdQuality->setTitle(QApplication::translate("CensusWidget", "Bestimmungsqualit\303\244t", 0, QApplication::UnicodeUTF8));
        rbBirdQual1->setText(QApplication::translate("CensusWidget", "sicher", "1", QApplication::UnicodeUTF8));
        rbBirdQual1->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "1", 0, QApplication::UnicodeUTF8)));
        rbBirdQual2->setText(QApplication::translate("CensusWidget", "sehr wahrscheinlich", "2", QApplication::UnicodeUTF8));
        rbBirdQual2->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "2", 0, QApplication::UnicodeUTF8)));
        rbBirdQual3->setText(QApplication::translate("CensusWidget", "m&\303\266glich", "3", QApplication::UnicodeUTF8));
        rbBirdQual3->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "3", 0, QApplication::UnicodeUTF8)));
        rbBirdQual4->setText(QApplication::translate("CensusWidget", "poten&ziell", "4", QApplication::UnicodeUTF8));
        rbBirdQual4->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "4", 0, QApplication::UnicodeUTF8)));
        wdgTabTypes->setTabText(wdgTabTypes->indexOf(tabBird), QApplication::translate("CensusWidget", "Vogel", 0, QApplication::UnicodeUTF8));
        tabMammal->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "MAMMAL", 0, QApplication::UnicodeUTF8)));
        groupBox->setTitle(QApplication::translate("CensusWidget", "Art des Objektes", 0, QApplication::UnicodeUTF8));
        gbxMammalQuality->setTitle(QApplication::translate("CensusWidget", "Bestimmungsqualit\303\244t", 0, QApplication::UnicodeUTF8));
        rbMammalQual1->setText(QApplication::translate("CensusWidget", "sicher", "1", QApplication::UnicodeUTF8));
        rbMammalQual1->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "1", 0, QApplication::UnicodeUTF8)));
        rbMammalQual2->setText(QApplication::translate("CensusWidget", "sehr wahrscheinlich", "2", QApplication::UnicodeUTF8));
        rbMammalQual2->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "2", 0, QApplication::UnicodeUTF8)));
        rbMammalQual3->setText(QApplication::translate("CensusWidget", "m&\303\266glich", "3", QApplication::UnicodeUTF8));
        rbMammalQual3->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "3", 0, QApplication::UnicodeUTF8)));
        rbMammalQual4->setText(QApplication::translate("CensusWidget", "poten&ziell", "4", QApplication::UnicodeUTF8));
        rbMammalQual4->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "4", 0, QApplication::UnicodeUTF8)));
        gbxMammalBehaviour->setTitle(QApplication::translate("CensusWidget", "Verhalten", 0, QApplication::UnicodeUTF8));
        rbMammalBehaveOver->setText(QApplication::translate("CensusWidget", "durchbricht\n"
"Wasseroberfl&\303\244che", "OW", QApplication::UnicodeUTF8));
        rbMammalBehaveOver->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "OW", 0, QApplication::UnicodeUTF8)));
        rbMammalBehaveUnder->setText(QApplication::translate("CensusWidget", "&unter Wassoberfl\303\244che", "UW", QApplication::UnicodeUTF8));
        rbMammalBehaveUnder->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "UW", 0, QApplication::UnicodeUTF8)));
        radio_button_not_visible->setText(QApplication::translate("CensusWidget", "nich&t bestimmbar", 0, QApplication::UnicodeUTF8));
        radio_button_not_visible->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "NV", 0, QApplication::UnicodeUTF8)));
        gbxMammalAge->setTitle(QApplication::translate("CensusWidget", "Alter", 0, QApplication::UnicodeUTF8));
        rbMammalAgeAdult->setText(QApplication::translate("CensusWidget", "adu&lt", "AD", QApplication::UnicodeUTF8));
        rbMammalAgeAdult->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "ADU", 0, QApplication::UnicodeUTF8)));
        rbMammalAgeJuv->setText(QApplication::translate("CensusWidget", "&juvenil", "JU", QApplication::UnicodeUTF8));
        rbMammalAgeJuv->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "JUV", 0, QApplication::UnicodeUTF8)));
        wdgTabTypes->setTabText(wdgTabTypes->indexOf(tabMammal), QApplication::translate("CensusWidget", "Meeress\303\244uger", 0, QApplication::UnicodeUTF8));
        tabAnthro->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "ANTHRO", 0, QApplication::UnicodeUTF8)));
        gbxAnthroName->setTitle(QApplication::translate("CensusWidget", "Art des Objektes", 0, QApplication::UnicodeUTF8));
        gbxAnthroQuality->setTitle(QApplication::translate("CensusWidget", "Bestimmungsqualit\303\244t", 0, QApplication::UnicodeUTF8));
        rbAnthroQual1->setText(QApplication::translate("CensusWidget", "sicher", "1", QApplication::UnicodeUTF8));
        rbAnthroQual1->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "1", 0, QApplication::UnicodeUTF8)));
        rbAnthroQual2->setText(QApplication::translate("CensusWidget", "sehr wahrscheinlich", "2", QApplication::UnicodeUTF8));
        rbAnthroQual2->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "2", 0, QApplication::UnicodeUTF8)));
        rbAnthroQual3->setText(QApplication::translate("CensusWidget", "m&\303\266glich", "3", QApplication::UnicodeUTF8));
        rbAnthroQual3->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "3", 0, QApplication::UnicodeUTF8)));
        rbAnthroQual4->setText(QApplication::translate("CensusWidget", "poten&ziell", "4", QApplication::UnicodeUTF8));
        rbAnthroQual4->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "4", 0, QApplication::UnicodeUTF8)));
        wdgTabTypes->setTabText(wdgTabTypes->indexOf(tabAnthro), QApplication::translate("CensusWidget", "Anthropogen", 0, QApplication::UnicodeUTF8));
        tab_misc->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "MISC", 0, QApplication::UnicodeUTF8)));
        gbx_misc_name->setTitle(QApplication::translate("CensusWidget", "Art des Objektes", 0, QApplication::UnicodeUTF8));
        gbx_misc_qual->setTitle(QApplication::translate("CensusWidget", "Bestimmungsqualit\303\244t", 0, QApplication::UnicodeUTF8));
        rbutton_misc_qual_1->setText(QApplication::translate("CensusWidget", "sicher", "1", QApplication::UnicodeUTF8));
        rbutton_misc_qual_1->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "1", 0, QApplication::UnicodeUTF8)));
        rbutton_misc_qual_2->setText(QApplication::translate("CensusWidget", "sehr wahrscheinlich", "2", QApplication::UnicodeUTF8));
        rbutton_misc_qual_2->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "2", 0, QApplication::UnicodeUTF8)));
        rbutton_misc_qual_3->setText(QApplication::translate("CensusWidget", "m&\303\266glich", "3", QApplication::UnicodeUTF8));
        rbutton_misc_qual_3->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "3", 0, QApplication::UnicodeUTF8)));
        rbutton_misc_qual_4->setText(QApplication::translate("CensusWidget", "poten&ziell", "4", QApplication::UnicodeUTF8));
        rbutton_misc_qual_4->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "4", 0, QApplication::UnicodeUTF8)));
        wdgTabTypes->setTabText(wdgTabTypes->indexOf(tab_misc), QApplication::translate("CensusWidget", "Sonstiges", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        tab_nosight->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        tab_nosight->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "NOSIGHT", 0, QApplication::UnicodeUTF8)));
        gbxNoSightQuality->setTitle(QApplication::translate("CensusWidget", "Bestimmungsqualit\303\244t", 0, QApplication::UnicodeUTF8));
        rbNoSightQual1->setText(QApplication::translate("CensusWidget", "sicher", "1", QApplication::UnicodeUTF8));
        rbNoSightQual1->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "1", 0, QApplication::UnicodeUTF8)));
        rbNoSightQual2->setText(QApplication::translate("CensusWidget", "sehr wahrscheinlich", "2", QApplication::UnicodeUTF8));
        rbNoSightQual2->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "2", 0, QApplication::UnicodeUTF8)));
        rbNoSightQual3->setText(QApplication::translate("CensusWidget", "m&\303\266glich", "3", QApplication::UnicodeUTF8));
        rbNoSightQual3->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "3", 0, QApplication::UnicodeUTF8)));
        rbNoSightQual4->setText(QApplication::translate("CensusWidget", "poten&ziell", "4", QApplication::UnicodeUTF8));
        rbNoSightQual4->setProperty("dbvalue", QVariant(QApplication::translate("CensusWidget", "4", 0, QApplication::UnicodeUTF8)));
        wdgTabTypes->setTabText(wdgTabTypes->indexOf(tab_nosight), QApplication::translate("CensusWidget", "Keine Sichtung", 0, QApplication::UnicodeUTF8));
        groupbox_size->setTitle(QApplication::translate("CensusWidget", "Gr\303\266\303\237enmessung", 0, QApplication::UnicodeUTF8));
        button_width->setText(QApplication::translate("CensusWidget", "Spannweite", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CensusWidget", "Spanne:", 0, QApplication::UnicodeUTF8));
        label_width->setText(QString());
        button_length->setText(QApplication::translate("CensusWidget", "K\303\266rperl\303\244nge", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CensusWidget", "L\303\244nge:", 0, QApplication::UnicodeUTF8));
        label_length->setText(QString());
        groupbox_stuk4->setTitle(QApplication::translate("CensusWidget", "StUK4 Codes", 0, QApplication::UnicodeUTF8));
        toolbutton_behaviour->setText(QApplication::translate("CensusWidget", "...", 0, QApplication::UnicodeUTF8));
        label_behaviour->setText(QApplication::translate("CensusWidget", "Verhalten:", 0, QApplication::UnicodeUTF8));
        text_behaviour->setText(QString());
        toolbutton_associations->setText(QApplication::translate("CensusWidget", "...", 0, QApplication::UnicodeUTF8));
        label_associations->setText(QApplication::translate("CensusWidget", "Assoz.:", 0, QApplication::UnicodeUTF8));
        text_associations->setText(QString());
        groupbox_group_ids->setTitle(QApplication::translate("CensusWidget", "Gruppenbestimmung", 0, QApplication::UnicodeUTF8));
        toolbutton_family->setText(QApplication::translate("CensusWidget", "...", 0, QApplication::UnicodeUTF8));
        label_family->setText(QApplication::translate("CensusWidget", "Familie:", 0, QApplication::UnicodeUTF8));
        text_family->setText(QString());
        checkbox_image_quality->setText(QApplication::translate("CensusWidget", "Hohe Bildqualit\303\244t", 0, QApplication::UnicodeUTF8));
        textedit_remarks->setDocumentTitle(QString());
        btnSave->setText(QApplication::translate("CensusWidget", "Speichern", 0, QApplication::UnicodeUTF8));
        btnDelete->setText(QApplication::translate("CensusWidget", "L\303\266schen", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CensusWidget: public Ui_CensusWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_CENSUS_H
