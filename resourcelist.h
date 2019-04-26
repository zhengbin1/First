#ifndef RESOURCELIST_H
#define RESOURCELIST_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLabel>

class ResourceList : public QWidget
{
    Q_OBJECT
public:
    explicit ResourceList(QWidget *parent = nullptr);
    ~ResourceList();
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // RESOURCELIST_H
