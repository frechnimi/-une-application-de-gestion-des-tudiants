#include "supprimer.h"
#include "ui_supprimer.h"

Supprimer::Supprimer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Supprimer)
{
    ui->setupUi(this);
}

Supprimer::~Supprimer()
{
    delete ui;
}

void Supprimer::on_supprimer_clicked()
{
    QString massar = ui->txtSupprimer->text();


    qDebug()<<"CNE:"<<massar;

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

    query.prepare(" delete from Etudient where massar = '"+massar+"' ");
    query.exec();
    query.prepare(" delete from Note where massar = '"+massar+"' ");
    query.exec();
    query.prepare(" delete from Consultation where massar = '"+massar+"' ");
    query.exec();
    qDebug()<<"last error :"<<query.lastError().text();
    database.close();
    ui->textS->setText("Supprime avec succes !!");
}

