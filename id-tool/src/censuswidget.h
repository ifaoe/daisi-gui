#ifndef CENSUSWIDGET_H
#define CENSUSWIDGET_H

#include <QFrame>

namespace Ui {
class CensusWidget;
}

class CensusWidget : public QFrame
{
    Q_OBJECT

public:
    explicit CensusWidget(QWidget *parent = 0);
    ~CensusWidget();

private:
    Ui::CensusWidget *ui;
};

#endif // CENSUSWIDGET_H
