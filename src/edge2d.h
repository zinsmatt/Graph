#ifndef EDGE2D_H
#define EDGE2D_H
#include <QGraphicsItem>
#include <QPainter>

class Node;

class Edge2D : public QGraphicsItem
{
private:
    Node* origin;
    Node* destination;
    QColor color;

public:
    Edge2D(Node* origin_, Node* destination_, const QString color_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // EDGE2D_H
