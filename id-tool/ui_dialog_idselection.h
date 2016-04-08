/********************************************************************************
** Form generated from reading UI file 'dialog_idselection.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_IDSELECTION_H
#define UI_DIALOG_IDSELECTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_dlg_idselection
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *btb_idselection;
    QTableView *tbv_idselection;

    void setupUi(QDialog *dlg_idselection)
    {
        if (dlg_idselection->objectName().isEmpty())
            dlg_idselection->setObjectName(QString::fromUtf8("dlg_idselection"));
        dlg_idselection->resize(924, 622);
        gridLayout = new QGridLayout(dlg_idselection);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btb_idselection = new QDialogButtonBox(dlg_idselection);
        btb_idselection->setObjectName(QString::fromUtf8("btb_idselection"));
        btb_idselection->setOrientation(Qt::Horizontal);
        btb_idselection->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        gridLayout->addWidget(btb_idselection, 1, 0, 1, 1);

        tbv_idselection = new QTableView(dlg_idselection);
        tbv_idselection->setObjectName(QString::fromUtf8("tbv_idselection"));
        tbv_idselection->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbv_idselection->setAlternatingRowColors(true);
        tbv_idselection->setSelectionMode(QAbstractItemView::MultiSelection);
        tbv_idselection->setSelectionBehavior(QAbstractItemView::SelectRows);
        tbv_idselection->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tbv_idselection, 0, 0, 1, 1);


        retranslateUi(dlg_idselection);
        QObject::connect(btb_idselection, SIGNAL(accepted()), dlg_idselection, SLOT(accept()));
        QObject::connect(btb_idselection, SIGNAL(rejected()), dlg_idselection, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlg_idselection);
    } // setupUi

    void retranslateUi(QDialog *dlg_idselection)
    {
        dlg_idselection->setWindowTitle(QApplication::translate("dlg_idselection", "ID Auswahl", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlg_idselection: public Ui_dlg_idselection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_IDSELECTION_H
