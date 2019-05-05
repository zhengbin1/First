#include "refreshbutton.h"

RefreshButton::RefreshButton(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #ffffff;");

    refreshIcon = new QImage;
    refreshIcon -> load(":/images/source/images/refresh.png");

    resize(refreshIcon -> width(), refreshIcon -> height());
}

RefreshButton::~RefreshButton()
{
    delete refreshIcon;
}

void RefreshButton::paintEvent(QPaintEvent *)
{
    QPixmap pixmap = QPixmap(":/images/source/images/refresh.png").scaled(this -> size());
    QPainter painter(this);
    painter.drawPixmap(this -> rect(), pixmap);
}

void RefreshButton::mousePressEvent(QMouseEvent *)
{
    emit refresh();
}
