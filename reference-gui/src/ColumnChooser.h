/*
 * ColumnChooser.h
 *
 *  Created on: Aug 13, 2015
 *      Author: awg
 */

#ifndef SRC_COLUMNCHOOSER_H_
#define SRC_COLUMNCHOOSER_H_

#include <qdialog.h>
#include "UserSettings.h"
#include <QDialogButtonBox>
#include <QButtonGroup>
#include <QLayout>

class ColumnChooser: public QDialog {
	Q_OBJECT
public:
	ColumnChooser(UserSettings * config, QWidget * parent =0);
	virtual ~ColumnChooser();
    void addColumn(QString text, QString column_name);
private:
//	Ui::ColumnOptions * ui;
	UserSettings * config;
    QWidget * main_widget;
    QWidget * column_widget;
    QVBoxLayout * vertical_layout;
    QGridLayout * column_layout;
    QButtonGroup * column_boxes;
    QDialogButtonBox * button_box;
    int max_rows = 10;
    int current_row = 0;
    int current_column = 0;
private slots:
    void onAccept();
    void onReject();
};

#endif /* SRC_COLUMNCHOOSER_H_ */
