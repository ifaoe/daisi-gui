#include <QStyle>
#include <QInputDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "db.h"
#include "QSearchDialog.h"

MainWindow::MainWindow(ConfigHandler *aConfig, Database * aDb)
    : QMainWindow(0), config(aConfig), ui(new Ui::MainWindow), db(aDb)
{
	qDebug() << "Main Window Construct";
    // Aufsetzen der GUI Grundumgebung + Logger
    ui->setupUi(this);
    resize(config->getAppSize());
    move(config->getAppPosition());


    this->setWindowTitle("BirdCensus");

    // Der QGIS Umgebung
    qgsPvrRegistry = QgsProviderRegistry::instance();
    qgsLyrRegistry = QgsMapLayerRegistry::instance();
    qgsCheckProviders();

    guiInitAdditionals();

//	QPalette dark_palette = ui->tbwObjects->palette();
//	ui->tbwObjects->viewport()->setBackgroundRole(QPalette::AlternateBase);
////	dark_palette.setColor(QPalette::Window, Qt::lightGray);
//	dark_palette.setColor(QPalette::AlternateBase, Qt::gray);
//	ui->tbwObjects->setPalette(dark_palette);

	initSessionFrame();

    object_table_model = db->getObjectView();
    ui->tbwObjects->setModel(object_table_model);
    ui->tbwObjects->hideColumn(object_table_model->fieldIndex("ux"));
    ui->tbwObjects->hideColumn(object_table_model->fieldIndex("uy"));
    ui->tbwObjects->hideColumn(object_table_model->fieldIndex("lx"));
    ui->tbwObjects->hideColumn(object_table_model->fieldIndex("ly"));
    ui->tbwObjects->hideColumn(object_table_model->fieldIndex("cam"));
    ui->tbwObjects->hideColumn(object_table_model->fieldIndex("img"));
    ui->tbwObjects->hideColumn(object_table_model->fieldIndex("session"));
//    ui->tbwObjects->setBackgroundRole(QPalette::Base);
//    ui->tbwObjects->setAutoFillBackground( true );
    ui->tbwObjects->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);


    if (config->getAdmin()) {
        ui->option_admin->setEnabled(false);
        ui->option_admin->setIcon(QIcon::fromTheme("object-unlocked"));
    }

/*
 * TODO:
 * werden die beiden tableview selectionModels wirklich gebraucht?
 */

    objSelector = ui->tbwObjects->selectionModel();

    connect( ui->btnMapSelect, SIGNAL(clicked()), this, SLOT(clearSelection()));

    connect( ui->btnMapRmObj, SIGNAL(clicked()), this, SLOT(deleteSelection()));

    connect( objSelector, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(objUpdateSelection(QModelIndex,QModelIndex)));

    connect( ui->cmbSession, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSessionSelection()));

    connect( ui->chbHideMarker, SIGNAL(clicked(bool)), mapCanvas, SLOT(hideMarker(bool)));

    connect( ui->option_admin, SIGNAL(clicked()), this, SLOT(handleAdminPass()));

    connect( ui->chbNotReady, SIGNAL(stateChanged(int)), this, SLOT(handleMissingCheckBox(int)));

    connect( ui->image_table->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(handleHeaderFilter(int)));

    connect( ui->option_location, SIGNAL(clicked()), this, SLOT(handleLocationSelection()));
}

// ------------------------------------------------------------------------
void MainWindow::saveData() {
   mapCanvas->doSaveData(config->current_cam, config->current_image);
   ovrCanvas->saveRawTile(false);
	config->setAppPosition(pos());
	config->setAppSize(size());
	config->setAppMaximized(isMaximized());
	config->sync();
}

// ------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}

