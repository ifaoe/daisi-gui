#include "censusanthro.h"
#include "ui_censusanthro.h"

CensusAnthro::CensusAnthro(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CensusAnthro)
{
    ui->setupUi(this);
}

CensusAnthro::~CensusAnthro()
{
    delete ui;
}
