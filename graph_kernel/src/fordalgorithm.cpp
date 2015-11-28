#include "fordalgorithm.h"
#include <limits>
#include <iostream>
#include <algorithm>

FordAlgorithm::FordAlgorithm(Graph *graph, Node *start, const std::string &key)
    : ShortestPathAlgorithm(graph,start,key)
{

}

FordAlgorithm::~FordAlgorithm()
{

}



bool FordAlgorithm::check() const
{
    // ford can be applied on any graphs
    return this->ShortestPathAlgorithm::check();
}

void FordAlgorithm::run()
{
    if(!check())
        return;

    std::vector<Node*> nodes;
    const std::map<unsigned int, Node*>& nodesMap = graph->getNodes();
    for(auto nodeIt: nodesMap)
        nodes.push_back(nodeIt.second);
    //const std::vector<Node*>& nodes = graph->getNodes();
    int nbNodes = nodes.size();

    for(int nodeIter=0; nodeIter<nbNodes; nodeIter++)
    {
        nodes[nodeIter]->setFloatAttribute("delta",std::numeric_limits<float>::max());
    }
    startingNode->setFloatAttribute("delta",0);
    bool change;
    do
    {
        change = false;
        for(int nodeIter=0; nodeIter<nbNodes; nodeIter++)
        {
            const std::vector<Edge*>& outEdges = nodes[nodeIter]->getAdjacentOutEdges();
            for(int edgeIter=0; edgeIter<outEdges.size(); edgeIter++)
            {
                float oldDelta = outEdges[edgeIter]->getNode2()->getFloatAttribute("delta");
                float newDelta = nodes[nodeIter]->getFloatAttribute("delta") + outEdges[edgeIter]->getFloatAttribute(attribute);
                if(newDelta < oldDelta)
                {
                    outEdges[edgeIter]->getNode2()->setFloatAttribute("delta",newDelta);
                    change = true;
                }
            }
        }
    }while(change);

    std::cout << "===================== FORD RESULTS ======================\n\n";
    std::cout << "Starting Node : " << startingNode->getId() << std::endl;
    for(int iter=0;iter<nbNodes;iter++)
    {
        if(nodes[iter] != startingNode)
        {
            std::cout << "cost to " << nodes[iter]->getId() << "\t=\t" << nodes[iter]->getFloatAttribute("delta") << std::endl;
        }
    }
}
