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
    QString setStyleHtml = "<p style=\"line-height:35px;height:50px;color:#fff;font-size:15px;margin-left:15px;\">%1</p>";
    strText = setStyleHtml.arg(strText);
    label_title_name ->setText(strText);
    label_title_name ->setStyleSheet("background-color: #333541;");
    label_title_name ->setAlignment(Qt::AlignLeft);
    label_title_name ->resize(Meger2_main_width - 50, 50);
    label_title_name ->move(0,0);

    ClickableLabel *label_title_close = new ClickableLabel(this);  // 关闭按钮
    QString setStyleHtml2 = "<p style=\"line-height:30px;height:50px;color:#fff;font-size:20px;text-align:center;\"><b>×</b></p>";
    label_title_close ->setText(setStyleHtml2);
    label_title_close ->setStyleSheet("background-color: #333541;");
    label_title_close ->resize(50, 50);
    label_title_close ->move(Meger2_main_width - 50, 0);

    connect(label_title_close, SIGNAL(clicked()), this, SLOT(on_label_title_close_click()));

    add_server = new CAddServer(this);  // 添加服务器
    add_server -> move(50, 100);

    connect(add_server, SIGNAL(sendStringList(QStringList)), this, SLOT(recvStringList(QStringList)));
}

Meger2_main::~Meger2_main()
{
    delete ui;
}

void Meger2_main::on_label_title_close_click()
{
    QApplication::exit();
}

void Meger2_main::paintEvent(QPaintEvent *event)
{
    int startX = 50;
    int startY = 100;

    int nextX = startX;
    int nextY = startY;

    ServerInfoStack.clear();

    for (int i = 0; i < ServerInfoList.size(); i ++)
    {
        CShowServerBlock *showServerBlock = new CShowServerBlock(this);
        showServerBlock -> setNameAndIP(ServerInfoList.at(i));
        ServerInfoStack.push(showServerBlock);
    }

    int j = 0;
    while (!ServerInfoStack.isEmpty())
    {
        CShowServerBlock *showServerBlock = ServerInfoStack.pop();
        showServerBlock -> move(nextX, nextY);
        showServerBlock -> show();
        nextX += 320;
        j ++;
        int tmpNum = j / 4;
        qDebug() << tmpNum;
        if (tmpNum != 0)
        {
            nextX = startX;
            nextY += 250;
        }
    }

    add_server -> move(nextX, nextY);
}

void Meger2_main::recvStringList(QStringList serverStringList)
{
    ServerInfoList = serverStringList;
}
