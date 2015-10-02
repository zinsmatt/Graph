#ifndef NODE_H
#define NODE_H
#include "element.h"
#include <QColor>
#include <QGraphicsEllipseItem>
#include <QPen>

class Node : public Element
{
private:
    QGraphicsEllipseItem* item;
    QPen pen;
    QBrush brush;

public:
    Node(float x, float y, const QString& printId, unsigned int numero, unsigned int radius, const QString& color);

    Node(){}
    Node(const Node& n);
    void setItem(QGraphicsEllipseItem* it){item = it;}
    float getX() const {return Element::getFloatAttribute("x");}
    float getY() const {return Element::getFloatAttribute("y");}
    QGraphicsEllipseItem& getItem() {return *item;}

    void setPen(QPen& p){pen = p;}
    void setBrush(QBrush& b){brush = b;}
    const QPen& getPen() const {return pen;}
    const QBrush& getBrush() const {return brush;}
};

#endif // NODE_H
