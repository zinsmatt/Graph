#include "edge2d.h"
#include "node.h"
Edge2D::Edge2D(Node *origin_, Node *destination_, const QString color_) : origin(origin_), destination(destination_),
    color(QColor(color_))
{

}

QRectF Edge2D::boundingRect() const
{
    return QRectF();
}



void Edge2D::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QLine line(QPoint(origin->getNode2D().x()+origin->getNode2D().getRadius(),
                      origin->getNode2D().y() + origin->getNode2D().getRadius()),
               QPoint(destination->getNode2D().x() + destination->getNode2D().getRadius(),
                      destination->getNode2D().y() + destination->getNode2D().getRadius()));
    QPen pen(color, 3);
    painter->setPen(pen);
    painter->drawLine(line);
}

