#include "ajouternote.h"
#include "ui_ajouternote.h"

AjouterNote::AjouterNote(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AjouterNote)
{
    ui->setupUi(this);
}

AjouterNote::~AjouterNote()
{
    delete ui;
}

void AjouterNote::on_txtSaveNote_clicked()
{
    QString massar = ui->txtMassar->text();
    QString module = ui->txtModule->text();
    QString note = ui->txtNote->text();


    qDebug()<<"massar:"<<massar<<"module :"<<module<<"note :"<<note;

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

    query.prepare(" select 1 from Etudient where massar = '"+massar+"' and (select 1 from Mataire where nom = '"+module+"' ) ");
    // query.prepare(" select 1 from Mataire where module = '"+module+"' ");
    query.bindValue("+massar+",massar);
    if(query.exec() && query.next())
    {
        query.prepare("insert into Note (nom,prenom,massar,module,note) select e.nom,e.prenom,e.massar,'"+module+"',"+note+" from Etudient e where massar='"+massar+"' ");
    }
    query.exec();
    qDebug()<<"last error :"<<query.lastError().text();
    database.close();
    this->close();
}

