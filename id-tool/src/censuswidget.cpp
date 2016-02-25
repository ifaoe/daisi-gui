#include "censuswidget.h"
#include "ui_widget_census.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QCryptographicHash>

CensusWidget::CensusWidget(QFrame *parent, ConfigHandler * conf, DatabaseHandler * database, ImgCanvas * canvas) :
    QFrame(parent), config(conf), db(database), ui(new Ui::CensusWidget), image_canavas(canvas)
{
    ui->setupUi(parent);

    family_dialog = new IdSelectionDialog(ui->text_family, this);
    association_dialog = new IdSelectionDialog(ui->text_associations, this);
    behaviour_dialog = new IdSelectionDialog(ui->text_behaviour, this);

    connect(ui->toolbutton_associations, SIGNAL(clicked()), this, SLOT(associationSelection()));
    connect(ui->toolbutton_behaviour, SIGNAL(clicked()), this, SLOT(behaviourSelection()));
    connect(ui->toolbutton_family, SIGNAL(clicked()), this, SLOT(familySelection()));

    connect(ui->wdgTabTypes, SIGNAL(currentChanged(int)), this, SLOT(chooseActiveCensusElements()));
    connect(ui->button_user_select, SIGNAL(clicked()), this, SLOT(userSelection()));

    connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(saveObject()));
    connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(deleteObject()));

    connect(ui->button_length, SIGNAL(released()), this, SLOT(passMeasureLength()));
    connect(ui->button_width, SIGNAL(released()), this, SLOT(passMeasureWidth()));
    connect(image_canavas, SIGNAL(measurementDone(int,double)), this, SLOT(receiveMeasurement(int,double)));

    connect(ui->button_user_select, SIGNAL(clicked()), this, SLOT(userSelection()));
    connect(ui->button_user_switch, SIGNAL(clicked()), this, SLOT(userSwitch()));
    connect(ui->button_user_default, SIGNAL(clicked()), this, SLOT(userDefault()));


    /*
     * TODO: Wait until users have made their minds up
     */
    ui->rbBirdBehaveDive->hide();

    ui->btnSave->setEnabled(false);
    ui->btnDelete->setEnabled(false);
}

CensusWidget::~CensusWidget()
{
    delete ui;
}

bool CensusWidget::userChanged() {
    return config->getUser() != config->getSystemUser();
}

void CensusWidget::setObjectLength(double length) {
    current_object->length = length;
    if (length > 0)
        ui->label_length->setText(QString::number(length) + " m");
    else
        ui->label_length->clear();
}

void CensusWidget::setObjectWidth(double width) {
    current_object->span = width;
    if (width > 0)
        ui->label_width->setText(QString::number(width) + " m");
    else
        ui->label_width->clear();
}

void CensusWidget::setupMetaData() {
    ui->cmb_bird_age->clear();
    db->GetBirdAgeClasses(ui->cmb_bird_age);
    ui->cmb_misc_name->clear();
    db->GetMiscObjects(ui->cmb_misc_name);
    ui->cmbAnthroName->clear();
    db->GetAnthroObjectList(ui->cmbAnthroName);
    ui->cmb_bird_age->clear();
    db->GetBirdAgeClasses(ui->cmb_bird_age);
    ui->cmbMammal->clear();
    db->getSpeciesList("MAMMAL", ui->cmbMammal);
    ui->cmbBird->clear();
    db->getSpeciesList("BIRD", ui->cmbBird);
    ui->combo_box_plumage->clear();
    db->GetBirdPlumageClasses(ui->combo_box_plumage);

    if (association_dialog->dataModel() != 0)
        delete association_dialog->dataModel();
    association_dialog->setDataModel(db->getStuk4Associations());
    if (behaviour_dialog->dataModel() != 0)
        delete behaviour_dialog->dataModel();
    behaviour_dialog->setDataModel(db->getStuk4Behaviour());
}

/*
 * Read results for the selected censor and set the Ui elements respectively
 */
void CensusWidget::userSelection() {
    census * obj;
    if(ui->cmbUsers->currentText().isEmpty()) return;
    obj = db->getRawObjectData(QString::number(current_object->id), ui->cmbUsers->currentText());
    uiPreselection(obj);
    delete obj;
}

