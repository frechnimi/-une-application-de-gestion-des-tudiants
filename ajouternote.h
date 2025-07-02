#ifndef AJOUTERNOTE_H
#define AJOUTERNOTE_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class AjouterNote;
}

class AjouterNote : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterNote(QWidget *parent = nullptr);
    ~AjouterNote();

private slots:
    void on_txtSaveNote_clicked();

private:
    Ui::AjouterNote *ui;
};

#endif // AJOUTERNOTE_H
