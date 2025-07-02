#ifndef MODIFIERPRENOM_H
#define MODIFIERPRENOM_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class ModifierPrenom;
}

class ModifierPrenom : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierPrenom(QWidget *parent = nullptr);
    ~ModifierPrenom();

private slots:
    void on_saveNouveauPrenom_clicked();

private:
    Ui::ModifierPrenom *ui;
};

#endif // MODIFIERPRENOM_H
