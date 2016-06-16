/*
 * MainWindow.cpp
 *
 *  Created on: Jul 22, 2015
 *      Author: awg
 */

#include "MainWindow.h"
#include <QInputDialog>
#include <QSqlError>
#include <QSqlQuery>
#include "QSearchDialog.h"
#include <QSqlRecord>

MainWindow::MainWindow(ConfigHandler * config, DatabaseHandler * db)
    : config(config), db(db), ui(new Ui::MainWindow) {
	// TODO Auto-generated constructor stub
	ui->setupUi(this);

    connect(ui->combo_session, SIGNAL(currentIndexChanged(QString)),this, SLOT(HandleSessionSelection(QString)));

	connect(ui->buttonGroup_save_type,SIGNAL(buttonClicked(QAbstractButton*)),this, SLOT(HandleSaveData(QAbstractButton*)));
    connect(ui->tableView_image_properties->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(handleHeaderFilter(int)));

    ui->combo_session->clear();
    ui->combo_session->addItem("");
    ui->combo_session->addItems(db->GetProjectList());

    if (property_table != 0)
        delete property_table;
    property_table = db->getPropertyTable();
    ui->tableView_image_properties->setModel(property_table);
    qDebug() << "Error: " << property_table->lastError().text();

    index_list.clear();
    index_list["glare_key"] = property_table->fieldIndex("glare_key");
    index_list["seastate"] = property_table->fieldIndex("seastate");
    index_list["turbidity"] =  property_table->fieldIndex("turbidity");
    index_list["clarity"] = property_table->fieldIndex("clarity");
    index_list["ice"] = property_table->fieldIndex("ice");
    index_list["remarks"] = property_table->fieldIndex("remarks");
    index_list["transect"] = property_table->fieldIndex("transect");
    index_list["camera"] = property_table->fieldIndex("camera");
    index_list["image"] = property_table->fieldIndex("image");

    for (int i=0; i<property_table->columnCount(); i++) {
        if (!index_list.values().contains(i))
            ui->tableView_image_properties->hideColumn(i);
    }

    ui->tableView_image_properties->horizontalHeader()->moveSection(index_list["transect"],0);
    ui->tableView_image_properties->verticalHeader()->setResizeMode(QHeaderView::Fixed);

//	property_table->setFilter("FALSE");
    property_table->setOrderClause("ORDER BY transect, camera, image");

}

MainWindow::~MainWindow() {
    config->setAppPosition(pos());
    config->setAppSize(size());
    config->setAppMaximized(isMaximized());
    config->sync();
}

void MainWindow::LoadSession() {
	UpdateProgress();
    ui->tableView_image_properties->resizeColumnsToContents();
}

void MainWindow::ApplyFilters() {
	ui->tableView_image_properties->clearSelection();
    SetTableQuery(static_cast<QStringList>(filter_map.values()).join(" AND "));
	ui->tableView_image_properties->resizeColumnsToContents();
	ui->tableView_image_properties->horizontalHeader()->setStretchLastSection(true);
//    ui->tableView_image_properties->setModel(property_table);
    property_table->select();
    qDebug() << "Filter: " << property_table->filter();
    qDebug() << "Error: " << property_table->lastError().text();
    qDebug() << "Query: " << property_table->query().lastQuery();
}

void MainWindow::SetTableQuery(QString where) {
	property_table->setFilter(where);
}

void MainWindow::UpdateProgress() {
	ui->groupBox_glare->setTitle("Glare: " + db->GetPropertyProgress("glare_key"));
	ui->groupBox_seastate->setTitle("Seastate: " + db->GetPropertyProgress("seastate"));
	ui->groupBox_turbidity->setTitle("Turbidity: " + db->GetPropertyProgress("turbidity"));
	ui->groupBox_clarity->setTitle("Clarity: " + db->GetPropertyProgress("clarity"));
	ui->groupBox_ice->setTitle("Ice: " + db->GetPropertyProgress("ice"));
}

QVariant MainWindow::getModelItem(int row, int column) {
    QModelIndex index = property_table->index(row, column);
    return property_table->data(index);
}

QStringList MainWindow::getColumnDataList(int column) {
    QStringList return_list;
    for (int row=0; row<property_table->rowCount(); row++) {
        QString item = getModelItem(row, column).toString();
        if (!return_list.contains(item))
            return_list.append(item);
    }
    return return_list;
}

/*
 * SLOTS:
 */

