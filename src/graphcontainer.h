#ifndef GRAPHCONTAINER_H
#define GRAPHCONTAINER_H
#include <sstream>
#include <QString>
class Node;
class Edge;

class GraphContainer
{
public:
    GraphContainer();
    virtual ~GraphContainer();


    /* \brief Add a node to the container
     * \param a pointer to the node
     * \return true if added, false if not added
     * */
    virtual bool addNode(Node* node) = 0;

    /* \brief Remove a node from the container
     * \param a pointer to the node to remove
     * \return true if removed, false if does not exist
     * */
    virtual bool removeNode(Node* node) = 0;

    /* \brief Add an edge to the container
     * \param a pointer to the edge
     * \return true if added, else false
     * */
    virtual bool addEdge(Edge *edge) = 0;

    /* \brief Remove an edge from the container
     * \param a pointer to the edge to remove
     * \return true if removed, false if does not exist
     * */
    virtual bool removeEdge(Edge *edge) = 0;

    /* \brief Get an edge
     * \param two pointers to the nodes
     * \return a pointeur to the edge if it exists, else NULL
     * */
    virtual Edge* getEdge(Node* n1, Node *n2) = 0;

    /* \brief Get a string that describes the object
     * \return an QString containing the description
     * */
    virtual QString toString() const = 0;
};

#endif // GRAPHCONTAINER_H
