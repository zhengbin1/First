#ifndef MEGER2_MAIN_CONTENT_H
#define MEGER2_MAIN_CONTENT_H

#include <QWidget>
#include <QLabel>
#include <QGuiApplication>
#include <QScreen>
#include <QStack>

#include "caddserver.h"
#include "cshowserverblock.h"

class Meger2_main_content : public QWidget
{
    Q_OBJECT
public:
    explicit Meger2_main_content(QWidget *parent = nullptr);

signals:

public slots:
    void recvStringList(QStringList);

private:
    QStringList ServerInfoList;  // 存放服务器地址
    CAddServer *add_server;  // 添加服务器
    QStack<CShowServerBlock *> ServerInfoStack;
    int Meger2_main_width;   // 主窗口宽度
};

#endif // MEGER2_MAIN_CONTENT_H
