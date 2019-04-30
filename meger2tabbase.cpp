#include "meger2tabbase.h"
#include <QDebug>

Meger2TabBase::Meger2TabBase(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #41434B;");

    titleOne = new QWidget(this);
    titleOne -> setStyleSheet("background-color: #4F5261;");

    setServer = new QLabel(this);
    setMedia = new QLabel(this);
    channelManage = new QLabel(this);

    setServer -> setText("<p style=\"line-height:30px;width:90px;height:40px;font-size:15px;text-align:center;\"><a href=\"setServer\" style=\"text-decoration:none;color:#AFB0B6;\">服务器设置</a></p>");
    setMedia -> setText("<p style=\"line-height:30px;width:90px;height:40px;font-size:15px;text-align:center;\"><a href=\"setMedia\" style=\"text-decoration:none;color:#AFB0B6;\">媒体设置</a></p>");
    channelManage -> setText("<p style=\"line-height:30px;width:90px;height:40px;font-size:15px;text-align:center;\"><a href=\"channelManage\" style=\"text-decoration:none;color:#AFB0B6;\">通道管理</a></p>");

    setServer -> setStyleSheet("background-color: #4F5261;");
    setMedia -> setStyleSheet("background-color: #4F5261;");
    channelManage -> setStyleSheet("background-color: #4F5261;");

    setServer -> resize(90, 30);
    setServer -> move(20, 0);
    setMedia -> resize(90, 30);
    setMedia -> move(120, 0);
    channelManage -> resize(90, 30);
    channelManage -> move(210, 0);

    connect(setServer, SIGNAL(linkActivated(QString)), this, SLOT(LinkActivated(QString)));
    connect(setMedia, SIGNAL(linkActivated(QString)), this, SLOT(LinkActivated(QString)));
    connect(channelManage, SIGNAL(linkActivated(QString)), this, SLOT(LinkActivated(QString)));

    setServerTab = new SetServerTab(this);
    setMediaTab = new SetMediaTab(this);
    channelManageTab = new ChannelManageTab(this);

    setServerTab -> hide();
    setMediaTab -> hide();
    channelManageTab -> hide();

    tabnum = 10;
}

void Meger2TabBase::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);

    int Meger2_width = this -> geometry().width();  // 窗口宽度
    int Meger2_height = this -> geometry().height();  // 窗口高度

    titleOne -> resize(Meger2_width, 40);
    titleOne -> move(0, 0);

    switch (tabnum) {
    case 10:
        setServerTab -> resize(Meger2_width - 20, Meger2_height - 60);
        setServerTab -> move(10, 50);
        setServerTab -> setStyleSheet("background-color: #41434E;");
        setServerTab -> show();
        setMediaTab -> hide();
        channelManageTab -> hide();
        break;
    case 11:
        setMediaTab -> resize(Meger2_width - 20, Meger2_height - 60);
        setMediaTab -> move(10, 50);
        setMediaTab -> setStyleSheet("background-color: #41434E;");
        setServerTab -> hide();
        setMediaTab -> show();
        channelManageTab -> hide();
        break;
    case 12:
        channelManageTab -> resize(Meger2_width - 20, Meger2_height - 60);
        channelManageTab -> move(10, 50);
        channelManageTab -> setStyleSheet("background-color: #41434E;");
        setServerTab -> hide();
        setMediaTab -> hide();
        channelManageTab -> show();
        break;
    }
}


Meger2TabBase::~Meger2TabBase()
{
    delete titleOne;
    delete setServer;
    delete setMedia;
    delete channelManage;

    delete channelManageTab;
    delete setMediaTab;
    delete setServerTab;
}

void Meger2TabBase::LinkActivated(QString tabName)
{
    if(tabName == "setServer"){
        tabnum = 10;
        setServer -> setText("<p style=\"line-height:30px;height:40px;font-size:15px;text-align:center;\"><a href=\"setServer\" style=\"text-decoration:none;color:#FFFFFF;\"><b>服务器设置</b></a></p>");
        setMedia -> setText("<p style=\"line-height:30px;height:40px;font-size:15px;text-align:center;\"><a href=\"setMedia\" style=\"text-decoration:none;color:#AFB0B6;\">媒体设置</a></p>");
        channelManage -> setText("<p style=\"line-height:30px;height:40px;font-size:15px;text-align:center;\"><a href=\"channelManage\" style=\"text-decoration:none;color:#AFB0B6;\">通道管理</a></p>");
    } else if (tabName == "setMedia") {
        tabnum = 11;
        setServer -> setText("<p style=\"line-height:30px;height:40px;font-size:15px;text-align:center;\"><a href=\"setServer\" style=\"text-decoration:none;color:#AFB0B6;\">服务器设置</a></p>");
        setMedia -> setText("<p style=\"line-height:30px;height:40px;font-size:15px;text-align:center;\"><a href=\"setMedia\" style=\"text-decoration:none;color:#FFFFFF;\"><b>媒体设置</b></a></p>");
        channelManage -> setText("<p style=\"line-height:30px;height:40px;font-size:15px;text-align:center;\"><a href=\"channelManage\" style=\"text-decoration:none;color:#AFB0B6;\">通道管理</a></p>");
    } else if (tabName == "channelManage") {
        tabnum = 12;
        setServer -> setText("<p style=\"line-height:30px;height:40px;font-size:15px;text-align:center;\"><a href=\"setServer\" style=\"text-decoration:none;color:#AFB0B6;\">服务器设置</a></p>");
        setMedia -> setText("<p style=\"line-height:30px;height:40px;font-size:15px;text-align:center;\"><a href=\"setMedia\" style=\"text-decoration:none;color:#AFB0B6;\">媒体设置</a></p>");
        channelManage -> setText("<p style=\"line-height:30px;height:40px;font-size:15px;text-align:center;\"><a href=\"channelManage\" style=\"text-decoration:none;color:#FFFFFF;\"><b>通道管理</b></a></p>");
    }
}

