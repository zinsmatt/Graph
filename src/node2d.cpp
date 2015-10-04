#include "node2d.h"

Node2D::Node2D(float x, float y, float radius_, float border_, const QString& fillColor_) : radius(radius_),
    border(border_), fillColor(QColor(fillColor_))
{
    setPos(x, y);
    setFlag(QGraphicsItem::ItemIsMovable);
}



QRectF Node2D::boundingRect() const
{
    return QRectF(0,0,radius*2,radius*2);
}

void Node2D::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::red, border);
    painter->setPen(pen);
    painter->setBrush(QBrush(fillColor));
    painter->drawEllipse(rect);
}

