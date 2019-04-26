#include "resourcelist.h"

ResourceList::ResourceList(QWidget *parent) : QWidget(parent)
{

}

ResourceList::~ResourceList()
{

}

void ResourceList::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}
