#include "programattribute_left.h"

ProgramAttributeLeft::ProgramAttributeLeft(QWidget *parent) : QWidget(parent)
{

}

ProgramAttributeLeft::~ProgramAttributeLeft()
{

}

void ProgramAttributeLeft::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);

    int width = geometry().width();  // 窗口宽度
    int height = geometry().height();  // 窗口高度

    QPainter painter1(this);
    painter1.setPen(QPen(QColor(126, 130, 142), 1));
    painter1.drawLine(0, height / 4, width, height / 4);
}
