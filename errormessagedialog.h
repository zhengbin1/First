#ifndef ERRORMESSAGEDIALOG_H
#define ERRORMESSAGEDIALOG_H

#include <QDialog>

#include "errormessagedialogtitle.h"
#include "clickablelabel.h"

namespace Ui {
class ErrorMessageDialog;
}

class ErrorMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorMessageDialog(QWidget *parent = nullptr);
    ~ErrorMessageDialog();

    void setTitleName(QString);
    void setTextContent(QString);

private:
    Ui::ErrorMessageDialog *ui;

    ErrorMessageDialogTitle *errorMessageDialogTitle;

private slots:
    void on_OkButton_click();
    void on_CancelButton_click();
};

#endif // ERRORMESSAGEDIALOG_H
