#ifndef CENSUSNOSIGHT_H
#define CENSUSNOSIGHT_H

#include <QFrame>

namespace Ui {
class CensusNosight;
}

class CensusNosight : public QFrame
{
    Q_OBJECT

public:
    explicit CensusNosight(QWidget *parent = 0);
    ~CensusNosight();

private:
    Ui::CensusNosight *ui;
};

#endif // CENSUSNOSIGHT_H
