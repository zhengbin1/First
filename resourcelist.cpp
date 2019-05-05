#include "resourcelist.h"
#include <QDebug>

ResourceList::ResourceList(QWidget *parent) : QWidget(parent)
{
    all_button = new QPushButton(this);
    all_button -> setStyleSheet("color:#FFFFFF;background-color:#41434E;border:1px solid #989A9C;font-size:12px;");
    all_button -> setText("全 部");
    all_button -> resize(45, 25);
    all_button -> move(30, 0);

    video_button = new QPushButton(this);
    video_button -> setStyleSheet("color:#FFFFFF;background-color:#41434E;border:1px solid #989A9C;font-size:12px;");
    video_button -> setText("视 频");
    video_button -> resize(45, 25);
    video_button -> move(75, 0);

    image_button = new QPushButton(this);
    image_button -> setStyleSheet("color:#FFFFFF;background-color:#41434E;border:1px solid #989A9C;font-size:12px;");
    image_button -> setText("图 片");
    image_button -> resize(45, 25);
    image_button -> move(120, 0);

    gather_button = new QPushButton(this);
    gather_button -> setStyleSheet("color:#FFFFFF;background-color:#41434E;border:1px solid #989A9C;font-size:12px;");
    gather_button -> setText("采 集");
    gather_button -> resize(45, 25);
    gather_button -> move(165, 0);

    sound_button = new QPushButton(this);
    sound_button -> setStyleSheet("color:#FFFFFF;background-color:#41434E;border:1px solid #989A9C;font-size:12px;");
    sound_button -> setText("音 频");
    sound_button -> resize(45, 25);
    sound_button -> move(210, 0);

    resourceListView = new QListView(this);
    resourceListView -> setStyleSheet("color:#FFFFFF;background-color:#3D404D;border:1px solid #989A9C;font-size:12px;");

    refreshButton = new RefreshButton(this);
    connect(refreshButton, SIGNAL(refresh()), this, SLOT(recvRefresh()));

    save_button = new QPushButton(this);
    save_button -> setStyleSheet("color:#FFFFFF;background-color:#E64545;border:1px solid #B04040;font-size:17px;");
    save_button -> setText("保 存");
}

ResourceList::~ResourceList()
{
    delete all_button;
    delete video_button;
    delete image_button;
    delete gather_button;
    delete sound_button;

    delete resourceListView;
}

void ResourceList::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);

    int resource_width = this -> geometry().width();  // 窗口宽度
    int resource_height = this -> geometry().height();  // 窗口高度

    resourceListView -> resize(resource_width - 10, resource_height / 10 * 7);
    resourceListView -> move(5, 40);

    refreshButton -> move(resource_width / 2, resource_height / 10 * 7 + 60);

    save_button -> resize(resource_width, 45);
    save_button -> move(0, resource_height / 10 * 7 + 100);
}

void ResourceList::recvRefresh()
{

}
