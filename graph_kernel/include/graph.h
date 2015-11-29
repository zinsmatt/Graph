#ifndef GRAPH_H
#define GRAPH_H
#include <vector>


#include "edge.h"
#include "graphcontainer.h"
#include "adjacencymatrix.h"


class Graph
{
private:

    std::map<ElementId, Node*> idToNode;
    std::map<ElementId, Edge*> idToEdge;

    std::vector<GraphContainer*> containers;

    bool orientation;

    /* \brief Get a non const pointer on a node
     * \param node id
     * \return pointer on the node or nullptr
     * */
    Node* getNode(ElementId id);

    /* \brief Get a non const pointer on an edge
     * \param edge id
     * \return pointer on the edge or nullptr
     * */
    Edge* getEdge(ElementId id);


public:


    /* \brief Constructor
     * \param a graph container and a boolean for orientation
     * */
    Graph(bool _orientation, GraphContainer *gc = nullptr);


    /* \brief Destructor
     * */
    ~Graph();

    // should be replaced
    unsigned int size() const {return idToNode.size();}

    /* \brief Tell if graph is oriented or not
     * \return boolean
     * */
    bool isOriented() const { return orientation; }

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
     * \param a pointer to the edge, extremity nodes pointer and a boolean for orientation
     * \return true if added, false otherwise
     * */
    bool addEdge(Edge *edge, Node *n1, Node *n2);

    /* \brief Add an edge to the graph
     * \param a pointer to the edge, extremity nodes id and a boolean for orientation
     * \return true if added, false otherwise
     * */
    bool addEdge(Edge *edge, ElementId idN1, ElementId idN2);

    /* \brief Remove an edge from the graph
     * \param a pointer to the edge to remove
     * \return true if removed, false if does not exist
     * */
    bool removeEdge(Edge *edge);

    /* \brief Get a const pointer on a node
     * \param node id
     * \return const pointer on the node or nullptr
     * */
    const Node* getNode(ElementId id) const;

    /* \brief Get a const pointer on an edge
     * \param edge id
     * \return const pointer on the edge or nullptr
     * */
    const Edge* getEdge(ElementId id) const;

    /* \brief Get all nodes
     * \return a reference on the map of node
     * */
    const std::map<ElementId, Node*>& getNodes() { return idToNode; }

    /* \brief Get all edges
     * \return a reference on the map of edges
     * */
    const std::map<ElementId, Edge*>& getEdges() { return idToEdge; }

    /* \brief Get a string description
     * \return std::string describing the graph
     * */
    std::string toString() const;

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


    /* \brief Transform the graph into an oriented graph
     * \return true if done, false if not possible
     * */
    bool transformIntoOriented();

    /* \brief Transform the graph into a non oriented graph
     * \return true if done, false if impossible
     * */
    bool transformIntoNonOriented();


};

std::ostream& operator<<(std::ostream& os, Graph& g);

#endif // GRAPH_H
