#include "adjacencymatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int size, Edge* initValue) : SquareMatrix(size, initValue), GraphContainer()
{

}

AdjacencyMatrix::AdjacencyMatrix() : SquareMatrix(0), GraphContainer()
{

}

AdjacencyMatrix::~AdjacencyMatrix()
{

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

bool AdjacencyMatrix::removeNode(Node *node)
{
    if(!node)
        return false;
    int idx = getNodeIndex(node);
    if(idx == -1)
        return -1;      //node is not in the matrix
    this->SquareMatrix<Edge*>::shrink(idx);
    idToIndex.erase(node->getId());
    for(auto it = idToIndex.begin(); it != idToIndex.end(); it++)
    {
        if(it->second > idx)
            it->second--;
    }
    return true;
}


bool AdjacencyMatrix::addEdge(Edge* edge)
{
    Node* n1 = edge->getNode1();
    Node* n2 = edge->getNode2();
    if(!edge || !n1 || !n2)
        return false;

    int idx1 = getNodeIndex(n1);
    int idx2 = getNodeIndex(n2);
    if(idx1==-1 || idx2==-1)
        return false;   //a node does not exist
    this->SquareMatrix<Edge*>::set(idx1, idx2,edge);
    if(!edge->isOriented())
        this->SquareMatrix<Edge*>::set(idx2, idx1, edge);
    return true;
}

bool AdjacencyMatrix::removeEdge(Edge* edge)
{
    Node* n1 = edge->getNode1();
    Node* n2 = edge->getNode2();
    if(!edge || !n1 || !n2)
        return false;
    if(!getEdge(n1,n2))
        return false;   //the edge is not in the matrix

    int idx1 = getNodeIndex(n1);
    int idx2 = getNodeIndex(n2);
    if(idx1==-1 || idx2==-1)
        return false;   //a node does not exist

    this->SquareMatrix<Edge*>::set(idx1, idx2, NULL);
    if(!edge->isOriented())
        this->SquareMatrix<Edge*>::set(idx2, idx1, NULL);
    return true;
}

Edge* AdjacencyMatrix::getEdge(Node *n1, Node *n2)
{
    if(!n1 || !n2)
        return NULL;
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
            if(this->get(i,j) == NULL)
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

