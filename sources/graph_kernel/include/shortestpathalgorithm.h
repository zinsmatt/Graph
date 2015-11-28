#ifndef SHORTESTPATHALGORITHM_H
#define SHORTESTPATHALGORITHM_H
#include "algorithm.h"

class ShortestPathAlgorithm : public Algorithm
{
protected:
    Node* startingNode;     //<! node from which you look for shortest path
    std::string attribute;      //<! name of attribute you use to compare two edges
public:
    ShortestPathAlgorithm(Graph* graph, Node* start, const std::string& key);
    ~ShortestPathAlgorithm();


    virtual bool check() const;
};

#endif // SHORTESTPATHALGORITHM_H
