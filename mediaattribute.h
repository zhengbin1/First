#ifndef MEDIAATTRIBUTE_H
#define MEDIAATTRIBUTE_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLabel>

class MediaAttribute : public QWidget
{
    Q_OBJECT
public:
    explicit MediaAttribute(QWidget *parent = nullptr);
    ~MediaAttribute();
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // MEDIAATTRIBUTE_H
