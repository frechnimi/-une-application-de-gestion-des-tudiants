#ifndef SUPPRIMER_H
#define SUPPRIMER_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class Supprimer;
}

class Supprimer : public QDialog
{
    Q_OBJECT

public:
    explicit Supprimer(QWidget *parent = nullptr);
    ~Supprimer();

private slots:
    void on_supprimer_clicked();

private:
    Ui::Supprimer *ui;
};

#endif // SUPPRIMER_H
