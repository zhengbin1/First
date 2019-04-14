#include "caddserver.h"


CAddServer::CAddServer(QWidget *parent) : QWidget(parent)
{


}

void CAddServer::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void CAddServer::showEvent(QShowEvent *event)
{
    QPixmap pixmap(":/images/source/images/add_server.png");
    QLabel *addServerPic = new QLabel(this);
    addServerPic -> setPixmap(pixmap);
    addServerPic -> show();
}
