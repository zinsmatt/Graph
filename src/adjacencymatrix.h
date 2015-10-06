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
    /* just for tests*/
    /* \brief Constructor
     * \param size of the matrix and an initial value
     * */
    AdjacencyMatrix(int size, Edge* initValue = NULL);

    /* \brief Constructor without parameter
     * */
    AdjacencyMatrix();


    /* \brief Destructor
     * */
    ~AdjacencyMatrix();

    /* \brief Get the node index in the matrix
     * \param a pointer to the node
     * \return index if the node exist, else -1
     * */
    int getNodeIndex(Node *n);


    /* \brief Add a Node to the matrix
     * \param a pointer to the node
     * \return true if added, false if not added
     * */
    bool addNode(Node* n);

    bool removeNode(Node* node);

    /* \brief Add an edge to the matrix
     * \param a pointer to the edge
     * \return true if added, else false
     * */
    bool addEdge(Edge *edge);

    /* \brief Remove an edge from the matrix
     * \param a pointer to the edge to remove
     * \return true if removed, false if does not exist
     * */
    bool removeEdge(Edge *edge);

    /* \brief Get an edge
     * \param two pointers to the nodes
     * \return a pointeur to the edge if it exists, else NULL
     * */
    Edge* getEdge(Node* n1, Node *n2);


    /* \brief Direct access to the matrix
     * \param index
     * \return a pointer to the edge if it exists, else NULL
     * */
    Edge* get(int x,int y) { return this->SquareMatrix<Edge*>::get(x,y); }

    /* \brief Get the matrix only
     * \return a reference to the square matrix
     * */
    SquareMatrix<Edge*>& getMatrix() { return static_cast<SquareMatrix<Edge*>&>(*this); }

    /* \brief Get the size of the matrix
     * */
    int size() const { return this->SquareMatrix<Edge*>::size(); }

};


/* \brief operator << to ouput a squareMatrix
 * \param output stream and a reference to the matrix
 * \return a reference to the stream
 * */
std::ostream& operator<<(std::ostream& os, AdjacencyMatrix& m);


#endif // ADJACENCYMATRIX_H
