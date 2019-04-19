#include "meger2_main_content.h"
#include <QDebug>


Meger2_main_content::Meger2_main_content(QWidget *parent) : QWidget(parent)
{
    add_server = new CAddServer(this);  // 添加服务器
    add_server -> move(40, 40);

    connect(add_server, SIGNAL(sendStringList(QStringList)), this, SLOT(recvStringList(QStringList)));

    Meger2_main_width = parent -> geometry().width();  // 主窗口宽度
}

void Meger2_main_content::recvStringList(QStringList serverStringList)
{
    ServerInfoList = serverStringList;

    int startX = 40;
    int startY = 40;

    int nextX = startX;
    int nextY = startY;

    ServerInfoStack.clear();

    for (int i = 0; i < ServerInfoList.size(); i ++)
    {
        CShowServerBlock *showServerBlock = new CShowServerBlock(this);
        showServerBlock -> setNameAndIP(i, ServerInfoList.at(i));
        ServerInfoStack.push(showServerBlock);

        connect(showServerBlock, SIGNAL(deleteblock(int, QString)), this, SLOT(delServerBlock(int, QString)));
    }

    int j = 0;
    while (!ServerInfoStack.isEmpty())
    {
        CShowServerBlock *showServerBlock = ServerInfoStack.pop();
        showServerBlock -> move(nextX, nextY);
        showServerBlock -> show();
        nextX += 320;
        j ++;
        int tmpNum = j % 4;

        if (tmpNum == 0)
        {
            nextX = startX;
            nextY += 250;
            resize(Meger2_main_width - 20, nextY + 350);
        }
    }

    add_server -> move(nextX, nextY);
}

void Meger2_main_content::delServerBlock(int id, QString ServerInfo)
{
    QStringList tmpInfo = ServerInfo.split("##");

    int blockID = id;
    QString ServerName = tmpInfo.at(0);
    QString ServerIP = tmpInfo.at(1);

    ServerInfoList.removeAt(blockID);

    int startX = 40;
    int startY = 40;

    int nextX = startX;
    int nextY = startY;

    ServerInfoStack.clear();

    int i = 0;
    QStringList::const_iterator constIterator;
    for (constIterator = ServerInfoList.constBegin(); constIterator != ServerInfoList.constEnd(); ++constIterator)
    {
        CShowServerBlock *showServerBlock = new CShowServerBlock(this);
        showServerBlock -> setNameAndIP(i, (*constIterator).toLocal8Bit().constData());
        ServerInfoStack.push(showServerBlock);

        connect(showServerBlock, SIGNAL(deleteblock(int, QString)), this, SLOT(delServerBlock(int, QString)));

        i ++;
    }


    int j = 0;
    while (!ServerInfoStack.isEmpty())
    {
        CShowServerBlock *showServerBlock = ServerInfoStack.pop();
        showServerBlock -> move(nextX, nextY);
        showServerBlock -> show();
        nextX += 320;
        j ++;
        int tmpNum = j % 4;

        if (tmpNum == 0)
        {
            nextX = startX;
            nextY += 250;
            resize(Meger2_main_width - 20, nextY + 350);
        }
    }

    add_server -> move(nextX, nextY);
}
