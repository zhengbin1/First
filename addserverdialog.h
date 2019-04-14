#ifndef ADDSERVERDIALOG_H
#define ADDSERVERDIALOG_H

#include <QDialog>

namespace Ui {
class AddServerDialog;
}

class AddServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddServerDialog(QWidget *parent = nullptr);
    ~AddServerDialog();

private:
    Ui::AddServerDialog *ui;
};

#endif // ADDSERVERDIALOG_H
