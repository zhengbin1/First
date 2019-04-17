#ifndef CSHOWSERVERBLOCK_H
#define CSHOWSERVERBLOCK_H

#include <QWidget>
#include <QLabel>

class CShowServerBlock : public QWidget
{
    Q_OBJECT

public:
    explicit CShowServerBlock(QWidget *parent = nullptr);
    void showEvent(QShowEvent *event);
    void setNameAndIP(QString);

private:
    QString m_ServerName;
    QString m_ServerIP;

signals:

public slots:
};

#endif // CSHOWSERVERBLOCK_H
