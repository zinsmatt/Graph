#include "node.h"
#include <iostream>

Node::Node(float x, float y, const QString& printId, unsigned int numero, unsigned int radius, const QString& color)
    : Element(), pen(QPen(QColor(Qt::black))), brush(QBrush(QColor(color)))
{
    Element::addStringAttribute("printId", printId);
    Element::addIntAttribute("numero", numero);
    Element::addFloatAttribute("radius",radius);
    Element::addFloatAttribute("border",2);
    Element::addStringAttribute("color", color);
    Element::addFloatAttribute("x",x);
    Element::addFloatAttribute("y",y);
}

Node::Node(const Node& n) : Element()
{
    setIntAttributes(n.getIntAttributes());
    setStringAttributes(n.getStringAttributes());
    setFloatAttributes(n.getFloatAttributes());
    setId(n.getId());
    pen = n.getPen();
    brush = n.getBrush();
}
