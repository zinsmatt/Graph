#include "node2d.h"
#include "edge2d.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <iostream>

Node2d::Node2d(const QString _id, int _size, const QString _color, float _x, float _y) :
    id(_id), color(_color), clicColor("#55aaff"), radius(_size)
{
    setX(_x);
    setX(_y);
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(0);
}



void Node2d::addEdge(Edge2d *edge)
{
    edgeList << edge;
    edge->adjust();
}


QRectF Node2d::boundingRect() const
{
    return QRectF(0 ,0 ,radius*2, radius*2);
}

QPainterPath Node2d::shape() const
{
    QPainterPath path;
    path.addEllipse(0,0, radius*2, radius*2);
    return path;
}

void Node2d::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    QRadialGradient gradient(-3, -3, 10);
    if (option->state & QStyle::State_Sunken) {
        gradient.setCenter(3, 3);
        gradient.setFocalPoint(3, 3);
        gradient.setColorAt(1, QColor(clicColor).light(120));
        gradient.setColorAt(0, QColor(clicColor).light(120));
    } else {
        gradient.setColorAt(0, QColor(color));
        gradient.setColorAt(1, QColor(color));
    }
    painter->setBrush(gradient);
    painter->setPen(QPen(Qt::white, 1));
    painter->drawEllipse(0 ,0 ,radius*2, radius*2);
    painter->setPen(QPen(Qt::black, 0));
    QRectF rec = boundingRect();
    painter->setFont(QFont("Arial", (rec.width() + rec.height()) / 4));
    painter->drawText(rec.x(), rec.y(), rec.width(), rec.height(),Qt::AlignCenter, id);

}


QVariant Node2d::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Edge2d *edge, edgeList)
            edge->adjust();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}


void Node2d::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Node2d::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
