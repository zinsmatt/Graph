#include "node.h"
#include "node2d.h"

Node::Node() : node2d(new Node2D())
{


}


bool Node::addAdjacentEdge(Edge *edge)
{
    for(std::vector<Edge*>::iterator it = adjacentEdges.begin(); it != adjacentEdges.end(); ++it)
        if(*it == edge)
            return false; //already stored
    adjacentEdges.push_back(edge);
    return true;
}

bool Node::removeAdjacentEdge(Edge *edge)
{
    auto pos = std::find(adjacentEdges.begin(),adjacentEdges.end(),edge);
    if(pos == adjacentEdges.end())
        return false; //edge was not adjacent to this node
    adjacentEdges.erase(pos);
    return true;
}

void Node::setProperties(float x, float y, const QString &color, const QString &clicColor, float radius)
{
    node2d->setColor(color);
    node2d->setRadius(radius);
    node2d->setClicColor(clicColor);
}
