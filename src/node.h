#ifndef NODE_H
#define NODE_H
#include "element.h"
#include <QColor>
#include <QGraphicsEllipseItem>
#include <QPen>

class Node : public Element, public QGraphicsEllipseItem
{
private:
    //QGraphicsEllipseItem* item;
    QBrush brush;

public:
    Node(float x, float y, const QString& printId, unsigned int numero, unsigned int radius, const QString& color);

    Node(){}
    Node(const Node& n);
    float getX() const {return Element::getFloatAttribute("x");}
    float getY() const {return Element::getFloatAttribute("y");}
   // void setItem(QGraphicsEllipseItem* it){item = it;}
   // QGraphicsEllipseItem& getItem() {return *item;}

    void setBrush(QBrush& b){brush = b;}
    const QBrush& getBrush() const {return brush;}

    void printPosition();
};

#endif // NODE_H
