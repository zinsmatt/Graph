#ifndef NODE2D_H
#define NODE2D_H
#include <QGraphicsItem>
#include <QPainter>

class Node2D : public QGraphicsItem
{
private:
    QColor fillColor;
    float radius;
    float border;
public:
    Node2D(float x, float y, float radius_, float border_, const QString &fillColor_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // NODE2D_H
