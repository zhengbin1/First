#ifndef MEGER2TABBASE_H
#define MEGER2TABBASE_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLabel>

#include "channelmanagetab.h"
#include "setmediatab.h"
#include "setservertab.h"


class Meger2TabBase : public QWidget
{
    Q_OBJECT
public:
    explicit Meger2TabBase(QWidget *parent = nullptr);
    ~Meger2TabBase();

    void paintEvent(QPaintEvent *);

private:
    int tabnum;

    QWidget *titleOne;
    QLabel *setServer;
    QLabel *setMedia;
    QLabel *channelManage;

    ChannelManageTab *channelManageTab;
    SetMediaTab *setMediaTab;
    SetServerTab *setServerTab;

signals:

private slots:
    void LinkActivated(QString);
};

#endif // MEGER2TABBASE_H
