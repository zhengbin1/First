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

    void paintEvent(QPaintEvent *);

private:
    QLabel *title;
    QLabel *videoIcon;
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

signals:

public slots:
};



#endif // SETMEDIA_BOTTOM_H
