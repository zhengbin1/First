#ifndef MEGER2_MAIN_H
#define MEGER2_MAIN_H

#include <QDialog>
#include <QLabel>
#include <QDesktopWidget>
#include <QGuiApplication>
#include <QScreen>

#include "clickablelabel.h"
#include "labeltitlename.h"
#include "caddserver.h"

#include <QDebug>

namespace Ui {
class Meger2_main;
}

class Meger2_main : public QDialog
{
    Q_OBJECT

public:
    explicit Meger2_main(QWidget *parent = nullptr);
    ~Meger2_main();
    void init();

private slots:
    void on_label_title_close_click();

private:
    Ui::Meger2_main *ui;
};

#endif // MEGER2_MAIN_H
