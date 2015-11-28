#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "graph.h"

/* \brief Abstract class representing an algorithm
 * */
class Algorithm
{
protected:
    Graph* graph;           //<! the graph on which the algorithm will be applied
public:
    Algorithm(Graph* graph);
    ~Algorithm();


    virtual void run() = 0;
    virtual bool check() const = 0;

};

#endif // ALGORITHM_H
