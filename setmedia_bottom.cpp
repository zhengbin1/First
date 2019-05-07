#include "setmedia_bottom.h"

SetMediaBottom::SetMediaBottom(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #242631;");

    bottomWidget = new QWidget(this);
    bottomWidget -> setStyleSheet("background-color: #3A3C4A");
}

SetMediaBottom::~SetMediaBottom()
{
    delete bottomWidget;
}

void SetMediaBottom::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);

    int width = geometry().width();  // 窗口宽度
    int height = geometry().height();  // 窗口高度

    bottomWidget -> resize(width, 60);
    bottomWidget -> move(0, 130);
}
