#include "modifiernote.h"
#include "ui_modifiernote.h"

ModifierNote::ModifierNote(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModifierNote)
{
    ui->setupUi(this);
}

ModifierNote::~ModifierNote()
{
    delete ui;
}

void ModifierNote::on_SaveNouveauNote_clicked()
{
    QString CodeMassar = ui->txtMassrNouveauNote->text();
    QString NomeModule = ui->txtModuleNouveauNote->text();
    QString AncienNote = ui->txtAncienNote->text();
    QString NouveauNote = ui->txtNouveauNote->text();


    qDebug()<<"massar:"<<CodeMassar<<"module :"<<NomeModule<<"Anote :"<<AncienNote<<"Nnote :"<<NouveauNote;

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

    query.prepare(" update Note set note='"+NouveauNote+"' where module='"+NomeModule+"' and massar='"+CodeMassar+"' ");
    query.exec();
    qDebug()<<"last error :"<<query.lastError().text();
    database.close();
    this->close();
}

