#ifndef GRAPHSCENE2D_H
#define GRAPHSCENE2D_H
#include <QGraphicsScene>
#include "graph2d.h"

class Graph2dScene : public QGraphicsScene
{
private:
    Graph2d* graph;
public:
    Graph2dScene(Graph2d* _graph);
    void setGraph2d(Graph2d*  g){graph = g;}
    Graph2d& getGraph2d(){return *graph;}
    void drawGraph2d(){
        for(auto& i : graph->getNodes())
        {
            if(i.second->scene() != this)
                addItem(i.second);
        }
        for(auto& i : graph->getEdges())
        {
            if(i.second->scene() != this)
                addItem(i.second);
        }
    }
};

#endif // GRAPH2DSCENE_H
