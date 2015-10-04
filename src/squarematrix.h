#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H
#include "matrix.h"

/* \class Square matrix in which you can store values
 * of type Type
 * */
template <class Type>
class SquareMatrix : private Matrix<Type>
{



public:

    /* \brief Constructor
     * \param size of the matrix
     * */
    SquareMatrix(int size) : Matrix<Type>(size, size) {}

    /* \brief Constructor
     * \param size of the matrix and an initial value
     * */
    SquareMatrix(int size, Type initValue) : Matrix<Type>(size, size, initValue) {}

    /* \brief Constructor
     * \param size of the matrix and init values
     * */
    SquareMatrix(int size, Type* tab) : Matrix<Type>(size, size, tab) {}

    /* \brief Destructor
     * */
    ~SquareMatrix() {}
    /* \brief Return the size
     * */
    int size() const { return this->Matrix<Type>::getNbRows(); }

    /* \brief Extend the matrix
     * \param init value for the added column and row
     * */
    void extend(Type initValue){
        this->addRow(initValue);
        this->addColumn(initValue);
    }

    /* \brief getter that adapt a Matrix method
     * \param coordinates
     * \return a reference to the value stored in the matrix
     * */
    Type& get(int x, int y) { return this->Matrix<Type>::get(x,y); }

    /* \brief setter that adapt a Matrix method
     * \param coordinates and the value
     * */
    void set(int x, int y, const Type& value) { this->Matrix<Type>::set(x,y,value); }



};



/* \brief operator << to ouput a squareMatrix
 * \param output stream and a reference to the matrix
 * \return a reference to the stream
 * */
template<class Type>
std::ostream& operator<<(std::ostream& os, SquareMatrix<Type>& m)
{
    for(int i=0; i<m.size(); i++)
    {
        for(int j=0;j<m.size(); j++)
            os<<m.get(i,j);
        os<<"\n";
    }
    return os;
}
#endif // SQUAREMATRIX_H
