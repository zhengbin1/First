#ifndef REFRESHBUTTON_H
#define REFRESHBUTTON_H

#include <QWidget>
#include <QPainter>

class RefreshButton : public QWidget
{
    Q_OBJECT
public:
    explicit RefreshButton(QWidget *parent = nullptr);
    ~RefreshButton();

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    QImage *refreshIcon;

signals:
    void refresh();
public slots:
};

#endif // REFRESHBUTTON_H
