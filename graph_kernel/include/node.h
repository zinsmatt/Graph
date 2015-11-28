#ifndef NODE_H
#define NODE_H
#include <vector>
#include "element.h"

class Edge;

class Node : public Element
{
private:
    std::vector<Edge*> adjacentEdges;       //!< vector of pointers to the adjacent edges
    std::vector<Edge*> adjacentInEdges;     //!< vector of pointers to only incident edges
    std::vector<Edge*> adjacentOutEdges;    //!< vector of pointers to only out edges

    /* \brief Default constructor
     * \param Node id
     * */
    Node(unsigned int id);

public:

    friend class ElementManager;


    /* \brief add an adjacent edge and put it in adjacent in/out edges if required
     * \param a pointer to the edge
     * \return true if added, false if already stored
     * */
    bool addAdjacentEdge(Edge* edge);

    /* \brief remove an adjacent edge and remove it from adjacent in/out edges if required
     * \param a pointer to the edge
     * \return true if removed, false else
     * */
    bool removeAdjacentEdge(Edge* edge);

    /* \brief get the adjacent edges liste
     * \return a const reference to the vector
     * */
    const std::vector<Edge *>& getAdjacentEdges() const { return adjacentEdges; }

    /* \brief get out edges
     * \return a const reference on a vector
     * */
    const std::vector<Edge*>& getAdjacentOutEdges() const { return adjacentOutEdges; }

    /* \brief get in edges
     * \return a const reference on a vector
     * */
    const std::vector<Edge*>& getAdjacentInEdges() const { return adjacentInEdges; }

    /* \brief get direct successors in O(nbSuccessors)
     * \param a reference on a vector to fill with nodes
     * \return number of successors
     * */
    int getDirectSuccessors(std::vector<Node *> &successors) const;

    /* \brief get direct predecessors in O(nbPredecessors)
     * \param a reference on a vector to fill with nodes
     * \return number of predecessors
     * */
    int getDirectPredecessors(std::vector<Node*>& predecessors) const;

    /* \brief get all the descendant nodes
     * \param a reference on a vector to fill wih nodes
     * \return number of descendant
     * */
    int getSuccessors(std::vector<Node*>& successors) const;

    /* \brief get all th ancestor nodes
     * \param a reference on a vector to fill
     * \return number of ancestor
     * */
    int getPredecessors(std::vector<Node*>& predecessors) const;

};

#endif // NODE_H
