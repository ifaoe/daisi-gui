#include "censusmisc.h"
#include "ui_censusmisc.h"

CensusMisc::CensusMisc(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CensusMisc)
{
    ui->setupUi(this);
}

CensusMisc::~CensusMisc()
{
    delete ui;
}
