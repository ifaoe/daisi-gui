/*
 * QFrozenRowTableWidget.h
 *
 *  Created on: Sep 2, 2015
 *      Author: awg
 */

#ifndef SRC_QTEXTENSION_QFROZENROWTABLEWIDGET_H_
#define SRC_QTEXTENSION_QFROZENROWTABLEWIDGET_H_

#include <QTableWidget>

class QFrozenRowTableWidget: public QTableWidget {
	Q_OBJECT
public:
	QFrozenRowTableWidget(QWidget * parent = 0);
//	QFrozenRowTableWidget(int rows, int columns, QWidget * parent = 0);
	virtual ~QFrozenRowTableWidget();
	void scrollTo (const QModelIndex & index, ScrollHint hint = EnsureVisible) { QTableWidget::scrollTo(index, hint); }
	void setColumnCount(int columns);
	void setRowCount(int rows);
	void setCellWidget(int row, int column, QWidget * widget);
protected:
      virtual void resizeEvent(QResizeEvent *event);
      virtual QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers);

private:
      QTableWidget * frozenTableWidget;
      void init();
      void updateFrozenTableGeometry();

      int frozenRows = 1;

private slots:
      void updateSectionWidth(int logicalIndex, int oldSize, int newSize);
      void updateSectionHeight(int logicalIndex, int oldSize, int newSize);
      void updateItemData(QTableWidgetItem * item);
      void updateCellData(int row, int column);
};

#endif /* SRC_QTEXTENSION_QFROZENROWTABLEWIDGET_H_ */
