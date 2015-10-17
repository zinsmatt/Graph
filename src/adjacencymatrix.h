#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H
#include <map>
#include "edge.h"
#include "squarematrix.h"
#include "graphcontainer.h"

class AdjacencyMatrix : private SquareMatrix<Edge*>, public GraphContainer
{
private:
    std::map<int, int> idToIndex;       //!< map between node id and index in the matrix

    /* \brief Direct access to the matrix
     * \param index
     * \return a pointer to the edge if it exists, else NULL
     * */
    Edge* get(int x,int y) { return this->SquareMatrix<Edge*>::get(x,y); }

    /* \brief const access to the matrix
     * \param index
     * \return a const pointer to the edge if it exists, else NULL
     * */
    const Edge* get(int x,int y) const { return this->SquareMatrix<Edge*>::get(x,y); }

    /* \brief Get the node index in the matrix
     * \param a pointer to the node
     * \return index if the node exist, else -1
     * */
    int getNodeIndex(Node *n);

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
    virtual ~AdjacencyMatrix();

    /* \brief Add a Node to the matrix
     * \param a pointer to the node
     * \return true if added, false if not added
     * */
    virtual bool addNode(Node* node);


    /* \brief Remove a node from the matrix
     * \param a pointer to the node to remove
     * \return true if removed, false if does not exist
     * */
    virtual bool removeNode(Node* node);

    /* \brief Add an edge to the matrix
     * \param a pointer to the edge
     * \return true if added, else false
     * */
    virtual bool addEdge(Edge *edge);

    /* \brief Remove an edge from the matrix
     * \param a pointer to the edge to remove
     * \return true if removed, false if does not exist
     * */
    virtual bool removeEdge(Edge *edge);

    /* \brief Get an edge
     * \param two pointers to the nodes
     * \return a pointeur to the edge if it exists, else NULL
     * */
    virtual Edge* getEdge(Node* n1, Node *n2);

    // TEMPORAIRE PAS UTILE
    /* \brief Get the matrix only
     * \return a reference to the square matrix
     * */
   // SquareMatrix<Edge*>& getMatrix() { return static_cast<SquareMatrix<Edge*>&>(*this); }

    // PAS UTILE getNbNode plutot
    /* \brief Get the size of the matrix
     * */
  //  int size() const { return this->SquareMatrix<Edge*>::size(); }

    /* \brief Get a string that describes the object
     * \return an QString containing the description
     * */
    virtual QString toString() const;

    /* \brief Get the number of nodes in the matrix
     * */
    int getNbNodes() const { return idToIndex.size(); }
};


/* \brief operator << to ouput an adjacency matrix
 * \param output stream and a reference to the matrix
 * \return a reference to the stream
 * */
std::ostream& operator<<(std::ostream& os, AdjacencyMatrix& m);


#endif // ADJACENCYMATRIX_H
