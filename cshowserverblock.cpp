#include "cshowserverblock.h"

CShowServerBlock::CShowServerBlock(QWidget *parent) : QWidget(parent)
{
    resize(290, 220);
    setStyleSheet("background-color: #ffffff;");
}

void CShowServerBlock::showEvent(QShowEvent *event)
{
    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
                     QBrush(QPixmap(":/images/source/images/show_server.png").scaled(
                                this -> size(),
                                Qt::IgnoreAspectRatio,
                                Qt::SmoothTransformation)));
    this->setPalette(palette);
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
