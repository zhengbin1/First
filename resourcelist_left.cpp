#include "resourcelist_left.h"

ResourceListLeft::ResourceListLeft(QWidget *parent) : QWidget(parent)
{

}

ResourceListLeft::~ResourceListLeft()
{

}

void ResourceListLeft::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}