// ------------------------------------------------------------------------
void MainWindow::qgsCheckProviders() {
    qDebug() << "QGIS PREFIX PATH IS "+config->getQGisPrefixPath();
    QString msg;
    qDebug() << "OPEN PROVIDER LIST";
    QStringList providers = qgsPvrRegistry->providerList();
    qDebug() << QString("PROVIDERS %1 FOUND").arg(providers.size());
    if (providers.size()==0) {
        qFatal("%s\n%s\n qgis : {\n  prefixPath=%s; \n  ... \n}",
               "Die Providerliste ist leer.",
               MNDW_ERR_MISSING_HINT_PFX,
               qPrintable(config->getQGisPrefixPath()) );
    }
    bool doneGdal = false;
    bool doneOgr = false;
    bool donePGIS = false;
    for (int i=0; i<providers.size(); ++i) {
        if (!doneGdal) { doneGdal = (providers.at(i) == QString("gdal")); }
        if (!doneOgr)  { doneOgr  = (providers.at(i) == QString("ogr")); }
        if (!donePGIS) { donePGIS = (providers.at(i) == QString("postgres")); }
        qDebug() << msg.sprintf("PROVIDER %0d: %s", (i+1),
                                providers.at(i).toUtf8().data());
    }
    if (!doneGdal) {
        qFatal(MNWD_ERR_MISSING_PROVIDER, "GDAL",
               MNDW_ERR_MISSING_HINT_PFX);
    } else { 	qDebug() << "TEST PROVIDER GDAL OK";  }

    if (!doneOgr) {
        qFatal(MNWD_ERR_MISSING_PROVIDER, "OGR",
               MNDW_ERR_MISSING_HINT_PFX);
    } else {  qDebug() << "TEST PROVIDER OGR OK"; }

    if (!donePGIS) {
        qFatal(MNWD_ERR_MISSING_PROVIDER, "Postgresql/PostGIS",
               MNDW_ERR_MISSING_HINT_PFX);
     } else {  qDebug() << "TEST PROVIDER POSTGRESQL/POSTGIS OK"; }

}


// ----------------------------------------------------------------------
void MainWindow::guiInitAdditionals() {

    QVBoxLayout *lytFrmImg = new QVBoxLayout;
    lytFrmImg->setMargin(0);
    mapCanvas = new CnsMapCanvas(this, ui, config, db, qgsLyrRegistry);
    lytFrmImg->addWidget(mapCanvas);
    ui->wdgMap->setLayout(lytFrmImg);

    QVBoxLayout *lytFrmOvr = new QVBoxLayout;
    lytFrmOvr->setMargin(0);
    ovrCanvas = new OvrMapCanvas(this, ui, config, db, mapCanvas, qgsLyrRegistry);
    lytFrmOvr->addWidget(ovrCanvas);
    ui->wdgOverview->setLayout(lytFrmOvr);

    connect(ui->btnPrevTile, SIGNAL(clicked()),
            ovrCanvas, SLOT( doSelectPrevTile()));

    connect(ui->btnNextTile, SIGNAL(clicked()),
            ovrCanvas, SLOT( doSelectNextTile()));

    ready_image_warning = new QLabel(mapCanvas);
    ready_image_warning->hide();
    ready_image_warning->setText("Bild bereits betrachtet!");

    QFont font("Sans Serif", 14, QFont::Bold);
    ready_image_warning->setFont(font);

    ready_image_warning->setStyleSheet("QLabel { background-color : red; color : black; }");

    /*
     * NOT WORKING:
     * Versuch die "Bereits betrachtet" Warnung ohne StyleSheet zu ändern
    QPalette palette = ready_image_warning->palette();
    palette.setColor(ready_image_warning->backgroundRole(), Qt::darkRed);
    palette.setColor(ready_image_warning->foregroundRole(), Qt::darkRed);
    ready_image_warning->setPalette(palette);
    */
}

/*
 * Gibt eine komplette, distinkte Liste der Werte in der Bereits gefilterten Tabelle aus.
 * Die Funktion operiert auf dem zugrundeliegenden Model.
 * Wird für die Filterfunktion mittels QSearchDialog benötigt
 * TODO: maximale Länge der Filterliste und max. Iterationszahl für sehr große Tabellen
 */
