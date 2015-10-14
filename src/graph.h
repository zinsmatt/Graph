#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QPen>
#include "edge.h"
#include "graphcontainer.h"
#include "adjacencymatrix.h"


class Graph
{
private:
    std::vector<Node> nodes;
    std::vector<Edge> edges;

    GraphContainer* container;

public:


    /* \brief Constructor
     * \param a graph container
     * */
    Graph(GraphContainer *gc = NULL);


    /* \brief Destructor
     * */
    ~Graph();


    void addNode(const Node& n){
        nodes.push_back(n);
    }
    void addEdge(const Edge& e){
        edges.push_back(e);
    }

    void addNode(const QString &label, float x, float y, float radius, float border, const QString &color);
    void addEdge(Node* n1, Node* n2, bool oriented, const QString &color);


    std::vector<Node>& getNodes(){return nodes;}

    unsigned int size() const {return nodes.size();}

    void draw(QGraphicsScene& scene);




    /* \brief Add a node to the graph
     * \param a pointer to the node
     * \return true if added, false if not added
     * */
    bool addNode(Node *node){
        return container->addNode(node);
    }

    /* \brief Remove a node from the graph
     * \param a pointer to the node to remove
     * \return true if removed, false if does not exist
     * */
    bool removeNode(Node *node){
        return container->removeNode(node);
    }

    /* \brief Add an edge to the graph
     * \param a pointer to the edge
     * \return true if added, else false
     * */
    bool addEdge(Edge *edge){
        return container->addEdge(edge);
    }

    /* \brief Remove an edge from the graph
     * \param a pointer to the edge to remove
     * \return true if removed, false if does not exist
     * */
    bool removeEdge(Edge *edge){
        return container->removeEdge(edge);
    }

    /* \brief Get an edge from the graph
     * \param two pointers to the nodes
     * \return a pointeur to the edge if it exists, else NULL
     * */
    Edge* getEdge(Node* n1, Node *n2){
        return container->getEdge(n1,n2);
    }

    /* \brief Get the container
     * \return a const pointer on the container
     * */
    const GraphContainer* getContainer() const{
        return container;
    }


};

std::ostream& operator<<(std::ostream& os, Graph& g);

#endif // GRAPH_H
