#ifndef ADDSERVERDIALOG_H
#define ADDSERVERDIALOG_H

#include <QDialog>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QMessageBox>

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
    QWidget *m_parent;


private slots:
    void on_label_title_close_click();
    void on_OkButton_click();
    void on_CancelButton_click();

signals:
    void sendServerInfo(QString);
};

#endif // ADDSERVERDIALOG_H
