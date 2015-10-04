#include "graph.h"
#include <iostream>

Graph::Graph()
{

}
void Graph::addNode(const QString& label, float x, float y, float radius, float border, const QString& color)
{
    nodes.push_back(Node(label, x, y, radius, border, color));
}

void Graph::addEdge(Node *n1, Node *n2, bool oriented, const QString &color)
{
    edges.push_back(Edge(n1, n2, oriented, color));
}



void Graph::draw(QGraphicsScene& scene)
{
    for(int i = 0; i < nodes.size(); ++i)
    {
        scene.addItem(&nodes[i].getNode2D());
    }
    for(int i = 0; i < edges.size(); ++i)
    {
        scene.addItem(&edges[i].getEdge2D());
    }
}
