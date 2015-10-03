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
    Node* n = &nodes.at(0);
    n->setFlag(QGraphicsItem::ItemIsSelectable);
    n->setFlag(QGraphicsItem::ItemIsMovable);

    dynamic_cast<QGraphicsEllipseItem*>(n)->setBrush(QBrush(Qt::red));
    scene.addItem(n);
    /*
    for(auto it : nodes)
    {
        //it = scene.addEllipse(it.getX(), it.getY(), 25, 25, it.getPen(), it.getBrush());
        scene.addItem(&it);
//       it.getItem().setFlag(QGraphicsItem::ItemIsSelectable);
//       it.getItem().setFlag(QGraphicsItem::ItemIsMovable);

    }*/
}
