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
#include "ui_widget_census.h"
#include "ui_widget_graphics.h"
#include "QCategoryCheckButton.h"
#include "MeasurementDialog.h"
#include "IdSelectionDialog.h"
#include "QCollapsibleToolbox.h"
#include "CensorSqlTableModel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(ConfigHandler *cfgArg = 0, DatabaseHandler *dbArg = 0, QWidget *parent = 0);
    ~MainWindow();
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

    QLabel * user_change_warning;
    bool user_changed = false;

    QMap<QString, QString> filterMap;

    // Treewidgets
    Ui::wdgSessions * wdgSession;
    Ui::wdgObjects * wdgObjects;
    Ui::wdgCensus * wdgCensus;
    Ui::wdgGraphics * wdgGraphics;

    QSet<int> sortSet;

    MeasurementDialog * measurementWindow = 0;

    IdSelectionDialog * group_dialog = 0;
    IdSelectionDialog * family_dialog = 0;
    IdSelectionDialog * association_dialog = 0;
    IdSelectionDialog * behaviour_dialog = 0;

    QVariant GetGroupBoxValue(QGroupBox * gbx, QButtonGroup * btng, QString value);
    QVariant GetButtonGroupValue(QButtonGroup * btng, QString value);
    void selectButtonByString(QButtonGroup * btnGrp, QString str);
    void initMapView();
    void UiPreSelection(census * cobj);
    void initFilters();
    void initCollapsibleMenu();
    void initCensusWidget();
    void initSessionWidget();
    bool compareResults(census * cobj, census * pobj);
    void conductMeasurement(double * length, QLabel * label);
    bool CheckInputValidity();
    QVariant GetComboBoxItem(QComboBox * combo_box);
    void SaveComboBoxSelection(QComboBox * combo_box);
    void updateTodoObjects();
    QVariant getObjectItemData(int row, int column);
    QStringList getColumnDataList(int column);
public slots:

private slots:
	void handleSessionSelection();
	void handleObjectSelection();
	void handleMapToolButton();
	void handleOneToOneZoom();
	void handleDirDial();
    void handleUsrSelect();
	void handleBrightnessSlider();
	void handleContrastSlider();
	void handleBrightnessReset();
	void handleContrastReset();
	void handleCensorFilter(int index);
	void handleUserCensorFilter(int index);
	void handleDeleteButton();
	void handleSaveButton();
	void handleBirdSpanMeasurement();
	void handleBirdLengthMeasurement();
	void handleMammalLengthMeasurement();
	void handleMiscMeasurement();
	void handleFlightInfoAction();
	void HandleAssociationSelection();
	void HandleBehaviourSelection();
	void HandleGroupSelection();
	void HandleFamilySelection();
	void HandleActiveCensusElements();
	void HandleServerSelection();
	void handleUserSwitch();
    void userDefault();
	void showFilterDialog(int index);
};

#endif // MAINWINDOW_H
