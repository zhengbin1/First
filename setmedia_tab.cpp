#include "setmedia_tab.h"
#include <QDebug>

SetMediaTab::SetMediaTab(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #41434E;");

    titleSon = new QWidget(this);
    titleSon -> setStyleSheet("background-color: #5F616E;");

    resourceList = new QLabel(this);
    programAttribute = new QLabel(this);
    mediaAttribute = new QLabel(this);

    resourceList -> setText("<p style=\"line-height:25px;width:80px;height:30px;font-size:14px;text-align:center;\"><a href=\"resourceListTab\" style=\"text-decoration:none;color:#FFFFFF;\"><b>资源列表</b></a></p>");
    programAttribute -> setText("<p style=\"line-height:25px;width:80px;height:30px;font-size:14px;text-align:center;\"><a href=\"programAttributeTab\" style=\"text-decoration:none;color:#AFB0B6;\">节目属性</a></p>");
    mediaAttribute -> setText("<p style=\"line-height:25px;width:80px;height:30px;font-size:14px;text-align:center;\"><a href=\"mediaAttributeTab\" style=\"text-decoration:none;color:#AFB0B6;\">媒体属性</a></p>");

    resourceList -> setStyleSheet("background-color: #5F616E;");
    programAttribute -> setStyleSheet("background-color: #5F616E;");
    mediaAttribute -> setStyleSheet("background-color: #5F616E;");

    resourceList -> resize(80, 30);
    resourceList -> move(20, 0);
    programAttribute -> resize(80, 30);
    programAttribute -> move(110, 0);
    mediaAttribute -> resize(80, 30);
    mediaAttribute -> move(200, 0);

    connect(resourceList, SIGNAL(linkActivated(QString)), this, SLOT(LinkActivated(QString)));
    connect(programAttribute, SIGNAL(linkActivated(QString)), this, SLOT(LinkActivated(QString)));
    connect(mediaAttribute, SIGNAL(linkActivated(QString)), this, SLOT(LinkActivated(QString)));

    resourceListTab = new ResourceList(this);
    programAttributeTab = new ProgramAttribute(this);
    mediaAttributeTab = new MediaAttribute(this);

    resourceListTab -> hide();
    programAttributeTab -> hide();
    mediaAttributeTab -> hide();

    tabnum = 10;
}

void SetMediaTab::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);

    int setmediatab_width = this -> geometry().width();  // 窗口宽度
    int setmediatab_height = this -> geometry().height();  // 窗口高度

    titleSon -> resize(setmediatab_width, 35);
    titleSon -> move(0, 0);

    switch (tabnum) {
    case 10:
        resourceListTab -> resize(setmediatab_width, setmediatab_height);
        resourceListTab -> move(0, 50);
        resourceListTab -> setStyleSheet("background-color: #41434E;");
        resourceListTab -> show();
        programAttributeTab -> hide();
        mediaAttributeTab -> hide();
        emit showSignal(111);
        break;
    case 11:
        programAttributeTab -> resize(setmediatab_width, setmediatab_height);
        programAttributeTab -> move(0, 50);
        programAttributeTab -> setStyleSheet("background-color: #41434E;");
        resourceListTab -> hide();
        programAttributeTab -> show();
        mediaAttributeTab -> hide();
        emit showSignal(112);
        break;
    case 12:
        mediaAttributeTab -> resize(setmediatab_width, setmediatab_height);
        mediaAttributeTab -> move(0, 50);
        mediaAttributeTab -> setStyleSheet("background-color: #41434E;");
        resourceListTab -> hide();
        programAttributeTab -> hide();
        mediaAttributeTab -> show();
        emit showSignal(113);
        break;
    }
}

SetMediaTab::~SetMediaTab()
{
    delete titleSon;
    delete resourceList;
    delete programAttribute;
    delete mediaAttribute;

    delete resourceListTab;
    delete programAttributeTab;
    delete mediaAttributeTab;
}

void SetMediaTab::LinkActivated(QString tabName)
{
    if(tabName == "resourceListTab"){
        tabnum = 10;
        resourceList -> setText("<p style=\"line-height:25px;width:80px;height:30px;font-size:14px;text-align:center;\"><a href=\"resourceListTab\" style=\"text-decoration:none;color:#FFFFFF;\"><b>资源列表</b></a></p>");
        programAttribute -> setText("<p style=\"line-height:25px;width:80px;height:30px;font-size:14px;text-align:center;\"><a href=\"programAttributeTab\" style=\"text-decoration:none;color:#AFB0B6;\">节目属性</a></p>");
        mediaAttribute -> setText("<p style=\"line-height:25px;width:80px;height:30px;font-size:14px;text-align:center;\"><a href=\"mediaAttributeTab\" style=\"text-decoration:none;color:#AFB0B6;\">媒体属性</a></p>");
    } else if (tabName == "programAttributeTab") {
        tabnum = 11;
        resourceList -> setText("<p style=\"line-height:25px;width:80px;height:30px;font-size:14px;text-align:center;\"><a href=\"resourceListTab\" style=\"text-decoration:none;color:#AFB0B6;\">资源列表</a></p>");
        programAttribute -> setText("<p style=\"line-height:25px;width:80px;height:30px;font-size:14px;text-align:center;\"><a href=\"programAttributeTab\" style=\"text-decoration:none;color:#FFFFFF;\"><b>节目属性</b></a></p>");
        mediaAttribute -> setText("<p style=\"line-height:25px;width:80px;height:30px;font-size:14px;text-align:center;\"><a href=\"mediaAttributeTab\" style=\"text-decoration:none;color:#AFB0B6;\">媒体属性</a></p>");
    } else if (tabName == "mediaAttributeTab") {
        tabnum = 12;
        resourceList -> setText("<p style=\"line-height:25px;width:80px;height:30px;font-size:14px;text-align:center;\"><a href=\"resourceListTab\" style=\"text-decoration:none;color:#AFB0B6;\">资源列表</a></p>");
        programAttribute -> setText("<p style=\"line-height:25px;width:80px;height:30px;font-size:14px;text-align:center;\"><a href=\"programAttributeTab\" style=\"text-decoration:none;color:#AFB0B6;\">节目属性</a></p>");
        mediaAttribute -> setText("<p style=\"line-height:25px;width:80px;height:30px;font-size:14px;text-align:center;\"><a href=\"mediaAttributeTab\" style=\"text-decoration:none;color:#FFFFFF;\"><b>媒体属性</b></a></p>");
    }
}

