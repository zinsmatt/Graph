#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QPen>

#include "edge.h"


class Graph
{
private:
    std::vector<Node> nodes;
    std::vector<Edge> edges;

public:
    Graph();

    void addNode(const Node& n){
        nodes.push_back(n);
    }
    void addEdge(const Edge& e){
        edges.push_back(e);
    }

    void addNode(float x, float y, const QString& printId, unsigned int numero, unsigned int radius, const QString& color)
    {
        nodes.push_back(Node(x,y,printId,numero,radius,color));
    }

    unsigned int size() const {return nodes.size();}

    void draw(QGraphicsScene& scene)
    {
        QPainter painter;
        QPen myPen(Qt::black, 2, Qt::SolidLine);
        QStyleOptionGraphicsItem i;
        painter.setPen(myPen);
        for(std::vector<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it)
        {
            (*it).QGraphicsEllipseItem::paint(painter,&i);
            scene.addItem(&*it);
        }
    }

};

#endif // GRAPH_H
