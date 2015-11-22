#include "adjacencymatrix.h"
#include "exception.h"

AdjacencyMatrix::AdjacencyMatrix(int size, Edge* initValue) : SquareMatrix(size, initValue), GraphContainer()
{

}

AdjacencyMatrix::AdjacencyMatrix() : SquareMatrix(0), GraphContainer()
{

}

AdjacencyMatrix::~AdjacencyMatrix()
{
    for(int edgeIter=0; edgeIter<getNbNodes(); edgeIter++)
    {
        for(int edgeIter2=0; edgeIter2<getNbNodes(); edgeIter2++)
        {
            Edge* ret = this->get(edgeIter,edgeIter2);
            if(ret != nullptr)
            {
                if(ret->isOriented())
                    set(edgeIter2,edgeIter,nullptr);
                delete ret;
            }
        }
    }
}

int AdjacencyMatrix::getNodeIndex(Node *n)
{
    if(!n)
        return -1;
    if(idToIndex.find(n->getId()) == idToIndex.end())
        return -1;
    else
        return idToIndex[n->getId()];
}


void AdjacencyMatrix::addNode(Node* node)
{
    if(!node)
        throw LogException("invalid node",__LINE__,__FILE__);
    if(idToIndex.find(node->getId()) != idToIndex.end())
        throw LogException("node already exists in the matrix",__LINE__,__FILE__);
    idToIndex[node->getId()] = this->size();
    this->extend(nullptr); //add a row and a column
}

void AdjacencyMatrix::removeNode(Node *node)
{
    if(!node)
        throw LogException("invalid node",__LINE__,__FILE__);
    int idx = getNodeIndex(node);
    if(idx == -1)
        throw LogException("node is not in the matrix",__LINE__,__FILE__);
    this->SquareMatrix<Edge*>::shrink(idx);
    idToIndex.erase(node->getId());
    for(auto it = idToIndex.begin(); it != idToIndex.end(); it++)
    {
        if(it->second > idx)
            it->second--;
    }
}


void AdjacencyMatrix::addEdge(Edge* edge)
{
    Node* n1 = edge->getNode1();
    Node* n2 = edge->getNode2();
    if(!edge || !n1 || !n2)
        throw LogException("invalid edge",__LINE__,__FILE__);

    int idx1 = getNodeIndex(n1);
    int idx2 = getNodeIndex(n2);
    if(idx1==-1 || idx2==-1)
        throw LogException("an extremity is not in the matrix",__LINE__,__FILE__);
    this->SquareMatrix<Edge*>::set(idx1, idx2,edge);
    if(!edge->isOriented())
        this->SquareMatrix<Edge*>::set(idx2, idx1, edge);
}

void AdjacencyMatrix::removeEdge(Edge* edge)
{
    Node* n1 = edge->getNode1();
    Node* n2 = edge->getNode2();
    if(!edge || !n1 || !n2)
        throw LogException("invalid edge",__LINE__,__FILE__);
    if(!getEdge(n1,n2))
        throw LogException("edge is not in the matrix",__LINE__,__FILE__);   //the edge is not in the matrix

    int idx1 = getNodeIndex(n1);
    int idx2 = getNodeIndex(n2);
    if(idx1==-1 || idx2==-1)
        throw LogException("an extremity is not in the matrix",__LINE__,__FILE__);   //a node does not exist

    this->SquareMatrix<Edge*>::set(idx1, idx2, nullptr);
    if(!edge->isOriented())
        this->SquareMatrix<Edge*>::set(idx2, idx1, nullptr);
}

Edge* AdjacencyMatrix::getEdge(Node *n1, Node *n2)
{
    if(!n1 || !n2)
        return nullptr;
    int idx1 = getNodeIndex(n1);
    int idx2 = getNodeIndex(n2);
    if(idx1 == -1 || idx2 == -1)
        return false;    // a node does not exist

    return this->SquareMatrix<Edge*>::get(idx1, idx2);
}

QString AdjacencyMatrix::toString() const
{
    std::stringstream is;
    is << "Adjacency Matrix : \n";
    for(int i=0; i<this->size(); i++)
    {
        for(int j=0;j<this->size(); j++)
        {
            if(this->get(i,j) == nullptr)
                is << "0 ";
            else
                is <<this->get(i,j)->getId()<<" ";
        }
        is<<"\n";
    }
    return is.str().c_str();
}


std::ostream& operator<<(std::ostream& os, AdjacencyMatrix& m)
{
    os << m.toString().toStdString();
    return os;
}

