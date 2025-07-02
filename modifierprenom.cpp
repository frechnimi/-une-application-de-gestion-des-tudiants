#include "modifierprenom.h"
#include "ui_modifierprenom.h"

ModifierPrenom::ModifierPrenom(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModifierPrenom)
{
    ui->setupUi(this);
}

ModifierPrenom::~ModifierPrenom()
{
    delete ui;
}

void ModifierPrenom::on_saveNouveauPrenom_clicked()
{
    QString cne = ui->txtCNE->text();
    QString Aprenom = ui->txtAprenom->text();
    QString Nprenom= ui->txtNprenom->text();


    qDebug()<<"CNE:"<<cne<<"Aprenom :"<<Aprenom<<"Nprenom :"<<Nprenom;

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

    query.prepare(" update Etudient set prenom='"+Nprenom+"' where CNE='"+cne+"' ");
    query.exec();
    qDebug()<<"last error :"<<query.lastError().text();
    database.close();
    this->close();
}

