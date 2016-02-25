#ifndef QSQLSORTMODEL_H
#define QSQLSORTMODEL_H

#include <QSqlTableModel>

class QSqlSortModel : public QSqlTableModel
{
    Q_OBJECT
public:
    QSqlSortModel(QObject * parent, QSqlDatabase * db);
    QSqlSortModel();
    virtual ~QSqlSortModel();
    void setOrderClause(const QString & text);
private:
    QString order_clause;
protected:
    QString orderByClause() const;
};

#endif // QSQLSORTMODEL_H
