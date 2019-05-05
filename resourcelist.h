#ifndef RESOURCELIST_H
#define RESOURCELIST_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLabel>
#include <QPushButton>
#include <QListView>

#include "refreshbutton.h"

class ResourceList : public QWidget
{
    Q_OBJECT
public:
    explicit ResourceList(QWidget *parent = nullptr);
    ~ResourceList();
    void paintEvent(QPaintEvent *);

private:
    QPushButton *all_button;
    QPushButton *video_button;
    QPushButton *image_button;
    QPushButton *gather_button;
    QPushButton *sound_button;

    QPushButton *save_button;

    QListView *resourceListView;
    RefreshButton *refreshButton;

signals:

public slots:
    void recvRefresh();
};

#endif // RESOURCELIST_H
