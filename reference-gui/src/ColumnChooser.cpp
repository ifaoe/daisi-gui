/*
 * ColumnChooser.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: awg
 */

#include "ColumnChooser.h"
#include <QDebug>
#include <QCheckBox>

ColumnChooser::ColumnChooser(UserSettings * config, QWidget * parent)
    : QDialog(parent), config(config) {
    main_widget = new QWidget(this);
    vertical_layout = new QVBoxLayout(main_widget);

    column_widget = new QWidget(main_widget);
    column_layout = new QGridLayout(column_widget);

    button_box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this);
    column_boxes = new QButtonGroup;
    column_boxes->setExclusive(false);

    vertical_layout->addWidget(column_widget);
    vertical_layout->addWidget(button_box);

    connect(button_box, SIGNAL(accepted()), this, SLOT(onAccept()));
    connect(button_box, SIGNAL(rejected()), this, SLOT(onReject()));
}

ColumnChooser::~ColumnChooser() {
	// TODO Auto-generated destructor stub
}

void ColumnChooser::addColumn(QString text, QString column_name) {
    QCheckBox * box = new QCheckBox(column_widget);
    if(config->getVisibleColumns().contains(column_name))
        box->setChecked(true);
    else
        box->setChecked(false);
    box->setText(QString("%1 (%2)").arg(text).arg(column_name));
    box->setProperty("dbvalue",column_name);
    if(current_row > max_rows) {
        current_column++;
        current_row = 0;
    }

    column_layout->addWidget(box, current_row, current_column);
    current_row++;
    column_boxes->addButton(box);
    column_widget->updateGeometry();
    main_widget->updateGeometry();
    setFixedSize(main_widget->sizeHint());
}

void ColumnChooser::onAccept() {
	QStringList columns;
    QList<QAbstractButton*> buttons = column_boxes->buttons();
	for (int i=0; i<buttons.size(); i++) {
		if (buttons[i]->isChecked())
			columns.append(buttons[i]->property("dbvalue").toString());
	}
	config->setVisibleColumns(columns);
	config->sync();
    accept();
}

void ColumnChooser::onReject() {
    reject();
}
