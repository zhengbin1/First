#ifndef LABELTITLENAME_H
#define LABELTITLENAME_H
#include <QLabel>
#include <QMouseEvent>

class LabelTitleName : public QLabel
{
    Q_OBJECT

public:
    explicit LabelTitleName(QWidget* parent = Q_NULLPTR);
    ~LabelTitleName();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    bool isDrag;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPoint;
    QWidget *label_parent;
};

#endif // LABELTITLENAME_H
