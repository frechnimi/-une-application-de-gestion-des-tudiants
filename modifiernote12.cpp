#include "modifiernote12.h"
#include "ui_modifiernote12.h"

ModifierNote12::ModifierNote12(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModifierNote12)
{
    ui->setupUi(this);

}

ModifierNote12::~ModifierNote12()
{
    delete ui;

}

void ModifierNote12::on_saveModifierNom_clicked()
{
    QString massar = ui->Emassar->text();
    QString Anom = ui->txtAncienNom->text();
    QString Nnom = ui->txtNouveauNom->text();


    qDebug()<<"massar:"<<massar<<"Anom :"<<Anom<<"Nnom :"<<Nnom;

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

    query.prepare(" update Etudient set nom='"+Nnom+"' where CNE='"+massar+"' ");
    query.exec();
    qDebug()<<"last error :"<<query.lastError().text();
    database.close();
    this->close();
}

