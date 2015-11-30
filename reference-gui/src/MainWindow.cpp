/*
 * MainWindow.cpp
 *
 *  Created on: Aug 7, 2015
 *      Author: awg
 */

#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "ImagePopup.h"
#include "ColumnChooser.h"
#include <QSqlError>
#include <QDebug>
#include <QScrollBar>
#include <QInputDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include "QSearchDialog.h"

MainWindow::MainWindow(UserSettings * config, DatabaseHandler * db)
	: QMainWindow(0), ui(new Ui::MainWindow), config(config), db(db){
	// TODO Auto-generated constructor stub
	ui->setupUi(this);

	type_tab_bar = new QTabBar(ui->widget_types);
	type_tab_bar->setExpanding(true);
	type_tab_bar->setShape(QTabBar::RoundedNorth);
	type_tab_bar->setCurrentIndex(-1);
	type_tab_bar->addTab(QString::fromUtf8("Alle Sichtungen"));
	type_tab_bar->addTab(QString::fromUtf8("Vögel"));
	type_tab_bar->addTab(QString::fromUtf8("Meeressäuger"));
	type_tab_bar->addTab(QString::fromUtf8("Anthropogenes"));
	type_tab_bar->addTab(QString::fromUtf8("Sonstiges"));
	type_tab_bar->addTab(QString::fromUtf8("Keine Sichtung"));

	type_tab_bar->setTabData(0,"%");
	type_tab_bar->setTabData(1,"BIRD");
	type_tab_bar->setTabData(2,"MAMMAL");
	type_tab_bar->setTabData(3,"ANTHRO");
	type_tab_bar->setTabData(4,"MISC");
	type_tab_bar->setTabData(5,"NOSIGHT");

	ui->widget_types->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
	ui->widget_types->setFixedHeight(type_tab_bar->height());
	filter_map["standard"] = "confidence<4 AND censor=2";

	if (!db->OpenDatabase())
		HandleServerSelection();

	SetDatabaseModels();
	ui->table_view_objects->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->table_view_objects->setSelectionMode(QAbstractItemView::SingleSelection);

    image_canvas_layout = new QVBoxLayout;
    image_canvas_layout->setMargin(0);
	canvas = new ImageCanvas(db, ui->widget_image);
    canvas->setMaximumSize(QSize(256,256));
//    ui->widget_side->setMaximumWidth(canvas->width());

	image_canvas_layout->addWidget(canvas);
	ui->widget_image->setLayout(image_canvas_layout);

	SetupTables();
	HandleColumnVisibility();

	connect(ui->table_view_objects->selectionModel(),
			SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this,
			SLOT(HandleSelectionChange(const QItemSelection &, const QItemSelection &)));
	connect(ui->actionMit_Server_verbinden,SIGNAL(triggered()),this,SLOT(HandleServerSelection()));
	connect(ui->button_image_popup, SIGNAL(clicked()),this,SLOT(HandleImagePopup()));
	connect(ui->actionSpalten,SIGNAL(triggered()),this,SLOT(HandleColumnChooser()));
	connect(ui->button_save_image,SIGNAL(clicked()),canvas, SLOT(SaveImage()));
	connect(type_tab_bar, SIGNAL(currentChanged(int)), this, SLOT(HandleTypeFilter(int)));
	connect(ui->table_view_objects->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(handleHeaderFilter(int)));

	ui->combo_session->setSizeAdjustPolicy(QComboBox::AdjustToContents);
	populateSessionBox();
	connect(ui->combo_session, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSessionSelection(int)));

    column_translation["session"] = "Projekt";
    column_translation["cam"] = "Kamera";
    column_translation["img"] = "Bildnummer";
    column_translation["pre_usr"] = "Vorsortierer";
    column_translation["usr"] = "Endbestimmer";
    column_translation["tp"] = "Typ";
    column_translation["name"] = "Bezeichung";
    column_translation["id_code"] = "ID Code";
    column_translation["confidence"] = "Sicherheit";
    column_translation["beh"] = "Verhalten";
    column_translation["length"] = QString::fromUtf8("Länge");
    column_translation["width"] = "Breite";
    column_translation["age"] = "Alter";
    column_translation["age_year"] = "Kalenderjahr";
    column_translation["plumage"] = "Gefieder";
    column_translation["gender"] = "Geschlecht";
    column_translation["dir"] = "Richtung";
    column_translation["imgqual"] = QString::fromUtf8("Bildqualität");
    column_translation["stuk4_beh"] = "Verhaltenscodes";
    column_translation["stuk4_ass"] = "Assoziationscodes";
    column_translation["group_objects"] = "Gruppe";
    column_translation["family_group"] = "Familie";
    column_translation["rem"] = "Bemerkungen";

    column_dialog = new ColumnChooser(config);
    QMap<QString, QString>::iterator i;
    for (i=column_translation.begin(); i!=column_translation.end(); ++i)
        column_dialog->addColumn(i.value(), i.key());
}

MainWindow::~MainWindow() {
	config->setAppPosition(pos());
	config->setAppSize(size());
	config->setAppMaximized(isMaximized());
	config->sync();
}

//void MainWindow::resizeEvent(QResizeEvent *event) {
//    QMainWindow::resizeEvent(event);
//    ui->widget_side->setMaximumWidth(event->size().width()/3);
//}

void MainWindow::HandleFilter() {
	census_model->setFilter( static_cast<QStringList>(filter_map.values()).join(" AND ") );
	census_model->select();
	ui->table_view_objects->resizeColumnsToContents();
}

