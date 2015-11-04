#include "graph.h"
#include "node2d.h"
#include "exception.h"
#include <iostream>
Graph::Graph(GraphContainer *gc) : container(gc)
{
    if(container == NULL)  //by default -> use an adjacency matrix
    {
        container = new AdjacencyMatrix;
    }
}

Graph::~Graph()
{
    delete container;
}





void Graph::draw(QGraphicsScene& scene)
{
    for(unsigned int i = 0; i < nodes.size(); ++i)
    {
        scene.addItem(&nodes[i]->getNode2D());
    }
    for(unsigned int i = 0; i < edges.size(); ++i)
    {
        scene.addItem(&edges[i]->getEdge2D());
    }
}


//--------------------------------------------------------------



bool Graph::addNode(Node *node)
{
    try
    {
        container->addNode(node);
    }catch(LogException& exp)
    {
        std::cout << exp.what() << std::endl;
        return false;
    }
    nodes.push_back(node);
    return true;
}

bool Graph::removeNode(Node *node)
{
    if(!node)
        return false;
    const std::vector<Edge*>& adjacentEdges = node->getAdjacentEdges();
    while(adjacentEdges.size()>0)               //remove the adjacent edges first
        this->removeEdge(adjacentEdges[0]);     //warning removeEdge remove the edge from adjacentEdges
    try
    {
        container->removeNode(node);
    }catch(LogException& exp)
    {
        std::cout << exp.what() << std::endl;
        return false;
    }

    std::vector<Node*>::iterator pos = std::find(nodes.begin(),nodes.end(),node);
    nodes.erase(pos);
    //delete node;
    return true;
}

bool Graph::addEdge(Edge *edge)
{
    try
    {
        container->addEdge(edge);
    }catch(LogException& exp)
    {
        std::cout << exp.what() << std::endl;
        return false;
    }
    edges.push_back(edge);
    return true;
}

bool Graph::removeEdge(Edge *edge)
{
    std::vector<Edge*>::iterator pos = std::find(edges.begin(),edges.end(),edge);
    if(pos == edges.end())
    {
        std::cout << "edge is not in the graph" << std::endl;
        return false; //edge was not in the list of edges
    }

    try
    {
        container->removeEdge(edge);
    }catch(LogException& exp)
    {
        std::cout << exp.what() << std::endl;
        return false;
    }

    edges.erase(pos);
    edge->getNode1()->removeAdjacentEdge(edge);     //remove edge from adjacent edges
    edge->getNode2()->removeAdjacentEdge(edge);     //remove edge from adjacent edges
    delete edge;
    return true;
}

QString Graph::toString() const
{
    std::stringstream ss;
    // rajouter affichage des attributs du graphe
    ss << "Nodes : ";
    for(unsigned int iter = 0;iter <nodes.size();iter++)
        ss << nodes[iter]->getId() << " ";
    ss << "\nEdges : ";
    for(unsigned int iter = 0;iter <edges.size();iter++)
        ss << edges[iter]->getId() << " ";
    ss << "\n";

    if(container)
        ss << container->toString().toStdString();
    else
        ss << "vide";
    return ss.str().c_str();
}
std::ostream& operator<<(std::ostream& os, Graph& g)
{
    os << "====== Graph =====\n\n";
    os << g.toString().toStdString() << std::endl;
    return os;
}
