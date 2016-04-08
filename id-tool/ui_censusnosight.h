/********************************************************************************
** Form generated from reading UI file 'censusnosight.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENSUSNOSIGHT_H
#define UI_CENSUSNOSIGHT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CensusNosight
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupbox_confidence;
    QHBoxLayout *horizontalLayout;
    QToolButton *button_confidence_1;
    QToolButton *button_confidence_2;
    QToolButton *button_confidence_3;
    QToolButton *button_confidence_4;
    QSpacerItem *verticalSpacer;
    QGroupBox *groubbox_remarks;
    QHBoxLayout *horizontalLayout_9;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QFrame *CensusNosight)
    {
        if (CensusNosight->objectName().isEmpty())
            CensusNosight->setObjectName(QString::fromUtf8("CensusNosight"));
        CensusNosight->resize(419, 442);
        CensusNosight->setFrameShape(QFrame::StyledPanel);
        CensusNosight->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(CensusNosight);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupbox_confidence = new QGroupBox(CensusNosight);
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

        verticalSpacer = new QSpacerItem(20, 104, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        groubbox_remarks = new QGroupBox(CensusNosight);
        groubbox_remarks->setObjectName(QString::fromUtf8("groubbox_remarks"));
        horizontalLayout_9 = new QHBoxLayout(groubbox_remarks);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        plainTextEdit = new QPlainTextEdit(groubbox_remarks);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout_9->addWidget(plainTextEdit);


        verticalLayout->addWidget(groubbox_remarks);


        retranslateUi(CensusNosight);

        QMetaObject::connectSlotsByName(CensusNosight);
    } // setupUi

    void retranslateUi(QFrame *CensusNosight)
    {
        CensusNosight->setWindowTitle(QApplication::translate("CensusNosight", "Frame", 0, QApplication::UnicodeUTF8));
        groupbox_confidence->setTitle(QApplication::translate("CensusNosight", "Bestimmungssicherheit", 0, QApplication::UnicodeUTF8));
        button_confidence_1->setText(QApplication::translate("CensusNosight", "sicher", 0, QApplication::UnicodeUTF8));
        button_confidence_1->setProperty("dbvalue", QVariant(QApplication::translate("CensusNosight", "1", 0, QApplication::UnicodeUTF8)));
        button_confidence_2->setText(QApplication::translate("CensusNosight", "sehr wahrscheinlich", 0, QApplication::UnicodeUTF8));
        button_confidence_2->setProperty("dbvalue", QVariant(QApplication::translate("CensusNosight", "2", 0, QApplication::UnicodeUTF8)));
        button_confidence_3->setText(QApplication::translate("CensusNosight", "m\303\266glich", 0, QApplication::UnicodeUTF8));
        button_confidence_3->setProperty("dbvalue", QVariant(QApplication::translate("CensusNosight", "3", 0, QApplication::UnicodeUTF8)));
        button_confidence_4->setText(QApplication::translate("CensusNosight", "potenziell", 0, QApplication::UnicodeUTF8));
        button_confidence_4->setProperty("dbvalue", QVariant(QApplication::translate("CensusNosight", "4", 0, QApplication::UnicodeUTF8)));
        groubbox_remarks->setTitle(QApplication::translate("CensusNosight", "Bemerkung", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CensusNosight: public Ui_CensusNosight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENSUSNOSIGHT_H
