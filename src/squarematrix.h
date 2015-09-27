#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H
#include "matrix.h"

/* \class Square matrix in which you can store values
 * of type Type
 * */
template <class Type>
class SquareMatrix : public Matrix<Type>
{
public:

    /* \brief Constructor
     * \param size of the matrix
     * */
    SquareMatrix(int size) : Matrix<Type>(size, size) {}

    /* \brief Constructor
     * \param size of the matrix and init values
     * */
    SquareMatrix(int size, Type* tab) : Matrix<Type>(size, size, tab) {}

    /* \brief Destructor
     * */
    ~SquareMatrix() {}
};

#endif // SQUAREMATRIX_H
