#include "elementmanager.h"
#include "edge.h"

ElementId ElementManager::countId = 0;

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

Node* ElementManager::getCopyOf(Node *node)
{
    Node* nouv = new Node(countId);
    idToElement[countId] = nouv;
    countId++;
    *nouv = *node;
    return nouv;
}

Edge* ElementManager::getCopyOf(Edge *edge)
{
    Edge* nouv = new Edge(countId);
    idToElement[countId] = nouv;
    countId++;
    *nouv = *edge;
    return nouv;
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
