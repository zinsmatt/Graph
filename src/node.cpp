#include "node.h"
#include "node2d.h"
#include "edge.h"

Node::Node() : node2d(new Node2D())
{


}


bool Node::addAdjacentEdge(Edge *edge)
{
    for(std::vector<Edge*>::iterator it = adjacentEdges.begin(); it != adjacentEdges.end(); ++it)
        if(*it == edge)
            return false; //already stored
    adjacentEdges.push_back(edge);
    if(edge->isOriented())
    {
        if(edge->getNode1() == this)
            adjacentOutEdges.push_back(edge);
        else if(edge->getNode2() == this)
            adjacentInEdges.push_back(edge);
    }
    return true;
}

bool Node::removeAdjacentEdge(Edge *edge)
{
    auto pos = std::find(adjacentEdges.begin(),adjacentEdges.end(),edge);
    if(pos == adjacentEdges.end())
        return false; //edge was not adjacent to this node
    adjacentEdges.erase(pos);
    if(edge->isOriented())
    {
        if(edge->getNode1() == this)
        {
            auto pos2 = std::find(adjacentOutEdges.begin(),adjacentOutEdges.end(),edge);
            if(pos2 != adjacentOutEdges.end())
                adjacentOutEdges.erase(pos2);
        }else if(edge->getNode2() == this)
        {
            auto pos2 = std::find(adjacentInEdges.begin(),adjacentInEdges.end(),edge);
            if(pos2 != adjacentInEdges.end())
                adjacentInEdges.erase(pos2);
        }
    }
    return true;
}

void Node::setProperties(float x, float y, const QString &color, const QString &clicColor, float radius)
{
    node2d->setColor(color);
    node2d->setRadius(radius);
    node2d->setClicColor(clicColor);
}
