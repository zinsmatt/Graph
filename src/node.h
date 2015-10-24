#ifndef NODE_H
#define NODE_H
#include <vector>
#include "element.h"
#include "node2d.h"

class Edge;

class Node : public Element
{
private:
    Node2D* node2d;
    std::vector<Edge*> adjacentEdges;


public:
    Node(const QString& label_, float x, float y, float radius, float border, const QString color);
    Node(){}

    /* \brief add an adjacent edge
     * \param a pointer to the edge
     * \return true if added, false if already stored
     * */
    bool addAdjacentEdge(Edge* edge);

    /* \brief remove an adjacent edge
     * \param a pointer to the edge
     * \return true if removed, false else
     * */
    bool removeAdjacentEdge(Edge* edge);

    /* \brief get the adjacent edges liste
     * \return a const reference to the vector
     * */
    const std::vector<Edge *> &getAdjacentEdges() const { return adjacentEdges; }

    Node2D& getNode2D() {return *node2d;}

};

#endif // NODE_H
