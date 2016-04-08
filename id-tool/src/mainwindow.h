//    Copyright (C) 2014, 2015 Axel Wegener
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDial>
#include <QScrollArea>
#include <QSignalMapper>
#include <QWebView>
#include <qgsproviderregistry.h>
#include <qgsmaplayerregistry.h>
#include "ImgCanvas.h"
#include "DatabaseHandler.h"
#include "ConfigHandler.h"
#include "ui_widget_sessions.h"
#include "ui_widget_objects.h"
#include "ui_widget_graphics.h"
#include "QCategoryCheckButton.h"
#include "IdSelectionDialog.h"
#include "QCollapsibleToolbox.h"
#include "CensorSqlTableModel.h"
#include "censuswidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(ConfigHandler *cfgArg = 0, DatabaseHandler *dbArg = 0, QWidget *parent = 0);
    ~MainWindow();
    ImgCanvas * getImageCanvas() { return imgcvs; }
    CensusWidget * getCensusWidget() { return census_widget; }
private:
    QgsProviderRegistry *prvRegistry = 0;
    QgsMapLayerRegistry *lyrRegistry = 0;
    ImgCanvas *imgcvs = 0;
    Ui::MainWindow *ui;
    ConfigHandler *config;
    DatabaseHandler *db;
    QItemSelectionModel *objSelector;
    CensorSqlTableModel * object_model;
    QString session = "";
    QString session_path = "/net/daisi";
    QStringList censorList;
    census * curObj = 0;
    int currentRow = -1;
    int mapMode = 0;
    QVBoxLayout *lytFrmImg;
    QWebView * geoMap;

    QDial * dirDial;

    QMap<QString, QString> filterMap;

    // Treewidgets
    Ui::wdgSessions * wdgSession;
    Ui::wdgObjects * wdgObjects;
    Ui::wdgGraphics * wdgGraphics;
    CensusWidget * census_widget;

    QSet<int> sortSet;

    void initMapView();
    void initFilters();
    void initCollapsibleMenu();
    void initSessionWidget();
    QVariant getObjectItemData(int row, int column);
    QStringList getColumnDataList(int column);
public slots:
private slots:
	void handleSessionSelection();
	void handleObjectSelection();
	void handleMapToolButton();
	void handleOneToOneZoom();
	void handleDirDial();
	void handleBrightnessSlider();
	void handleContrastSlider();
	void handleBrightnessReset();
	void handleContrastReset();
	void handleCensorFilter(int index);
	void handleUserCensorFilter(int index);
    void widthMeasurement();
    void lengthMeasurement();
	void handleMiscMeasurement();
	void handleFlightInfoAction();
	void HandleLocationSelection();
	void showFilterDialog(int index);
    void selectNextObject();
};

#endif // MAINWINDOW_H
