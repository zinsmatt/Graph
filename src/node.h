#ifndef NODE_H
#define NODE_H
#include <vector>
#include "element.h"

class Edge;
class Node2D;

class Node : public Element
{
private:
    Node2D* node2d;
    std::vector<Edge*> adjacentEdges;       //!< vector of pointers to the adjacent edges
    std::vector<Edge*> adjacentInEdges;     //!< vector of pointers to only incident edges
    std::vector<Edge*> adjacentOutEdges;    //!< vector of pointers to only out edges


public:
    Node();

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

    const std::vector<Edge*>& getAdjacentOutEdges() const { return adjacentOutEdges; }
    const std::vector<Edge*>& getAdjacentInEdges() const { return adjacentInEdges; }

    void setProperties(float x, float y, const QString& color, const QString& clicColor, float radius);
    Node2D& getNode2D() {return *node2d;}

};

#endif // NODE_H
