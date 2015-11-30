#include "censusnosight.h"
#include "ui_censusnosight.h"

CensusNosight::CensusNosight(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CensusNosight)
{
    ui->setupUi(this);
}

CensusNosight::~CensusNosight()
{
    delete ui;
}
