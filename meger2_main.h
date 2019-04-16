#ifndef MEGER2_MAIN_H
#define MEGER2_MAIN_H

#include <QDialog>
#include <QLabel>
#include <QDesktopWidget>
#include <QGuiApplication>
#include <QScreen>

#include "clickablelabel.h"
#include "labeltitlename.h"
#include "caddserver.h"
#include "cshowserverblock.h"

#include <QDebug>

namespace Ui {
class Meger2_main;
}

class Meger2_main : public QDialog
{
    Q_OBJECT

public:
    explicit Meger2_main(QWidget *parent = nullptr);
    ~Meger2_main();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_label_title_close_click();
    void recvStringList(QStringList);

private:
    Ui::Meger2_main *ui;
    QStringList ServerInfoList;  // 存放服务器地址
    CAddServer *add_server;  // 添加服务器
};

#endif // MEGER2_MAIN_H
