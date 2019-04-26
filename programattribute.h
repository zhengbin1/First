#ifndef PROGRAMATTRIBUTE_H
#define PROGRAMATTRIBUTE_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLabel>

class ProgramAttribute : public QWidget
{
    Q_OBJECT
public:
    explicit ProgramAttribute(QWidget *parent = nullptr);
    ~ProgramAttribute();
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // PROGRAMATTRIBUTE_H
