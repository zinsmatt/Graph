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
    QString label;
    QPoint posLabel;

public:
    Node2D(const QString &label_, float x, float y, float radius_, float border_, const QString &fillColor_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    float getRadius() const {return radius;}
};

#endif // NODE2D_H
