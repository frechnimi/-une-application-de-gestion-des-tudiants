#ifndef LISTEV_H
#define LISTEV_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class ListeV;
}

class ListeV : public QDialog
{
    Q_OBJECT

public:
    explicit ListeV(QWidget *parent = nullptr);
    ~ListeV();

private slots:
    void on_okM_clicked();

private:
    Ui::ListeV *ui;
    QSqlQueryModel *model;
};

#endif // LISTEV_H
