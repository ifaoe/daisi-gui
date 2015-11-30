#ifndef CENSUSMAMMAL_H
#define CENSUSMAMMAL_H

#include <QFrame>

namespace Ui {
class CensusMammal;
}

class CensusMammal : public QFrame
{
    Q_OBJECT

public:
    explicit CensusMammal(QWidget *parent = 0);
    ~CensusMammal();

private:
    Ui::CensusMammal *ui;
};

#endif // CENSUSMAMMAL_H
