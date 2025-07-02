#include "trier.h"
#include "ui_trier.h"

Trier::Trier(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Trier)
{
    ui->setupUi(this);
    model = NULL;
}

Trier::~Trier()
{
    delete ui;
    delete model;

}

void Trier::on_btnRechercher_clicked()
{

    QString att = ui->txtAttribut->text();
    QString var = ui->txtV->text();


    qDebug()<<"att :"<<att<<"variable :"<<var;

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

    query.prepare(" select * from Note where "+att+" like '%"+var+"%' ");
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

