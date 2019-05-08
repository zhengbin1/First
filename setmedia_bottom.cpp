#include "setmedia_bottom.h"


SetMediaBottom::SetMediaBottom(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #242631;");


    bottomWidget = new BottomWidget(this);
}

SetMediaBottom::~SetMediaBottom()
{
    delete bottomWidget;
}

void SetMediaBottom::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);

    int width = geometry().width();  // 窗口宽度
    int height = geometry().height();  // 窗口高度

    bottomWidget -> resize(width, 60);
    bottomWidget -> move(0, 130);
}


VideoWidget::VideoWidget(QWidget *parent) : QWidget(parent)
{
    resize(120, 120);

    title = new QLabel(this);
}

VideoWidget::~VideoWidget()
{
    delete title;
}

void VideoWidget::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);

    int width = geometry().width();  // 窗口宽度
    int height = geometry().height();  // 窗口高度
}


BottomWidget::BottomWidget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #3A3C4A");

    stopButton = new QLabel(this);
    playButton = new QLabel(this);
    nextButton = new QLabel(this);
    soundButton = new QLabel(this);

    QPixmap Pixmap1(":/images/source/images/stop.png");
    stopButton -> setPixmap(Pixmap1);
    stopButton -> resize(Pixmap1.size());

    QPixmap Pixmap2(":/images/source/images/play.png");
    playButton -> setPixmap(Pixmap2);
    playButton -> resize(Pixmap2.size());

    QPixmap Pixmap3(":/images/source/images/next.png");
    nextButton -> setPixmap(Pixmap3);
    nextButton -> resize(Pixmap3.size());

    QPixmap Pixmap4(":/images/source/images/sound.png");
    soundButton -> setPixmap(Pixmap4);
    soundButton -> resize(Pixmap4.size());
}

BottomWidget::~BottomWidget()
{
    delete stopButton;
    delete playButton;
    delete nextButton;
    delete soundButton;
}

void BottomWidget::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);

    int width = geometry().width();  // 窗口宽度
    int height = geometry().height();  // 窗口高度

    stopButton -> move(20, 10);
    playButton -> move(90, 10);
    nextButton -> move(160, 10);
    soundButton -> move(280, 20);

    QPainter painterProgress(this);
    painterProgress.setPen(QPen(QColor(41, 43, 55), 6));
    painterProgress.drawLine(330, 30, width / 2 , 30);
}
