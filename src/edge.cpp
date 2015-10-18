#include "edge.h"

Edge::Edge(Node* n1, Node *n2, bool orient, const QString color):
    oriented(orient), Element(), edge2d(new Edge2D(n1,n2, color))
{
    nodes[0] = n1;
    nodes[1] = n2;

    // n1 and n2 should not be NULL
    nodes[0]->addAdjacentEdge(this);
    nodes[1]->addAdjacentEdge(this);

}

Edge::~Edge()
{

}

