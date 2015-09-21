#ifndef EDGE_H
#define EDGE_H
#include "node.h"

class Edge
{
    Node *node1;
    Node *node2;
    bool isOriented;
public:
    Edge(Node* n1, Node *n2, bool oriented);
    ~Edge();
};

#endif // EDGE_H
