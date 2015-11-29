#include "edge.h"


Edge::Edge(ElementId id) : Element(id), oriented(true), nodes{nullptr,nullptr}
{

}


/*Edge::Edge(unsigned int id, Node* n1, Node *n2, bool orient): Element(id), nodes{n1, n2}, oriented(orient)
{
    // n1 and n2 should not be null
    if(nodes[0])
        nodes[0]->addAdjacentEdge(this);
    if(nodes[1])
        nodes[1]->addAdjacentEdge(this);
}*/

Edge::~Edge()
{

}

