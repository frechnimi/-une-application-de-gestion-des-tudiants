#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ajouteretudient.h"
#include "ajouternote.h"
// #include "modifieretudient.h"
#include "modifiernote.h"
#include "consulter.h"
#include "supprimer.h"
#include "trier.h"
#include "filtrer.h"
#include "modifieretudient2.h"
#include "listev.h"
#include "listnv.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_btnValider_clicked();

    void on_btnNV_clicked();

private:
    Ui::MainWindow *ui;
    AjouterEtudient *ptrAjouterEtudient;
    AjouterNote *ptrAjouterNote;
    // ModifierEtudient *ptrModifierEtudient;
    ModifierNote *ptrModifierNote;
    Supprimer *ptrSupprimer;
    Trier *ptrTrier;
    Filtrer *ptrFiltrer;
    Consulter *ptrConsulter;
    ModifierEtudient2 *ptrModifierEtudient2;
    ListeV *ptrListeV;
    ListNV *ptrListNV;
};
#endif // MAINWINDOW_H
