#ifndef ELEMENTFACTORY_H
#define ELEMENTFACTORY_H
#include "node.h"
#include "edge.h"

class ElementFactory
{
public:
    enum Type {node, edge};
    static Element* instanciate(const Type& t)
    {
        switch(t)
        {
            case node:
                return new Node;
            case edge:
                return new Edge;
        }
    }

    ElementFactory();
};

#endif // ELEMENTFACTORY_H
