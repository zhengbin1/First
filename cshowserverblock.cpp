#include "cshowserverblock.h"
#include <QDebug>

CShowServerBlock::CShowServerBlock(QWidget *parent) : QWidget(parent)
{
    resize(290, 220);
    setStyleSheet("background-color: #ffffff;");

    deleteIcon = new QImage;
    editIcon = new QImage;

    deleteLabel = new QLabel(this);
    editLabel = new QLabel(this);

    deleteIcon -> load(":/images/source/images/delete.png");
    editIcon -> load(":/images/source/images/edit.png");

    editLabel -> resize(editIcon -> width(), editIcon -> height());
    editLabel -> setAttribute(Qt::WA_TranslucentBackground);
    editLabel -> setPixmap(QPixmap::fromImage(*editIcon));
    editLabel -> move(230, 130);

    deleteLabel -> resize(deleteIcon -> width(), deleteIcon -> height());
    deleteLabel -> setAttribute(Qt::WA_TranslucentBackground);
    deleteLabel -> setPixmap(QPixmap::fromImage(*deleteIcon));
    deleteLabel -> move(260, 130);

    connect(deleteLabel, SIGNAL(mousePressEvent(QMouseEvent *)), this, SLOT(on_deleteLabel_click(QMouseEvent *)));
}

void CShowServerBlock::paintEvent(QPaintEvent *)
{
    //this -> setAutoFillBackground(true);

    QPixmap pixmap = QPixmap(":/images/source/images/show_server.png").scaled(this -> size());
    QPainter painter(this);
    painter.drawPixmap(this -> rect(), pixmap);
}

void CShowServerBlock::setNameAndIP(QString ServerInfo)
{
    QStringList tmpInfo = ServerInfo.split("##");
    m_ServerName = tmpInfo.at(0);
    m_ServerIP = tmpInfo.at(1);

    QLabel *ServerName = new QLabel(this);
    ServerName -> setStyleSheet("background-color: #FFFFFF;");
    QString serverName("<span style=\"height:20px;color:#000000;font-size:15px;\">%1</span>");
    ServerName -> setText(serverName.arg(m_ServerName));
    ServerName -> move(20, 170);

    QLabel *ServerIP = new QLabel(this);
    ServerIP -> setStyleSheet("background-color: #FFFFFF;");
    QString serverIP("<span style=\"height:20px;color:#000000;font-size:15px;\">%1</span>");
    ServerIP -> setText(serverIP.arg(m_ServerIP));
    ServerIP -> move(20, 192);
}

void CShowServerBlock::mousePressEvent(QMouseEvent *)
{
    qDebug() << m_ServerName << m_ServerIP;
}

CShowServerBlock::~CShowServerBlock()
{
    delete deleteIcon;
    delete editIcon;

    delete deleteLabel;
    delete editLabel;
}

void CShowServerBlock::on_deleteLabel_click(QMouseEvent *)
{
    qDebug() << "on_deleteLabel_click";
}
