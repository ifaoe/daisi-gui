/********************************************************************************
** Form generated from reading UI file 'censuswidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENSUSWIDGET_H
#define UI_CENSUSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CensusWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_2;
    QWidget *widget_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QFrame *CensusWidget)
    {
        if (CensusWidget->objectName().isEmpty())
            CensusWidget->setObjectName(QString::fromUtf8("CensusWidget"));
        CensusWidget->resize(456, 675);
        CensusWidget->setFrameShape(QFrame::StyledPanel);
        CensusWidget->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(CensusWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(CensusWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);

        toolButton_3 = new QToolButton(widget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));

        horizontalLayout->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(widget);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));

        horizontalLayout->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(widget);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));

        horizontalLayout->addWidget(toolButton_5);

        toolButton_2 = new QToolButton(widget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));

        horizontalLayout->addWidget(toolButton_2);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(CensusWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        verticalLayout->addWidget(widget_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(CensusWidget);

        QMetaObject::connectSlotsByName(CensusWidget);
    } // setupUi

    void retranslateUi(QFrame *CensusWidget)
    {
        CensusWidget->setWindowTitle(QApplication::translate("CensusWidget", "Frame", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("CensusWidget", "Vogel", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("CensusWidget", "Meeress\303\244uger", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("CensusWidget", "Anthropogen", 0, QApplication::UnicodeUTF8));
        toolButton_5->setText(QApplication::translate("CensusWidget", "Sonstiges", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("CensusWidget", "Keine Sichtung", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CensusWidget: public Ui_CensusWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENSUSWIDGET_H