QStringList MainWindow::getColumnDataList(int column) {
    QStringList return_list;
    for (int row=0; row<image_table_model->rowCount(); row++) {
        QString item = image_table_model->data(row, column).toString();
        if (!return_list.contains(item))
            return_list.append(item);
    }
    return return_list;
}

/*
 * Verbindung der UI zur Datenbankschnittstelle um markierte Objekte zu löschen
 */
void MainWindow::deleteSelection() {
	QModelIndex index = objSelector->selectedRows(0).at(0);
	int rcns_id = ui->tbwObjects->model()->data(index).toInt();
    // Objekt aus der Datenbank löschen
    db->deleteRawCensus(rcns_id, selected_cam, selected_file, config->getUser());
    // Aktuelle Objektliste laden
    // Das ist die sichere Variante zum seperaten Löschen in DB und UI
    mapCanvas->UpdateObjectMarkers();

}

void MainWindow::clearSelection() {
	mapCanvas->DeselectObjects();
	objSelector->reset();
}

void MainWindow::objUpdateSelection(QModelIndex old_index,QModelIndex new_index) {
    Q_UNUSED(old_index);
    Q_UNUSED(new_index);

    int row = objSelector->currentIndex().row();
    ui->tbwObjects->scrollTo(new_index);
    ui->btnMapRmObj->setEnabled(false);

    mapCanvas->DeselectObjects();

    int rcns_id =  object_table_model->data(row, object_table_model->fieldIndex("rcns_id")).toInt();
    QString user = object_table_model->data(row, object_table_model->fieldIndex("usr")).toString();
    double utm_x = object_table_model->data(row, object_table_model->fieldIndex("ux")).toDouble();
    double utm_y = object_table_model->data(row, object_table_model->fieldIndex("uy")).toDouble();

	mapCanvas->doCenter1by1(utm_x,utm_y);
	if (mapCanvas->map_mode() == MAP_MODE_SELECT) {
		mapCanvas->SelectObjectById(rcns_id);
		if (user == config->getUser() || config->getAdmin())
			ui->btnMapRmObj->setEnabled(true);
	}
}

