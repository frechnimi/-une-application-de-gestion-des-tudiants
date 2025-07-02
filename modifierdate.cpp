#include "modifierdate.h"
#include "ui_modifierdate.h"

ModifierDate::ModifierDate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModifierDate)
{
    ui->setupUi(this);
}

ModifierDate::~ModifierDate()
{
    delete ui;
}

void ModifierDate::on_saveDate_clicked()
{
    QString cne = ui->txtCne->text();
    QString Ndate = ui->txtDate->text();


    qDebug()<<"cne:"<<cne<<"Ndate :"<<Ndate;

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

    query.prepare(" update Etudient set dateN='"+Ndate+"' where CNE='"+cne+"' ");
    query.exec();
    qDebug()<<"last error :"<<query.lastError().text();
    database.close();
    this->close();
}

