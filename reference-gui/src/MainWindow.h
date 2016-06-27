/*
 * MainWindow.h
 *
 *  Created on: Aug 7, 2015
 *      Author: awg
 */

#ifndef SRC_MAINWINDOW_H_
#define SRC_MAINWINDOW_H_

#include <QMainWindow>
#include <QItemSelection>
#include <QAbstractButton>
#include <QPlainTextEdit>
#include <QToolButton>
#include <QLayout>

#include "DatabaseHandler.h"
#include "ImageCanvas.h"
#include "UserSettings.h"
#include "ColumnChooser.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(UserSettings * config, DatabaseHandler * db);
    ~MainWindow();
private:
	Ui::MainWindow * ui;
	UserSettings * config;
	DatabaseHandler * db;
	ImageCanvas * canvas;
	QVBoxLayout * image_canvas_layout;
	QTabBar * type_tab_bar;

	QSqlTableModel * census_model = 0;
	QMap<QString, QString> filter_map;
	QMap<QString, int> census_index_map;
	QMap<QString, bool> enabled_columns_map;

	QString current_session;
	QString current_cam;
	QString current_img;

    QMap<QString, QString> column_translation;

    ColumnChooser * column_dialog;

	void HandleFilter();
	void ClearFilter();
	void SetDatabaseModels();
	void SetupTables();
	void RefreshColumnMap();
	QStringList getColumnData(int column);
	void populateSessionBox();
protected:
//    virtual void resizeEvent(QResizeEvent * event);
private slots:
	void HandleColumnVisibility();
	void HandleColumnChooser();
	void HandleTypeFilter(int index);
	void HandleSelectionChange(const QItemSelection & selected, const QItemSelection & deselected);
    void handleLocationSelection();
	void HandleImagePopup();
	void handleHeaderFilter(int column);
	void handleSessionSelection(int index);
};

#endif /* SRC_MAINWINDOW_H_ */
