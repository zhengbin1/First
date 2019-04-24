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

    tcpsocket = new QTcpSocket(this);
    tcpsocket -> abort();
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

    tcpsocket -> connectToHost(m_ServerIP, 3210, QTcpSocket::ReadWrite);

    struct NET_PACKAGE_HEAD sendPackge;
    sendPackge.dwHeadFlag = 0x51CDBEEF;
    sendPackge.dwCmdType = 1;
    sendPackge.dwBobySize = 0;
    sendPackge.dwData = 0;

    QByteArray sendData;
    sendData.resize(sizeof(struct NET_PACKAGE_HEAD));
    memcpy(sendData.data(), &sendPackge, sizeof(struct NET_PACKAGE_HEAD));

    if (tcpsocket -> waitForConnected(10000))
    {
        tcpsocket -> write(sendData);
        tcpsocket -> flush();
    }
    else
    {
        ErrorMessageDialog *errorMessageDialog = new ErrorMessageDialog(this);
        errorMessageDialog -> setTextContent(m_ServerIP + " 服务器连接失败！");
        errorMessageDialog -> exec();

        tcpsocket -> close();
        delete errorMessageDialog;
        return;
    }

    struct NET_PACKAGE_HEAD *pPackage = new struct NET_PACKAGE_HEAD;

    tcpsocket -> read(reinterpret_cast<char *>(pPackage), sizeof(struct NET_PACKAGE_HEAD));
    struct NET_PACKAGE_HEAD recvPackge;

    memcpy(&recvPackge, pPackage, sizeof(struct NET_PACKAGE_HEAD));

    qDebug() << "dwHeadFlag:" << QString::number(recvPackge.dwHeadFlag, 16);
    qDebug() << "dwBobySize:" << recvPackge.dwBobySize;
    qDebug() << "dwCmdType:" << recvPackge.dwCmdType;
    qDebug() << "dwData:" << recvPackge.dwData;

    if(recvPackge.dwBobySize > 0)
    {
        QTextCodec *codeGBK = QTextCodec::codecForName("gbk");
        QTextCodec *codeUTF8 = QTextCodec::codecForName("UTF-8");

        QByteArray recvBuffer;

        recvBuffer = codeGBK -> fromUnicode(tcpsocket -> readAll());
        qDebug() << recvBuffer;

        QJsonParseError jsonerror;
        QJsonDocument doucment = QJsonDocument::fromJson(codeUTF8 -> fromUnicode(recvBuffer), &jsonerror);

        QStringList mediaItem;

        if (jsonerror.error == QJsonParseError::NoError) {
            if (doucment.isObject()) {
                QJsonObject object = doucment.object();
                QJsonValue jsonValue = object.value("media");
                QJsonArray jsonArray = jsonValue.toArray();

                qDebug() << jsonValue;

                for (int i = 0; i < jsonArray.size(); i ++) {
                    QString jsonLine = jsonArray.at(i).toString();

                    mediaItem << codeGBK -> fromUnicode(jsonLine);
                }

                QStringListModel *mediaListModel = new QStringListModel(this);
                mediaListModel -> setStringList(mediaItem);
            }
        }
    }

    tcpsocket -> close();

    delete pPackage;
}

CShowServerBlock::~CShowServerBlock()
{
    delete deleteLabel;
    delete editLabel;

    delete BackgroundPixmap;
    delete BackgroundPainter;
}
