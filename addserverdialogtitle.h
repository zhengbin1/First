#ifndef ADDSERVERDIALOGTITLE_H
#define ADDSERVERDIALOGTITLE_H

#include <QLabel>
#include <QMouseEvent>

class AddServerDialogTitle : public QLabel
{
public:
    explicit AddServerDialogTitle(QWidget *parent);

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    bool isDrag;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPoint;
    QWidget *label_parent;
};

#endif // ADDSERVERDIALOGTITLE_H
