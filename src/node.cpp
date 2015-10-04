#include "node.h"


Node::Node(const QString &label_, float x, float y, float radius, float border, const QString color) : Element(),
    node2d(new Node2D(label_, x, y, radius, border, color))
{


}


