#ifndef CSHOWSERVERBLOCK_H
#define CSHOWSERVERBLOCK_H

#include <QWidget>
#include <QLabel>
#include <QPainter>

#include "cdeletelabel.h"
#include "ceditlabel.h"


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

signals:
    void deleteblock(int, QString);

public slots:
};

#endif // CSHOWSERVERBLOCK_H
