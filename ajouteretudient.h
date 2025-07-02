#ifndef AJOUTERETUDIENT_H
#define AJOUTERETUDIENT_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class AjouterEtudient;
}

class AjouterEtudient : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterEtudient(QWidget *parent = nullptr);
    ~AjouterEtudient();

private slots:
    void on_SaveEtudient_clicked();

private:
    Ui::AjouterEtudient *ui;
};

#endif // AJOUTERETUDIENT_H
