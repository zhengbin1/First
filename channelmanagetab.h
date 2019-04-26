#ifndef CHANNELMANAGETAB_H
#define CHANNELMANAGETAB_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLabel>

class ChannelManageTab : public QWidget
{
    Q_OBJECT
public:
    explicit ChannelManageTab(QWidget *parent = nullptr);
    ~ChannelManageTab();
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // CHANNELMANAGETAB_H
