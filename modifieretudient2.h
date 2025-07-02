#ifndef MODIFIERETUDIENT2_H
#define MODIFIERETUDIENT2_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class ModifierEtudient2;
}

class ModifierEtudient2 : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierEtudient2(QWidget *parent = nullptr);
    ~ModifierEtudient2();

private slots:
    void on_ptSave_clicked();

private:
    Ui::ModifierEtudient2 *ui;
};

#endif // MODIFIERETUDIENT2_H
