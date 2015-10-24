#ifndef NODE2D_H
#define NODE2D_H
#include <QGraphicsItem>
#include <QList>


class Edge2D;
QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

class Node2D : public QGraphicsItem
{
private:
    QList<Edge2D*> edgeList;


public:
    Node2D();
    void addEdge(Edge2D *edge);

    QList<Edge2D *> edges() const;

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const
    QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    QVariant itemChange(GraphicsItemChange change, const    QVariant &value);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // NODE2D_H
