#include "edge.h"

Edge::Edge(Node* n1, Node *n2, bool oriented):
    isOriented(oriented)
{
    nodes[0] = n1;
    nodes[1] = n2;
}

Edge::~Edge()
{

}

