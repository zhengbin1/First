#ifndef CADDSERVER_H
#define CADDSERVER_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLabel>

class CAddServer : public QWidget
{
    Q_OBJECT
public:
    explicit CAddServer(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);
    void showEvent(QShowEvent *event);

signals:

public slots:
};

#endif // CADDSERVER_H
