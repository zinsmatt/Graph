#ifndef EDGE_H
#define EDGE_H
#include "node.h"
#include "types.h"

class Edge : public Element
{
    Node *nodes[2];     //!< nodes linked by the edge. If oriented allways from nodes[0] to nodes[1]
    bool oriented;

    /* \brief Default constructor
     * \param Edge id
     * */
    Edge(ElementId id);

    /* \brief Set nodes[0]
     * \param a pointer to the node
     * */
    void setNode1(Node *n) { nodes[0] = n; }

    /* \brief Set nodes[1]
     * \param a pointer to the node
     * */
    void setNode2(Node *n) { nodes[1] = n; }


public:

    friend class ElementManager;
    friend class Graph;

    /* \brief Destructor
     * */
    virtual ~Edge();

    /* \brief Set or unset orientation
     * \param boolean value
     * */
    void setOriented(bool is) { oriented = is; }

    /* \brief Check if oriented
     * \return true if the edge is oriented, else false
     * */
    bool isOriented() const { return oriented; }

    /* \brief Get nodes[0]
     * \return a pointer to the node
     * */
    Node* getNode1() const { return nodes[0]; }

    /* \brief Get nodes[1]
     * \return a pointer to the node
     * */
    Node* getNode2() const { return nodes[1]; }

};

#endif // EDGE_H

