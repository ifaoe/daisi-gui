/*
 * QCollapsibleToolbox.h
 *
 *  Created on: Aug 31, 2015
 *      Author: awg
 */

#ifndef SRC_QTEXTENSION_QCOLLAPSIBLETOOLBOX_H_
#define SRC_QTEXTENSION_QCOLLAPSIBLETOOLBOX_H_

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "QCategoryCheckButton.h"

class QCollapsibleToolbox : public QTreeWidget{
public:
	QCollapsibleToolbox(QWidget * parent);
	virtual ~QCollapsibleToolbox();
	void addWidget(const QString & name, QWidget * widget);
	void removeWidget(const QString & name);
	void setExpanded(const QString & name, bool expanded);
	bool isExpanded(const QString & name);
	QCategoryCheckButton * getCategoryButton(const QString & name);
	QTreeWidgetItem * getToolboxSection(const QString & name);
private:
	QMap<QString, QTreeWidgetItem*> sections;
	QMap<QString, QCategoryCheckButton*> buttons;
};

#endif /* SRC_QTEXTENSION_QCOLLAPSIBLETOOLBOX_H_ */
