#ifndef MODIFIERNOTE_H
#define MODIFIERNOTE_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class ModifierNote;
}

class ModifierNote : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierNote(QWidget *parent = nullptr);
    ~ModifierNote();

private slots:
    void on_SaveNouveauNote_clicked();

private:
    Ui::ModifierNote *ui;
};

#endif // MODIFIERNOTE_H
