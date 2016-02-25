/*
 * CensorSqlTableModel.h
 *
 *  Created on: Oct 12, 2015
 *      Author: awg
 */

#ifndef SRC_CENSORSQLTABLEMODEL_H_
#define SRC_CENSORSQLTABLEMODEL_H_

#include <QSqlTableModel>

class CensorSqlTableModel: public QSqlTableModel {
	Q_OBJECT
	enum censor_status {
		no_census,
		first_census,
		conflict_census,
		finished_census
	};
public:
	virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	void setCensorCountColumn(int column) { censor_count_column = column; }
	void setCensorMax(int column) { censor_max_column = column; }
private:
	QColor getCensorColor(int row) const;
	int censor_count_column;
	int censor_max_column;
};

#endif /* SRC_CENSORSQLTABLEMODEL_H_ */
