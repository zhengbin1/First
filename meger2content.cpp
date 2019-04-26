#include "meger2content.h"
#include "ui_meger2content.h"

#include <QDebug>

Meger2Content::Meger2Content(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Meger2Content)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint | windowFlags());

    setStyleSheet("background-color: #242631;");

    // 获取桌面屏幕大小
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rect = screen -> availableGeometry();
    screen_width = rect.width();
    screen_height = rect.height();

    this -> resize(screen_width - ((screen_width / 10) * 3), screen_height - ((screen_height / 10) * 2));

    int Meger2_width = geometry().width();  // 窗口宽度
    int Meger2_height = geometry().height();  // 窗口高度

    label_title_name = new LabelTitleName(this);  // 标题栏

    QString strText("Meger V2.0");
    QString setStyleHtml = "<p style=\"line-height:35px;height:50px;color:#fff;font-size:15px;margin-left:15px;\">%1</p>";
    strText = setStyleHtml.arg(strText);
    label_title_name ->setText(strText);
    label_title_name ->setStyleSheet("background-color: #333541;");
    label_title_name ->setAlignment(Qt::AlignLeft);
    label_title_name ->resize(Meger2_width - 100, 50);
    label_title_name ->move(0,0);

    label_title_max = new ClickableLabel(this);  // 最大化按钮
    QString setStyleHtml2 = "<p style=\"line-height:30px;height:50px;color:#fff;font-size:20px;text-align:center;\"><b>□</b></p>";
    label_title_max ->setText(setStyleHtml2);
    label_title_max ->setStyleSheet("background-color: #333541;");
    label_title_max ->resize(50, 50);
    label_title_max ->move(Meger2_width - 100, 0);
    label_title_max ->hide();

    label_title_mini = new ClickableLabel(this);  // 最小化按钮
    QString setStyleHtml3 = "<p style=\"line-height:30px;height:50px;color:#fff;font-size:20px;text-align:center;\"><b>■</b></p>";
    label_title_mini ->setText(setStyleHtml3);
    label_title_mini ->setStyleSheet("background-color: #333541;");
    label_title_mini ->resize(50, 50);
    label_title_mini ->move(Meger2_width - 100, 0);
    label_title_mini ->hide();

    label_title_close = new ClickableLabel(this);  // 关闭按钮
    QString setStyleHtml4 = "<p style=\"line-height:30px;height:50px;color:#fff;font-size:20px;text-align:center;\"><b>×</b></p>";
    label_title_close ->setText(setStyleHtml4);
    label_title_close ->setStyleSheet("background-color: #333541;");
    label_title_close ->resize(50, 50);
    label_title_close ->move(Meger2_width - 50, 0);

    connect(label_title_max, SIGNAL(clicked()), this, SLOT(on_label_max_click()));
    connect(label_title_mini, SIGNAL(clicked()), this, SLOT(on_label_mini_click()));
    connect(label_title_close, SIGNAL(clicked()), this, SLOT(on_label_title_close_click()));

    meger2TabBase = new Meger2TabBase(this);
}

Meger2Content::~Meger2Content()
{
    delete ui;

    delete label_title_name;
    delete label_title_max;
    delete label_title_close;
}

void Meger2Content::on_label_max_click()
{
    this -> showMaximized();
}

void Meger2Content::on_label_mini_click()
{
    this -> showNormal();
}

void Meger2Content::on_label_title_close_click()
{
    this -> close();
}

void Meger2Content::paintEvent(QPaintEvent *)
{
    int Meger2_width = geometry().width();  // 窗口宽度
    int Meger2_height = geometry().height();  // 窗口高度

    label_title_name ->resize(Meger2_width - 100, 50);
    label_title_name ->move(0,0);

    if(Meger2_width == screen_width){
        label_title_mini ->resize(50, 50);
        label_title_mini ->move(Meger2_width - 100, 0);
        label_title_mini ->show();
        label_title_max -> hide();
    } else {
        label_title_max ->resize(50, 50);
        label_title_max ->move(Meger2_width - 100, 0);
        label_title_max ->show();
        label_title_mini ->hide();
    }

    label_title_close ->resize(50, 50);
    label_title_close ->move(Meger2_width - 50, 0);

    meger2TabBase -> resize(320, Meger2_height - 50);
    meger2TabBase -> move(Meger2_width - 320, 50);
}
