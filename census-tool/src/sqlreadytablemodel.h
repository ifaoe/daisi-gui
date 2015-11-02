#ifndef SQLREADYTABLEMODEL_H
#define SQLREADYTABLEMODEL_H

#include <QSqlTableModel>
#include <QColor>

class SqlReadyTableModel : public QSqlTableModel
{
    Q_OBJECT
public:
    virtual QVariant data(int row, int column, int role = Qt::DisplayRole) const;
    virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
private:
    QColor getReadyColor(int row) const;
};

#endif // SQLREADYTABLEMODEL_H
