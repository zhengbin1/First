#include "programattribute.h"

ProgramAttribute::ProgramAttribute(QWidget *parent) : QWidget(parent)
{

}

ProgramAttribute::~ProgramAttribute()
{

}

void ProgramAttribute::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}
