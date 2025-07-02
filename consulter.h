#ifndef CONSULTER_H
#define CONSULTER_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class Consulter;
}

class Consulter : public QDialog
{
    Q_OBJECT

public:
    explicit Consulter(QWidget *parent = nullptr);
    ~Consulter();

private slots:
    void on_saveConsultation_clicked();

private:
    Ui::Consulter *ui;
};

#endif // CONSULTER_H
