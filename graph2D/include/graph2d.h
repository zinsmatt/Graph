#ifndef GRAPH2D_H
#define GRAPH2D_H
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QPen>
#include "node2d.h"
#include <map>
#include <vector>
#include "edge2d.h"

class Graph2d
{
private:
    std::map<const std::string, Node2d*> nodes;
    std::map<const std::string, Edge2d*> edges;
    void addNode2d(const std::string _id, Node2d* _node){nodes[_id] = _node;}
    void addEdge2d(const std::string _id, Edge2d* _edge){edges[_id] = _edge;}
    Node2d* getNode2d(const std::string _id) {return nodes[_id];}

public:


    void addNode2d(const std::string _label, int _size, const std::string _color, float _x=0, float _y=0){
        Node2d* n = new Node2d(QString::fromStdString(_label), _size, QString::fromStdString(_color), _x, _y);
        addNode2d(_label, n);
    }

    void addEdge2d(const std::string _label, const std::string _ori, const std::string _dest)
    {
        Edge2d* edge = new Edge2d(QString::fromStdString(_label), getNode2d(_ori), getNode2d(_dest), false);
        addEdge2d(_label, edge);
    }

    std::map<const std::string, Node2d*> getNodes() {return nodes;}
    std::map<const std::string, Edge2d*> getEdges() {return edges;}


};


#endif // GRAPH2D_H
