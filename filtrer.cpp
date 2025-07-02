#include "filtrer.h"
#include "ui_filtrer.h"

Filtrer::Filtrer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Filtrer)
{
    ui->setupUi(this);
    model = NULL;
}

Filtrer::~Filtrer()
{
    delete ui;
    delete model;
}

void Filtrer::on_Rechercher_clicked()
{
    QString prenom = ui->txtRechercher->text();
    QString txtv = ui->txtVariable->text();


    qDebug()<<"prenom :"<<prenom<<"variable :"<<txtv;

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
        return;
    }
    else
    {
        qDebug()<<"Database open successfully..";
    }

    QSqlQuery query(database);

    query.prepare(" select * from Etudient where "+txtv+" like '%"+prenom+"%' ");
    query.exec();
    qDebug()<<"last error :"<<query.lastError().text();
    qDebug()<<"last query :"<<query.lastQuery();


    if(model == NULL)
    {
        model = new QSqlQueryModel();
    }
    model->setQuery(std::move(query));
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,200);
    ui->tableView->setColumnWidth(1,200);
    ui->tableView->setColumnWidth(2,200);
    database.close();
}

