#ifndef MODIFIERCNE_H
#define MODIFIERCNE_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class ModifierCNE;
}

class ModifierCNE : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierCNE(QWidget *parent = nullptr);
    ~ModifierCNE();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ModifierCNE *ui;
};

#endif // MODIFIERCNE_H
