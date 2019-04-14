#include "meger2_main.h"
#include "ui_meger2_main.h"

#include <QDebug>


Meger2_main::Meger2_main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Meger2_main)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint | windowFlags());

    setStyleSheet("background-color: #242631;");

    // 获取桌面屏幕大小
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rect = screen -> availableGeometry();
    int screen_width = rect.width();
    int screen_height = rect.height();

    this -> resize(screen_width - ((screen_width / 10) * 3), screen_height - ((screen_height / 10) * 2));

    int Meger2_main_width = geometry().width();  // 主窗口宽度

    LabelTitleName *label_title_name = new LabelTitleName(this);  // 标题栏

    QString strText("Meger V2.0 登录");
    QString setStyleHtml = "<p style=\"line-height:35px;height:50px;color:#fff;font-size:15px;margin-left:15px;\">%1<p>";
    strText = setStyleHtml.arg(strText);
    label_title_name ->setText(strText);
    label_title_name ->setStyleSheet("background-color: #333541;");
    label_title_name ->setAlignment(Qt::AlignLeft);
    label_title_name ->resize(Meger2_main_width - 50, 50);
    label_title_name ->move(0,0);

    ClickableLabel *label_title_close = new ClickableLabel(this);  // 关闭按钮
    QString setStyleHtml2 = "<p style=\"line-height:40px;height:50px;color:#fff;font-size:20px;text-align:center;\"><b>×</b><p>";
    label_title_close ->setText(setStyleHtml2);
    label_title_close ->setStyleSheet("background-color: #333541;");
    label_title_close ->resize(50, 50);
    label_title_close ->move(Meger2_main_width - 50, 0);

    connect(label_title_close, SIGNAL(clicked()), this, SLOT(on_label_title_close_click()));

    CAddServer *add_server = new CAddServer(this);  // 添加服务器
    add_server -> resize(300, 280);
    add_server -> move(50, 80);
    add_server -> setStyleSheet("background-color: #242631;");
    QLabel *addServer = new QLabel(add_server);
    addServer -> setText("<p style=\"color:#fff;font-size:18px;text-align:center;\">添加服务器<p>");
    addServer -> move(100, 240);
}

Meger2_main::~Meger2_main()
{
    delete ui;
}

void Meger2_main::on_label_title_close_click(){
    QApplication::exit();
}

void Meger2_main::init()
{

}
