#ifndef MEGER2_MAIN_CONTENT_H
#define MEGER2_MAIN_CONTENT_H

#include <QWidget>
#include <QLabel>
#include <QGuiApplication>
#include <QScreen>
#include <QStack>
#include <QPushButton>

#include "caddserver.h"
#include "cshowserverblock.h"
#include "errormessagedialog.h"

class Meger2_main_content : public QWidget
{
    Q_OBJECT
public:
    explicit Meger2_main_content(QWidget *parent = nullptr);

    void inputServerBlockList();

signals:

public slots:
    void recvStringList(QString);
    void delServerBlock(int, QString);

private:
    QStringList ServerInfoList;  // 存放服务器地址
    CAddServer *add_server;  // 添加服务器
    QStack<CShowServerBlock *> ServerInfoStack;
    QStack<CShowServerBlock *> delServerInfoStack;
    int Meger2_main_width;   // 主窗口宽度
};

#endif // MEGER2_MAIN_CONTENT_H
