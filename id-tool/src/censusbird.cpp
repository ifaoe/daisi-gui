#include "censusbird.h"
#include "ui_censusbird.h"

CensusBird::CensusBird(QWidget *parent) : QFrame(parent), ui(new Ui::CensusBird) {
    ui->setupUi(this);
}

CensusBird::~CensusBird() {
    delete ui;
}

void CensusBird::selectObject(census * object) {
    census_object = object;
    ui->combobox_name->setCurrentIndex(ui->combobox_name->findText(object->name));
    selectButtonByData(ui->buttongroup_confidence, object->confidence);
    selectButtonByData(ui->buttongroup_behaviour, object->behavior);
    if (!object->age.isEmpty()) {
        ui->groupbox_age->setChecked(true);
        selectButtonByData(ui->buttongroup_age, object->age);
        ui->combobox_age_years->setCurrentIndex( ui->combobox_age_years->findData(object->age_year));
    }
    if (!object->gender.isEmpty()) {
        ui->groupbox_sex->setChecked(true);
        selectButtonByData(ui->buttongroup_sex, object->gender);
    }
    if (!object->plumage.isEmpty()) {
        ui->groupbox_plumage->setChecked(true);
        ui->combobox_plumage->setCurrentIndex( ui->combobox_plumage->findText(object->plumage));
    }
    ui->text_remarks->setPlainText(object->remarks);
    if (object->length > 0)
        ui->label_length->setText(QString::number(object->length) + " m");
    if (object->span > 0 )
        ui->label_width->setText(QString::number(object->span) + " m");
    ui->label_stuk4_assoziations->setText(object->stuk4_ass.join(","));
    ui->label_stuk4_behaviour->setText(object->stuk4_beh.join(","));
    ui->label_group->setText(object->group.join(","));
    ui->label_family->setText(object->family.join(","));
}

void CensusBird::saveData() {
    census_object->age = ui->buttongroup_age->checkedButton()->property("dbvalue").toString();
}

void CensusBird::selectButtonByData(QButtonGroup *group, const QVariant &data) {
    if (data.isNull() || !data.isValid())
        return;
    QList<QAbstractButton*> btnList = group->buttons();
    for(int i=0; i<btnList.size(); i++) {
        if(btnList.at(i)->property("dbvalue") == data) {
            btnList.at(i)->setChecked(true);
            return;
        }
    }
}
