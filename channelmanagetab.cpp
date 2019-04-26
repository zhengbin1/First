#include "channelmanagetab.h"

ChannelManageTab::ChannelManageTab(QWidget *parent) : QWidget(parent)
{

}

void ChannelManageTab::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

ChannelManageTab::~ChannelManageTab()
{

}
