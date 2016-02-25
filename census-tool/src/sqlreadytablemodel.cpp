#include "sqlreadytablemodel.h"
#include <QBrush>
#include <QDebug>

QVariant SqlReadyTableModel::data(int row, int column, int role) const {
    return data(index(row, column), role);
}

QVariant SqlReadyTableModel::data(const QModelIndex &index, int role) const {
    QVariant return_data;
    switch(role)
    {
    case Qt::BackgroundRole:
        return_data = QVariant( QBrush(getReadyColor(index.row())));
        break;
    default:
        return_data = QSqlTableModel::data(index, role);
        break;
    }
    return return_data;
}

QColor SqlReadyTableModel::getReadyColor(int row) const {
    bool ready_state = QSqlTableModel::data(index(row, fieldIndex("examined")), Qt::DisplayRole).toBool();
    bool analysed_state = QSqlTableModel::data(index(row, fieldIndex("analysed")), Qt::DisplayRole).toBool();
    if (!analysed_state)
        return Qt::darkRed;
    if (ready_state)
        return Qt::darkGreen;
    return Qt::darkGray;
}
