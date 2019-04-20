#ifndef CADDSERVER_H
#define CADDSERVER_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLabel>

#include "addserverdialog.h"

class CAddServer : public QWidget
{
    Q_OBJECT
public:
    explicit CAddServer(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *);

private:
    AddServerDialog *addServerDialog;

signals:
    void sendServerInfo(QString);
};

#endif // CADDSERVER_H
