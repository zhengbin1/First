#include "errormessagedialog.h"
#include "ui_errormessagedialog.h"

ErrorMessageDialog::ErrorMessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorMessageDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint | windowFlags());
    setStyleSheet("background-color: #FFFFFF;");
    setModal(true);

    int AddServerDialogWidth = geometry().width();

    ErrorMessageDialogTitle *errorMessageDialogTitle = new ErrorMessageDialogTitle(this);  // 标题栏

    QString strText("<p style=\"line-height:30px;height:40px;color:#fff;font-size:15px;margin-left:15px;\">连接提醒<p>");
    errorMessageDialogTitle -> setText(strText);
    errorMessageDialogTitle -> setStyleSheet("background-color: #333541;");
    errorMessageDialogTitle -> setAlignment(Qt::AlignLeft);
    errorMessageDialogTitle -> resize(AddServerDialogWidth - 50, 40);
    errorMessageDialogTitle -> move(0,0);

    ClickableLabel *label_title_close = new ClickableLabel(this);  // 关闭按钮
    label_title_close ->setText("<p style=\"line-height:32px;height:40px;color:#fff;font-size:20px;text-align:center;\"><b>×</b><p>");
    label_title_close ->setStyleSheet("background-color: #333541;");
    label_title_close ->resize(50, 40);
    label_title_close ->move(AddServerDialogWidth - 50, 0);

    ui -> OkButton -> setStyleSheet("background-color: #E64545; color: white;");
    ui -> CancelButton -> setStyleSheet("background-color: white; color: #727272;");

    ui -> label_content -> setStyleSheet("background-color: white; color: black;");

    connect(ui -> OkButton, SIGNAL(clicked()), this, SLOT(on_OkButton_click()));
    connect(ui -> CancelButton, SIGNAL(clicked()), this, SLOT(on_CancelButton_click()));
}

ErrorMessageDialog::~ErrorMessageDialog()
{
    delete ui;
}

void ErrorMessageDialog::on_OkButton_click()
{
    this -> close();
}

void ErrorMessageDialog::on_CancelButton_click()
{
    this -> close();
}

void ErrorMessageDialog::setTextContent(QString text)
{
    ui -> label_content ->setText("<p style=\"line-height:30px;height:30px;color:#000;font-size:16px;text-align:center;\">" + text + "<p>");
}
