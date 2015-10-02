#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H
#include "edge.h"
#include "squarematrix.h"
#include "graphcontainer.h"
#include <map>


class AdjacencyMatrix : private SquareMatrix<Edge*>, public GraphContainer
{
private:
    std::map<int, int> idToIndex;       //!< map between node id and index in the matrix

public:
    AdjacencyMatrix(int size, Edge* initValue = NULL);
    ~AdjacencyMatrix();

    bool addNode(Node* n);

    int size() const { return this->size(); }

    /* \brief getter that adapt a SquareMatrix method
     * \param coordinates
     * \return a reference to the value stored in the matrix
     * */
    Edge& get(int x, int y) { return this->get(x,y); }
};


/* \brief operator << to ouput a squareMatrix
 * \param output stream and a reference to the matrix
 * \return a reference to the stream
 * */
std::ostream& operator<<(std::ostream& os, AdjacencyMatrix& m);


#endif // ADJACENCYMATRIX_H
