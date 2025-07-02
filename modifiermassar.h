#ifndef MODIFIERMASSAR_H
#define MODIFIERMASSAR_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class ModifierMassar;
}

class ModifierMassar : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierMassar(QWidget *parent = nullptr);
    ~ModifierMassar();

private slots:
    void on_ModifierMassar_2_clicked();

private:
    Ui::ModifierMassar *ui;
};

#endif // MODIFIERMASSAR_H
