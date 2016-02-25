#ifndef CENSUSANTHRO_H
#define CENSUSANTHRO_H

#include <QFrame>

namespace Ui {
class CensusAnthro;
}

class CensusAnthro : public QFrame
{
    Q_OBJECT

public:
    explicit CensusAnthro(QWidget *parent = 0);
    ~CensusAnthro();

private:
    Ui::CensusAnthro *ui;
};

#endif // CENSUSANTHRO_H
