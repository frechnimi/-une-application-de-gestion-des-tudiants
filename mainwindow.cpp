#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/hp/OneDrive/Desktop/Documents/fpslogo123.png");
    ui->label_pic->setPixmap(pix);
    QPixmap pix1("C:/Users/hp/OneDrive/Desktop/Documents/fps.jpg");
    ui->label_3->setPixmap(pix1);


    ptrAjouterEtudient = new AjouterEtudient();
    ptrAjouterNote = new AjouterNote();
    // ptrModifierEtudient = new ModifierEtudient();
    ptrModifierNote = new ModifierNote();
    ptrSupprimer = new Supprimer();
    ptrConsulter = new Consulter();
    ptrTrier =new Trier();
    ptrFiltrer = new Filtrer();
    ptrModifierEtudient2 = new ModifierEtudient2();
    ptrListeV = new ListeV();
    ptrListNV = new ListNV();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrAjouterEtudient;
    delete ptrAjouterNote;
    // delete ptrModifierEtudient;
    delete ptrModifierNote;
    delete ptrSupprimer;
    delete ptrConsulter;
    delete ptrTrier;
    delete ptrFiltrer;
    delete ptrModifierEtudient2;
    delete ptrListeV;
    delete ptrListNV;
}

void MainWindow::on_pushButton_clicked()
{
    ptrAjouterEtudient->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    ptrAjouterNote->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    ptrModifierNote->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    // ptrModifierEtudient->show();
    ptrModifierEtudient2->show();
}


void MainWindow::on_pushButton_7_clicked()
{
    ptrFiltrer->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    ptrConsulter->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    ptrSupprimer->show();
}


void MainWindow::on_pushButton_8_clicked()
{
    ptrTrier->show();
}


void MainWindow::on_btnValider_clicked()
{
    ptrListeV->show();
}


void MainWindow::on_btnNV_clicked()
{
    ptrListNV->show();
}

