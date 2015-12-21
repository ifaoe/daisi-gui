#ifndef CENSUSWIDGET_H
#define CENSUSWIDGET_H

#include <QFrame>
#include <QGroupBox>

#include "ConfigHandler.h"
#include "DatabaseHandler.h"
#include "IdSelectionDialog.h"

namespace Ui {
class CensusWidget;
}

class CensusWidget : public QFrame
{
    Q_OBJECT

public:
    explicit CensusWidget(QFrame *parent = 0, ConfigHandler * conf = 0, DatabaseHandler * database = 0);
    ~CensusWidget();

    void setObjectLength(double length);
    void setObjectWidth(double width);

    void setupMetaData();
    void setDirectionData(int angle);
    void setPreType(QString type);
private:
    ConfigHandler * config = 0;
    DatabaseHandler * db = 0;
    Ui::CensusWidget *ui = 0;

    IdSelectionDialog * association_dialog;
    IdSelectionDialog * behaviour_dialog;
    IdSelectionDialog * family_dialog;

    census * current_object = 0;
    QStringList censor_list;

    bool userChanged();

    void selectButtonByString(QButtonGroup * btnGrp, QString str);
    void SaveComboBoxSelection(QComboBox * combo_box);
    QVariant GetComboBoxItem(QComboBox * combo_box);
    QVariant GetGroupBoxValue(QGroupBox * gbx, QButtonGroup * btng, QString value);
    QVariant GetButtonGroupValue(QButtonGroup * btng, QString value);

    bool compareResults(census * current, census * next);
    bool sanityCheck();
    void uiPreselection(census * object);

public slots:
    void userSelection();
    void userSwitch();
    void userDefault();

    void associationSelection();
    void behaviourSelection();
    void familySelection();

    void chooseActiveCensusElements();

    void saveObject();
    void deleteObject();

    void loadObjectData(census * object);
private slots:
    void passMeasureLength(){ if(current_object!=0) emit measureLength(); }
    void passMeasureWidth() { if(current_object!=0) emit measureWidth(); }
signals:
    void dataChanged();
    void directionChanged(int angle);
    void measureLength();
    void measureWidth();
    void nextObject();
};

#endif // CENSUSWIDGET_H
