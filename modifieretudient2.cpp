#include "modifieretudient2.h"
#include "ui_modifieretudient2.h"

ModifierEtudient2::ModifierEtudient2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModifierEtudient2)
{
    ui->setupUi(this);
}

ModifierEtudient2::~ModifierEtudient2()
{
    delete ui;
}

void ModifierEtudient2::on_ptSave_clicked()
{
    QString massar = ui->txtMassar->text();
    QString champ = ui->txtChamp->text();
    QString AV = ui->txtAv->text();
    QString NV = ui->txtNv->text();

    qDebug()<<"massar :"<<massar<<"champ :"<<champ<<"AV :"<<AV<<"NV :"<<NV;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/hp/OneDrive/Desktop/Documents/gestionEdatabase/mygestion.db");

    if(QFile::exists("C:/Users/hp/OneDrive/Desktop/Documents/gestionEdatabase/mygestion.db"))
    {
        qDebug()<<"Database file exists";
    }
    else
    {
        qDebug()<<"Database file doesnt't exists";
        return;
    }

    if(!database.open())
    {
        qDebug()<<"error: unable to open Database";
    }
    else
    {
        qDebug()<<"Database open successfully..";
    }

    QSqlQuery query(database);

    query.prepare("update Etudient set "+champ+"='"+NV+"' where massar='"+massar+"' and "+champ+"='"+AV+"'  ");
    query.exec();
    query.prepare("update Note set "+champ+"='"+NV+"' where massar='"+massar+"' and "+champ+"='"+AV+"'  ");
    query.exec();
    qDebug()<<"last error :"<<query.lastError().text();
    database.close();
    this->close();
}

