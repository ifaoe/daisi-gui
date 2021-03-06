/*
 * QCategoryCheckButton.h
 *
 *  Created on: May 6, 2015
 *      Author: awg
 */

#ifndef QCATEGORYCHECKBUTTON_H_
#define QCATEGORYCHECKBUTTON_H_

#include <QPushButton>
#include <QToolButton>
#include <QTreeWidget>
#include <QResizeEvent>

class QCategoryCheckButton: public QFrame {
    Q_OBJECT
public:
    QCategoryCheckButton(const QString& a_Text, QTreeWidget* a_pParent,
        QTreeWidgetItem* a_pItem);
    bool isChecked();

private slots:
    void ButtonPressed();
    void CheckBoxSwitched();

private:
    QTreeWidgetItem* m_pItem;
    QPushButton * btnCategory;
    QPushButton * chbCategory;

protected:
    void resizeEvent(QResizeEvent * e);
};

#endif /* QCATEGORYCHECKBUTTON_H_ */
