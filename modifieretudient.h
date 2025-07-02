#ifndef MODIFIERETUDIENT_H
#define MODIFIERETUDIENT_H

#include <QDialog>
#include "modifiernote12.h"
#include "modifierprenom.h"
#include "modifiercne.h"
#include "modifiermassar.h"
#include "modifierdate.h"

namespace Ui {
class ModifierEtudient;
}

class ModifierEtudient : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierEtudient(QWidget *parent = nullptr);
    ~ModifierEtudient();

private slots:
    void on_MleN_clicked();

    void on_btnModifierPrenom_clicked();

    void on_ModifierCNE_clicked();

    void on_ModifierMassar_clicked();

    void on_ModifierDate_clicked();

private:
    Ui::ModifierEtudient *ui;
    ModifierNote12 *ptrModifierNom;
    ModifierPrenom *ptrModifierPrenom;
    ModifierCNE *ptrModifierCNE;
    ModifierMassar *ptrModifierMassar;
    ModifierDate *ptrModifierDate;
};

#endif // MODIFIERETUDIENT_H
