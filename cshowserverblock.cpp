#include "cshowserverblock.h"

CShowServerBlock::CShowServerBlock(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #ffffff;");
    resize(300, 300);
    show();
}

void CShowServerBlock::showEvent(QShowEvent *event)
{
    QPixmap pixmap(":/images/source/images/show_server.png");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}
