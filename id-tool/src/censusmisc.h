#ifndef CENSUSMISC_H
#define CENSUSMISC_H

#include <QFrame>

namespace Ui {
class CensusMisc;
}

class CensusMisc : public QFrame
{
    Q_OBJECT

public:
    explicit CensusMisc(QWidget *parent = 0);
    ~CensusMisc();

private:
    Ui::CensusMisc *ui;
};

#endif // CENSUSMISC_H
