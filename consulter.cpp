#include "consulter.h"
#include "ui_consulter.h"

Consulter::Consulter(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Consulter)
{
    ui->setupUi(this);
}

Consulter::~Consulter()
{
    delete ui;
}

void Consulter::on_saveConsultation_clicked()
{
    QString massar = ui->txtMassarConsulter->text();
    QString consultation = ui->txtConsulter->toPlainText();


    qDebug()<<"massar :"<<massar<<"consulter :"<<consultation;

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

    query.prepare(" select 1 from Etudient where massar = '"+massar+"' ");
    query.bindValue("+massar+",massar);
    if(query.exec() && query.next())
    {
        query.prepare("insert into Consultation (massar,consultation) values ('"+massar+"','"+consultation+"')");
    }
    query.exec();
    qDebug()<<"last error :"<<query.lastError().text();
    database.close();
    this->close();
}

