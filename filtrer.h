#ifndef FILTRER_H
#define FILTRER_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class Filtrer;
}

class Filtrer : public QDialog
{
    Q_OBJECT

public:
    explicit Filtrer(QWidget *parent = nullptr);
    ~Filtrer();

private slots:
    void on_Rechercher_clicked();

private:
    Ui::Filtrer *ui;
    QSqlQueryModel *model;
};

#endif // FILTRER_H
