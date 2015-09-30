#include "node.h"

Node::Node(float x, float y, const QString& printId, unsigned int numero, unsigned int radius, const QString& color)
{
    Element::addStringAttribute("printId", printId);
    Element::addIntAttribute("numero", numero);
    Element::addFloatAttribute("radius",radius);
    Element::addFloatAttribute("border",2);
    Element::addStringAttribute("color", color);
    QGraphicsEllipseItem::setX(x);
    QGraphicsEllipseItem::setY(y);
    QGraphicsEllipseItem::setRect(x,y,25,25);

}

Node::Node(const Node& n) : Element(), QGraphicsEllipseItem()
{
    setIntAttributes(n.getIntAttributes());
    setStringAttributes(n.getStringAttributes());
    setFloatAttributes(n.getFloatAttributes());
    setId(n.getId());
}
