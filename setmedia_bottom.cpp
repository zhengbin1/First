#include "setmedia_bottom.h"
#include <QHBoxLayout>
#include <QDebug>

SetMediaBottom::SetMediaBottom(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #242631;");

    topWidget = new QWidget(this);
    topWidget -> resize(120, 120);
    topWidget -> move(0, 0);

    bottomWidget = new BottomWidget(this);

    addVideo = new QLabel(topWidget);
    addVideo -> resize(120,120);
    addVideo -> setStyleSheet("background-color: #000000;");
    addVideo -> setText("<a href=\"add_video\" style=\"text-decoration:none;\"><p style=\"line-height:120px;height:120px;color:#FFFFFF;font-size:90px;text-align:center;\">+<p></a>");

    connect(addVideo, SIGNAL(linkActivated(QString)), this, SLOT(addVideoW(QString)));

    m_video_count = 1;

    // int width = geometry().width();  // 窗口宽度

    scrollArea = new QScrollArea(this);
    scrollArea -> setFrameShape(QFrame::NoFrame);
    scrollArea -> setWidgetResizable(false);
    scrollArea -> setWidget(topWidget);
}

SetMediaBottom::~SetMediaBottom()
{
    qDeleteAll(VideoList.begin(), VideoList.end());

    delete topWidget;
    delete bottomWidget;
    delete addVideo;
    delete scrollArea;
}

void SetMediaBottom::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);

    bottomWidget -> resize(this -> width(), 60);
    bottomWidget -> move(0, 130);
}

void SetMediaBottom::resizeEvent(QResizeEvent *event)
{
    scrollArea -> resize(this -> width(), 130);
    scrollArea -> move(0, 0);
}

void SetMediaBottom::addVideoW(QString str)
{
    VideoWidget *videoWidget = new VideoWidget(topWidget);
    videoWidget -> setTitleName("节目" + QString::number(m_video_count));

    VideoList.append(videoWidget);

    int list_width = 0;

    m_video_count ++;

    for (int i = 0; i < VideoList.size(); ++i) {
        VideoWidget *videoWidget = VideoList.at(i);
        videoWidget -> move(list_width, 10);
        videoWidget -> show();
        list_width += 120;
        topWidget -> resize(list_width + 120, 120);
    }

    addVideo -> move(list_width, 10);
}

VideoWidget::VideoWidget(QWidget *parent) : QWidget(parent)
{
    resize(120, 120);
    this -> setStyleSheet("background-color: #454753;border:1px solid #545454;");

    title = new QLabel(this);
    title -> setStyleSheet("background-color: #5C5D67");

    videoIcon = new QLabel(this);
    QPixmap Pixmap1(":/images/source/images/video.png");
    videoIcon -> setStyleSheet("border-style: none;");
    videoIcon -> setPixmap(Pixmap1);
    videoIcon -> resize(Pixmap1.size());
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

    title -> resize(width, 30);
    title -> move(0, 0);

    videoIcon -> move(40, 60);
}

void VideoWidget::setTitleName(QString name)
{
    title -> setText("<p style=\"line-height:25px;height:30px;color:#FFFFFF;font-size:15px;text-align:center;\">" + name + "<p>");
}


BottomWidget::BottomWidget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #3A3C4A;");

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
