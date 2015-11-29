#include "graph.h"
#include "exception.h"
#include "elementmanager.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

Graph::Graph(bool _orientation, GraphContainer *gc) : orientation(_orientation)
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

bool Graph::addEdge(Edge *edge, Node *n1, Node *n2)
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
    edge->setOriented(orientation);

    n1->addAdjacentEdge(edge);
    n2->addAdjacentEdge(edge);

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

bool Graph::addEdge(Edge *edge, ElementId idN1, ElementId idN2)
{
    Node *n1 = this->getNode(idN1);
    Node *n2 = this->getNode(idN2);

    return this->addEdge(edge,n1,n2);
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

const Node* Graph::getNode(ElementId id) const
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

const Edge* Graph::getEdge(ElementId id) const
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

Node* Graph::getNode(ElementId id)
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

Edge* Graph::getEdge(ElementId id)
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

bool Graph::transformIntoOriented()
{
    if(orientation == true)
    {
        std::cerr << "Warning : graph already oriented" << std::endl;
        return false;
    }
    ElementManager* manager = ElementManager::getInstance();
    this->orientation = true;

    // extract current edges
    std::vector<Edge*> currentEdge;
    for(auto edgeIt : idToEdge)
        currentEdge.push_back(edgeIt.second);

    for(Edge* edgeIt : currentEdge)
    {
        Edge *old = edgeIt;
        Node *n1 = old->getNode1();
        Node *n2 = old->getNode2();

        this->removeEdge(old);

        Edge* nouvInverse = manager->getCopyOf(old);
        this->addEdge(old,n1,n2);
        this->addEdge(nouvInverse,n2,n1);
    }
    return true;
}

bool Graph::transformIntoNonOriented()
{
    if(!orientation)
    {
        std::cerr << "Warning : graph already non oriented" << std::endl;
        return false;
    }

    // extract current edges
    std::vector<Edge*> currentEdge;
    for(auto edgeIt : idToEdge)
        currentEdge.push_back(edgeIt.second);

    // edge that were mrege into one non oriented
    std::set<Edge*> alreadyDeleted;
    ElementManager* manager = ElementManager::getInstance();
    this->orientation = false;

    for(int edgeIt = 0; edgeIt<currentEdge.size(); edgeIt++)
    {
        Edge *edge = currentEdge[edgeIt];

        if(alreadyDeleted.find(edge) != alreadyDeleted.end())
            continue;

        Edge *inverse = nullptr;
        for(int edgeIt2 = edgeIt; edgeIt2 < currentEdge.size(); edgeIt2++)
        {
            if(edge->getNode1() == currentEdge[edgeIt2]->getNode2() &&
                    edge->getNode2() == currentEdge[edgeIt2]->getNode1())
            {
                inverse = currentEdge[edgeIt2];
            }
        }

        if(inverse)
        {
            Node *n1 = edge->getNode1();
            Node *n2 = edge->getNode2();
            this->removeEdge(edge);
            this->removeEdge(inverse);

            this->addEdge(edge,n1,n2);

            alreadyDeleted.insert(inverse);
            edge->mergeAttributes(inverse);

        }else
        {
            // if no inverse edge is removed
            this->removeEdge(edge);
        }
    }
    return false;
}

