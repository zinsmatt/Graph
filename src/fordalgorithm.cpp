#include "fordalgorithm.h"
#include <iostream>

FordAlgorithm::FordAlgorithm(Graph *graph, Node *start, const QString &key)
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

    const std::vector<Node*>& nodes = graph->getNodes();
    int nbNodes = nodes.size();
   /* int iter=0;
    for(;iter<nbNodes && nodes[iter]!=startingNode;iter++){}
    int startingIndex = iter;

    int* delta = new int[nbNodes];
    memset(delta,INFINITY,sizeof(int));
    delta[startingIndex] = 0;

    bool change = true;
    while(change)
    {
        change = false;
        for(int nodeIter=0; nodeIter<nbNodes; nodeIter++)
        {
            std::vector<Edges*>& outEdges = nodes[nodeIter]->getAdjacentOutEdges();
            for(int edgeIter=0; edgeIter<outEdges.size(); edgeIter++)
            {
                int index2 = outEdges[edgeIter]->getNode2()
                if(delta[])
            }

        }
    }*/

    for(int nodeIter=0; nodeIter<nbNodes; nodeIter++)
    {
        nodes[nodeIter]->addIntAttribute("delta",INFINITY);
    }
    startingNode->setIntAttribute("delta",0);
    bool change;
    do
    {
        change = false;
        for(int nodeIter=0; nodeIter<nbNodes; nodeIter++)
        {
            const std::vector<Edge*>& outEdges = nodes[nodeIter]->getAdjacentOutEdges();
            for(int edgeIter=0; edgeIter<outEdges.size(); edgeIter++)
            {
                int oldDelta = outEdges[edgeIter]->getNode2()->getIntAttribute("delta");
                int newDelta = nodes[nodeIter]->getIntAttribute("delta") + outEdges[edgeIter]->getIntAttribute(attribute);
                if(newDelta < oldDelta)
                {
                    outEdges[edgeIter]->getNode2()->setIntAttribute("delta",newDelta);
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
            std::cout << "cost to " << nodes[iter]->getId() << "\t=\t" << nodes[iter]->getIntAttribute("delta") << std::endl;
        }
    }
}
