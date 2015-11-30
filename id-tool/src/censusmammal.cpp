#include "censusmammal.h"
#include "ui_censusmammal.h"

CensusMammal::CensusMammal(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CensusMammal)
{
    ui->setupUi(this);
}

CensusMammal::~CensusMammal()
{
    delete ui;
}
