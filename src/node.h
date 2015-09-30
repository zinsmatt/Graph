#ifndef NODE_H
#define NODE_H
#include "element.h"
#include <QColor>
#include <QGraphicsEllipseItem>

class Node : public Element, public QGraphicsEllipseItem
{
private:


public:
    Node(float x, float y, const QString& printId, unsigned int numero, unsigned int radius, const QString& color);

    Node(){}
    Node(const Node& n);

};

#endif // NODE_H
