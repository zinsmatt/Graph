#include "graph.h"
#include <iostream>

Graph::Graph()
{

}
void Graph::addNode(float x, float y, float radius, float border, const QString& color)
{
    nodes.push_back(Node(x, y, radius, border, color));
}



void Graph::draw(QGraphicsScene& scene)
{
    for(int i = 0; i < nodes.size(); ++i)
    {
        scene.addItem(&nodes[i].getNode2D());
    }
}
