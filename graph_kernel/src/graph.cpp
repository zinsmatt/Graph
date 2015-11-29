#include "graph.h"
#include "exception.h"
#include <iostream>

Graph::Graph(GraphContainer *gc)
{
    if(gc != nullptr)  //if a container is passed, it is added
    {
        containers.push_back(gc);
    }
}

Graph::~Graph()
{
    for(GraphContainer* it : containers)
    {
        delete it;
    }
}




//--------------------------------------------------------------



bool Graph::addNode(Node *node)
{
    if(!node)
        return false;
    if(this->isIn(node))
    {
        std::cerr << "Impossible to add node in the graph : node already in" << std::endl;
        return false;
    }
    idToNode[node->getId()] = node;

    for(GraphContainer* contIt: containers)
    {
        try{
            contIt->addNode(node);
        }catch(LogException& exp){
            std::cerr << "Impossible to add node in the container : " << exp.what() << std::endl;
        }
    }
    return true;
}

bool Graph::removeNode(Node *node)
{
    if(!node)
        return false;
    if(!this->isIn(node))
    {
        std::cerr << "Impossible to remove node from graph : node is not in the graph" << std::endl;
        return false;
    }
    const std::vector<Edge*>& adjacentEdges = node->getAdjacentEdges();
    while(adjacentEdges.size()>0)               //remove the adjacent edges first
        this->removeEdge(adjacentEdges[0]);     //warning removeEdge remove the edge from adjacentEdges

    idToNode.erase(node->getId());

    for(GraphContainer* contIt: containers)
    {
        try{
            contIt->removeNode(node);
        }catch(LogException& exp){
            std::cerr << "Impossible to remove form a container :" << exp.what() << std::endl;
        }
    }
    return true;
}

bool Graph::addEdge(Edge *edge, Node *n1, Node *n2, bool isOriented)
{
    if(!edge || !n1 || !n2)
        return false;
    if(this->isIn(edge))
    {
        std::cerr << "Impossible to add edge in the graph : edge already in" << std::endl;
        return false;
    }
    if(!this->isIn(n1) || !this->isIn(n2))
    {
        std::cerr << "Impossible to add edge in the graph : one extremity doesn't exist in the graph" << std::endl;
        return false;
    }

    edge->setNode1(n1);
    edge->setNode2(n2);
    edge->setOriented(isOriented);
    idToEdge[edge->getId()] = edge;

    for(GraphContainer* contIt: containers)
    {
        try{
            contIt->addEdge(edge);
        }catch(LogException& exp){
            std::cerr << "Impossible to add edge in the container : " << exp.what() << std::endl;
        }
    }
    return true;
}

bool Graph::addEdge(Edge *edge, unsigned int idN1, unsigned int idN2, bool isOriented)
{
    Node *n1 = this->getNode(idN1);
    Node *n2 = this->getNode(idN2);

    return this->addEdge(edge,n1,n2,isOriented);
}

bool Graph::removeEdge(Edge *edge)
{
    if(!edge || !edge->getNode1() || ! edge->getNode2())
        return false;

    if(!this->isIn(edge))
    {
        std::cerr << "Impossible to remove edge from graph : edge is not in the graph" << std::endl;
        return false;
    }

    idToEdge.erase(edge->getId());

    edge->getNode1()->removeAdjacentEdge(edge);     //remove edge from adjacent edges
    edge->getNode2()->removeAdjacentEdge(edge);     //remove edge from adjacent edges

    for(GraphContainer* contIt: containers)
    {
        try{
            contIt->removeEdge(edge);
        }catch(LogException& exp){
            std::cerr << "Impossible to remove edge from a container : " << exp.what() << std::endl;
        }
    }
    return true;
}

bool Graph::isIn(Node *node) const
{
    bool ret;
    if(!node) return false;
    try
    {
      ret = idToNode.at(node->getId()) == node;
    }catch(std::out_of_range& exp)
    {
        return false;
    }
    return ret;
}

bool Graph::isIn(Edge *edge) const
{
    bool ret;
    if(!edge) return false;
    try
    {
      ret = idToEdge.at(edge->getId()) == edge;
    }catch(std::out_of_range& exp)
    {
        return false;
    }
    return ret;
}

const Node* Graph::getNode(unsigned int id) const
{
    try
    {
        Node* temp = idToNode.at(id);
        return temp;
    }catch(...)
    {
        std::cerr << "Imposible to get node " << id << " : id unknow" << std::endl;
        return nullptr;
    }
}

const Edge* Graph::getEdge(unsigned int id) const
{
    try
    {
        Edge* temp = idToEdge.at(id);
        return temp;
    }catch(...)
    {
        std::cerr << "Imposible to get edeg " << id << " : id unknow" << std::endl;
        return nullptr;
    }
}

Node* Graph::getNode(unsigned int id)
{
    try
    {
        Node* temp = idToNode.at(id);
        return temp;
    }catch(...)
    {
        std::cerr << "Imposible to get node " << id << " : id unknow" << std::endl;
        return nullptr;
    }
}

Edge* Graph::getEdge(unsigned int id)
{
    try
    {
        Edge* temp = idToEdge.at(id);
        return temp;
    }catch(...)
    {
        std::cerr << "Imposible to get edeg " << id << " : id unknow" << std::endl;
        return nullptr;
    }
}

std::string Graph::toString() const
{
    std::stringstream ss;
    // rajouter affichage des attributs du graphe
    ss << "Nodes : ";
    for(auto nodeIt : idToNode) //unsigned int iter = 0;iter <nodes.size();iter++)
        ss << nodeIt.first << " ";
    ss << "\nEdges : ";
    for(auto edgeIt : idToEdge) //unsigned int iter = 0;iter <edges.size();iter++)
        ss << edgeIt.first << " ";
    ss << "\n";

    if(containers.size()>0)
        ss << containers[0]->toString();
    else
        ss << "vide";
    return ss.str().c_str();
}
std::ostream& operator<<(std::ostream& os, Graph& g)
{
    os << "====== Graph =====\n\n";
    os << g.toString() << std::endl;
    return os;
}
