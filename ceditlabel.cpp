#include "ceditlabel.h"
#include <QtDebug>

CEditLabel::CEditLabel(QWidget *parent) : QWidget(parent)
{
    editIcon = new QImage;
    editIcon -> load(":/images/source/images/edit.png");

    resize(editIcon -> width(), editIcon -> height());
}

void CEditLabel::paintEvent(QPaintEvent *)
{
    QPixmap pixmap = QPixmap(":/images/source/images/edit.png").scaled(this -> size());
    QPainter painter(this);
    painter.drawPixmap(this -> rect(), pixmap);
}

void CEditLabel::mousePressEvent(QMouseEvent *)
{
    qDebug() << "eeeeeeeeeeeee";
}

CEditLabel::~CEditLabel()
{
    delete editIcon;
}
