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

    void addNode(float x, float y, const QString& printId, unsigned int numero, unsigned int radius,
                 const QString& color);

    unsigned int size() const {return nodes.size();}

    void draw(QGraphicsScene& scene);

    void printInfo(){
        for(auto i : nodes)
        {
            i.printPosition();
        }
    }

};

#endif // GRAPH_H