void MainWindow::SetupTables() {
	QString column_name;
	for (int i=0; i<census_model->columnCount();i++) {
		column_name = census_model->headerData(i,Qt::Horizontal).toString();
		census_index_map[column_name] = census_model->fieldIndex(column_name);
	}
}

void MainWindow::RefreshColumnMap() {
	census_index_map.clear();
	QString column_name;
	for (int i=0; i<census_model->columnCount();i++) {
		column_name = census_model->headerData(i,Qt::Horizontal).toString();
		census_index_map[column_name] = census_model->fieldIndex(column_name);
	}
}

void MainWindow::ClearFilter() {
	foreach (QString column, config->getVisibleColumns())
		filter_map.remove(column);
}

void MainWindow::SetDatabaseModels() {
	if (census_model != 0) {
		delete census_model;
		census_model = 0;
	}
	census_model = db->getObjectModel();
	ui->table_view_objects->setModel(census_model);
}

QStringList MainWindow::getColumnData(int column) {
	QStringList item_list;
	QString item_text;
	QModelIndex item_index;
	for (int row=0; row<census_model->rowCount(); row++) {
		item_index = census_model->index(row, column);
		item_text = census_model->data(item_index).toString();
		if (!item_list.contains(item_text))
			item_list.append(item_text);
	}
	return item_list;
}

void MainWindow::populateSessionBox() {
	ui->combo_session->clear();
	ui->combo_session->addItems(db->GetSessionList());
}

/*
 * SLOTS
 */

void MainWindow::handleSessionSelection(int index) {
	if (index > 0)
		filter_map["session"] = QString("session='%1'").arg(ui->combo_session->currentText());
	else
		filter_map.remove("session");
	HandleFilter();
}

void MainWindow::handleHeaderFilter(int column) {
    QSearchDialog dialog;
	dialog.updateItemList(getColumnData(column));
	if (dialog.exec()) {
            if (dialog.isSorted())
				ui->table_view_objects->sortByColumn(column, dialog.getSortingOrder());
			if (dialog.getFilterString().isEmpty())
				filter_map.remove(census_model->headerData(column, Qt::Horizontal).toString());
			else
				filter_map[census_model->headerData(column, Qt::Horizontal).toString()] = QString("cast(%1 as text) like '%%2%'")
					.arg(census_model->headerData(column, Qt::Horizontal).toString()).arg(dialog.getFilterString());
			census_model->setFilter(static_cast<QStringList>(filter_map.values()).join(" AND "));
    }
    ui->table_view_objects->resizeColumnsToContents();
}

void MainWindow::HandleSelectionChange(const QItemSelection & selected, const QItemSelection & deselected){
	Q_UNUSED(deselected);

	current_session.clear();
	current_cam.clear();
	current_img.clear();

	if (selected.isEmpty()) {
		canvas->UnloadObject();
		return;
	}

	int row = selected.indexes().at(0).row();
	current_session = census_model->data(census_model->index(row, census_index_map["session"])).toString();
	current_cam = census_model->data(census_model->index(row, census_index_map["cam"])).toString();
	current_img = census_model->data(census_model->index(row, census_index_map["img"])).toString();


	double ux = census_model->data(census_model->index(row, census_index_map["ux"])).toDouble();
	double uy = census_model->data(census_model->index(row, census_index_map["uy"])).toDouble();

    double lx = census_model->data(census_model->index(row, census_index_map["lx"])).toDouble();
    double ly = census_model->data(census_model->index(row, census_index_map["ly"])).toDouble();

    ui->info_table->item(0,0)->setText(current_session);
    ui->info_table->item(1,0)->setText(QString::number(ux));
    ui->info_table->item(2,0)->setText(QString::number(uy));
    ui->info_table->item(3,0)->setText(QString::number(lx));
    ui->info_table->item(4,0)->setText(QString::number(ly));

	if (!canvas->LoadObject(current_session, current_cam, current_img,ux,uy)) {
		QMessageBox messageBox;
		messageBox.critical(0,"Fehler","Bild konnte nicht geladen werden.");
	}
//    updateMapPosition(lx, ly);
}

void MainWindow::HandleColumnVisibility() {
	int column;
	for (int i=0; i<census_index_map.keys().size();i++) {
		column = census_index_map[census_index_map.keys().at(i)];
		if (!config->getVisibleColumns().contains(census_index_map.keys().at(i))) {
            ui->table_view_objects->hideColumn(column);
		} else {
			ui->table_view_objects->showColumn(column);
		}
	}
    ui->table_view_objects->resizeColumnsToContents();
}

void MainWindow::HandleColumnChooser() {
    column_dialog->exec();
    qDebug() << config->getVisibleColumns();
    HandleColumnVisibility();
}

void MainWindow::HandleTypeFilter(int index){
	if (!db->isOpen()) return;
	QString type_filter = QString("tp like '%1'").arg(type_tab_bar->tabData(index).toString());
    ClearFilter();
    filter_map["tp"] = type_filter;
    handleSessionSelection(ui->combo_session->currentIndex());
};

void MainWindow::HandleServerSelection() {
	bool check;
	QString database = QInputDialog::getItem(this,tr("Datenbank auswählen..."),tr("Datenbank:"),
			config->getDatabaseList(),0,false,&check);
	if (check) {
		config->setPreferredDatabase(database);
		db->OpenDatabase();
		SetDatabaseModels();
	} else {
		return;
	}
	filter_map.remove("session");
	populateSessionBox();
	RefreshColumnMap();
	HandleColumnVisibility();
	HandleFilter();
}

void MainWindow::HandleImagePopup() {
	ImagePopup * window = new ImagePopup(ui->widget_image, canvas, this);
	window->show();
}
