#include "adjacencymatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int size, Edge* initValue) : SquareMatrix(size, initValue), GraphContainer()
{

}

AdjacencyMatrix::~AdjacencyMatrix()
{

}



bool AdjacencyMatrix::addNode(Node* n)
{
    if(!n)
        return false;
    if(idToIndex.find(n->getId()) != idToIndex.end())
        return false;   //node is already in the matrix
    idToIndex[n->getId()] = this->size();
    this->extend(NULL); //add a row and a column
    return true;
}


std::ostream& operator<<(std::ostream& os, AdjacencyMatrix& m)
{
    os << "Adjacency MAtrix : \n";
    for(int i=0; i<m.size(); i++)
    {
        for(int j=0;j<m.size(); j++)
            os<<(void*)m.get(i,j)<<" ";
        os<<"\n";
    }
    return os;
}

