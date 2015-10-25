#include <QPainter>

#include "edge2d.h"
#include "node2d.h"

#include <math.h>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

Edge2D::Edge2D(Node2D *sourceNode, Node2D *destNode, bool orient)
    : arrowSize(10), oriented(orient)
{
    setAcceptedMouseButtons(0);
    source = sourceNode;
    dest = destNode;

    source->addEdge(this);
    dest->addEdge(this);
    setZValue(-1);
    adjust();
}


Node2D *Edge2D::sourceNode() const
{
    return source;
}

Node2D *Edge2D::destNode() const
{
    return dest;
}


void Edge2D::adjust()
{
    if (!source || !dest)
        return;

    QLineF line(mapFromItem(source, sourceNode()->getRadius(), sourceNode()->getRadius()),
                mapFromItem(dest, destNode()->getRadius(), destNode()->getRadius()));
    //line centre source à centre dest
    qreal length = line.length();
    prepareGeometryChange();

    //cas ou les 2 nodes se chevauchent, on n'afficher pas l'edge
    if (length > qreal(sourceNode()->getRadius() + destNode()->getRadius())) {
      //  QPointF edgeOffsetSource((line.dx() * sqrt(2) * sourceNode()->getRadius()*2) / length, (line.dy() * 12) / length);
        //QPointF edgeOffsetDest((line.dx() * 25) / length, (line.dy() * 25) / length);
        sourcePoint = line.p1();// + edgeOffsetSource;
        destPoint = line.p2();// - edgeOffsetDest;
    } else {
        sourcePoint = destPoint = line.p1();
    }
}


QRectF Edge2D::boundingRect() const
{
    if (!source || !dest)
        return QRectF();

    qreal penWidth = 1;
    qreal extra = (penWidth + arrowSize) / 2.0;

    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}


void Edge2D::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (!source || !dest)
        return;

    QLineF line(sourcePoint, destPoint);
    if (qFuzzyCompare(line.length(), qreal(0.)))
        return;


    // Draw the line itself
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    painter->drawLine(line);



    if(oriented)
    {
        // Draw the arrows
        double angle = ::acos(line.dx() / line.length());
        if (line.dy() >= 0)
            angle = TwoPi - angle;

        QPointF destArrowP1 = destPoint + QPointF(sin(angle - Pi / 3) * arrowSize,
                                                  cos(angle - Pi / 3) * arrowSize);
        QPointF destArrowP2 = destPoint + QPointF(sin(angle - Pi + Pi / 3) * arrowSize,
                                                  cos(angle - Pi + Pi / 3) * arrowSize);
        painter->setBrush(Qt::black);
        painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);
    }
}

