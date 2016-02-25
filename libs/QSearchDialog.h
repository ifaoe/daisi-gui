/*
 * QSearchDialog.h
 *
 *  Created on: Oct 7, 2015
 *      Author: awg
 */

#ifndef SRC_QTEXTENSION_QSEARCHDIALOG_H_
#define SRC_QTEXTENSION_QSEARCHDIALOG_H_

#include <QDialog>
#include <QListWidget>
#include <QToolButton>
#include <QLineEdit>
#include <QLabel>
#include <QLayout>
#include <QDialogButtonBox>
#include <QAbstractItemView>

class QSearchDialog: public QDialog {
	Q_OBJECT;
public:
	QSearchDialog();
	virtual ~QSearchDialog();
	void updateItemList(QStringList list);
	QString getFilterString() {return filter_text->text(); }
	Qt::SortOrder getSortingOrder() { return sort_order; }
    bool isSorted() { return sorted; }
    void setSortingEnabled(bool sorting);
private:
	QDialogButtonBox * button_box;
	QToolButton * sort_ascend_button;
	QToolButton * sort_descend_button;
	QLineEdit * filter_text;
	QListWidget * result_widget;
	QStringList item_list;
	bool sorted = false;
	Qt::SortOrder sort_order = Qt::AscendingOrder;

    QAbstractItemView * view = 0;
	QLabel * filter_label;
	QVBoxLayout * vertical_layout;
	QWidget * filter_widget;
	QHBoxLayout * horizontal_filter_layout;
private slots:
	void onAccept();
	void onReject();
	void onFilterChange(const QString & text);
	void onItemSelection(QListWidgetItem * item);
	void handleSortAscend(bool checked);
	void handleSortDescend(bool checked);
};

#endif /* SRC_QTEXTENSION_QSEARCHDIALOG_H_ */
