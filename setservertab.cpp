#include "setservertab.h"

SetServerTab::SetServerTab(QWidget *parent) : QWidget(parent)
{

}

void SetServerTab::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}
