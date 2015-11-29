#ifndef GRAPH2D_H
#define GRAPH2D_H
#include <vector>
#include <map>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QPen>
#include "node2d.h"
#include "edge2d.h"

class Graph2d
{
private:
    std::map<const QString, Node2d*> nodes;
    std::map<const QString, Edge2d*> edges;
    void addNode2d(const QString _id, Node2d* _node){nodes[_id] = _node;}
    void addEdge2d(const QString _id, Edge2d* _edge){edges[_id] = _edge;}

public:


    void addNode2d(const QString _label, int _size, const QString& _color, float _x, float _y){
        Node2d* n = new Node2d(_label, _size, _color, _x, _y);
        addNode2d(_label, n);
    }

    void addEdge2d(const QString _label, Node2d* _ori, Node2d* _dest)
    {
        Edge2d* edge = new Edge2d(_ori, _dest, false);
        addEdge2d(_label, edge);
    }

    const std::map<const QString, Node2d*>& getNodes() const {return nodes;}
    const std::map<const QString, Edge2d*>& getEdges() const {return edges;}

    Node2d* getNode2d(const QString _id) {return nodes[_id];}

};


#endif // GRAPH2D_H
