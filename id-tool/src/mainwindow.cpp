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

#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ImgCanvas.h"
#include <QSqlQuery>
#include <QMotifStyle>
#include <QMessageBox>
#include <qgsmultibandcolorrenderer.h>
#include <QLineEdit>
#include <QInputDialog>
#include <QSqlRecord>
#include "QSearchDialog.h"

MainWindow::MainWindow( ConfigHandler *cfgArg, DatabaseHandler *dbArg, QWidget *parent) :
    QMainWindow(0), ui(new Ui::MainWindow), config(cfgArg), db(dbArg)
{
    Q_UNUSED(parent);
    ui->setupUi(this);

    initMapView();
    initCollapsibleMenu();
    initFilters();

    prvRegistry = QgsProviderRegistry::instance();
    lyrRegistry = QgsMapLayerRegistry::instance();
    QStringList providers = prvRegistry->providerList();
    if (providers.size()==0) {
        qFatal("Die Providerliste ist leer.");
    }
    bool doneGdal = false;
    bool doneOgr = false;
    bool donePGIS = false;
    for (int i=0; i<providers.size(); ++i) {
        if (!doneGdal) { doneGdal = (providers.at(i) == QString("gdal")); }
        if (!doneOgr)  { doneOgr  = (providers.at(i) == QString("ogr")); }
        if (!donePGIS) { donePGIS = (providers.at(i) == QString("postgres")); }
    }
    if (!doneGdal) {
        qFatal("GDAL");
    }

    if (!doneOgr) {
        qFatal("OGR");
    }
    if (!donePGIS) {
        qFatal("Postgresql/PostGIS");
    }

    initSessionWidget();

    object_model = db->getObjectModel();
    wdgObjects->tblObjects->setModel(object_model);
    wdgObjects->tblObjects->hideColumn(0);
    wdgObjects->tblObjects->hideColumn(6);
    wdgObjects->tblObjects->hideColumn(7);
    wdgObjects->tblObjects->hideColumn(8);
    wdgObjects->tblObjects->setSelectionMode(QAbstractItemView::SingleSelection);
    wdgObjects->tblObjects->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect( wdgObjects->tblObjects->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(handleObjectSelection()));

    connect(wdgGraphics->sldBrightness, SIGNAL(sliderReleased()), this, SLOT(handleBrightnessSlider()));
    connect(wdgGraphics->sldContrast, SIGNAL(sliderReleased()), this, SLOT(handleContrastSlider()));
    connect(wdgGraphics->btnBrightnessReset, SIGNAL(clicked()), this, SLOT(handleBrightnessReset()));
    connect(wdgGraphics->btnContrastReset, SIGNAL(clicked()), this, SLOT(handleContrastReset()));

    connect(ui->toolbutton_map_view, SIGNAL(clicked()), this, SLOT(handleMapToolButton()));
    connect(ui->toolbutton_zoom_original, SIGNAL(clicked()), this, SLOT(handleOneToOneZoom()));
    connect(ui->toolbutton_take_measurement, SIGNAL(clicked()), this, SLOT(handleMiscMeasurement()));

    ui->statusBar->showMessage("Bereit. Kein Objekt geladen.");

    connect(wdgObjects->tblObjects->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(showFilterDialog(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
	config->setAppPosition(pos());
	config->setAppSize(size());
	config->setAppMaximized(isMaximized());
	config->sync();
}

void MainWindow::initFilters() {
    wdgObjects->cmbFilterCensor->clear();
    wdgObjects->cmbFilterCensor->addItem(trUtf8(""), QVariant(""));
    wdgObjects->cmbFilterCensor->addItem( trUtf8("Unbestimmt"),QVariant("(max_censor=0 OR max_censor IS NULL)"));
//    wdgObjects->cmbFilterCensor->setItemData( 1, QColor( Qt::white ), Qt::BackgroundRole );
    wdgObjects->cmbFilterCensor->addItem(trUtf8("Erstbestimmt"),QVariant("(max_censor=1 AND count_censor=1)"));
//    wdgObjects->cmbFilterCensor->setItemData( 2, QColor( Qt::gray ), Qt::BackgroundRole );
    wdgObjects->cmbFilterCensor->addItem(trUtf8("Unstimmigkeiten"),QVariant("(max_censor=1 AND count_censor>1)"));
//    wdgObjects->cmbFilterCensor->setItemData( 3, QColor( Qt::red ), Qt::BackgroundRole );
    wdgObjects->cmbFilterCensor->addItem(trUtf8("Enbestimmt"),QVariant("max_censor>1"));
//    wdgObjects->cmbFilterCensor->setItemData( 4, QColor( Qt::green ), Qt::BackgroundRole );

    wdgObjects->cmbFilterUserCensor->clear();
    wdgObjects->cmbFilterUserCensor->addItem(trUtf8(""), QVariant(""));
    wdgObjects->cmbFilterUserCensor->addItem(trUtf8("Unbearbeitet"),
            QString("NOT user_list@>ARRAY['%1']").arg(config->getUser()));
    wdgObjects->cmbFilterUserCensor->addItem(trUtf8("Bearbeitet"), QString("user_list@>ARRAY['%1']").arg(config->getUser()));

    filterMap["True"] = "TRUE";

    connect(wdgObjects->cmbFilterCensor, SIGNAL(currentIndexChanged(int)), this, SLOT(handleCensorFilter(int)));
    connect(wdgObjects->cmbFilterUserCensor, SIGNAL(currentIndexChanged(int)), this, SLOT(handleUserCensorFilter(int)));
}

void MainWindow::initMapView() {
    // Setup image and map
    imgcvs = new ImgCanvas(ui->wdgImg, ui, config, db);

    geoMap = new QWebView(ui->wdgImg);
    lytFrmImg = new QVBoxLayout;
    lytFrmImg->setMargin(0);
    lytFrmImg->addWidget(imgcvs);
    ui->wdgImg->setLayout(lytFrmImg);

    // Add QDial for direction
    dirDial = new QDial(imgcvs);
    dirDial->setFixedSize(80,80);
    dirDial->move(10,50);
    dirDial->setMaximum(359);
    dirDial->setMinimum(0);
    dirDial->setWrapping(true);
    dirDial->setNotchesVisible(false);
    dirDial->setStyle(new QMotifStyle);
//    dirDial->setInvertedAppearance(true);
    dirDial->setTracking(false);
    connect(dirDial, SIGNAL(sliderReleased()), this, SLOT(handleDirDial()));
}

void MainWindow::initCollapsibleMenu(){
    // create expandable widget type
    QFrame * widget;

    widget = new QFrame;
    wdgSession = new Ui::wdgSessions;
    wdgSession->setupUi(widget);
    ui->toolbox_widget->addWidget("Projektauswahl", widget);

    widget = new QFrame;
    wdgObjects = new Ui::wdgObjects;
    wdgObjects->setupUi(widget);
    ui->toolbox_widget->addWidget("Objektauswahl", widget);

    widget = new QFrame;
    census_widget = new CensusWidget(widget, config, db, imgcvs);
    ui->toolbox_widget->addWidget("Bestimmungstabellen", widget);
    ui->toolbox_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    connect(census_widget, SIGNAL(directionChanged(int)), dirDial, SLOT(setValue(int)));
    connect(census_widget, SIGNAL(dataChanged()), this, SLOT(handleSessionSelection()));
    connect(census_widget, SIGNAL(nextObject()), this, SLOT(selectNextObject()));
//    connect(census_widget, SIGNAL(directionChanged(int)), dirDial, SLOT(setValue(int)));

    widget = new QFrame;
    wdgGraphics = new Ui::wdgGraphics;
    wdgGraphics->setupUi(widget);
    ui->toolbox_widget->addWidget("Bildbearbeitung", widget);
    ui->toolbox_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    wdgObjects->tblObjects->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    wdgObjects->tblObjects->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
}

void MainWindow::initSessionWidget() {
    /*
     * Populate session widget and select preselected server and session
     */
    wdgSession->combo_location->addItem(QString());
    wdgSession->combo_location->addItems(db->getLocationList());
    connect(wdgSession->combo_location, SIGNAL(currentIndexChanged(int)), this, SLOT(HandleLocationSelection()));

    connect(wdgSession->cmbSession, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSessionSelection()));
    if (!config->getPreferredSession().isEmpty())
        wdgSession->cmbSession->setCurrentIndex(wdgSession->cmbSession->findText(config->getPreferredSession()));
}

QVariant MainWindow::getObjectItemData(int row, int column) {
	QModelIndex index = object_model->index(row, column, QModelIndex());
	return object_model->data(index);
}

QStringList MainWindow::getColumnDataList(int column) {
	QStringList result_list;
	for (int i=0; i<object_model->rowCount(); i++) {
		QString item_text =  getObjectItemData(i,column).toString();
		if (item_text.contains(',')) {
			QStringList array = item_text.split(',');
			for (int j=0; j<array.size(); j++) {
				if (!result_list.contains(array[j]))
					result_list.append(array[j]);
			}
		} else {
			if (!result_list.contains(item_text))
				result_list.append(item_text);
		}
	}

	return result_list;
}

/*
 * SLOTS
 */

void MainWindow::selectNextObject() {
    QModelIndex newIndex = wdgObjects->tblObjects->selectionModel()->model()->index(currentRow+1, 0);
    wdgObjects->tblObjects->scrollTo(newIndex);
    wdgObjects->tblObjects->selectionModel()->select(newIndex, QItemSelectionModel::ClearAndSelect | QItemSelectionModel::Rows);
    object_model->select();
}

/*
 * Recalculate direction value depending on QDial value
 * Set the direction value only when dial is touched
 */
void MainWindow::handleDirDial() {
    qDebug() << QString("Raw dial value %1").arg( dirDial->value() );
    int angle = (dirDial->value() + 180) % 360;
    census_widget->setDirectionData(angle);
}

/*
 * 1:1 Zoom Button handler
 */
void MainWindow::handleOneToOneZoom() {
    if (curObj == 0) return;
    imgcvs->centerOnWorldPosition(curObj->ux, curObj->uy, 1.0);
}

void MainWindow::handleBrightnessSlider() {
    imgcvs->setRasterBrightness(wdgGraphics->sldBrightness->value());
}

void MainWindow::handleContrastSlider() {
    imgcvs->setRasterContrast(wdgGraphics->sldContrast->value());
}

void MainWindow::handleBrightnessReset() {
    wdgGraphics->sldBrightness->setValue(0);
    handleBrightnessSlider();
}

void MainWindow::handleContrastReset() {
    wdgGraphics->sldContrast->setValue(0);
    handleContrastSlider();
}

/*
 * Handle Inet Map Button
 * Set Url and Load via Browser Widget
 * TODO: Use proper map API
 * TODO: Google or OpenStreetMaps ?
 */
void MainWindow::handleMapToolButton() {
    if (curObj == 0) return;
    QString scale="8";
    QString url = "";
    url += "http://www.openstreetmap.org/?mlat="
            + QString::number(curObj->ly) + "&mlon=" + QString::number(curObj->lx);
    url += "#map=" + scale + "/" + QString::number(curObj->ly) + "/" + QString::number(curObj->lx);

    if (ui->toolbutton_map_view->isChecked()) {
        qDebug() << "Load URL: " << url;
        geoMap->load(QUrl(url));
        geoMap->show();
        lytFrmImg->removeWidget(imgcvs);
        lytFrmImg->addWidget(geoMap);
    } else {
        lytFrmImg->removeWidget(geoMap);
        lytFrmImg->addWidget(imgcvs);
        geoMap->hide();
    }
}

void MainWindow::handleSessionSelection() {
	if (wdgSession->cmbSession->currentText().isEmpty())
		return;
    sortSet.clear();

    session = wdgSession->cmbSession->currentText();
    config->setSessionName(session);
    db->refreshSessionProperties(session);
    census_widget->setupMetaData();
    filterMap["session"] = QString("session='%1'").arg(session);
    object_model->setFilter(QStringList(filterMap.values()).join(" AND "));
    currentRow = -1;

	object_model->select();

    if (!ui->toolbox_widget->getCategoryButton("Projektauswahl")->isChecked())
        ui->toolbox_widget->getToolboxSection("Projektauswahl")->setExpanded(false);
    if (!ui->toolbox_widget->getCategoryButton("Objektauswahl")->isChecked())
    	 ui->toolbox_widget->getToolboxSection("Objektauswahl")->setExpanded(true);
}

void MainWindow::handleObjectSelection() {
    qDebug() << "Object changed.";
    wdgGraphics->sldBrightness->setValue(0);
    wdgGraphics->sldContrast->setValue(0);

    if (wdgObjects->tblObjects->selectionModel()->selectedRows().isEmpty()) return;
    currentRow = wdgObjects->tblObjects->selectionModel()->selectedRows().at(0).row();
    QString objId = getObjectItemData(currentRow, 1).toString();

    curObj = db->getRawObjectData(objId, config->getUser());

    if (!imgcvs->loadObject(curObj)) {
        census_widget->setEnabled(false);
        return;
    }
    census_widget->setEnabled(true);
    census_widget->loadObjectData(curObj);


    handleBrightnessSlider();
    if (!ui->toolbox_widget->getCategoryButton("Objektauswahl")->isChecked())
    	ui->toolbox_widget->getToolboxSection("Objektauswahl")->setExpanded(false);
    if (!ui->toolbox_widget->getCategoryButton("Bestimmungstabellen")->isChecked())
    	ui->toolbox_widget->getToolboxSection("Bestimmungstabellen")->setExpanded(true);


    ui->toolbox_widget->scrollToItem(ui->toolbox_widget->getToolboxSection("Bestimmungstabellen"));

    ui->statusBar->showMessage(
            QString("Project: %1, Kamera: %2, Bild: %3, Objekt ID: %4")
            .arg(curObj->session).arg(curObj->camera).arg(curObj->image).arg(curObj->id)
            );
}

void MainWindow::handleCensorFilter(int index) {
	qDebug() << "Censor data:" << wdgObjects->cmbFilterCensor->itemData( index ).toString();
	if (index > 0)
		filterMap["Censor"] = wdgObjects->cmbFilterCensor->itemData( index ).toString();
	else
		filterMap.remove("Censor");
    handleSessionSelection();
}

void MainWindow::handleUserCensorFilter(int index) {
	if (index > 0)
		filterMap["UserCensor"] = wdgObjects->cmbFilterUserCensor->itemData( index ).toString();
	else
		filterMap.remove("UserCensor");
    handleSessionSelection();
}

void MainWindow::widthMeasurement() {
    double width = -1;
    census_widget->setObjectWidth(width);
}

void MainWindow::lengthMeasurement() {
    double length = -1;
    census_widget->setObjectLength(length);
}

void MainWindow::handleMiscMeasurement() {
	if (curObj == 0) return;
        imgcvs->beginMeasurement(0);
//    conductMeasurement(0);
}

void MainWindow::handleFlightInfoAction() {
}

void MainWindow::HandleLocationSelection() {
    if (wdgSession->combo_location->currentText().isEmpty()) {
		wdgSession->cmbSession->setEnabled(false);
		return;
	}

    config->setLocation(wdgSession->combo_location->currentText());


	wdgSession->cmbSession->clear();

	wdgSession->cmbSession->addItem(QString());
	wdgSession->cmbSession->setCurrentIndex(0);
    wdgSession->cmbSession->addItems(db->getSessionList(config->location()));
	wdgSession->cmbSession->setEnabled(true);
}

void MainWindow::showFilterDialog(int index) {
	QSearchDialog dialog;
	dialog.updateItemList(getColumnDataList(index));
	if (dialog.exec()) {
        if (dialog.isSorted())
			wdgObjects->tblObjects->sortByColumn(index, dialog.getSortingOrder());
		if (dialog.getFilterString().isEmpty())
			filterMap.remove(object_model->headerData(index, Qt::Horizontal).toString());
		else
			filterMap[object_model->headerData(index, Qt::Horizontal).toString()] = QString("cast(%1 as text) like '%%2%'")
                .arg(object_model->record(0).fieldName(index)).arg(dialog.getFilterString());
		object_model->setFilter(static_cast<QStringList>(filterMap.values()).join(" AND "));
	}

}