void MainWindow::SetTableData(QString column_name, QVariant data) {
    qDebug() << "Save " << column_name << " as " << data.toString();
	int column = property_table->fieldIndex(column_name);
	QModelIndexList index_list = ui->tableView_image_properties->selectionModel()->selectedRows(column);
	QItemSelection old_selection = ui->tableView_image_properties->selectionModel()->selection();
	progress_dialog_ = new QProgressDialog(tr("Speichere aktuelle Auswahl..."), tr("Abbrechen"),0,old_selection.size(),this);
	progress_dialog_->setWindowModality(Qt::WindowModal);
	progress_dialog_->setMinimumDuration(0);
	progress_dialog_->show();
	QList<int> top_left_row, top_left_column;
	QList<int> bottom_right_row, bottom_right_column;
	for (int i=0; i<old_selection.size();i++) {
		progress_dialog_->setValue(i);
		top_left_row.append(old_selection[i].topLeft().row());
		top_left_column.append(old_selection[i].topLeft().column());
		bottom_right_row.append(old_selection[i].bottomRight().row());
		bottom_right_column.append(old_selection[i].bottomRight().column());
	}
	progress_dialog_->setLabelText(tr("Erstelle Datensatz"));
	progress_dialog_->setRange(0,index_list.size());
	progress_dialog_->setValue(0);
	for (int i=0; i<index_list.size(); i++) {
		progress_dialog_->setValue(i);
		if (progress_dialog_->wasCanceled())
			break;
		property_table->setData(index_list[i], data.toString());
	}
	progress_dialog_->setLabelText(tr("Schreibe Daten in Datenbank..."));
	database_progess_ = index_list.size();
	connect(property_table, SIGNAL(beforeUpdate(int, QSqlRecord&)), this, SLOT(UpdateDatabaseProgress()));
    if (!property_table->submitAll()) {
        qDebug() << property_table->lastError().text();
    };
	progress_dialog_->setLabelText(tr("Stelle Auswahl wieder her..."));
	progress_dialog_->setRange(0, top_left_row.size());
	QModelIndex top_left, bottom_right;
    QItemSelection selection;
    connect(this, SIGNAL(updateProgress(int)), progress_dialog_, SLOT(setValue(int)));
	for (int i=0; i<top_left_row.size(); i++) {
        emit updateProgress(i);
		if (progress_dialog_->wasCanceled())
			break;
		top_left = property_table->index(top_left_row[i],top_left_column[i],QModelIndex());
		bottom_right = property_table->index(bottom_right_row[i],bottom_right_column[i],QModelIndex());
		selection.select(top_left, bottom_right);
	}
	ui->tableView_image_properties->selectionModel()->select(selection,QItemSelectionModel::Select);
	UpdateProgress();
	delete progress_dialog_;
}

void MainWindow::setComboModelView(QComboBox *combo, QAbstractItemModel *model) {
    QTableView * view = new QTableView;
    combo->setModel(model);
    combo->setView(view);
    view->resizeColumnsToContents();
    combo->setModelColumn(0);
}

void MainWindow::HandleSessionSelection(const QString & session) {
    if (session.isEmpty())
        return;
    config->setVersion(db->getSessionVersion(session));
    setComboModelView(ui->comboBox_clarity, db->getClarityCodes());
    setComboModelView(ui->comboBox_glare, db->getGlareCodes());
    setComboModelView(ui->comboBox_ice, db->getIceCodes());
    setComboModelView(ui->comboBox_seastate, db->getSeastateCodes());
    setComboModelView(ui->comboBox_turbidity, db->getTurbidityCodes());
    filter_map["session"] = QString("session='%1'").arg(session);
    config->setSessionName(session);
    UpdateProgress();
    ApplyFilters();
}

void MainWindow::HandleSaveData(QAbstractButton * button) {
	QString type = button->property("dbvalue").toString();
	if (type == "glare_key") {
        SetTableData(type, ui->comboBox_glare->currentText());
	} else if (type == "seastate") {
        SetTableData(type, ui->comboBox_seastate->currentText());
	} else if (type == "turbidity") {
        SetTableData(type,ui->comboBox_turbidity->currentText());
	} else if (type == "clarity") {
        SetTableData(type, ui->comboBox_clarity->currentText());
	} else if (type == "ice") {
        SetTableData(type, ui->comboBox_ice->currentText());
	} else if (type == "remarks") {
		SetTableData(type, ui->plainTextEdit_remarks->toPlainText());
	}
}

void MainWindow::UpdateDatabaseProgress() {
	progress_dialog_->setValue(progress_dialog_->maximum() - database_progess_);
	database_progess_--;
}


void MainWindow::handleHeaderFilter(int index) {
    QSearchDialog dialog;
    dialog.updateItemList(getColumnDataList(index));
    if (dialog.exec()) {
        if (dialog.isSorted())
            ui->tableView_image_properties->sortByColumn(index, dialog.getSortingOrder());
        if (dialog.getFilterString().isEmpty())
            filter_map.remove(property_table->headerData(index, Qt::Horizontal).toString());
        else
            filter_map[property_table->headerData(index, Qt::Horizontal).toString()] = QString("cast(%1 as text) like '%%2%'")
                .arg(property_table->record(0).fieldName(index)).arg(dialog.getFilterString());
        property_table->setFilter(static_cast<QStringList>(filter_map.values()).join(" AND "));
    }
}
