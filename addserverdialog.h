#ifndef ADDSERVERDIALOG_H
#define ADDSERVERDIALOG_H

#include <QDialog>
#include <QFile>
#include <QFileInfo>
#include <QStack>
#include <QTextStream>

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
    QStack<QString> ServerStack;  // 栈方式存放服务器地址

private slots:
    void on_label_title_close_click();
    void on_OkButton_click();
    void on_CancelButton_click();
};

#endif // ADDSERVERDIALOG_H