void CensusWidget::userSwitch() {
    if (ui->cmbUsers->currentText().isEmpty()) return;
    if (!config->getAdmin()) {
        bool ok;
        QString password;
        password = QInputDialog::getText(this, tr("Admin Zugang freischalten"), tr("Passwort:"), QLineEdit::Password,QString(),&ok);

        //MD5 sum of password
        //b90793dee6e8828cef899658c45ad8aa
        QCryptographicHash password_hash(QCryptographicHash::Md5);
        password_hash.addData(password.toStdString().c_str());
        if (ok ) {
            if(QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5).toHex())
                    == QString("b90793dee6e8828cef899658c45ad8aa")) {
                QMessageBox message;
                message.setText(tr("Freischaltung erfolgreich."));
                message.setStandardButtons(QMessageBox::Ok);
                message.exec();
                config->setAdmin(true);
            } else {
                QMessageBox message;
                message.setText("Freischaltung fehlgeschlagen.");
                message.setStandardButtons(QMessageBox::Ok);
                message.exec();
                return;
            }
        } else {
            return;
        }
    }


    config->setUser(ui->cmbUsers->currentText());
    ui->label_user_status->setText(QString("Bestimmung als Nutzer: %1").arg(config->getUser()));
    userSelection();
}

void CensusWidget::userDefault() {
    if (!userChanged())
        return;
    config->setUser(config->getSystemUser());
    ui->label_user_status->setText(QString("Bestimmung als Nutzer: %1").arg(config->getUser()));
}

bool CensusWidget::sanityCheck() {
    if (current_object->name == "" && current_object->type != "NOSIGHT") {
        QMessageBox * msgBox = new QMessageBox();
        msgBox->setText(trUtf8("Bitte Art/Bezeichnung auswählen!"));
        QAbstractButton *nextButton = msgBox->addButton(trUtf8("Ok"), QMessageBox::YesRole);
        msgBox->exec();
        if(msgBox->clickedButton() == nextButton) {
            delete msgBox;
            return false;
        }
        delete msgBox;
    }
    if (current_object->type == "BIRD") {
        if ((current_object->behavior == "FLY") && (current_object->direction < 0)) {
                QMessageBox * msgBox = new QMessageBox();
                msgBox->setText(trUtf8("Bitte Flugrichtung bestimmen, oder als unbestimmt markieren."));
                QAbstractButton *nextButton = msgBox->addButton(trUtf8("Ok"), QMessageBox::NoRole);
                QAbstractButton *noDirButton = msgBox->addButton(trUtf8("Unbestimmt"), QMessageBox::YesRole);
                msgBox->exec();
                if (msgBox->clickedButton() == nextButton) {
                    delete msgBox;
                    return false;
                } else if (msgBox->clickedButton() == noDirButton) {
                    current_object->direction = -1;
                }
                delete msgBox;
        } else if (current_object->behavior != "FLY") {
            current_object->direction = -1;
        }
    } else if (current_object->type == "MAMMAL") {
        if (current_object->direction < 0) {
            QMessageBox * msgBox = new QMessageBox();
            msgBox->setText(trUtf8("Bitte Schwimmrichtung bestimmen, oder als unbestimmt markieren."));
            QAbstractButton *nextButton = msgBox->addButton(trUtf8("Ok"), QMessageBox::NoRole);
            QAbstractButton *noDirButton = msgBox->addButton(trUtf8("Unbestimmt"), QMessageBox::YesRole);
            msgBox->exec();
            if (msgBox->clickedButton() == nextButton) {
                delete msgBox;
                return false;
            } else if (msgBox->clickedButton() == noDirButton) {;
                current_object->direction = -1;
            }
            delete msgBox;
        }
    }
    return true;
}

void CensusWidget::setDirectionData(int angle) {
    qDebug() << angle;
//    angle = (angle + 180) % 360;
    if (current_object == 0) return;
    if (angle > 0)
        current_object->direction = angle;
    else
        current_object->direction = -1;
}

void CensusWidget::selectButtonByString(QButtonGroup * btnGrp, QString str) {
    QList<QAbstractButton*> btnList = btnGrp->buttons();
    for(int i=0; i<btnList.size(); i++) {
        if(btnList.at(i)->property("dbvalue") == str) {
            btnList.at(i)->setChecked(true);
        }
    }
}

