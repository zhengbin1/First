#ifndef SETMEDIATAB_H
#define SETMEDIATAB_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLabel>

class SetMediaTab : public QWidget
{
    Q_OBJECT
public:
    explicit SetMediaTab(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~SetMediaTab();

private:
    int tabnum;

    QWidget *titleSon;
    QLabel *resourceList;
    QLabel *programAttribute;
    QLabel *mediaAttribute;

signals:

public slots:
};

#endif // SETMEDIATAB_H
