/*
 * QSearchDialog.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: awg
 */

#include "QSearchDialog.h"

QSearchDialog::QSearchDialog() {
	// Widget which contains the filter widgets
	filter_widget = new QWidget(this);
	filter_label = new QLabel(filter_widget);
	filter_label->setText("Filter:");
	filter_text = new QLineEdit(filter_widget);

	horizontal_filter_layout = new QHBoxLayout(filter_widget);
	horizontal_filter_layout->addWidget(filter_label);
	horizontal_filter_layout->addWidget(filter_text);

	sort_ascend_button = new QToolButton(this);
	sort_ascend_button->setText("aufsteigend sortieren");
	sort_ascend_button->setCheckable(true);
	sort_ascend_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	sort_ascend_button->setIcon(QIcon::fromTheme("view-sort-ascending"));
	sort_ascend_button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	sort_descend_button = new QToolButton(this);
	sort_descend_button->setText("absteigend sortieren");
	sort_descend_button->setCheckable(true);
	sort_descend_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	sort_descend_button->setIcon(QIcon::fromTheme("view-sort-descending"));
	sort_descend_button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	result_widget = new QListWidget(this);
	button_box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this);

	vertical_layout = new QVBoxLayout(this);
	vertical_layout->addWidget(sort_ascend_button);
	vertical_layout->addWidget(sort_descend_button);
	vertical_layout->addWidget(filter_widget);
	vertical_layout->addWidget(result_widget);
	vertical_layout->addWidget(button_box);

	connect(button_box, SIGNAL(accepted()), this, SLOT(onAccept()));
	connect(button_box, SIGNAL(rejected()), this, SLOT(onReject()));
	connect(filter_text, SIGNAL(textChanged(QString)), this, SLOT(onFilterChange(QString)));
	connect(sort_ascend_button, SIGNAL(clicked(bool)), this, SLOT(handleSortAscend(bool)));
	connect(sort_descend_button, SIGNAL(clicked(bool)), this, SLOT(handleSortDescend(bool)));
	connect(result_widget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemSelection(QListWidgetItem*)));
}

QSearchDialog::~QSearchDialog() {

}

void QSearchDialog::updateItemList(QStringList list) {
	item_list = list;
	result_widget->clear();
	result_widget->addItems(list);
}

// private slots

void QSearchDialog::onAccept() {
	accept();
	QList<QListWidgetItem*> selected_items = result_widget->selectedItems();
};

void QSearchDialog::onReject() {
	reject();
};

void QSearchDialog::onFilterChange(const QString & text) {
	QRegExp expression(text, Qt::CaseInsensitive, QRegExp::WildcardUnix);
	result_widget->clear();
	result_widget->addItems(item_list.filter(expression));
}

void QSearchDialog::handleSortAscend(bool checked) {
	sort_descend_button->setChecked(false);
	if (checked) {
		sort_order = Qt::AscendingOrder;
		sorted = true;
	} else {
		sorted = false;
	}

}

void QSearchDialog::handleSortDescend(bool checked) {
	sort_ascend_button->setChecked(false);
	if (checked) {
		sort_order = Qt::DescendingOrder;
		sorted = true;
	} else {
		sorted = false;
	}

}

void QSearchDialog::onItemSelection(QListWidgetItem * item) {
	filter_text->setText(item->text());
}
