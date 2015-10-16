/*
 * QFrozenRowTableWidget.cpp
 *
 *  Created on: Sep 2, 2015
 *      Author: awg
 */

#include "QFrozenRowTableWidget.h"
#include <QScrollBar>
#include <QHeaderView>

QFrozenRowTableWidget::QFrozenRowTableWidget(QWidget * parent) : QTableWidget(parent){
	frozenTableWidget = new QTableWidget(this);

	init();

	//connect the headers and scrollbars of both tableviews together
	connect(horizontalHeader(),SIGNAL(sectionResized(int,int,int)), this, SLOT(updateSectionWidth(int,int,int)));
	connect(verticalHeader(),SIGNAL(sectionResized(int,int,int)), this, SLOT(updateSectionHeight(int,int,int)));

	connect(frozenTableWidget->horizontalScrollBar(), SIGNAL(valueChanged(int)), horizontalScrollBar(), SLOT(setValue(int)));
	connect(horizontalScrollBar(), SIGNAL(valueChanged(int)), frozenTableWidget->horizontalScrollBar(), SLOT(setValue(int)));

//	connect(this, SIGNAL(cellChanged(int, int)), this, SLOT(updateCellData(int, int)));
}

//QFrozenRowTableWidget::QFrozenRowTableWidget(int rows, int columns, QWidget * parent)
//	: QTableWidget(rows, columns, parent){
//
//}

QFrozenRowTableWidget::~QFrozenRowTableWidget() {
	// TODO Auto-generated destructor stub
}

void QFrozenRowTableWidget::init() {
	frozenTableWidget->setFocusPolicy(Qt::NoFocus);
	frozenTableWidget->horizontalHeader()->hide();
	frozenTableWidget->verticalHeader()->hide();
	frozenTableWidget->verticalHeader()->setResizeMode(QHeaderView::Fixed);

	viewport()->stackUnder(frozenTableWidget);

	frozenTableWidget->setSelectionModel(selectionModel());

	for (int i=0; i<frozenRows; i++)
		frozenTableWidget->setRowHeight(i, rowHeight(i) );

	frozenTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	frozenTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	frozenTableWidget->show();

	updateFrozenTableGeometry();

	setHorizontalScrollMode(ScrollPerPixel);
	setVerticalScrollMode(ScrollPerPixel);
	frozenTableWidget->setHorizontalScrollMode(ScrollPerPixel);
}

void QFrozenRowTableWidget::updateSectionWidth(int logicalIndex, int oldSize, int newSize) {
	Q_UNUSED(oldSize);
	frozenTableWidget->setColumnWidth(logicalIndex, newSize);
}

void QFrozenRowTableWidget::updateSectionHeight(int logicalIndex, int oldSize, int newSize)
{
	Q_UNUSED(oldSize);
	if (logicalIndex < frozenRows){
		  frozenTableWidget->setRowHeight(0, newSize);
		  updateFrozenTableGeometry();
	}
}

void QFrozenRowTableWidget::setColumnCount(int columns) {
	QTableWidget::setColumnCount(columns);
	frozenTableWidget->setColumnCount(columns);
}

void QFrozenRowTableWidget::setRowCount(int rows) {
	QTableWidget::setRowCount(rows);
	rows = rows > frozenRows ? frozenRows : rows;
	frozenTableWidget->setRowCount(rows);
}

void QFrozenRowTableWidget::setCellWidget(int row, int column, QWidget * widget) {
	if (row > frozenRows)
		QTableWidget::setCellWidget(row, column, widget);
	else {
		frozenTableWidget->setCellWidget(row, column, widget);
		QTableWidget::setItem(row, column, new QTableWidgetItem);
		QTableWidget::item(row, column)->setSizeHint(widget->sizeHint());
	}

}

void QFrozenRowTableWidget::resizeEvent(QResizeEvent * event)
{
      QTableWidget::resizeEvent(event);
      updateFrozenTableGeometry();
 }

QModelIndex QFrozenRowTableWidget::moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers)
{
      QModelIndex current = QTableWidget::moveCursor(cursorAction, modifiers);

      if (cursorAction == MoveLeft && current.column() > 0
              && visualRect(current).topLeft().x() < frozenTableWidget->rowHeight(0) ){
            const int newValue = verticalScrollBar()->value() + visualRect(current).topLeft().x()
                                 - frozenTableWidget->rowHeight(0);
            verticalScrollBar()->setValue(newValue);
      }
      return current;
}

void QFrozenRowTableWidget::updateFrozenTableGeometry()
{
      frozenTableWidget->setGeometry(frameWidth(),
                                   horizontalHeader()->height() + frameWidth(), viewport()->width()+verticalHeader()->width(),
								   rowHeight(0) );
}

void QFrozenRowTableWidget::updateItemData(QTableWidgetItem * item) {
	Q_UNUSED(item);
}

void QFrozenRowTableWidget::updateCellData(int row, int column) {
	if (row > frozenRows)
		return;
	frozenTableWidget->setCellWidget(row, column, cellWidget(row, column));
}
