#include "caddserver.h"

#include <QDebug>


CAddServer::CAddServer(QWidget *parent) : QWidget(parent)
{
    resize(300, 280);
    setStyleSheet("background-color: #242631;");

    QLabel *addServer = new QLabel(this);
    addServer -> setText("<p style=\"color:#fff;font-size:18px;text-align:center;\">添加服务器<p>");
    addServer -> move(100, 240);

    addServerDialog = new AddServerDialog(this);
    connect(addServerDialog, SIGNAL(sendStringList(QStringList)), this, SLOT(recvStringList(QStringList)));

    QPixmap pixmap(":/images/source/images/add_server.png");
    QLabel *addServerPic = new QLabel(this);
    addServerPic -> setPixmap(pixmap);
    addServerPic -> show();
}

void CAddServer::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void CAddServer::mousePressEvent(QMouseEvent *)
{
    addServerDialog -> setWindowModality(Qt::ApplicationModal);
    addServerDialog -> show();
}

void CAddServer::recvStringList(QStringList serverInfoList)
{
    emit sendStringList(serverInfoList);
}