// ----------------------------------------------------------------------
void MainWindow::handleImageSelection()
 {
	if (imgSelector->selectedIndexes().isEmpty())
		return;

	objSelector->clearSelection();
	int currentRow = imgSelector->selectedRows().at(0).row();
    selected_file = image_table_model->data(currentRow, image_table_model->fieldIndex("img")).toString();
    selected_cam  = image_table_model->data(currentRow, image_table_model->fieldIndex("cam")).toString();
    config->current_cam = selected_cam;
    config->current_image = selected_file;
    bool image_done = image_table_model->data(currentRow, image_table_model->fieldIndex("examined")).toBool();
    bool analysed = image_table_model->data(currentRow, image_table_model->fieldIndex("analysed")).toBool();

    if (!analysed) {
        QMessageBox::information(this, "Information", QString("Bild %1 auf Kamera %2 wurde aus der Auswertung genommen.").arg(selected_file).arg(selected_cam),"OK");
        return;
    }

	  ui->chbHideMarker->setChecked(false);
	  if (!mapCanvas->doSaveData(config->current_cam, config->current_image)) {
		  QMessageBox::critical(this,"Fehler","Fehler beim Sichern der Daten fuer"
								"Metadaten fuer "+config->current_cam+" Kamera "+config->current_image+
								"\n konnte nicht gesichert werden!",
							   "OK");
		  imgSelector->clearSelection();
		  return;
	  }
	  if (!mapCanvas->doOpenRasterLayer(selected_cam, selected_file)) {
		  QMessageBox::critical(this,"Fehler beim Laden Bilddatei",
		  "Bild "+selected_file+" Kamera "+selected_cam+
		  "\n konnte nicht geoeffnet werden!","OK");
		  imgSelector->clearSelection();
		  return;
	  }
	  if (!ovrCanvas->openImageEnvelope(selected_cam, selected_file, mapCanvas->extent())) {
		  QMessageBox::critical(this,"Fehler beim Laden der Envelope",
		  "Envelope fuer Bild "+selected_file+" Kamera "+selected_cam+
		  "\n konnte nicht geoeffnet werden!","OK");
		  imgSelector->clearSelection();
		  return;
	  }
	  if (!ovrCanvas->openImageTiles(selected_cam, selected_file)) {
		  QMessageBox::critical(this,"Fehler beim Laden der Tiles",
		  "Tiles fuer Bild "+selected_file+" Kamera "+selected_cam+
		  "\n konnte nicht geoeffnet werden!","OK");
		  imgSelector->clearSelection();
		  return;
	  }
	  this->setWindowTitle("BirdCensus - Kamera "
			  + selected_cam +" - "+selected_file);
	  ovrCanvas->doSelectFirstTile();

    if (config->getProjectId().startsWith("Testdatensatz") && !config->getAdmin())
        object_table_model->setFilter(QString("session='%1' AND cam='%2' AND img='%3' AND usr='%4'")
                                      .arg(config->getProjectId()).arg(config->getCurrentCam()).arg(config->getCurrentImage()).arg(config->getUser()));
    else
        object_table_model->setFilter(QString("session='%1' AND cam='%2' AND img='%3'").arg(config->getProjectId()).arg(config->getCurrentCam()).arg(config->getCurrentImage()));
      object_table_model->select();

	  ui->tbxTasks->setCurrentIndex(1);
	  mapCanvas->setFocus();
	  mapCanvas->doSetupEditModus();

      mapCanvas->UpdateObjectMarkers();
	  mapCanvas->setEnabled(true);
	  ovrCanvas->setEnabled(true);

      if (image_done)
		  ready_image_warning->show();
	  else
		  ready_image_warning->hide();
 }


// ----------------------------------------------------------------------

bool MainWindow::checkButtonByKey(QString tp) {
	QList<QAbstractButton*> btnList = ui->button_group_types->buttons();
	for (int i=0; i<btnList.size(); i++) {
		if (btnList[i]->property("dbvalue").toString() == tp) {
			btnList[i]->setChecked(true);
			return true;
		}
	}
	QAbstractButton * cbtn = ui->button_group_types->checkedButton();
	if ( cbtn != 0 )
		cbtn->setChecked(false);
	return false;
}

void MainWindow::initSessionFrame() {
	ui->cmbSession->clear();
	ui->cmbSession->addItem("");
	ui->cmbSession->addItems(db->getSessionList());
}

void MainWindow::handleSessionSelection() {
    if (!mapCanvas->saveData(config->current_cam, config->current_image)) {
        QMessageBox::critical(this,"Fehler","Fehler beim Sichern der Daten fuer"
                              "Metadaten fuer "+config->current_cam+" Kamera "+config->current_image+
                              "\n konnte nicht gesichert werden!",
                             "OK");
        imgSelector->clearSelection();
    }
	config->setProjectId(ui->cmbSession->currentText());
	if (config->getProjectId().isEmpty())
		return;
    QStringList project_parameters = db->getSessionParameters(config->getProjectId());
    qDebug() << config->getProjectId();
    config->setFlightId(project_parameters[0]);
    config->setUtmSector(project_parameters[1].toInt());
    config->setProjectPath(project_parameters[2]);

    /*
     * Filtern nach session und anschließend nach project_list.
     * Operation auf unindizierter project_list ist sonst zu langsam.
     * TODO: image_properties neu indizieren
     */
    filter_map.clear();
    filter_map["session"] = QString("session='%1' AND project='%2'").arg(config->getFlightId()).arg(config->getProjectId());
    ui->chbNotReady->setChecked(false);
    /*
     * ModelView referenziert Datenbank-View daisi_bird_census_images
     * session und rdy Spalte werden ausgeblendet
     */
    image_table_model = db->getImageView();
    ui->image_table->setModel(image_table_model);
    ui->image_table->hideColumn(image_table_model->fieldIndex("session"));
    ui->image_table->hideColumn(image_table_model->fieldIndex("project"));
    ui->image_table->hideColumn(image_table_model->fieldIndex("project_list"));
    ui->image_table->hideColumn(image_table_model->fieldIndex("examined"));
    ui->image_table->hideColumn(image_table_model->fieldIndex("analysed"));
    ui->image_table->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    image_table_model->setFilter(getFilterString());
    image_table_model->select();
    qDebug() << image_table_model->query().executedQuery();
    qDebug() << image_table_model->filter();

    imgSelector = ui->image_table->selectionModel();
    connect( imgSelector, SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(handleImageSelection()));
}

