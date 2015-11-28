#ifndef ELEMENTMANAGER_H
#define ELEMENTMANAGER_H
#include <map>

class Element;
class Node;
class Edge;

class ElementManager
{

private:

    //std::vector<Element*> elements;
    static ElementManager *instance;
    static unsigned int countId;

    std::map<unsigned int, Element*> idToElement;

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
    Edge* getNewEdge(Node *n1, Node *n2, bool isOriented = true);

    void releaseElement(Element* element);


};

#endif // ELEMENTMANAGER_H
