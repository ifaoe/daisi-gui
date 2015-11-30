#ifndef CENSUSBIRD_H
#define CENSUSBIRD_H

#include <QFrame>
#include <QButtonGroup>
#include "census.hpp"

namespace Ui {
class CensusBird;
}

class CensusBird : public QFrame
{
    Q_OBJECT

public:
    explicit CensusBird(QWidget *parent = 0);
    ~CensusBird();
    void selectObject(census * object);

private:
    Ui::CensusBird *ui;
    void saveData();
    void selectButtonByData(QButtonGroup * group, const QVariant & data);
    census * census_object;
};

#endif // CENSUSBIRD_H
