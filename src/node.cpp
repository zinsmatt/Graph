#include "node.h"
#include <iostream>
#include <QPainter>

Node::Node(float x, float y, const QString& printId, unsigned int numero, unsigned int radius, const QString& color)
    : Element(), QGraphicsEllipseItem(25,25,25,25), brush(QBrush(Qt::red))
{
    Element::addStringAttribute("printId", printId);
    Element::addIntAttribute("numero", numero);
    Element::addFloatAttribute("radius",radius);
    Element::addFloatAttribute("border",2);
    Element::addStringAttribute("color", color);
    Element::addFloatAttribute("x",x);
    Element::addFloatAttribute("y",y);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsMovable);
    //QGraphicsEllipseItem::setBrush(brush);
}

Node::Node(const Node& n) : Element(), QGraphicsEllipseItem(25,25,25,25)
{
    setIntAttributes(n.getIntAttributes());
    setStringAttributes(n.getStringAttributes());
    setFloatAttributes(n.getFloatAttributes());
    setId(n.getId());
    brush = n.getBrush();
}

void Node::printPosition(){
    std::cout << getX() << std::endl;
    std::cout << getY() << std::endl;
//    std::cout << item->x() << std::endl;
//    std::cout << item->y() << std::endl;

}
