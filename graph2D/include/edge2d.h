#ifndef EDGE2D_H
#define EDGE2D_H
#include <QGraphicsItem>


class Node2d;

class Edge2d : public QGraphicsItem
{
private:
    Node2d* source;
    Node2d* dest;
    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
    bool oriented;

public:
    Edge2d(Node2d *sourceNode, Node2d *destNode, bool orient);

    Node2d* sourceNode() const;
    Node2d* destNode() const;

    void adjust();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const
    QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // EDGE2D_H
