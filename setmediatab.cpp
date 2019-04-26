#include "setmediatab.h"

SetMediaTab::SetMediaTab(QWidget *parent) : QWidget(parent)
{

}

void SetMediaTab::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

SetMediaTab::~SetMediaTab()
{

}
