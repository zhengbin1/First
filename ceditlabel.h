#ifndef CEDITLABEL_H
#define CEDITLABEL_H

#include <QWidget>
#include <QPainter>

class CEditLabel : public QWidget
{
    Q_OBJECT
public:
    explicit CEditLabel(QWidget *parent = nullptr);
    ~CEditLabel();

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

signals:

public slots:

private:
    QImage *editIcon;
};

#endif // CEDITLABEL_H
