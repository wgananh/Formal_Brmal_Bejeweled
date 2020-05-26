#ifndef MYQPIXMAP_H
#define MYQPIXMAP_H

#include <QObject>
#include <QPixmap>
#include <QMouseEvent>

class MyQPixmap : public QPixmap
{
    Q_OBJECT
public:
    explicit MyQPixmap();

protected:
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);

public:
    int column;// 图片可以知道自己的行列
    int row;//图片位置发生变化时要修改这两个值
};

#endif // MYQPIXMAP_H
