#ifndef ELEMENTMANAGER_H
#define ELEMENTMANAGER_H
#include "types.h"
#include <map>

class Element;
class Node;
class Edge;

class ElementManager
{

private:

    static ElementManager *instance;
    static ElementId countId;

    std::map<ElementId, Element*> idToElement;

    ElementManager();
    ElementManager(const ElementManager&);
    ElementManager& operator=(const ElementManager&);
    ~ElementManager();



public:

    static ElementManager* getInstance(){
        if(!instance)
            instance = new ElementManager;
        return instance;
    }

    static void killInstance(){
        if(instance)
            delete instance;
        instance = nullptr ;
    }

    Node* getNewNode();
    Edge* getNewEdge();
    Node* getCopyOf(Node* node);
    Edge* getCopyOf(Edge* edge);

    void releaseElement(Element* element);


};

#endif // ELEMENTMANAGER_H
