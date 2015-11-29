#include "edge.h"


Edge::Edge(ElementId id) : Element(id), oriented(true), nodes{nullptr,nullptr}
{

}


Edge& Edge::operator =(const Edge& edge)
{
   // nodes not copied because this may not be in a graph
   // this->nodes[0] = edge.nodes[0];
   // this->nodes[1] = edge.nodes[1];

    Element::operator =(edge);
    this->oriented = edge.oriented;
}

Edge::~Edge()
{

}

