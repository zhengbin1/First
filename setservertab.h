#ifndef SETSERVERTAB_H
#define SETSERVERTAB_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLabel>

class SetServerTab : public QWidget
{
    Q_OBJECT
public:
    explicit SetServerTab(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // SETSERVERTAB_H
