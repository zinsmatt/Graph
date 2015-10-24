#include "node.h"


Node::Node(const QString &label_, float x, float y, float radius, float border, const QString color) : Element()
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
