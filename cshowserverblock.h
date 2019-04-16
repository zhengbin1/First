#ifndef CSHOWSERVERBLOCK_H
#define CSHOWSERVERBLOCK_H

#include <QWidget>

class CShowServerBlock : public QWidget
{
    Q_OBJECT
public:
    explicit CShowServerBlock(QWidget *parent = nullptr);
    void showEvent(QShowEvent *event);

signals:

public slots:
};

#endif // CSHOWSERVERBLOCK_H
