#include "shortestpathalgorithm.h"
#include "edge.h"

ShortestPathAlgorithm::ShortestPathAlgorithm(Graph *graph, Node *start, const QString &key)
    : startingNode(start), attribute(key), Algorithm(graph)
{

}

ShortestPathAlgorithm::~ShortestPathAlgorithm()
{

}


bool ShortestPathAlgorithm::check() const
{
    if(!graph)
        return false;
    if(!startingNode)
        return false;

    std::vector<Node*>& nodes = graph->getNodes();
    if(std::find(nodes.begin(),nodes.end(),startingNode) == nodes.end())
        return false;       //starting node does not belong to the graph

    std::vector<Edge*>& edges = graph->getEdges();
    for(int iter=0 ; iter<edges.size(); iter++)
    {
        if(!edges[iter]->hasFloatAttribute(attribute))      //sortestPath algorithm require a float attribute for each node
            return false;       //an edge canot be compared
    }
    return true;
}
