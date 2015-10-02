#include "graph.h"
#include <iostream>

Graph::Graph()
{

}
void Graph::addNode(float x, float y, const QString& printId, unsigned int numero, unsigned int radius, const QString& color)
{
    nodes.push_back(Node(x, y, printId, numero, radius, color));
}



void Graph::draw(QGraphicsScene& scene)
{

    for(auto it : nodes)
    {
       it.setItem(scene.addEllipse(it.getX(), it.getY(), 25, 25, it.getPen(), it.getBrush()));
       it.getItem().setFlag(QGraphicsItem::ItemIsSelectable);
       it.getItem().setFlag(QGraphicsItem::ItemIsMovable);
    }
}
