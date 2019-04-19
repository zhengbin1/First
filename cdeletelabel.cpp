#include "cdeletelabel.h"
#include <QDebug>

CDeleteLabel::CDeleteLabel(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #ffffff;");

    deleteIcon = new QImage;
    deleteIcon -> load(":/images/source/images/delete.png");

    resize(deleteIcon -> width(), deleteIcon -> height());
}

void CDeleteLabel::paintEvent(QPaintEvent *)
{
    QPixmap pixmap = QPixmap(":/images/source/images/delete.png").scaled(this -> size());
    QPainter painter(this);
    painter.drawPixmap(this -> rect(), pixmap);
}

void CDeleteLabel::mousePressEvent(QMouseEvent *)
{
    emit deleteblock(BlockID, m_ServerInfo);
}

void CDeleteLabel::setIDandServerInfo(int id, QString ServerInfo)
{
    BlockID = id;
    m_ServerInfo = ServerInfo;
}

CDeleteLabel::~CDeleteLabel()
{
    delete deleteIcon;
}
