#ifndef QSQLEXTENDEDTABLEMODEL_H
#define QSQLEXTENDEDTABLEMODEL_H

/*
 * Einfache Erweiterung des Qt4 QSqlTableModels um nützliche Funktionen.
 * Achtung: Einige der Funktionen sind in Qt5 bereits umgesetzt.
 */

#include <QSqlTableModel>

class QSqlExtendedTableModel : public QSqlTableModel
{
public:
    virtual QVariant data(int row, int column, int role = Qt::DisplayRole) const;
//    void setSort(int column, Qt::SortOrder order);
private:
    /*
     * Variablen um die Multi-Column Sortierung zu verwirklichen
    QStringList sort_order;
    QMap<int, Qt::SortOrder> order_map;
    QString order_clause;
    */
protected:
    // orderByClause();
signals:

public slots:
};

#endif // QSQLEXTENDEDTABLEMODEL_H
