#ifndef NODE2D_H
#define NODE2D_H
#include <QGraphicsItem>
#include <QList>


class Edge2d;
QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

class Node2d : public QGraphicsItem
{
private:
    QList<Edge2d*> edgeList;
    float radius;
    QString color;
    QString clicColor;
    QString id;

public:
    Node2d(const QString _id, int _size, QString _color, float _x, float _y);
    void addEdge(Edge2d *edge);

    QList<Edge2d *> edges() const;

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const
    QStyleOptionGraphicsItem *option, QWidget *widget);

    float getRadius() const {return radius;}
    void setRadius(float r){radius = r;}

    const QString& getColor(){return color;}
    void setColor(const QString& c){color = c;}

    const QString& getClicColor(){return clicColor;}
    void setClicColor(const QString& c){clicColor = c;}


protected:
    QVariant itemChange(GraphicsItemChange change, const    QVariant &value);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // NODE2d_H
