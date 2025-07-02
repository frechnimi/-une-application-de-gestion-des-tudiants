#ifndef MODIFIERDATE_H
#define MODIFIERDATE_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class ModifierDate;
}

class ModifierDate : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierDate(QWidget *parent = nullptr);
    ~ModifierDate();

private slots:
    void on_saveDate_clicked();

private:
    Ui::ModifierDate *ui;
};

#endif // MODIFIERDATE_H
