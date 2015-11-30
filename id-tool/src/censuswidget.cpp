#include "censuswidget.h"
#include "ui_censuswidget.h"

CensusWidget::CensusWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CensusWidget)
{
    ui->setupUi(this);
}

CensusWidget::~CensusWidget()
{
    delete ui;
}
