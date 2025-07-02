#include "listnv.h"
#include "ui_listnv.h"

ListNV::ListNV(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ListNV)
{
    ui->setupUi(this);
    model = NULL;
}

ListNV::~ListNV()
{
    delete ui;
    delete model;
}


void ListNV::on_ok_clicked()
{
    QString module = ui->txtModule->text();


    qDebug()<<"module:"<<module;

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

    query.prepare(" select * from Note where module ='"+module+"' and note < 10 ");
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

