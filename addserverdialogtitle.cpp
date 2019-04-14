#include "addserverdialogtitle.h"

AddServerDialogTitle::AddServerDialogTitle(QWidget *parent)
    : QLabel(parent) {
    label_parent = parent;
    isDrag = false;
}

// 窗口拖动操作
void AddServerDialogTitle::mousePressEvent(QMouseEvent *event)
{
    if(event -> button() == Qt::LeftButton)
    {
        isDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event -> globalPos();
        //获得窗口的初始位置
        windowTopLeftPoint = this -> frameGeometry().topLeft();
    }
}

void AddServerDialogTitle::mouseMoveEvent(QMouseEvent *event)
{
    if(isDrag == true)
    {
        //获得鼠标移动的距离
        QPoint distance = event -> globalPos() - mouseStartPoint;
        //改变窗口的位置
        this -> move(windowTopLeftPoint + distance);
    }
}

void AddServerDialogTitle::mouseReleaseEvent(QMouseEvent *event)
{
    if(event -> button() == Qt::LeftButton)
    {
        isDrag = false;
    }
}
