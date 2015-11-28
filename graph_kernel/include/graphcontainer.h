#ifndef GRAPHCONTAINER_H
#define GRAPHCONTAINER_H
#include <sstream>
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
    virtual void addNode(Node* node) = 0;

    /* \brief Remove a node from the container
     * \param a pointer to the node to remove
     * \return true if removed, false if does not exist
     * */
    virtual void removeNode(Node* node) = 0;

    /* \brief Add an edge to the container
     * \param a pointer to the edge
     * \return true if added, else false
     * */
    virtual void addEdge(Edge *edge) = 0;

    /* \brief Remove an edge from the container
     * \param a pointer to the edge to remove
     * \return true if removed, false if does not exist
     * */
    virtual void removeEdge(Edge *edge) = 0;

    /* \brief Get an edge
     * \param two pointers to the nodes
     * \return a pointeur to the edge if it exists, else nullptr
     * */
    virtual Edge* getEdge(Node* n1, Node *n2) = 0;

    /* \brief Get a string that describes the object
     * \return an std::string containing the description
     * */
    virtual std::string toString() const = 0;
};

#endif // GRAPHCONTAINER_H
