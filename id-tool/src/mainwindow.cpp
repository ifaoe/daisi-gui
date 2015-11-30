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

    initMapView();
    initCensusWidget();
    initSessionWidget();

    objSelector = wdgObjects->tblObjects->selectionModel();
    wdgObjects->tblObjects->setSelectionMode(QAbstractItemView::SingleSelection);
    wdgObjects->tblObjects->setSelectionBehavior(QAbstractItemView::SelectRows);

    measurementWindow = new MeasurementDialog(imgcvs);

    connect( objSelector, SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(handleObjectSelection()));

    connect(dirDial, SIGNAL(sliderReleased()), this, SLOT(handleDirDial()));

    connect(wdgGraphics->sldBrightness, SIGNAL(sliderReleased()),
            this, SLOT(handleBrightnessSlider()));
    connect(wdgGraphics->sldContrast, SIGNAL(sliderReleased()),
            this, SLOT(handleContrastSlider()));
    connect(wdgGraphics->btnBrightnessReset, SIGNAL(clicked()),
            this, SLOT(handleBrightnessReset()));
    connect(wdgGraphics->btnContrastReset, SIGNAL(clicked()), this, SLOT(handleContrastReset()));

    connect(wdgCensus->btnSave, SIGNAL(released()), this, SLOT(handleSaveButton()));

    connect(wdgCensus->btnDelete, SIGNAL(released()), this, SLOT(handleDeleteButton()));

    connect(wdgCensus->btnBirdSizeSpan, SIGNAL(clicked()), this, SLOT(handleBirdSpanMeasurement()));
    connect(wdgCensus->btnBirdSizeLength, SIGNAL(clicked()), this, SLOT(handleBirdLengthMeasurement()));
    connect(wdgCensus->btnMammalSizeLength, SIGNAL(clicked()), this, SLOT(handleMammalLengthMeasurement()));

    connect(ui->toolbutton_map_view, SIGNAL(clicked()), this, SLOT(handleMapToolButton()));
    connect(ui->toolbutton_zoom_original, SIGNAL(clicked()), this, SLOT(handleOneToOneZoom()));
    connect(ui->toolbutton_take_measurement, SIGNAL(clicked()), this, SLOT(handleMiscMeasurement()));
    connect(ui->toolbutton_user_switch, SIGNAL(clicked()), this, SLOT(handleUserSwitch()));

    wdgCensus->btnBirdSizeLength->setEnabled(false);
    wdgCensus->btnBirdSizeSpan->setEnabled(false);
    wdgCensus->btnMammalSizeLength->setEnabled(false);

    ui->statusBar->showMessage("Bereit. Kein Objekt geladen.");

    connect(wdgObjects->tblObjects->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(showFilterDialog(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
    measurementWindow->close();
    delete measurementWindow;
	config->setAppPosition(pos());
	config->setAppSize(size());
	config->setAppMaximized(isMaximized());
	config->sync();
}

void MainWindow::updateTodoObjects() {
	int census_index = wdgObjects->cmbFilterCensor->currentIndex();
	int censor_index = wdgObjects->cmbFilterUserCensor->currentIndex();
	wdgObjects->cmbFilterCensor->disconnect();
	wdgObjects->cmbFilterUserCensor->disconnect();

	int all_count = db->getCensusCount(session, "%", "TRUE");
	int no_censor_count = db->getCensusCount(session, "%", "mc=0 OR mc IS NULL");
	int one_censor_count = db->getCensusCount(session, "%", "mc=1 AND cnt=1");
	int conflict_censor_count = db->getCensusCount(session, "%", "mc=1 AND cnt>1");
	int done_censor_count = db->getCensusCount(session, "%", "mc>1");
	wdgObjects->cmbFilterCensor->clear();
    wdgObjects->cmbFilterCensor->addItem(trUtf8(""), QVariant("TRUE"));
    wdgObjects->cmbFilterCensor->addItem(
    		trUtf8("Unbestimmt \t%1\t/%2").arg(no_censor_count).arg(all_count),QVariant("(mc=0 OR mc IS NULL)"));
//    wdgObjects->cmbFilterCensor->setItemData( 1, QColor( Qt::white ), Qt::BackgroundRole );
    wdgObjects->cmbFilterCensor->addItem(
    		trUtf8("Erstbestimmt \t%1\t/%2").arg(one_censor_count).arg(all_count),QVariant("(mc=1 AND cnt=1)"));
//    wdgObjects->cmbFilterCensor->setItemData( 2, QColor( Qt::gray ), Qt::BackgroundRole );
    wdgObjects->cmbFilterCensor->addItem(
    		trUtf8("Unstimmigkeiten \t%1\t/%2").arg(conflict_censor_count).arg(all_count),QVariant("(mc=1 AND cnt>1)"));
//    wdgObjects->cmbFilterCensor->setItemData( 3, QColor( Qt::red ), Qt::BackgroundRole );
    wdgObjects->cmbFilterCensor->addItem(
    		trUtf8("Enbestimmt \t%1\t/%2").arg(done_censor_count).arg(all_count),QVariant("mc>1"));
//    wdgObjects->cmbFilterCensor->setItemData( 4, QColor( Qt::green ), Qt::BackgroundRole );

    int todo  = db->getCensusCount(session, "%", "(mc<2 OR mc IS NULL)", QString("(usr!='%1' OR usr IS NULL)").arg(config->getUser()));
    int finished = db->getCensusCount(session, config->getUser(), "TRUE", "tp IS NOT NULL");
    wdgObjects->cmbFilterUserCensor->clear();
    wdgObjects->cmbFilterUserCensor->addItem(trUtf8(""), QVariant("TRUE"));
    wdgObjects->cmbFilterUserCensor->addItem(trUtf8("Unbearbeitet  %1\t/%2").arg(todo).arg(todo+finished),
            QVariant("tp IS NULL AND (mc<2 OR mc IS NULL)"));
    wdgObjects->cmbFilterUserCensor->addItem(trUtf8("Bearbeitet  %1\t/%2").arg(finished).arg(todo+finished),
    		QVariant("tp IS NOT NULL"));

	wdgObjects->cmbFilterCensor->setCurrentIndex(census_index);
    wdgObjects->cmbFilterUserCensor->setCurrentIndex(censor_index);
    int min_width_censor = wdgObjects->cmbFilterCensor->minimumSizeHint().width();
    int min_width_user_censor = wdgObjects->cmbFilterUserCensor->minimumSizeHint().width();
    wdgObjects->cmbFilterCensor->view()->setMinimumWidth(min_width_censor+15);
    wdgObjects->cmbFilterUserCensor->view()->setMinimumWidth(min_width_user_censor+15);
    connect(wdgObjects->cmbFilterCensor, SIGNAL(currentIndexChanged(int)), this, SLOT(handleCensorFilter(int)));
    connect(wdgObjects->cmbFilterUserCensor, SIGNAL(currentIndexChanged(int)), this, SLOT(handlUserCensorFilter(int)));
}

void MainWindow::selectButtonByString(QButtonGroup * btnGrp, QString str) {
    QList<QAbstractButton*> btnList = btnGrp->buttons();
    for(int i=0; i<btnList.size(); i++) {
        if(btnList.at(i)->property("dbvalue") == str) {
            btnList.at(i)->setChecked(true);
        }
    }
}

QVariant MainWindow::getObjectItemData(int row, int column) {
	QModelIndex index = object_model->index(row, column, QModelIndex());
	return object_model->data(index);
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
}
/*
 * Function which selects Ui elements depending on the data in
 * the census struct.
 */
void MainWindow::UiPreSelection(census * cobj) {

    // Save Census checkbox ticked?
    // save all info but size and direction
    if (wdgCensus->chbSaveCensus->isChecked()) {
        dirDial->setValue(180);
        cobj->direction = -1;

        // clear size box
        wdgCensus->lblMammalSizeLength->clear();
        wdgCensus->lblBirdSizeLength->clear();
        wdgCensus->lblBirdSizeSpan->clear();
        cobj->span = -1;
        cobj->length = -1;

        cobj->remarks.clear();

        cobj->imageQuality = 0;
        return;
    }

    association_dialog->set_id_list(&cobj->stuk4_ass);
    behaviour_dialog->set_id_list(&cobj->stuk4_beh);
    family_dialog->set_id_list(&cobj->family);
    group_dialog->set_id_list(&cobj->group);

//    // handle those differently -- courtesy of the stuk4 table widget
    curObj->stuk4_ass = cobj->stuk4_ass;
    curObj->stuk4_beh = cobj->stuk4_beh;
    curObj->length = cobj->length;
    curObj->span = cobj->span;

    wdgCensus->textedit_remarks->clear();

    // clear size box
    wdgCensus->lblMammalSizeLength->clear();
    wdgCensus->lblBirdSizeLength->clear();
    wdgCensus->lblBirdSizeSpan->clear();

    // Recalculate values of the QDial to 0=North
    if (cobj->direction >= 0 ) {
        dirDial->setValue((cobj->direction+180)%360);
        handleDirDial();
    } else {
        dirDial->setValue(180);
    }

    // Checkbox for very good objects in image quality
    // which could be used as example pictures
    if (cobj->imageQuality > 0) {
        wdgGraphics->chbImgQuality->setChecked(true);
    } else {
        wdgGraphics->chbImgQuality->setChecked(false);
    }

    // by default, all options are off
    wdgCensus->gbxMammalAge->setChecked(false);
	wdgCensus->gbxBirdAge->setChecked(false);
	wdgCensus->cmb_bird_age->setCurrentIndex(0);
    wdgCensus->gbxBirdGender->setChecked(false);
	wdgCensus->group_box_plumage->setChecked(false);
	wdgCensus->combo_box_plumage->setCurrentIndex(0);

    wdgCensus->textedit_remarks->setPlainText(cobj->remarks);

    if(cobj->type == "BIRD" ||curObj->type.left(1) == "V" ) { // Bird Tab
            wdgCensus->wdgTabTypes->setCurrentIndex(0);
            int index = wdgCensus->cmbBird->findText(cobj->name);
            wdgCensus->cmbBird->setCurrentIndex(index);
            selectButtonByString(wdgCensus->buttongroup_bird_confidence, QString::number(cobj->confidence));
            selectButtonByString(wdgCensus->buttongroup_bird_behaviour, cobj->behavior);
            if(cobj->gender != "") {
                wdgCensus->gbxBirdGender->setChecked(true);
                selectButtonByString(wdgCensus->buttongroup_bird_sex, cobj->gender);
            }
            if(cobj->age != "" || cobj->age_year>0) {
                wdgCensus->gbxBirdAge->setChecked(true);
                selectButtonByString(wdgCensus->buttongroup_bird_age, cobj->age);
                index = wdgCensus->cmb_bird_age->findData(curObj->age_year);
                wdgCensus->cmb_bird_age->setCurrentIndex(index);
            }
            if (!cobj->plumage.isEmpty()) {
            	wdgCensus->group_box_plumage->setChecked(true);
            	wdgCensus->combo_box_plumage->setCurrentIndex(
            			wdgCensus->combo_box_plumage->findData(cobj->plumage));
            }
            if (cobj->length > 0 ) wdgCensus->lblBirdSizeLength->setText(QString::number(cobj->length));
            if (cobj->span > 0 ) wdgCensus->lblBirdSizeSpan->setText(QString::number(cobj->span));

            wdgCensus->cmbBird->setFocus();
        } else if (cobj->type == "MAMMAL" || curObj->type == "MM" ) { // Mammal Tab
            wdgCensus->wdgTabTypes->setCurrentIndex(1);
            int index = wdgCensus->cmbMammal->findText(cobj->name);
            wdgCensus->cmbMammal->setCurrentIndex(index);
            selectButtonByString(wdgCensus->buttongroup_mammal_confidence, QString::number(cobj->confidence));
            selectButtonByString(wdgCensus->buttongroup_mammal_behaviour, cobj->behavior);
            if (cobj->age != "") {
                wdgCensus->gbxMammalAge->setChecked(true);
                selectButtonByString(wdgCensus->buttongroup_mammal_age, cobj->age);
            }
            if (cobj->length > 0 )
                wdgCensus->lblMammalSizeLength->setText(QString::number(cobj->length));
            wdgCensus->cmbMammal->setFocus();
        } else if (cobj->type == "ANTHRO" || curObj->type == "AN" ) { // Anthro Tab
            int index = wdgCensus->cmbAnthroName->findData(cobj->code);
            wdgCensus->cmbAnthroName->setCurrentIndex(index);
            wdgCensus->wdgTabTypes->setCurrentIndex(2);
            selectButtonByString(wdgCensus->buttongroup_anthro_confidence, QString::number(cobj->confidence));
        } else if (cobj ->type== "MISC"  || curObj->type == "TR" ) {
        	if (curObj->type == "TR") curObj->code = "7101";
        	int index = wdgCensus->cmb_misc_name->findData(cobj->code);
        	wdgCensus->cmb_misc_name->setCurrentIndex(index);
        	wdgCensus->wdgTabTypes->setCurrentIndex(3);
            selectButtonByString(wdgCensus->buttongroup_misc_confidence, QString::number(cobj->confidence));
        } else { //NoSighting tab
            wdgCensus->wdgTabTypes->setCurrentIndex(4);
            selectButtonByString(wdgCensus->buttongroup_nosight_confidence, QString::number(cobj->confidence));
        }
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
    		QVariant(QString("user_list@>ARRAY['%1']").arg(config->getUser())));
    wdgObjects->cmbFilterUserCensor->addItem(trUtf8("Bearbeitet"), QVariant("tp IS NOT NULL"));

    filterMap["True"] = "TRUE";

    connect(wdgObjects->cmbFilterCensor, SIGNAL(currentIndexChanged(int)), this, SLOT(handleCensorFilter(int)));
    connect(wdgObjects->cmbFilterUserCensor, SIGNAL(currentIndexChanged(int)), this, SLOT(handleUserCensorFilter(int)));
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

bool MainWindow::compareResults(census * curObj, census * cenObj) {
    bool agree = true;
    agree = agree && (curObj->name == cenObj->name);
    agree = agree && (curObj->type == cenObj->type);
    if (curObj->confidence == 4 || cenObj->confidence == 4)
        agree = agree && (curObj->confidence == cenObj->confidence);
    return agree;
}

void MainWindow::conductMeasurement(double * length, QLabel * label) {
    measurementWindow->move(size().width()*0.75,size().height()*0.25);
    measurementWindow->startMeasurement(length, label);
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
    wdgCensus = new Ui::wdgCensus;
    wdgCensus->setupUi(widget);
    ui->toolbox_widget->addWidget("Bestimmungstabellen", widget);
    ui->toolbox_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    widget = new QFrame;
    wdgGraphics = new Ui::wdgGraphics;
    wdgGraphics->setupUi(widget);
    ui->toolbox_widget->addWidget("Bildbearbeitung", widget);
    ui->toolbox_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	wdgCensus->btnSave->setEnabled(false);
	wdgCensus->btnDelete->setEnabled(false);

	wdgObjects->tblObjects->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
	wdgObjects->tblObjects->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
}

void MainWindow::initCensusWidget() {
    group_dialog = new IdSelectionDialog(wdgCensus->text_group, this);
	family_dialog = new IdSelectionDialog(wdgCensus->text_family, this);
    association_dialog = new IdSelectionDialog(wdgCensus->text_associations, this);
    behaviour_dialog = new IdSelectionDialog(wdgCensus->text_behaviour, this);

    connect(wdgCensus->toolbutton_associations, SIGNAL(clicked()), this, SLOT(HandleAssociationSelection()));
    connect(wdgCensus->toolbutton_behaviour, SIGNAL(clicked()), this, SLOT(HandleBehaviourSelection()));
    connect(wdgCensus->toolbutton_group, SIGNAL(clicked()), this, SLOT(HandleGroupSelection()));
    connect(wdgCensus->toolbutton_family, SIGNAL(clicked()), this, SLOT(HandleFamilySelection()));

    connect(wdgCensus->wdgTabTypes, SIGNAL(currentChanged(int)), this, SLOT(HandleActiveCensusElements()));
    /*
     * TODO: Wait until users have made their minds up
     */
    wdgCensus->rbBirdBehaveDive->hide();
}

void MainWindow::initSessionWidget() {
    /*
     * Populate session widget and select preselected server and session
     */
    wdgSession->combo_server->addItem(QString());
    wdgSession->combo_server->addItems(config->getDatabaseList());
    connect(wdgSession->combo_server, SIGNAL(currentIndexChanged(int)), this, SLOT(HandleServerSelection()));
    if (!config->getPreferredDatabase().isEmpty())
    	wdgSession->combo_server->setCurrentIndex(wdgSession->combo_server->findText(config->getPreferredDatabase()));

    connect(wdgSession->cmbSession, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSessionSelection()));
    if (!config->getPreferredSession().isEmpty())
    	wdgSession->cmbSession->setCurrentIndex(wdgSession->cmbSession->findText(config->getPreferredSession()));
}

QVariant MainWindow::GetComboBoxItem(QComboBox * combo_box) {
	return combo_box->itemData(combo_box->currentIndex());
}

void MainWindow::SaveComboBoxSelection(QComboBox * combo_box) {
	int row = combo_box->currentIndex();
	curObj->name = combo_box->model()->data(combo_box->model()->index(row,0)).toString();
	curObj->code = combo_box->model()->data(combo_box->model()->index(row,2)).toString();
}

QVariant MainWindow::GetButtonGroupValue(QButtonGroup * btng, QString value) {
	return btng->checkedButton()->property(value.toStdString().c_str());
}

QVariant MainWindow::GetGroupBoxValue(QGroupBox * gbx, QButtonGroup * btng, QString value) {
	if (gbx->isCheckable()) {
		if (gbx->isChecked()) {
			return GetButtonGroupValue(btng,value);
		} else {
			return QVariant::fromValue(QString::fromStdString(""));
		}
	} else {
		return GetButtonGroupValue(btng,value);
	}
}

bool MainWindow::CheckInputValidity() {
	if (curObj->name == "" && curObj->type != "NOSIGHT") {
		QMessageBox * msgBox = new QMessageBox();
		msgBox->setText(trUtf8("Bitte Art/Bezeichnung auswählen!"));
		QAbstractButton *nextButton = msgBox->addButton(trUtf8("Ok"), QMessageBox::YesRole);
		msgBox->exec();
		if(msgBox->clickedButton() == nextButton) {
			delete msgBox;
			return false;
		}
		delete msgBox;
	}
	if (curObj->type == "BIRD") {
		if ((curObj->behavior == "FLY") && (curObj->direction < 0)) {
				QMessageBox * msgBox = new QMessageBox();
				msgBox->setText(trUtf8("Bitte Flugrichtung bestimmen, oder als unbestimmt markieren."));
				QAbstractButton *nextButton = msgBox->addButton(trUtf8("Ok"), QMessageBox::NoRole);
				QAbstractButton *noDirButton = msgBox->addButton(trUtf8("Unbestimmt"), QMessageBox::YesRole);
				msgBox->exec();
				if (msgBox->clickedButton() == nextButton) {
					delete msgBox;
					return false;
				} else if (msgBox->clickedButton() == noDirButton) {
					curObj->direction = -1;
				}
				delete msgBox;
		} else if (curObj->behavior != "FLY") {
			curObj->direction = -1;
		}
	} else if (curObj->type == "MAMMAL") {
		if (curObj->direction < 0) {
			QMessageBox * msgBox = new QMessageBox();
			msgBox->setText(trUtf8("Bitte Schwimmrichtung bestimmen, oder als unbestimmt markieren."));
			QAbstractButton *nextButton = msgBox->addButton(trUtf8("Ok"), QMessageBox::NoRole);
			QAbstractButton *noDirButton = msgBox->addButton(trUtf8("Unbestimmt"), QMessageBox::YesRole);
			msgBox->exec();
			if (msgBox->clickedButton() == nextButton) {
				delete msgBox;
				return false;
			} else if (msgBox->clickedButton() == noDirButton) {;
				curObj->direction = -1;
			}
			delete msgBox;
		}
	}
	return true;
}

/*
 * SLOTS
 */

/*
 * Recalculate direction value depending on QDial value
 * Set the direction value only when dial is touched
 */
void MainWindow::handleDirDial() {
	if (curObj == 0) return;
    qDebug() << "Handle direction dial with value: " << dirDial->value();
    curObj->direction = (dirDial->value() + 180)%360;
    qDebug() << curObj->direction;
}

/*
 * Read results for the selected censor and set the Ui elements respectively
 */
void MainWindow::handleUsrSelect(int index) {
    census * obj;
    if (index == -1) return;
    obj = db->getRawObjectData(QString::number(curObj->id), wdgCensus->cmbUsers->currentText());
    UiPreSelection(obj);
    delete obj;
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
    wdgCensus->btnSave->setEnabled(false);
    wdgCensus->btnDelete->setEnabled(false);

    session = wdgSession->cmbSession->currentText();
    config->setSessionName(session);
    filterMap["session"] = QString("session='%1'").arg(session);
    object_model->setFilter(QStringList(filterMap.values()).join(" AND "));
    currentRow = -1;
	wdgObjects->tblObjects->setModel(object_model);
	wdgObjects->tblObjects->hideColumn(0);
	wdgObjects->tblObjects->hideColumn(6);
	wdgObjects->tblObjects->hideColumn(7);
	wdgObjects->tblObjects->hideColumn(8);
	object_model->select();

    if (!ui->toolbox_widget->getCategoryButton("Projektauswahl")->isChecked())
        ui->toolbox_widget->getToolboxSection("Projektauswahl")->setExpanded(false);
    if (!ui->toolbox_widget->getCategoryButton("Objektauswahl")->isChecked())
    	 ui->toolbox_widget->getToolboxSection("Objektauswahl")->setExpanded(true);
}

void MainWindow::handleObjectSelection() {
	wdgCensus->cmbUsers->disconnect();
    wdgGraphics->sldBrightness->setValue(0);
    wdgGraphics->sldContrast->setValue(0);

    if (objSelector->selectedRows().isEmpty()) return;
    currentRow = objSelector->selectedRows().at(0).row();
    QString objId = getObjectItemData(currentRow, 1).toString();
    QString cam = getObjectItemData(currentRow, 2).toString();
    QString img = getObjectItemData(currentRow, 3).toString();
    QString type = getObjectItemData(currentRow, 4).toString();

    wdgCensus->cmbUsers->clear();
    curObj = db->getRawObjectData(objId, config->getUser());

    if (!imgcvs->loadObject(curObj)) {
        wdgCensus->btnSave->setEnabled(false);
        wdgCensus->btnDelete->setEnabled(false);
        wdgCensus->btnBirdSizeLength->setEnabled(false);
        wdgCensus->btnBirdSizeSpan->setEnabled(false);
        wdgCensus->btnMammalSizeLength->setEnabled(false);
        return;
    }

    if (curObj->type.isEmpty()) curObj->type = type;
    censorList = db->getUserList(objId);
    wdgCensus->cmbUsers->addItems(censorList);

    group_dialog->setDataModel(db->getCloseObjects(curObj));
    family_dialog->setDataModel(db->getCloseObjects(curObj));

    association_dialog->set_id_list(&curObj->stuk4_ass);
    behaviour_dialog->set_id_list(&curObj->stuk4_beh);
    family_dialog->set_id_list(&curObj->family);
    group_dialog->set_id_list(&curObj->group);

    UiPreSelection(curObj);

    // handle user selection
    if ((curObj->censor > 0) && (db->getMaxCensor(QString::number(curObj->id),config->getUser()) > 1)) {
        wdgCensus->btnDelete->setEnabled(false);
        wdgCensus->btnSave->setEnabled(false);
    } else {
        wdgCensus->btnDelete->setEnabled(true);
        wdgCensus->btnSave->setEnabled(true);
    }
    if (curObj->censor < 0)
        wdgCensus->btnDelete->setEnabled(false);

    if (db->getCensorCount(QString::number(curObj->id), "1", config->getUser()) >= 2
            || db->getMaxCensor(QString::number(curObj->id)) >= 2) {
        wdgCensus->cmbUsers->setDisabled(false);
    } else {
        wdgCensus->cmbUsers->clear();
        wdgCensus->cmbUsers->setDisabled(true);
    }

    wdgCensus->btnBirdSizeLength->setEnabled(true);
    wdgCensus->btnBirdSizeSpan->setEnabled(true);
    wdgCensus->btnMammalSizeLength->setEnabled(true);
    // If project done can't change anything
    if (!db->getSessionActive(session)) {
        wdgCensus->btnSave->setEnabled(false);
        wdgCensus->btnDelete->setEnabled(false);
    }
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
    connect(wdgCensus->cmbUsers, SIGNAL(currentIndexChanged(int)), this, SLOT(handleUsrSelect(int)));
}

void MainWindow::handleSaveButton() {
    qDebug() << "Trying to save as user: " << curObj->usr;

    curObj->type = wdgCensus->wdgTabTypes->currentWidget()->property("dbvalue").toString();

    // Check wether all inputs are done
    bool check_required = false;
    if(curObj->type == "BIRD") {
    	check_required = true;
    	SaveComboBoxSelection(wdgCensus->cmbBird);
        curObj->confidence = GetButtonGroupValue(wdgCensus->buttongroup_bird_confidence, "dbvalue").toInt();
        curObj->behavior = GetButtonGroupValue(wdgCensus->buttongroup_bird_behaviour, "dbvalue").toString();
        curObj->gender = GetGroupBoxValue(wdgCensus->gbxBirdGender, wdgCensus->buttongroup_bird_sex, "dbvalue").toString();
    	if (wdgCensus->gbxBirdAge->isChecked()) {
            curObj->age = GetButtonGroupValue(wdgCensus->buttongroup_bird_age, "dbvalue").toString();
    		curObj->age_year = GetComboBoxItem(wdgCensus->cmb_bird_age).toInt();
    	} else {
    		curObj->age = "";
    		curObj->age_year = -1;
    	}
    	if (wdgCensus->group_box_plumage->isChecked())
    		curObj->plumage = wdgCensus->combo_box_plumage->itemData(
    				wdgCensus->combo_box_plumage->currentIndex()).toString();
    	else
    		curObj->plumage = "";
    } else if (curObj->type == "MAMMAL") {
    	check_required = true;
    	SaveComboBoxSelection(wdgCensus->cmbMammal);
        curObj->confidence = GetButtonGroupValue(wdgCensus->buttongroup_mammal_confidence,"dbvalue").toInt();
        curObj->behavior = GetButtonGroupValue(wdgCensus->buttongroup_mammal_behaviour, "dbvalue").toString();
        curObj->age = GetGroupBoxValue(wdgCensus->gbxMammalAge, wdgCensus->buttongroup_mammal_age, "dbvalue").toString();
        curObj->age_year = -1;
        curObj->gender = "";
    } else if (curObj->type == "NOSIGHT" || curObj->type=="UNKNOWN" ) {
        curObj->name = "";
        curObj->confidence = GetButtonGroupValue(wdgCensus->buttongroup_nosight_confidence, "dbvalue").toInt();
        curObj->behavior = "";
        curObj->age = "";
        curObj->code = "";
        curObj->age_year = -1;
        curObj->gender = "";
        curObj->direction = -1;
        curObj->code = "";
    } else if (curObj->type == "ANTHRO") {
        curObj->name = wdgCensus->cmbAnthroName->currentText();
        curObj->code = GetComboBoxItem(wdgCensus->cmbAnthroName).toString();
        curObj->confidence = GetButtonGroupValue(wdgCensus->buttongroup_anthro_confidence, "dbvalue").toInt();
        curObj->behavior = "";
        curObj->age = "";
        curObj->age_year = -1;
        curObj->gender = "";
        curObj->direction = -1;
    } else if (curObj->type == "MISC") {
        curObj->name = wdgCensus->cmb_misc_name->currentText();
        curObj->code = GetComboBoxItem(wdgCensus->cmb_misc_name).toString();
        curObj->confidence = GetButtonGroupValue(wdgCensus->buttongroup_misc_confidence, "dbvalue").toInt();
        curObj->behavior = "";
        curObj->age = "";
        curObj->age_year = -1;
        curObj->gender = "";
        curObj->direction = -1;
    } else {
        qDebug() << "Invalid save type. Aborting.";
        return;
    }

    if (!CheckInputValidity()) return;

    curObj->remarks = wdgCensus->textedit_remarks->toPlainText();

    if (check_required || curObj->confidence != 1 || db->getMaxCensor(QString::number(curObj->id), curObj->usr) > 0) {
    	int tmpcensor = 0;
		if (db->getMaxCensor(QString::number(curObj->id), curObj->usr) >= 2) {
			tmpcensor = 0;
		} else if (db->getMaxCensor(QString::number(curObj->id), curObj->usr) == 1) {
			if (db->getCensorCount(QString::number(curObj->id), "1", config->getUser()) > 1) {
				tmpcensor = 3;
			} else {
				tmpcensor = 2;
			}
		} else if (db->getMaxCensor(QString::number(curObj->id), curObj->usr) < 1) {
			tmpcensor = 1;
		} else {
			tmpcensor = -1;
		}

		switch (tmpcensor) {
			case -1: {
				qDebug() << "Kann Nuzter nicht bestimmen!";
				curObj->censor = -1;
				break;
			} case 0: {
				qDebug() << "Zusätzlicher Bestimmer.";
				curObj->censor = 0;
				QMessageBox * msgBox = new QMessageBox();
				msgBox->setText(trUtf8("Objekt bereits Endbestimmt. Abspeichern als zusätzliche Bestimmung."));
				msgBox->addButton(trUtf8("Ok"), QMessageBox::YesRole);
				msgBox->exec();
				delete msgBox;
				break;
			} case 1: {
				qDebug() << "Erster Bestimmer.";
				curObj->censor = 1;
				break;
			} case 2: {
				qDebug() << "Zweiter Bestimmer.";
				curObj->censor = 2;
				census * cenObj = db->getCensusData(QString::number(curObj->id));
				bool agree = compareResults(curObj, cenObj);
				if (!agree) {
					QMessageBox * msgBox = new QMessageBox();
					msgBox->setText(QString::fromUtf8("Keine Übereinstimmung zum Erstbestimmer.\n"
							" Noch keine Endbestimmung möglich.\n"
							"Bestimmung als Vorbestimmer."));
					msgBox->addButton(trUtf8("Ok"), QMessageBox::YesRole);
					msgBox->exec();
					delete msgBox;
					curObj->censor = 1;
				}
				break;
			} case 3: {
				qDebug() << "Ditter Bestimmer.";
				curObj->censor = 2;
				QMessageBox * msgBox = new QMessageBox();
				msgBox->setText("Endbestimmung als " + QString::number(censorList.size()) + ". Bestimmer. \n"
						+ "Bitte mit " + censorList.join(", ") + " abstimmen.");
				msgBox->addButton(trUtf8("Ok"), QMessageBox::YesRole);
				QAbstractButton *noButton = msgBox->addButton(trUtf8("Abbrechen"), QMessageBox::NoRole);
				msgBox->exec();
				if (msgBox->clickedButton() == noButton) {
					delete msgBox;
					return;
				}
				break;
			} default: {
				qDebug() << "Exit route on switch!";
				exit(1);
			}
		}
    } else {
    	curObj->censor = 2;
    }


    if (wdgGraphics->chbImgQuality->isChecked()) {
        curObj->imageQuality = 1;
    } else {
        curObj->imageQuality = 0;
    }

    // write object data to db
    if (!db->writeCensus(curObj)) {
        QMessageBox * msgBox = new QMessageBox();
        msgBox->setText(QString::fromUtf8("Fehler beim schreiben in die Datenbank."
                "Der Datensatz wurde möglicherweise nicht gespeichert."));
        msgBox->addButton(trUtf8("Ok"), QMessageBox::YesRole);
        msgBox->exec();
        delete msgBox;
        return;
    }

    // delete object structure
    delete curObj;
    wdgCensus->btnSave->setEnabled(false);
    wdgCensus->btnDelete->setEnabled(false);
    // select next object in table
	QModelIndex newIndex = objSelector->model()->index(currentRow+1, 0);
	wdgObjects->tblObjects->scrollTo(newIndex);
	objSelector->select(newIndex, QItemSelectionModel::ClearAndSelect | QItemSelectionModel::Rows);
	object_model->select();
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

void MainWindow::handleDeleteButton() {
    db->deleteCensusData(QString::number(curObj->id), config->getUser());
    wdgCensus->btnDelete->setEnabled(false);
    handleSessionSelection();
}

void MainWindow::handleBirdSpanMeasurement() {
    conductMeasurement(&curObj->span, wdgCensus->lblBirdSizeSpan);
};

void MainWindow::handleBirdLengthMeasurement() {
    conductMeasurement(&curObj->length, wdgCensus->lblBirdSizeLength);
};

void MainWindow::handleMammalLengthMeasurement() {
    conductMeasurement(&curObj->length, wdgCensus->lblMammalSizeLength);
};

void MainWindow::handleMiscMeasurement() {
	if (curObj == 0) return;
    conductMeasurement(0,0);
}

void MainWindow::handleFlightInfoAction() {
}

void MainWindow::HandleAssociationSelection() {
	association_dialog->ToggleHidden();
}

void MainWindow::HandleBehaviourSelection() {
	behaviour_dialog->ToggleHidden();
}

void MainWindow::HandleGroupSelection() {
	group_dialog->ToggleHidden();
}

void MainWindow::HandleFamilySelection() {
	family_dialog->ToggleHidden();
}

void MainWindow::HandleActiveCensusElements() {
	if (curObj == 0) return;
	curObj->type = wdgCensus->wdgTabTypes->currentWidget()->property("dbvalue").toString();
	if (curObj->type == "BIRD" || curObj->type == "MAMMAL") {
		wdgCensus->frame_id_selections->setEnabled(true);
	} else {
		wdgCensus->frame_id_selections->setEnabled(false);
	}
}

void MainWindow::HandleServerSelection() {
	if (wdgSession->combo_server->currentText().isEmpty()) {
		wdgSession->cmbSession->setEnabled(false);
		return;
	}

	wdgSession->cmbSession->clear();
	config->setPreferredDatabase(wdgSession->combo_server->currentText());
	if (db->OpenDatabase())
		object_model = db->getObjectModel();

	if (association_dialog->dataModel() != 0)
		delete association_dialog->dataModel();
    association_dialog->setDataModel(db->getStuk4Associations());
    if (behaviour_dialog->dataModel() != 0)
    	delete behaviour_dialog->dataModel();
    behaviour_dialog->setDataModel(db->getStuk4Behaviour());

    wdgCensus->cmb_bird_age->clear();
    db->GetBirdAgeClasses(wdgCensus->cmb_bird_age);
    wdgCensus->cmb_misc_name->clear();
    db->GetMiscObjects(wdgCensus->cmb_misc_name);
    wdgCensus->cmbAnthroName->clear();
    db->GetAnthroObjectList(wdgCensus->cmbAnthroName);
    wdgCensus->cmb_bird_age->clear();
    db->GetBirdAgeClasses(wdgCensus->cmb_bird_age);
    wdgCensus->cmbMammal->clear();
    db->getSpeciesList("MAMMAL", wdgCensus->cmbMammal);
    wdgCensus->cmbBird->clear();
    db->getSpeciesList("BIRD", wdgCensus->cmbBird);
    wdgCensus->combo_box_plumage->clear();
    db->GetBirdPlumageClasses(wdgCensus->combo_box_plumage);

	wdgSession->cmbSession->addItem(QString());
	wdgSession->cmbSession->setCurrentIndex(0);
	wdgSession->cmbSession->addItems(db->getSessionList());
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

void MainWindow::handleUserSwitch() {
	bool ok;
	QString password, user;
	user = QInputDialog::getText(this, tr("Nutzer wechseln"), tr("User:"), QLineEdit::Normal,QString(),&ok);
    if (!ok)
        return;
	password = QInputDialog::getText(this, tr("Admin Zugang freischalten"), tr("Passwort:"), QLineEdit::Password,QString(),&ok);
	/*
	 * MD5 sum of password
	 * b90793dee6e8828cef899658c45ad8aa
	 */

	QCryptographicHash password_hash(QCryptographicHash::Md5);
	password_hash.addData(password.toStdString().c_str());
	if (ok ) {
		if(QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5).toHex())
				== QString("b90793dee6e8828cef899658c45ad8aa")) {
			QMessageBox message;
			message.setText(tr("Nutzer erfolgreich gewechselt."));
			message.setStandardButtons(QMessageBox::Ok);
			message.exec();
			config->setUser(user);
		} else {
			QMessageBox message;
			message.setText("Nutzerwechsel fehlgeschlagen: Falsches Passwort.");
			message.setStandardButtons(QMessageBox::Ok);
			message.exec();
		}
    }
}
