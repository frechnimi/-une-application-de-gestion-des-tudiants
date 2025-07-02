#ifndef TRIER_H
#define TRIER_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class Trier;
}

class Trier : public QDialog
{
    Q_OBJECT

public:
    explicit Trier(QWidget *parent = nullptr);
    ~Trier();

private slots:
    void on_btnRechercher_clicked();

private:
    Ui::Trier *ui;
    QSqlQueryModel *model;
};

#endif // TRIER_H
