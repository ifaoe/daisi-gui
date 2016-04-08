/********************************************************************************
** Form generated from reading UI file 'censusanthro.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENSUSANTHRO_H
#define UI_CENSUSANTHRO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CensusAnthro
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
    QSpacerItem *verticalSpacer;
    QGroupBox *groubbox_remarks;
    QHBoxLayout *horizontalLayout_9;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QFrame *CensusAnthro)
    {
        if (CensusAnthro->objectName().isEmpty())
            CensusAnthro->setObjectName(QString::fromUtf8("CensusAnthro"));
        CensusAnthro->resize(584, 653);
        CensusAnthro->setFrameShape(QFrame::StyledPanel);
        CensusAnthro->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(CensusAnthro);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupbox_name = new QGroupBox(CensusAnthro);
        groupbox_name->setObjectName(QString::fromUtf8("groupbox_name"));
        horizontalLayout_11 = new QHBoxLayout(groupbox_name);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        combobox_name = new QComboBox(groupbox_name);
        combobox_name->setObjectName(QString::fromUtf8("combobox_name"));

        horizontalLayout_11->addWidget(combobox_name);


        verticalLayout->addWidget(groupbox_name);

        groupbox_confidence = new QGroupBox(CensusAnthro);
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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        groubbox_remarks = new QGroupBox(CensusAnthro);
        groubbox_remarks->setObjectName(QString::fromUtf8("groubbox_remarks"));
        horizontalLayout_9 = new QHBoxLayout(groubbox_remarks);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        plainTextEdit = new QPlainTextEdit(groubbox_remarks);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout_9->addWidget(plainTextEdit);


        verticalLayout->addWidget(groubbox_remarks);


        retranslateUi(CensusAnthro);

        QMetaObject::connectSlotsByName(CensusAnthro);
    } // setupUi

    void retranslateUi(QFrame *CensusAnthro)
    {
        CensusAnthro->setWindowTitle(QApplication::translate("CensusAnthro", "Frame", 0, QApplication::UnicodeUTF8));
        groupbox_name->setTitle(QApplication::translate("CensusAnthro", "Name des Objektes", 0, QApplication::UnicodeUTF8));
        groupbox_confidence->setTitle(QApplication::translate("CensusAnthro", "Bestimmungssicherheit", 0, QApplication::UnicodeUTF8));
        button_confidence_1->setText(QApplication::translate("CensusAnthro", "sicher", 0, QApplication::UnicodeUTF8));
        button_confidence_1->setProperty("dbvalue", QVariant(QApplication::translate("CensusAnthro", "1", 0, QApplication::UnicodeUTF8)));
        button_confidence_2->setText(QApplication::translate("CensusAnthro", "sehr wahrscheinlich", 0, QApplication::UnicodeUTF8));
        button_confidence_2->setProperty("dbvalue", QVariant(QApplication::translate("CensusAnthro", "2", 0, QApplication::UnicodeUTF8)));
        button_confidence_3->setText(QApplication::translate("CensusAnthro", "m\303\266glich", 0, QApplication::UnicodeUTF8));
        button_confidence_3->setProperty("dbvalue", QVariant(QApplication::translate("CensusAnthro", "3", 0, QApplication::UnicodeUTF8)));
        button_confidence_4->setText(QApplication::translate("CensusAnthro", "potenziell", 0, QApplication::UnicodeUTF8));
        button_confidence_4->setProperty("dbvalue", QVariant(QApplication::translate("CensusAnthro", "4", 0, QApplication::UnicodeUTF8)));
        groubbox_remarks->setTitle(QApplication::translate("CensusAnthro", "Bemerkung", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CensusAnthro: public Ui_CensusAnthro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENSUSANTHRO_H
