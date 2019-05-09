#ifndef PROGRAMATTRIBUTE_LEFT_H
#define PROGRAMATTRIBUTE_LEFT_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLabel>

class ProgramAttributeLeft : public QWidget
{
    Q_OBJECT
public:
    explicit ProgramAttributeLeft(QWidget *parent = nullptr);
    ~ProgramAttributeLeft();
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // PROGRAMATTRIBUTE_LEFT_H
