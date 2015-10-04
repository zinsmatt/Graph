#ifndef NODE_H
#define NODE_H
#include "element.h"
#include "node2d.h"

class Node : public Element
{
private:
    Node2D* node2d;


public:
    Node(float x, float y, float radius, float border, const QString color);
    Node(){}

    Node2D& getNode2D() {return *node2d;}

};

#endif // NODE_H
