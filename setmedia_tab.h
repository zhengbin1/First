#ifndef SETMEDIATAB_H
#define SETMEDIATAB_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLabel>

#include "resourcelist.h"
#include "programattribute.h"
#include "mediaattribute.h"

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

    ResourceList *resourceListTab;
    ProgramAttribute *programAttributeTab;
    MediaAttribute *mediaAttributeTab;

signals:
    void showSignal(int);

public slots:
    void LinkActivated(QString);
};

#endif // SETMEDIATAB_H
