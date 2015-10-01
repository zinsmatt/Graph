#include "node.h"

Node::Node(float x, float y, const QString& printId, unsigned int numero, unsigned int radius, const QString& color)
{
    Element::addStringAttribute("printId", printId);
    Element::addIntAttribute("numero", numero);
    Element::addFloatAttribute("radius",radius);
    Element::addFloatAttribute("border",2);
    Element::addStringAttribute("color", color);
    Element::addFloatAttribute("x",x);
    Element::addFloatAttribute("y",y);

    pen.setColor(Qt::red);
    brush.setColor(Qt::blue);
    pen.setWidth(10);
}

Node::Node(const Node& n) : Element()
{
    setIntAttributes(n.getIntAttributes());
    setStringAttributes(n.getStringAttributes());
    setFloatAttributes(n.getFloatAttributes());
    setId(n.getId());
}