// TODO: Entfernen
void CensusWidget::SaveComboBoxSelection(QComboBox * combo_box) {
    int row = combo_box->currentIndex();
    current_object->name = combo_box->model()->data(combo_box->model()->index(row,0)).toString();
    current_object->code = combo_box->model()->data(combo_box->model()->index(row,2)).toString();
}

QVariant CensusWidget::GetComboBoxItem(QComboBox * combo_box) {
    return combo_box->itemData(combo_box->currentIndex());
}

QVariant CensusWidget::GetButtonGroupValue(QButtonGroup * btng, QString value) {
    return btng->checkedButton()->property(value.toStdString().c_str());
}

QVariant CensusWidget::GetGroupBoxValue(QGroupBox * gbx, QButtonGroup * btng, QString value) {
    if (gbx->isCheckable()) {
        if (gbx->isChecked()) {
            return GetButtonGroupValue(btng,value);
        } else {
            return QVariant::fromValue(QString::fromStdString(""));
        }
    } else {
        return GetButtonGroupValue(btng,value);
    }
}

bool CensusWidget::compareResults(census * current, census * census) {
    bool agree = true;
    agree = agree && (current->name == census->name);
    agree = agree && (current->type == census->type);
    if (current->confidence == 4 || census->confidence == 4)
        agree = agree && (current->confidence == census->confidence);
    return agree;
}

/*
 * Function which selects Ui elements depending on the data in
 * the census struct.
 */
void CensusWidget::uiPreselection(census * cobj) {
    // Check if preselection is from another user
    if (cobj->usr == config->getUser())
        current_object->censor = cobj->censor;

    // Save Census checkbox ticked?
    // save all info but size and direction
    if (ui->chbSaveCensus->isChecked()) {
        cobj->direction = -1;

        // clear size box
        ui->label_length->clear();
        ui->label_width->clear();

        cobj->span = -1;
        cobj->length = -1;

        cobj->remarks.clear();

        cobj->imageQuality = 0;
        return;
    }

    /*
     * emit Signal um Richtungsanzeiger zu ändern
     * die Eigentliche Richtungsangabe muss zusätzlich getan werden,
     * weil setValue nicht das Signal SliderReleased triggered
     */
    emit directionChanged((cobj->direction+180) % 360);
    current_object->direction = cobj->direction;

    association_dialog->set_id_list(cobj->stuk4_ass);
    behaviour_dialog->set_id_list(cobj->stuk4_beh);
    family_dialog->set_id_list(cobj->family);

    ui->textedit_remarks->clear();

    // Checkbox for very good objects in image quality
    // which could be used as example pictures
    if (cobj->imageQuality > 0) {
        ui->checkbox_image_quality->setChecked(true);
    } else {
        ui->checkbox_image_quality->setChecked(false);
    }

    // by default, all options are off
    ui->gbxMammalAge->setChecked(false);
    ui->gbxBirdAge->setChecked(false);
    ui->cmb_bird_age->setCurrentIndex(0);
    ui->gbxBirdGender->setChecked(false);
    ui->group_box_plumage->setChecked(false);
    ui->combo_box_plumage->setCurrentIndex(0);

    ui->textedit_remarks->setPlainText(cobj->remarks);

    if(cobj->type == "BIRD" ||current_object->type.left(1) == "V" ) { // Bird Tab
            ui->wdgTabTypes->setCurrentIndex(0);
            int index = ui->cmbBird->findText(cobj->name);
            ui->cmbBird->setCurrentIndex(index);
            selectButtonByString(ui->buttongroup_bird_confidence, QString::number(cobj->confidence));
            selectButtonByString(ui->buttongroup_bird_behaviour, cobj->behavior);
            if(cobj->gender != "") {
                ui->gbxBirdGender->setChecked(true);
                selectButtonByString(ui->buttongroup_bird_sex, cobj->gender);
            }
            if(!cobj->age.isEmpty() || cobj->age_year>0) {
                ui->gbxBirdAge->setChecked(true);
                selectButtonByString(ui->buttongroup_bird_age, cobj->age);
                index = ui->cmb_bird_age->findData(cobj->age_year);
                ui->cmb_bird_age->setCurrentIndex(index);
            }
            if (!cobj->plumage.isEmpty()) {
                ui->group_box_plumage->setChecked(true);
                ui->combo_box_plumage->setCurrentIndex(
                        ui->combo_box_plumage->findData(cobj->plumage));
            }

            ui->cmbBird->setFocus();
        } else if (cobj->type == "MAMMAL" || current_object->type == "MM" ) { // Mammal Tab
            ui->wdgTabTypes->setCurrentIndex(1);
            int index = ui->cmbMammal->findText(cobj->name);
            ui->cmbMammal->setCurrentIndex(index);
            selectButtonByString(ui->buttongroup_mammal_confidence, QString::number(cobj->confidence));
            selectButtonByString(ui->buttongroup_mammal_behaviour, cobj->behavior);
            if (cobj->age != "") {
                ui->gbxMammalAge->setChecked(true);
                selectButtonByString(ui->buttongroup_mammal_age, cobj->age);
            }
            ui->cmbMammal->setFocus();
        } else if (cobj->type == "ANTHRO" || current_object->type == "AN" ) { // Anthro Tab
            int index = ui->cmbAnthroName->findData(cobj->code);
            ui->cmbAnthroName->setCurrentIndex(index);
            ui->wdgTabTypes->setCurrentIndex(2);
            selectButtonByString(ui->buttongroup_anthro_confidence, QString::number(cobj->confidence));
        } else if (cobj ->type== "MISC"  || current_object->type == "TR" ) {
            if (current_object->type == "TR") current_object->code = "7101";
            int index = ui->cmb_misc_name->findData(cobj->code);
            ui->cmb_misc_name->setCurrentIndex(index);
            ui->wdgTabTypes->setCurrentIndex(3);
            selectButtonByString(ui->buttongroup_misc_confidence, QString::number(cobj->confidence));
        } else { //NoSighting tab
            ui->wdgTabTypes->setCurrentIndex(4);
            selectButtonByString(ui->buttongroup_nosight_confidence, QString::number(cobj->confidence));
        }

        setObjectLength(cobj->length);
        setObjectWidth(cobj->span);
}

