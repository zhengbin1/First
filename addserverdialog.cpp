#include "addserverdialog.h"
#include "ui_addserverdialog.h"

AddServerDialog::AddServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddServerDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint | windowFlags());
}

AddServerDialog::~AddServerDialog()
{
    delete ui;
}
