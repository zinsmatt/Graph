#ifndef EDGE_H
#define EDGE_H
#include "node.h"

class Edge
{
    Node *nodes[2];     //!< nodes linked by the edge. If oriented allways from nodes[0] to nodes[1]
    bool oriented;
public:

    /* \brief Constructor
     * \param 2 nodes and a boolean for orientation
     * */
    Edge(Node* n1, Node *n2, bool oriented);

    /* \brief Destructor
     * */
    ~Edge();

    /* \brief Set or unset orientation
     * \param boolean value
     * */
    void setOriented(bool is) { oriented = is; }

    /* \brief Check if oriented
     * \return true if the edge is oriented, else false
     * */
    bool isOriented() const { return oriented; }

    /* \brief Set nodes[0]
     * \param a pointer to the node
     * */
    void setNode1(Node *n) { nodes[0] = n; }

    /* \brief Set nodes[1]
     * \param a pointer to the node
     * */
    void setNode2(Node *n) { nodes[1] = n; }

    /* \brief Get nodes[0]
     * \return a pointer to the node
     * */
    Node* getNode1(Node *n) const { return nodes[0]; }

    /* \brief Get nodes[1]
     * \return a pointer to the node
     * */
    Node* getNode2() const { return nodes[1]; }



};

#endif // EDGE_H

