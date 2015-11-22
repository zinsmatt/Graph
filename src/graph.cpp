#include "graph.h"
#include "node2d.h"
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
    };
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
    if(!node)
        return false;
    if(this->isIn(node))
        return false;   //node already in the graph
    nodes.push_back(node);

    for(GraphContainer* contIt: containers)
    {
        try{
            contIt->addNode(node);
        }catch(LogException& exp){
            std::cout << "Impossible to add node in the container : " << exp.what() << std::endl;
        }
    }
    return true;
}

bool Graph::removeNode(Node *node)
{
    if(!node)
        return false;
    std::vector<Node*>::iterator pos = std::find(nodes.begin(),nodes.end(),node);
    if(pos == nodes.end())
    {
        std::cout << "Impossible to remove : node is not in the graph" << std::endl;
        return false; //node was not in the list of nodes
    }

    const std::vector<Edge*>& adjacentEdges = node->getAdjacentEdges();
    while(adjacentEdges.size()>0)               //remove the adjacent edges first
        this->removeEdge(adjacentEdges[0]);     //warning removeEdge remove the edge from adjacentEdges

    nodes.erase(pos);

    for(GraphContainer* contIt: containers)
    {
        try{
            contIt->removeNode(node);
        }catch(LogException& exp){
            std::cout << "Impossible to remove form a container :" << exp.what() << std::endl;
        }
    }
    return true;
}

bool Graph::addEdge(Edge *edge)
{
    if(!edge)
        return false;
    if(this->isIn(edge))
        return false;   // edge already in the graph

    edges.push_back(edge);

    for(GraphContainer* contIt: containers)
    {
        try{
            contIt->addEdge(edge);
        }catch(LogException& exp){
            std::cout << "Impossible to add edge in the container : " << exp.what() << std::endl;
        }
    }

    return true;
}

bool Graph::removeEdge(Edge *edge)
{
    if(!edge || !edge->getNode1() || ! edge->getNode2())
        return false;

    std::vector<Edge*>::iterator pos = std::find(edges.begin(),edges.end(),edge);
    if(pos == edges.end())
    {
        std::cout << "Impossible to remove : edge is not in the graph" << std::endl;
        return false; //edge was not in the list of edges
    }

    Node* extremity1 = edge->getNode1();
    Node* extremity2 = edge->getNode2();

    if(!this->isIn(extremity1) || !this->isIn(extremity2))
    {
        std::cout << "Impossible to remove : an extremity is not in the graph" << std::endl;
        return false; //an edge extremity was not in the graph
    }

    edges.erase(pos);
    edge->getNode1()->removeAdjacentEdge(edge);     //remove edge from adjacent edges
    edge->getNode2()->removeAdjacentEdge(edge);     //remove edge from adjacent edges

    for(GraphContainer* contIt: containers)
    {
        try{
            contIt->removeEdge(edge);
        }catch(LogException& exp){
            std::cout << "Impossible to remove edge from a container : " << exp.what() << std::endl;
        }
    }

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

    if(containers.size()>0)
        ss << containers[0]->toString().toStdString();
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
