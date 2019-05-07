#ifndef SETMEDIA_BOTTOM_H
#define SETMEDIA_BOTTOM_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>


class SetMediaBottom : public QWidget
{
    Q_OBJECT
public:
    explicit SetMediaBottom(QWidget *parent = nullptr);
    ~SetMediaBottom();

    void paintEvent(QPaintEvent *);

private:
    QWidget *bottomWidget;

signals:

public slots:
};

#endif // SETMEDIA_BOTTOM_H
