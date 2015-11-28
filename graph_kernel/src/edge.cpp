#include "edge.h"


Edge::Edge() : oriented(true), nodes{nullptr,nullptr}
{

}

Edge::Edge(Node* n1, Node *n2, bool orient):
    oriented(orient), Element()
{
    nodes[0] = n1;
    nodes[1] = n2;

    // n1 and n2 should not be null
    if(nodes[0])
        nodes[0]->addAdjacentEdge(this);
    if(nodes[1])
        nodes[1]->addAdjacentEdge(this);

}

Edge::~Edge()
{

}

