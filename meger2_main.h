#ifndef MEGER2_MAIN_H
#define MEGER2_MAIN_H

#include <QDialog>
#include <QLabel>
#include <QGuiApplication>
#include <QScreen>
#include <QStack>
#include <QScrollArea>

#include "clickablelabel.h"
#include "labeltitlename.h"
#include "meger2_main_content.h"

namespace Ui {
class Meger2_main;
}

class Meger2_main : public QDialog
{
    Q_OBJECT

public:
    explicit Meger2_main(QWidget *parent = nullptr);
    ~Meger2_main();

private slots:
    void on_label_title_close_click();

private:
    Ui::Meger2_main *ui;
    Meger2_main_content *MegerMainContent;
};

#endif // MEGER2_MAIN_H