void CensusWidget::deleteObject() {
    db->deleteCensusData(QString::number(current_object->id), config->getUser());
    ui->btnDelete->setEnabled(false);
    // TODO: Update ObjectList
//    handleSessionSelection();
    emit dataChanged();
}

void CensusWidget::saveObject() {
    qDebug() << "Trying to save as user: " << config->getUser();

    current_object->type = ui->wdgTabTypes->currentWidget()->property("dbvalue").toString();

    // Check wether all inputs are done
    bool check_required = false;
    if(current_object->type == "BIRD") {
        check_required = true;
        SaveComboBoxSelection(ui->cmbBird);
        current_object->confidence = GetButtonGroupValue(ui->buttongroup_bird_confidence, "dbvalue").toInt();
        current_object->behavior = GetButtonGroupValue(ui->buttongroup_bird_behaviour, "dbvalue").toString();
        current_object->gender = GetGroupBoxValue(ui->gbxBirdGender, ui->buttongroup_bird_sex, "dbvalue").toString();
        if (ui->gbxBirdAge->isChecked()) {
            current_object->age = GetButtonGroupValue(ui->buttongroup_bird_age, "dbvalue").toString();
            current_object->age_year = GetComboBoxItem(ui->cmb_bird_age).toInt();
        } else {
            current_object->age = "";
            current_object->age_year = -1;
        }
        if (ui->group_box_plumage->isChecked())
            current_object->plumage = ui->combo_box_plumage->itemData(
                    ui->combo_box_plumage->currentIndex()).toString();
        else
            current_object->plumage = "";
    } else if (current_object->type == "MAMMAL") {
        check_required = true;
        SaveComboBoxSelection(ui->cmbMammal);
        current_object->confidence = GetButtonGroupValue(ui->buttongroup_mammal_confidence,"dbvalue").toInt();
        current_object->behavior = GetButtonGroupValue(ui->buttongroup_mammal_behaviour, "dbvalue").toString();
        current_object->age = GetGroupBoxValue(ui->gbxMammalAge, ui->buttongroup_mammal_age, "dbvalue").toString();
        current_object->age_year = -1;
        current_object->gender = "";
    } else if (current_object->type == "NOSIGHT" || current_object->type=="UNKNOWN" ) {
        current_object->name = "";
        current_object->confidence = GetButtonGroupValue(ui->buttongroup_nosight_confidence, "dbvalue").toInt();
        current_object->behavior = "";
        current_object->age = "";
        current_object->code = "";
        current_object->age_year = -1;
        current_object->gender = "";
        current_object->direction = -1;
        current_object->code = "";
    } else if (current_object->type == "ANTHRO") {
        current_object->name = ui->cmbAnthroName->currentText();
        current_object->code = GetComboBoxItem(ui->cmbAnthroName).toString();
        current_object->confidence = GetButtonGroupValue(ui->buttongroup_anthro_confidence, "dbvalue").toInt();
        current_object->behavior = "";
        current_object->age = "";
        current_object->age_year = -1;
        current_object->gender = "";
        current_object->direction = -1;
    } else if (current_object->type == "MISC") {
        current_object->name = ui->cmb_misc_name->currentText();
        current_object->code = GetComboBoxItem(ui->cmb_misc_name).toString();
        current_object->confidence = GetButtonGroupValue(ui->buttongroup_misc_confidence, "dbvalue").toInt();
        current_object->behavior = "";
        current_object->age = "";
        current_object->age_year = -1;
        current_object->gender = "";
        current_object->direction = -1;
    } else {
        qDebug() << "Invalid save type. Aborting.";
        return;
    }

    if (!sanityCheck()) return;

    current_object->stuk4_ass = association_dialog->getIdList();
    current_object->stuk4_beh = behaviour_dialog->getIdList();
    current_object->family = family_dialog->getIdList();

    current_object->remarks = ui->textedit_remarks->toPlainText();

    if (!userChanged()) {
        if (check_required || current_object->confidence != 1 || db->getMaxCensor(QString::number(current_object->id), config->getUser()) > 0) {
            int tmpcensor = 0;
            if (db->getMaxCensor(QString::number(current_object->id), config->getUser()) >= 2) {
                tmpcensor = 0;
            } else if (db->getMaxCensor(QString::number(current_object->id), config->getUser()) == 1) {
                if (db->getCensorCount(QString::number(current_object->id), "1", config->getUser()) > 1) {
                    tmpcensor = 3;
                } else {
                    tmpcensor = 2;
                }
            } else if (db->getMaxCensor(QString::number(current_object->id), config->getUser()) < 1) {
                tmpcensor = 1;
            } else {
                tmpcensor = -1;
            }

            switch (tmpcensor) {
                case -1: {
                    qDebug() << "Kann Nuzter nicht bestimmen!";
                    current_object->censor = -1;
                    break;
                } case 0: {
                    qDebug() << "Zusätzlicher Bestimmer.";
                    current_object->censor = 0;
                    QMessageBox * msgBox = new QMessageBox();
                    msgBox->setText(trUtf8("Objekt bereits Endbestimmt. Abspeichern als zusätzliche Bestimmung."));
                    msgBox->addButton(trUtf8("Ok"), QMessageBox::YesRole);
                    msgBox->exec();
                    delete msgBox;
                    break;
                } case 1: {
                    qDebug() << "Erster Bestimmer.";
                    current_object->censor = 1;
                    break;
                } case 2: {
                    qDebug() << "Zweiter Bestimmer.";
                    current_object->censor = 2;
                    census * cenObj = db->getCensusData(QString::number(current_object->id));
                    bool agree = compareResults(current_object, cenObj);
                    if (!agree) {
                        QMessageBox * msgBox = new QMessageBox();
                        msgBox->setText(QString::fromUtf8("Keine Übereinstimmung zum Erstbestimmer.\n"
                                " Noch keine Endbestimmung möglich.\n"
                                "Bestimmung als Vorbestimmer."));
                        msgBox->addButton(trUtf8("Ok"), QMessageBox::YesRole);
                        msgBox->exec();
                        delete msgBox;
                        current_object->censor = 1;
                    }
                    break;
                } case 3: {
                    qDebug() << "Ditter Bestimmer.";
                    current_object->censor = 2;
                    QMessageBox * msgBox = new QMessageBox();
                    msgBox->setText("Endbestimmung als " + QString::number(censor_list.size()) + ". Bestimmer. \n"
                            + "Bitte mit " + censor_list.join(", ") + " abstimmen.");
                    msgBox->addButton(trUtf8("Ok"), QMessageBox::YesRole);
                    QAbstractButton *noButton = msgBox->addButton(trUtf8("Abbrechen"), QMessageBox::NoRole);
                    msgBox->exec();
                    if (msgBox->clickedButton() == noButton) {
                        delete msgBox;
                        return;
                    }
                    break;
                } default: {
                    qDebug() << "Exit route on switch!";
                    exit(1);
                }
            }
        } else {
            current_object->censor = 2;
        }
    }


    if (ui->checkbox_image_quality->isChecked()) {
        current_object->imageQuality = 1;
    } else {
        current_object->imageQuality = 0;
    }

    //write user
    current_object->usr = config->getUser();
    if (config->getUser() != config->getSystemUser())
        current_object->log.append(QString("Saved as %1 by %2. ").arg(config->getUser()).arg(config->getSystemUser()));

    // write object data to db
    if (!db->writeCensus(current_object)) {
        QMessageBox * msgBox = new QMessageBox();
        msgBox->setText(QString::fromUtf8("Fehler beim schreiben in die Datenbank."
                "Der Datensatz wurde möglicherweise nicht gespeichert."));
        msgBox->addButton(trUtf8("Ok"), QMessageBox::YesRole);
        msgBox->exec();
        delete msgBox;
        return;
    }

    // delete object structure
    delete current_object;
    ui->btnSave->setEnabled(false);
    ui->btnDelete->setEnabled(false);
    // select next object in table
    emit nextObject();
}

