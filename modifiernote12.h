#ifndef MODIFIERNOTE12_H
#define MODIFIERNOTE12_H

#include <QDialog>
#include "databaseheader.h"
namespace Ui {
class ModifierNote12;
}

class ModifierNote12 : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierNote12(QWidget *parent = nullptr);
    ~ModifierNote12();

private slots:
    void on_saveModifierNom_clicked();

private:
    Ui::ModifierNote12 *ui;
};

#endif // MODIFIERNOTE12_H
