#include "node.h"


Node::Node(float x, float y, float radius, float border, const QString color) : Element(),
    node2d(new Node2D(x, y, radius, border, color))
{


}
