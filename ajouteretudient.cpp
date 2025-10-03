#include "ajouteretudient.h"
#include "ui_ajouteretudient.h"

AjouterEtudient::AjouterEtudient(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AjouterEtudient)
{
    ui->setupUi(this);
}

AjouterEtudient::~AjouterEtudient()
{
    delete ui;
}

void AjouterEtudient::on_SaveEtudient_clicked()
{
    QString nom = ui->NomEtudient->text();
    QString prenom = ui->PrenomEtudient->text();
    QString CNE = ui->CNEEtudient->text();
    QString massar = ui->MassarEtudient->text();
    QString dateN = ui->dateNaisEtudient->text();

    qDebug()<<"nom :"<<nom<<"prenom :"<<prenom<<"CNE :"<<CNE<<"massar :"<<massar<<"date de Naissance :"<<dateN;

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

    query.prepare("insert into Etudient (nom,prenom,CNE,massar,dateN) values ('"+nom+"','"+prenom+"','"+CNE+"','"+massar+"','"+dateN+"')");
    query.exec();
    qDebug()<<"last error :"<<query.lastError().text();
    database.close();
    this->close();
}


