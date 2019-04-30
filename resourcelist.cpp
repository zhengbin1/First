#include "resourcelist.h"

ResourceList::ResourceList(QWidget *parent) : QWidget(parent)
{
    all_button = new QPushButton(this);
    all_button -> setStyleSheet("color:#FFFFFF;background-color:#5C6378;border:1px solid #989A9C;");
    all_button -> resize(100, 50);
}

ResourceList::~ResourceList()
{
    delete all_button;
}

void ResourceList::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}
