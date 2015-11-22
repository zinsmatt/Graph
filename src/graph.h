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

    std::map<unsigned int, Node*> idToNode;
    std::map<unsigned int, Edge*> idToEdge;

    std::vector<GraphContainer*> containers;

public:


    /* \brief Constructor
     * \param a graph container
     * */
    Graph(GraphContainer *gc = nullptr);


    /* \brief Destructor
     * */
    ~Graph();


    unsigned int size() const {return idToNode.size();}

    void draw(QGraphicsScene& scene);




    /* \brief Add a node to the graph
     * \param a pointer to the node
     * \return true if added, false if not added
     * */
    bool addNode(Node *node);

    /* \brief Remove a node from the graph
     * \param a pointer to the node to remove
     * \return true if removed, false if does not exist
     * */
    bool removeNode(Node *node);

    /* \brief Add an edge to the graph
     * \param a pointer to the edge
     * \return true if added, else false
     * */
    bool addEdge(Edge *edge);

    /* \brief Remove an edge from the graph
     * \param a pointer to the edge to remove
     * \return true if removed, false if does not exist
     * */
    bool removeEdge(Edge *edge);

    /* \brief Get an edge from the graph
     * \param two pointers to the nodes
     * \return a pointeur to the edge if it exists, else nullptr
     * */
    Edge* getEdge(Node* n1, Node *n2){
        //return container->getEdge(n1,n2);
    }

    /* \brief Get all nodes
     * \return a reference on the map of node
     * */
    std::map<unsigned int, Node*>& getNodes() { return idToNode; }

    /* \brief Get all edges
     * \return a reference on the map of edges
     * */
    const std::map<unsigned int, Edge*>& getEdges() { return idToEdge; }

    /* \brief Get a string description
     * \return QString describing the graph
     * */
    QString toString() const;

    /* \brief inline function that tells if a node is in the graph
     * \param a pointer to the node
     * \return boolean true if it is in, false otherwise
     * */
    bool isIn(Node *node) const;

    /* \brief inline function that tells if an edge is in the graph
     * \param a pointer to the edge
     * \return boolean true if it is in, false otherwise
     * */
    bool isIn(Edge *edge) const;

    // PAS UTILE POUR l INSTANT
    /* \brief Get the container
     * \return a const pointer on the container
     * */
  /*  const GraphContainer* getContainer() const{
        return container;
    }*/


};

std::ostream& operator<<(std::ostream& os, Graph& g);

#endif // GRAPH_H
