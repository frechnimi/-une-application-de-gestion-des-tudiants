#include "modifiermassar.h"
#include "ui_modifiermassar.h"

ModifierMassar::ModifierMassar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModifierMassar)
{
    ui->setupUi(this);
}

ModifierMassar::~ModifierMassar()
{
    delete ui;
}

void ModifierMassar::on_ModifierMassar_2_clicked()
{
    QString massar = ui->txtMassar->text();
    QString Nmassar = ui->txtNMassar->text();


    qDebug()<<"massar:"<<massar<<"Nmassar :"<<Nmassar;

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

    query.prepare(" update Etudient set massar='"+Nmassar+"' where massar='"+massar+"' ");
    query.exec();
    query.prepare(" update Note set massar='"+Nmassar+"' where massar='"+massar+"' ");
    query.exec();
    qDebug()<<"last error :"<<query.lastError().text();
    database.close();
    this->close();
}

