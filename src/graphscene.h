#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H
#include <QGraphicsScene>
#include "graph.h"

class GraphScene : public QGraphicsScene
{
private:
    Graph* graph;
public:
    GraphScene();
    void setGraph(Graph*  g){graph = g;}
    Graph& getGraph(){return *graph;}
};

#endif // GRAPHSCENE_H
