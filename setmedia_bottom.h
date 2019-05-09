#ifndef SETMEDIA_BOTTOM_H
#define SETMEDIA_BOTTOM_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLabel>


class BottomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BottomWidget(QWidget *);
    ~BottomWidget();

    void paintEvent(QPaintEvent *);

private:
    QLabel *stopButton;
    QLabel *playButton;
    QLabel *nextButton;
    QLabel *soundButton;
};


class VideoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoWidget(QWidget *);
    ~VideoWidget();

    void setTitleName(QString);

private:
    void paintEvent(QPaintEvent *);

    QLabel *title;
    QLabel *videoIcon;
    QString titleName;
};


class SetMediaBottom : public QWidget
{
    Q_OBJECT
public:
    explicit SetMediaBottom(QWidget *parent = nullptr);
    ~SetMediaBottom();

    void paintEvent(QPaintEvent *);

private:
    BottomWidget *bottomWidget;
    VideoWidget *videoWidget1;
    VideoWidget *videoWidget2;
    VideoWidget *videoWidget3;
    VideoWidget *videoWidget4;
    VideoWidget *videoWidget5;

    QLabel *addVideo;

signals:

public slots:
};



#endif // SETMEDIA_BOTTOM_H
