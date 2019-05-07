#ifndef RESOURCELISTLEFT_H
#define RESOURCELISTLEFT_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>

class ResourceListLeft : public QWidget
{
    Q_OBJECT
public:
    explicit ResourceListLeft(QWidget *parent = nullptr);
    ~ResourceListLeft();
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // RESOURCELISTLEFT_H
