#include "qsqlsortmodel.h"

QSqlSortModel::QSqlSortModel(QObject * parent, QSqlDatabase * db){
  QSqlTableModel(parent, *db);
}

QSqlSortModel::QSqlSortModel(){
    QSqlTableModel();
}

QSqlSortModel::~QSqlSortModel() {
}

void QSqlSortModel::setOrderClause(const QString & text) {
    order_clause = text;
}

QString QSqlSortModel::orderByClause() const {
    return order_clause;
}
