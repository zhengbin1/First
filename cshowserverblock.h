#ifndef CSHOWSERVERBLOCK_H
#define CSHOWSERVERBLOCK_H

#include <QWidget>
#include <QLabel>
#include <QPainter>

class CShowServerBlock : public QWidget
{
    Q_OBJECT

public:
    explicit CShowServerBlock(QWidget *parent = nullptr);
    void setNameAndIP(QString);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    QString m_ServerName;
    QString m_ServerIP;

    QImage *deleteIcon;
    QImage *editIcon;

    QLabel *deleteLabel;
    QLabel *editLabel;

    ~CShowServerBlock();

signals:

public slots:
    void on_deleteLabel_click(QMouseEvent *);
};

#endif // CSHOWSERVERBLOCK_H
