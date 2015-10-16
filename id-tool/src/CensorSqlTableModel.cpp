/*
 * CensorSqlTableModel.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: awg
 */

#include "CensorSqlTableModel.h"
#include <QBrush>
#include <QDebug>

QVariant CensorSqlTableModel::data(const QModelIndex & index, int role) const {
	QVariant return_data;
	switch(role)
	{
	case Qt::BackgroundRole:
		return_data = QVariant( QBrush(getCensorColor(index.row())));
		break;
	default:
		return_data = QSqlTableModel::data(index, role);
		break;
	}
	return return_data;
}

QColor CensorSqlTableModel::getCensorColor(int row) const {
	QModelIndex count_index = this->index(row, censor_count_column, QModelIndex());
	int censor_count = QSqlTableModel::data(count_index, Qt::DisplayRole).toInt();
	QModelIndex max_index = this->index(row, censor_max_column, QModelIndex());
	int censor_max = QSqlTableModel::data(max_index, Qt::DisplayRole).toInt();
	switch (censor_max)
	{
	case 1:
		if (censor_count > 1)
			return QColor(Qt::darkRed);
		else
			return QColor(Qt::darkGray);
	case 2:
		return QColor(Qt::darkGreen);
	default:
		return QColor(Qt::darkGray);
	}

}
