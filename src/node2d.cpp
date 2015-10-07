#include "node2d.h"
#include <iostream>
#include <QStyleOptionGraphicsItem>

Node2D::Node2D(const QString& label_, float x, float y, float radius_, float border_, const QString& fillColor_) :
    radius(radius_), border(border_), fillColor(QColor(fillColor_)), label(label_), posLabel(x+radius*.75,
                                                                                             y+radius*1.25)
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
    painter->setClipRect( option->exposedRect );

    QRectF rect = boundingRect();
    QPen pen(Qt::red, border);
    painter->setPen(pen);
    painter->setBrush(QBrush(fillColor));
    painter->drawEllipse(rect);
    QFont font("Arial", 25,10);
    painter->setFont(font);
    painter->drawText(posLabel,label);
}

void Node2D::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << x() << " " << y() << std::endl;
}

