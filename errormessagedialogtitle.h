#ifndef ERRORMESSAGEDIALOGTITLE_H
#define ERRORMESSAGEDIALOGTITLE_H

#include <QLabel>
#include <QMouseEvent>


class ErrorMessageDialogTitle : public QLabel
{
public:
    ErrorMessageDialogTitle(QWidget *parent);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    bool isDrag;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPoint;
    QWidget *label_parent;
};

#endif // ERRORMESSAGEDIALOGTITLE_H
