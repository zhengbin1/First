#include "mediaattribute.h"

MediaAttribute::MediaAttribute(QWidget *parent) : QWidget(parent)
{

}

MediaAttribute::~MediaAttribute()
{

}

void MediaAttribute::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}
