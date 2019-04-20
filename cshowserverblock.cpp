#include "cshowserverblock.h"
#include <QDebug>

CShowServerBlock::CShowServerBlock(QWidget *parent) : QWidget(parent)
{
    resize(290, 220);
    setStyleSheet("background-color: #ffffff;");


    editLabel = new CEditLabel(this);
    editLabel -> move(230, 130);

    deleteLabel = new CDeleteLabel(this);
    deleteLabel -> move(260, 130);

    connect(deleteLabel, SIGNAL(deleteblock(int, QString)), this, SIGNAL(deleteblock(int, QString)));
}

void CShowServerBlock::paintEvent(QPaintEvent *)
{
    //this -> setAutoFillBackground(true);

    BackgroundPixmap = new QPixmap(":/images/source/images/show_server.png");
    BackgroundPixmap -> scaled(this -> size());
    BackgroundPainter = new QPainter(this);
    BackgroundPainter -> drawPixmap(this -> rect(), *BackgroundPixmap);
}

void CShowServerBlock::setNameAndIP(int id, QString ServerInfo)
{
    QStringList tmpInfo = ServerInfo.split("##");

    BlockID = id;
    m_ServerName = tmpInfo.at(0);
    m_ServerIP = tmpInfo.at(1);

    deleteLabel -> setIDandServerInfo(id, ServerInfo);

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
    delete deleteLabel;
    delete editLabel;

    delete BackgroundPixmap;
    delete BackgroundPainter;
}
