#include "programattribute.h"
#include <QDebug>

VideoItem::VideoItem(QWidget *parent) : QWidget(parent)
{
    m_parent = parent;

    videoName = new QLabel(this);

    stop_unselected = new QLabel(this);
    QPixmap Pixmap1(":/images/source/images/stop_unselected.png");
    stop_unselected -> setPixmap(Pixmap1);
    stop_unselected -> resize(Pixmap1.size());

    cycle_unselected = new QLabel(this);
    QPixmap Pixmap2(":/images/source/images/cycle_unselected.png");
    cycle_unselected -> setPixmap(Pixmap2);
    cycle_unselected -> resize(Pixmap2.size());

    order_unselected = new QLabel(this);
    QPixmap Pixmap3(":/images/source/images/order_unselected.png");
    order_unselected -> setPixmap(Pixmap3);
    order_unselected -> resize(Pixmap3.size());


    hBoxLayout = new QHBoxLayout(this);
    hBoxLayout -> addWidget(videoName);
    hBoxLayout -> addWidget(stop_unselected);
    hBoxLayout -> addWidget(cycle_unselected);
    hBoxLayout -> addWidget(order_unselected);

    hBoxLayout ->setStretchFactor(videoName, 5);
    hBoxLayout ->setStretchFactor(stop_unselected, 1);
    hBoxLayout ->setStretchFactor(cycle_unselected, 1);
    hBoxLayout ->setStretchFactor(order_unselected, 1);

    this -> setLayout(hBoxLayout);
}

VideoItem::~VideoItem()
{
    delete hBoxLayout;

    delete videoName;

    delete stop_unselected;
    delete cycle_unselected;
    delete order_unselected;
}

void VideoItem::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);

    int parentW = m_parent -> geometry().width();  // 父窗口宽度
    int parentH = m_parent -> geometry().height();  // 父窗口高度

    resize(parentW, 50);
}

void VideoItem::setItemName(QString name)
{
    videoName -> setText("<p style=\"line-height:25px;height:25px;color:#FFFFFF;font-size:13px;text-align:center;\">" + name + "<p>");
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
