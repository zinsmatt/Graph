#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H


class AdjacencyMAtrix : private SquareMatrix, public GraphContainer
{
public:
    AdjacencyMAtrix();
    ~AdjacencyMAtrix();
};

#endif // ADJACENCYMATRIX_H
