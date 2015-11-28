#include "elementmanager.h"
#include "edge.h"

unsigned int ElementManager::countId = 0;

ElementManager* ElementManager::instance = nullptr;

ElementManager::ElementManager()
{

}

ElementManager::~ElementManager()
{
    for(auto it : idToElement)
    {
        if(it.second)
        {
            delete it.second;
            it.second = nullptr;
        }
    }

}

Node* ElementManager::getNewNode()
{
    Node* node = new Node(countId);
    idToElement[countId] = node;
    //node->setId(countId);
    countId++;
    return node;
}

Edge* ElementManager::getNewEdge()
{
    Edge* edge = new Edge(countId);
    idToElement[countId] = edge;
    countId++;
    return edge;
}

Edge* ElementManager::getNewEdge(Node *n1, Node *n2, bool isOriented)
{
    Edge* edge =  new Edge(countId,n1,n2,isOriented);
    idToElement[countId] = edge;
    countId++;
    return edge;
}



void ElementManager::releaseElement(Element *element)
{
    if(element)
    {
        unsigned int id = element->getId();
        delete idToElement[id];
        idToElement[id] = nullptr;
        idToElement.erase(id);
    }
}
