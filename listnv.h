#ifndef LISTNV_H
#define LISTNV_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class ListNV;
}

class ListNV : public QDialog
{
    Q_OBJECT

public:
    explicit ListNV(QWidget *parent = nullptr);
    ~ListNV();

private slots:
    void on_ok_clicked();

private:
    Ui::ListNV *ui;
    QSqlQueryModel *model;
};

#endif // LISTNV_H
