#include "modifieretudient.h"
#include "ui_modifieretudient.h"

ModifierEtudient::ModifierEtudient(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModifierEtudient)
{
    ui->setupUi(this);
    ptrModifierNom =new ModifierNote12();
    ptrModifierPrenom = new ModifierPrenom();
    ptrModifierCNE =new ModifierCNE();
    ptrModifierMassar =new ModifierMassar();
    ptrModifierDate =new ModifierDate();
}

ModifierEtudient::~ModifierEtudient()
{
    delete ui;
    delete ptrModifierNom;
    delete ptrModifierPrenom;
    delete ptrModifierCNE;
    delete ptrModifierMassar;
    delete ptrModifierDate;
}

void ModifierEtudient::on_MleN_clicked()
{
    ptrModifierNom->show();
}


void ModifierEtudient::on_btnModifierPrenom_clicked()
{
    ptrModifierPrenom->show();
}


void ModifierEtudient::on_ModifierCNE_clicked()
{
    ptrModifierCNE->show();
}


void ModifierEtudient::on_ModifierMassar_clicked()
{
    ptrModifierMassar->show();
}


void ModifierEtudient::on_ModifierDate_clicked()
{
    ptrModifierDate->show();
}