void CensusWidget::associationSelection() {
    association_dialog->ToggleHidden();
}

void CensusWidget::behaviourSelection() {
    behaviour_dialog->ToggleHidden();
}

void CensusWidget::familySelection() {
    family_dialog->ToggleHidden();
}

void CensusWidget::chooseActiveCensusElements() {
    if (current_object == 0) return;
    current_object->type = ui->wdgTabTypes->currentWidget()->property("dbvalue").toString();
    if (current_object->type == "BIRD" || current_object->type == "MAMMAL") {
        ui->frame_shared->setEnabled(true);
    } else {
        ui->frame_shared->setEnabled(false);
    }
}

void CensusWidget::loadObjectData(census * object) {
    current_object = object;
    ui->cmbUsers->clear();

    censor_list = db->getUserList(current_object->id);
    ui->cmbUsers->addItems(censor_list);

    family_dialog->setDataModel(db->getCloseObjects(current_object));

    uiPreselection(current_object);

    // handle user selection
    if (config->getAdmin()) {
        ui->btnDelete->setEnabled(true);
        ui->btnSave->setEnabled(true);
    } else {
        if ((current_object->censor > 0) && (db->getMaxCensor(QString::number(current_object->id),config->getUser()) > 1)) {
            ui->btnDelete->setEnabled(false);
            ui->btnSave->setEnabled(false);
        } else {
            ui->btnDelete->setEnabled(true);
            ui->btnSave->setEnabled(true);
        }
    }

    if (current_object->censor < 0)
        ui->btnDelete->setEnabled(false);

    if (db->getCensorCount(QString::number(current_object->id), "1", config->getUser()) >= 2
            || db->getMaxCensor(QString::number(current_object->id)) >= 2) {
        ui->button_user_select->setDisabled(false);
    } else {
        ui->cmbUsers->clear();
        ui->button_user_select->setDisabled(true);
    }

    ui->button_length->setEnabled(true);
    ui->button_width->setEnabled(true);
    // If project done can't change anything
    if (!db->getSessionActive(current_object->session)) {
        ui->btnSave->setEnabled(false);
        ui->btnDelete->setEnabled(false);
    }
}

void CensusWidget::receiveMeasurement(int type, double size) {
    qDebug() << "Received";
    qDebug() << type << " " << size;
    if (type == 1)
        setObjectLength(size);
    if (type == 2)
        setObjectWidth(size);
}
