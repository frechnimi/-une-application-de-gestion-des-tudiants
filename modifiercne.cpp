#include "modifiercne.h"
#include "ui_modifiercne.h"

ModifierCNE::ModifierCNE(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModifierCNE)
{
    ui->setupUi(this);
}

ModifierCNE::~ModifierCNE()
{
    delete ui;
}

void ModifierCNE::on_pushButton_clicked()
{
    QString cne = ui->txtCNE->text();
    QString Ncne = ui->txtNCNE->text();


    qDebug()<<"CNE:"<<cne<<"Ncne :"<<Ncne;

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

    query.prepare(" update Etudient set CNE='"+Ncne+"' where CNE='"+cne+"' ");
    query.exec();
    qDebug()<<"last error :"<<query.lastError().text();
    database.close();
    this->close();
}

