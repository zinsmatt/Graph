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

    void addNode(float x, float y, float radius, float border, const QString &color);

    unsigned int size() const {return nodes.size();}

    void draw(QGraphicsScene& scene);

};

#endif // GRAPH_H
