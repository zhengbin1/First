#include "programattribute.h"
#include <QDebug>

VideoItem::VideoItem(QWidget *parent) : QWidget(parent)
{
    videoName = new QLabel(this);
    videoName -> resize(100, 50);

    stop_unselected = new QLabel(this);
    QPixmap Pixmap1(":/images/source/images/stop_unselected.png");
    stop_unselected -> setPixmap(Pixmap1);
    stop_unselected -> resize(Pixmap1.size());

    int parentW = parent -> geometry().width();  // 父窗口宽度
    int parentH = parent -> geometry().height();  // 父窗口高度

    resize(parentW, 50);
}

VideoItem::~VideoItem()
{
    delete videoName;

    delete stop_unselected;
}

void VideoItem::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);


    videoName -> move(0, 0);
    stop_unselected -> move(100, 0);
}

void VideoItem::setItemName(QString name)
{
    videoName -> setText("<p style=\"line-height:35px;height:50px;color:#FFFFFF;font-size:13px;text-align:center;\">" + name + "<p>");
}


ProgramAttribute::ProgramAttribute(QWidget *parent) : QWidget(parent)
{
    videoName = new QLabel(this);
    videoName -> setText("<p style=\"line-height:20px;height:20px;color:#FFFFFF;font-size:15px;text-align:center;\">节目名称<p>");
    videoName -> resize(100, 20);
    videoName -> move(0, 5);

    videoItem = new VideoItem(this);
    videoItem -> setItemName("节目1");
}

ProgramAttribute::~ProgramAttribute()
{
    delete videoName;
    delete videoItem;
}

void ProgramAttribute::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);

    videoItem -> move(0, 25);
    videoItem -> show();
}
