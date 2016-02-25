#include "qsqlextendedtablemodel.h"

#include <QSqlRecord>

/*
 * Einfacher wrapper um auf Daten mittels Zeile und Spalte zugreifen zu können
 */
QVariant QSqlExtendedTableModel::data(int row, int column, int role) const {
    return QSqlTableModel::data(index(row, column), role);
}

/*
 *Noch nicht fertig: Sortierung nach mehreren Spalten
 *
void QSqlExtendedTableModel::setSort(int column, Qt::SortOrder order) {
    QString column_name = record().fieldName(column);
    sort_order.append(column_name);
    order_map[column] = order;

}
*/
