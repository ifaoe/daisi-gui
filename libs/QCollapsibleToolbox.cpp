/*
 * QCollapsibleToolbox.cpp
 *
 *  Created on: Aug 31, 2015
 *      Author: awg
 */

#include "QCollapsibleToolbox.h"
#include <QDebug>

QCollapsibleToolbox::QCollapsibleToolbox(QWidget * parent =0) : QTreeWidget(parent) {
	setRootIsDecorated(false);
	setIndentation(0);
	viewport()->setBackgroundRole(QPalette::Background);
	setBackgroundRole(QPalette::Window);
	setAutoFillBackground(true);
	setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
}

QCollapsibleToolbox::~QCollapsibleToolbox() {
	// TODO Auto-generated destructor stub
	foreach (QTreeWidgetItem * item, sections)
			delete item;
}

void QCollapsibleToolbox::addWidget(const QString & name, QWidget * widget) {
	if (sections.contains(name)) {
		qDebug() << "Menu already contains section named: " << name;
		return;
	}
	QTreeWidgetItem * widget_item = new QTreeWidgetItem;
	sections[name] = widget_item;
	addTopLevelItem(widget_item);
	QCategoryCheckButton * button = new QCategoryCheckButton(name, this, widget_item);
	setItemWidget(widget_item,0,button);
	buttons[name] = button;
	QTreeWidgetItem * container = new QTreeWidgetItem;
	container->setDisabled(true);
	widget_item->addChild(container);
    widget->setBackgroundRole(QPalette::Window);
    widget->setAutoFillBackground(true);
    setItemWidget(container, 0, widget);
    widget_item->setExpanded(false);
}

void QCollapsibleToolbox::removeWidget(const QString & name) {
	if (!sections.contains(name)) {
		qDebug() << "Menu does not contain section named: " << name;
		return;
	}
	delete sections[name];
	delete buttons[name];
}

void QCollapsibleToolbox::setExpanded(const QString & name, bool expanded) {
	if (!sections.contains(name)) {
		qDebug() << "Menu does not contain section named: " << name;
		return;
	}
	sections[name]->setExpanded(expanded);
}

bool QCollapsibleToolbox::isExpanded(const QString & name) {
	if (!sections.contains(name)) {
		qDebug() << "Menu does not contain section named: " << name;
		return false;
	}
	return sections[name]->isExpanded();
}

QCategoryCheckButton * QCollapsibleToolbox::getCategoryButton(const QString & name) {
	if (!buttons.contains(name)) {
		qDebug() << "No button for section named: " << name;
		return 0;
	}
	return buttons[name];
}

QTreeWidgetItem * QCollapsibleToolbox::getToolboxSection(const QString & name) {
	if (!sections.contains(name)) {
		qDebug() << "Menu does not contain section named: " << name;
		return 0;
	}
	return sections[name];
}
