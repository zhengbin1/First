#ifndef MEGER2CONTENT_H
#define MEGER2CONTENT_H

#include <QDialog>

#include <QGuiApplication>
#include <QScreen>

#include "clickablelabel.h"
#include "labeltitlename.h"
#include "meger2tabbase.h"
#include "resourcelist_left.h"
#include "setmedia_bottom.h"


namespace Ui {
class Meger2Content;
}

class Meger2Content : public QDialog
{
    Q_OBJECT

public:
    explicit Meger2Content(QWidget *parent = nullptr);
    ~Meger2Content();
    void paintEvent(QPaintEvent *);

private:
    Ui::Meger2Content *ui;

    int screen_width;
    int screen_height;

    LabelTitleName *label_title_name;
    ClickableLabel *label_title_max;
    ClickableLabel *label_title_mini;
    ClickableLabel *label_title_close;

    Meger2TabBase *meger2TabBase;
    ResourceListLeft *resourceListLeft;
    SetMediaBottom *setMediaBottom;


public slots:
    void on_label_title_close_click();
    void on_label_max_click();
    void on_label_mini_click();

    void showSlot(int);
};

#endif // MEGER2CONTENT_H
