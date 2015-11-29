#ifndef GRAPHSCENE2D_H
#define GRAPHSCENE2D_H
#include <QGraphicsScene>
#include "graph2d.h"

class Graph2dScene : public QGraphicsScene
{
private:
    Graph2d* graph;
public:
    Graph2dScene();
    void setGraph2d(Graph2d*  g){graph = g;}
    Graph2d& getGraph2d(){return *graph;}
    void drawGraph2d(){
        for(auto& i : graph->getNodes())
            addItem(i.second);
        for(auto& i : graph->getEdges())
            addItem(i.second);
    }
};

#endif // GRAPH2DSCENE_H
