#include "labeltitlename.h"


LabelTitleName::LabelTitleName(QWidget *parent, Qt::WindowFlags f)
    : QLabel(parent) {
    label_parent = parent;
    isDrag = false;
}

LabelTitleName::~LabelTitleName() {}

// 窗口拖动操作
void LabelTitleName::mousePressEvent(QMouseEvent *event)
{
    if(event -> button() == Qt::LeftButton)
    {
        isDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event -> globalPos();
        //获得窗口的初始位置
        windowTopLeftPoint = label_parent -> frameGeometry().topLeft();
    }
}

void LabelTitleName::mouseMoveEvent(QMouseEvent *event)
{
    if(isDrag == true)
    {
        //获得鼠标移动的距离
        QPoint distance = event -> globalPos() - mouseStartPoint;
        //改变窗口的位置
        label_parent -> move(windowTopLeftPoint + distance);
    }
}

void LabelTitleName::mouseReleaseEvent(QMouseEvent *event)
{
    if(event -> button() == Qt::LeftButton)
    {
        isDrag = false;
    }
}
