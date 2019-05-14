#ifndef SETMEDIA_BOTTOM_H
#define SETMEDIA_BOTTOM_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLabel>
#include <QList>
#include <QScrollArea>


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
    void resizeEvent(QResizeEvent *);

private:
    QWidget *topWidget;
    BottomWidget *bottomWidget;
    QScrollArea *scrollArea;

    QLabel *addVideo;
    QList<VideoWidget *> VideoList;

    int m_video_count;

signals:

public slots:
    void addVideoW(QString);
};



#endif // SETMEDIA_BOTTOM_H
