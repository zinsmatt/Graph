#include <QStyleOptionGraphicsItem>
#include "edge2d.h"
#include "node.h"
#include <iostream>

Edge2D::Edge2D(Node *origin_, Node *destination_, const QString color_) : origin(origin_), destination(destination_),
    color(QColor(color_))
{

}

QRectF Edge2D::boundingRect() const
{
    std::cout << origin->getNode2D().x() << " " << origin->getNode2D().y() << std::endl;
    std::cout << destination->getNode2D().x() + destination->getNode2D().getRadius() * 2 << " " << destination->getNode2D().y() + destination->getNode2D().getRadius() * 2 << std::endl;
    return QRectF(QPoint(origin->getNode2D().x(), origin->getNode2D().y()),
                  QPoint(destination->getNode2D().x() + destination->getNode2D().getRadius() * 2,
                         destination->getNode2D().y() + destination->getNode2D().getRadius() * 2));
}



void Edge2D::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QLine line(QPoint(origin->getNode2D().x()+origin->getNode2D().getRadius(),
                      origin->getNode2D().y() + origin->getNode2D().getRadius()),
               QPoint(destination->getNode2D().x() + destination->getNode2D().getRadius(),
                      destination->getNode2D().y() + destination->getNode2D().getRadius()));
    // QRectF line = boundingRect();
//    QLine line(origin->getNode2D().x()+origin->getNode2D().getRadius(),
//               origin->getNode2D().y() + origin->getNode2D().getRadius(),25,25);
    QPen pen(color, 3);
    painter->setPen(pen);
    painter->drawLine(line);
}

