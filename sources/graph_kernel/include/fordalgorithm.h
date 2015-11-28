#ifndef FORDALGORITHM_H
#define FORDALGORITHM_H
#include "shortestpathalgorithm.h"


class FordAlgorithm : public ShortestPathAlgorithm
{
public:
    FordAlgorithm(Graph *graph, Node* start, const std::string &key);
    ~FordAlgorithm();

    virtual void run();
    virtual bool check() const;
};

#endif // FORDALGORITHM_H
