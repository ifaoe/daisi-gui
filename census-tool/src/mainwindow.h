#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QItemSelectionModel>
#include <QMessageBox>
#include <QModelIndex>
#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QStringList>
#include <qgsproviderregistry.h>
#include <qgsmaplayerregistry.h>
#include "ovrmapcanvas.h"
#include "cnsmapcanvas.h"
#include "db.h"


const char MNWD_ERR_MISSING_PROVIDER[] = "Der Provider %s fehlt!\n%s";
const char MNDW_ERR_MISSING_HINT_PFX[] = "Vermutlich ist der QGIS Pfad in der "
      "Umgebungsvariable $qgis.prefixPath falsch gesetzt!";

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(ConfigHandler *aConfig, Db * aDb);
    ~MainWindow();
    
private:
    ConfigHandler *config;
    Ui::MainWindow *ui = 0;
    Db *db = 0;
    QgsProviderRegistry *qgsPvrRegistry = 0;
    QgsMapLayerRegistry *qgsLyrRegistry = 0;

    QItemSelectionModel *imgSelector= 0;
    QItemSelectionModel *objSelector= 0;

    QString selected_file;
    QString selected_cam;

    QMap<QString, QString> filter_map;

    QString edtCurKey;
    QString edtCurView;

    QLabel * ready_image_warning;

    QComboBox * combobox_cam_filter;
    QComboBox * combobox_trac_filter;
    QLineEdit * lineedit_image_filter;

    bool keyMarkerHide = false;

    QSqlQueryModel* object_query_model = 0;

    CnsMapCanvas *mapCanvas = 0;
    OvrMapCanvas *ovrCanvas = 0;
    void qgsCheckProviders();
    void guiInitAdditionals();
    bool checkButtonByKey(QString tp);
    void initSessionFrame();
    void initFilters();
    QString getFilterString();
    QAbstractButton * GetButtonByKey(QButtonGroup * button_group, QString key, QString value);
    void RefreshObjectList();
signals:

public slots:
//    void checkRdyImages();
    void saveData();
    void clearSelection();
    void deleteSelection();
    void handleImageSelection();
    void objUpdateSelection();
    void hideMarker(bool checked);
    void handleSessionSelection();
    void handleCamFilter();
    void handleTrcFilter();
    void handleImgFilter();
    void handleMissingCheckBox();
private slots:
	void handleAdminPass();
	void handleServerSelection();
};

#endif // MAINWINDOW_H