QString MainWindow::getFilterString() {
    QStringList filter_list = filter_map.values();
	return filter_list.join(" AND ");
}

void MainWindow::handleMissingCheckBox(int state) {
    if (state == Qt::Checked)
        filter_map["missing"] = "examined IS FALSE";
    else
        filter_map.remove("missing");
    image_table_model->setFilter(getFilterString());
    qDebug() << image_table_model->query().executedQuery();
    qDebug() << image_table_model->filter();
}

QAbstractButton * MainWindow::GetButtonByKey(QButtonGroup * button_group, QString key, QString value) {
	QList<QAbstractButton*> button_list = button_group->buttons();
	for (int i=0; i<button_list.size(); i++) {
		if (button_list[i]->property(key.toStdString().c_str()).toString() == value) {
			return button_list[i];
		}
	}
	return NULL;
}

void MainWindow::RefreshObjectList() {
    object_table_model->query().exec();
}

void MainWindow::handleAdminPass() {
	bool ok;
	QString password;
	password = QInputDialog::getText(this, tr("Admin Zugang freischalten"), tr("Passwort:"), QLineEdit::Password,QString(),&ok);
	/*
	 * MD5 sum of password
     * 5d2e35ab7e9e437b5a81a55ef8a1c895
	 */

	QCryptographicHash password_hash(QCryptographicHash::Md5);
	password_hash.addData(password.toStdString().c_str());
	if (ok ) {
		if(QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5).toHex())
                == QString("5d2e35ab7e9e437b5a81a55ef8a1c895")) {
			QMessageBox message;
			message.setText(tr("Adminzugang erfolgreich freigeschaltet."));
			message.setStandardButtons(QMessageBox::Ok);
			message.exec();
			config->setAdmin(true);
		} else {
			QMessageBox message;
			message.setText("Admin Freischaltung: Falsches Passwort.");
			message.setStandardButtons(QMessageBox::Ok);
			message.exec();
		}
	}
}

void MainWindow::handleHeaderFilter(int index) {
    QSearchDialog dialog;
    dialog.updateItemList(getColumnDataList(index));
    if (dialog.exec()) {
        if (dialog.isSorted())
            ui->image_table->sortByColumn(index, dialog.getSortingOrder());
        if (dialog.getFilterString().isEmpty())
            filter_map.remove(image_table_model->headerData(index, Qt::Horizontal).toString());
        else
            filter_map[image_table_model->headerData(index, Qt::Horizontal).toString()] =
                    QString("cast(%1 as text) LIKE '%2'").arg(image_table_model->record().fieldName(index)).arg(dialog.getFilterString());
        image_table_model->setFilter(getFilterString());
    }

}

void MainWindow::handleLocationSelection() {
    bool ok;
    QString location = QInputDialog::getItem(this, tr("Standortwahl"), tr("Bitte den Standort wählen"), db->getLocationList(), 0, false, &ok);
    if (location.isEmpty() || !ok)
        return;
    config->setLocation(location);
    ui->cmbSession->clear();
    ui->cmbSession->addItem("");
    ui->cmbSession->addItems(db->getSessionList());
}
