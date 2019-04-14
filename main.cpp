#include "meger2_main.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Meger2_main w;
    w.setWindowTitle("Meger V2.0 登录");
    w.show();

    return a.exec();
}
