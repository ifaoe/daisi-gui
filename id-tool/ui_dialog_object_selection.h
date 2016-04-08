/********************************************************************************
** Form generated from reading UI file 'dialog_object_selection.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_OBJECT_SELECTION_H
#define UI_DIALOG_OBJECT_SELECTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_object_selection
{
public:
    QGridLayout *gridLayout;
    QTableView *selection_view;
    QDialogButtonBox *buttonbox;
    QTableWidget *focus_widget;
    QFrame *image_frame;
    QVBoxLayout *verticalLayout;
    QWidget *image_widget;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *object_selection)
    {
        if (object_selection->objectName().isEmpty())
            object_selection->setObjectName(QString::fromUtf8("object_selection"));
        object_selection->resize(936, 661);
        gridLayout = new QGridLayout(object_selection);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        selection_view = new QTableView(object_selection);
        selection_view->setObjectName(QString::fromUtf8("selection_view"));
        selection_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
        selection_view->setAlternatingRowColors(true);
        selection_view->setSelectionMode(QAbstractItemView::MultiSelection);
        selection_view->setSelectionBehavior(QAbstractItemView::SelectRows);
        selection_view->verticalHeader()->setVisible(false);

        gridLayout->addWidget(selection_view, 0, 1, 1, 1);

        buttonbox = new QDialogButtonBox(object_selection);
        buttonbox->setObjectName(QString::fromUtf8("buttonbox"));
        buttonbox->setOrientation(Qt::Horizontal);
        buttonbox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        gridLayout->addWidget(buttonbox, 1, 1, 1, 1);

        focus_widget = new QTableWidget(object_selection);
        focus_widget->setObjectName(QString::fromUtf8("focus_widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(focus_widget->sizePolicy().hasHeightForWidth());
        focus_widget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(focus_widget, 0, 0, 1, 1);

        image_frame = new QFrame(object_selection);
        image_frame->setObjectName(QString::fromUtf8("image_frame"));
        image_frame->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(image_frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        image_widget = new QWidget(image_frame);
        image_widget->setObjectName(QString::fromUtf8("image_widget"));
        image_widget->setMinimumSize(QSize(320, 240));

        verticalLayout->addWidget(image_widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(image_frame, 0, 2, 1, 1);


        retranslateUi(object_selection);
        QObject::connect(buttonbox, SIGNAL(accepted()), object_selection, SLOT(accept()));
        QObject::connect(buttonbox, SIGNAL(rejected()), object_selection, SLOT(reject()));

        QMetaObject::connectSlotsByName(object_selection);
    } // setupUi

    void retranslateUi(QDialog *object_selection)
    {
        object_selection->setWindowTitle(QApplication::translate("object_selection", "ID Auswahl", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class object_selection: public Ui_object_selection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_OBJECT_SELECTION_H
