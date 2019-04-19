#ifndef CDELETELABEL_H
#define CDELETELABEL_H

#include <QWidget>
#include <QPainter>

class CDeleteLabel : public QWidget
{
    Q_OBJECT
public:
    explicit CDeleteLabel(QWidget *parent = nullptr);
    ~CDeleteLabel();

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

    void setIDandServerInfo(int id, QString ServerInfo);

signals:
    void deleteblock(int, QString);

public slots:

private:
    QImage *deleteIcon;

    int BlockID;
    QString m_ServerInfo;
};

#endif // CDELETELABEL_H
