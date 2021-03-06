#include "shortestpathalgorithm.h"
#include "edge.h"
#include <algorithm>

ShortestPathAlgorithm::ShortestPathAlgorithm(Graph *graph, Node *start, const std::string &key)
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

    std::vector<Node*> nodes;
    const std::map<ElementId, Node*>& nodesMap = graph->getNodes();
    for(auto nodeIt: nodesMap)
        nodes.push_back(nodeIt.second);

    if(std::find(nodes.begin(),nodes.end(),startingNode) == nodes.end())
        return false;       //starting node does not belong to the graph

    std::vector<Edge*> edges;
    const std::map<ElementId, Edge*>& edgesMap = graph->getEdges();
    for(auto edgeIt: edgesMap)
        edges.push_back(edgeIt.second);

    for(int iter=0 ; iter<edges.size(); iter++)
    {
        if(!edges[iter]->hasFloatAttribute(attribute))      //sortestPath algorithm require a float attribute for each node
            return false;       //an edge canot be compared
    }
    return true;
}
