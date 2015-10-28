#include "edge.h"

Edge::Edge(Node* n1, Node *n2, bool orient):
    oriented(orient), Element(), edge2d(new Edge2D(&n1->getNode2D(), &n2->getNode2D(), orient))
{
    nodes[0] = n1;
    nodes[1] = n2;

    // n1 and n2 should not be NULL
    nodes[0]->addAdjacentEdge(this);
    nodes[1]->addAdjacentEdge(this);

}

Edge::~Edge()
{
    delete edge2d;
}

Edge::Edge()
{

}
