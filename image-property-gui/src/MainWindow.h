/*
 * MainWindow.h
 *
 *  Created on: Jul 22, 2015
 *      Author: awg
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include "ui_main_window.h"
#include <QMainWindow>
#include <QDebug>
#include <QProgressDialog>
#include "ConfigHandler.h"
#include "DatabaseHandler.h"
#include "qsqlsortmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	MainWindow(ConfigHandler * cfg, DatabaseHandler * db);
	virtual ~MainWindow();
private:
	QProgressDialog * progress_dialog_ = 0;
	int database_progess_ = 0;
	ConfigHandler * cfg = 0;
	DatabaseHandler * db = 0;
	Ui::MainWindow * ui = 0;
	QMap<QString, QString> filter_map;
    QSqlSortModel * property_table = 0;
	QMap<QString,int> index_list;
	void LoadSession();
    void ApplyFilters();
	void SetTableQuery(QString where);
	void SetTableData(QString column_name, QVariant data);
	void UpdateProgress();
    QVariant getModelItem(int row, int column);
    QStringList getColumnDataList(int column);
private slots:
    void HandleServerSelection(const QString & server);
    void HandleSessionSelection(const QString & session);
	void HandleSaveData(QAbstractButton * button);
	void UpdateDatabaseProgress();
    void handleHeaderFilter(int index);
};

#endif /* MAINWINDOW_H_ */
