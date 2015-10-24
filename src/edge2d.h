#ifndef EDGE2D_H
#define EDGE2D_H
#include <QGraphicsItem>


class Node2D;

class Edge2D : public QGraphicsItem
{
private:
    Node2D* source;
    Node2D* dest;
    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;

public:
    Edge2D(Node2D *sourceNode, Node2D *destNode);

    Node2D* sourceNode() const;
    Node2D* destNode() const;

    void adjust();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const
    QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // EDGE2D_H
