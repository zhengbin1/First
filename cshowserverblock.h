#ifndef CSHOWSERVERBLOCK_H
#define CSHOWSERVERBLOCK_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QTcpSocket>
#include <QHostAddress>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QStringListModel>
#include <QTextCodec>

#include "cdeletelabel.h"
#include "ceditlabel.h"
#include "errormessagedialog.h"


class CShowServerBlock : public QWidget
{
    Q_OBJECT

public:
    explicit CShowServerBlock(QWidget *parent = nullptr);
    ~CShowServerBlock();

    void setNameAndIP(int, QString);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    int BlockID;
    QString m_ServerName;
    QString m_ServerIP;

    CEditLabel *editLabel;
    CDeleteLabel *deleteLabel;

    QPixmap *BackgroundPixmap;
    QPainter *BackgroundPainter;

    QTcpSocket *tcpsocket;

signals:
    void deleteblock(int, QString);

public slots:
};

struct NET_PACKAGE_HEAD
{
    unsigned long dwHeadFlag; // 包头标记，固定为0x51CDBEEF
    unsigned long dwCmdType;  // 命令类型
    unsigned long dwBobySize; // 数据体大小，JSON字符串的长度
    unsigned long dwData;     // 包头自带的包头数据，对于简短命令直接使用这个包头数据
};

#endif // CSHOWSERVERBLOCK_H
