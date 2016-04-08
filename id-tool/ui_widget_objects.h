/********************************************************************************
** Form generated from reading UI file 'widget_objects.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_OBJECTS_H
#define UI_WIDGET_OBJECTS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wdgObjects
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QComboBox *cmbFilterUserCensor;
    QComboBox *cmbFilterCensor;
    QWidget *wdgObjectsTable;
    QVBoxLayout *verticalLayout_2;
    QTableView *tblObjects;

    void setupUi(QFrame *wdgObjects)
    {
        if (wdgObjects->objectName().isEmpty())
            wdgObjects->setObjectName(QString::fromUtf8("wdgObjects"));
        wdgObjects->resize(831, 228);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wdgObjects->sizePolicy().hasHeightForWidth());
        wdgObjects->setSizePolicy(sizePolicy);
        wdgObjects->setFrameShape(QFrame::StyledPanel);
        wdgObjects->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(wdgObjects);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(wdgObjects);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cmbFilterUserCensor = new QComboBox(frame);
        cmbFilterUserCensor->setObjectName(QString::fromUtf8("cmbFilterUserCensor"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cmbFilterUserCensor->sizePolicy().hasHeightForWidth());
        cmbFilterUserCensor->setSizePolicy(sizePolicy2);
        cmbFilterUserCensor->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(cmbFilterUserCensor);

        cmbFilterCensor = new QComboBox(frame);
        cmbFilterCensor->setObjectName(QString::fromUtf8("cmbFilterCensor"));
        sizePolicy2.setHeightForWidth(cmbFilterCensor->sizePolicy().hasHeightForWidth());
        cmbFilterCensor->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(cmbFilterCensor);


        verticalLayout->addWidget(frame);

        wdgObjectsTable = new QWidget(wdgObjects);
        wdgObjectsTable->setObjectName(QString::fromUtf8("wdgObjectsTable"));
        sizePolicy1.setHeightForWidth(wdgObjectsTable->sizePolicy().hasHeightForWidth());
        wdgObjectsTable->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(wdgObjectsTable);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tblObjects = new QTableView(wdgObjectsTable);
        tblObjects->setObjectName(QString::fromUtf8("tblObjects"));
        sizePolicy1.setHeightForWidth(tblObjects->sizePolicy().hasHeightForWidth());
        tblObjects->setSizePolicy(sizePolicy1);
        tblObjects->setMinimumSize(QSize(0, 0));
        tblObjects->setMaximumSize(QSize(16777215, 16777215));
        tblObjects->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tblObjects->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblObjects->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblObjects->setAlternatingRowColors(true);
        tblObjects->setSelectionMode(QAbstractItemView::SingleSelection);
        tblObjects->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblObjects->horizontalHeader()->setStretchLastSection(true);
        tblObjects->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tblObjects);


        verticalLayout->addWidget(wdgObjectsTable);


        retranslateUi(wdgObjects);

        QMetaObject::connectSlotsByName(wdgObjects);
    } // setupUi

    void retranslateUi(QFrame *wdgObjects)
    {
        wdgObjects->setWindowTitle(QApplication::translate("wdgObjects", "Frame", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wdgObjects: public Ui_wdgObjects {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_OBJECTS_H
