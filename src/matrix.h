#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <ostream>

/* \class Represents a matrix in which you can store values
 * of type Type
 * */
template <class Type>
class Matrix
{
    int nbRows;
    int nbCols;
    std::vector<std::vector<Type> > matrix;
public:

    /* \brief Constructor
     * \param nb of rows and columns
     * */
    Matrix(int rows, int cols) : nbRows(rows), nbCols(cols)
    {
        for(int iter=0; iter<nbRows; iter++)
        {
            matrix.push_back(std::vector<Type>());
            for(int iter2=0;iter2<nbCols;iter2++)
            {
                matrix[iter].push_back(Type());
            }
        }
    }

    /* \brief Constructor
     * \param nb of rows and columns, init values
     * */
    Matrix(int rows, int cols, Type* tab) : nbRows(rows), nbCols(cols){
        int idx=0;
        for(int iter=0; iter<nbRows; iter++)
        {
            matrix.push_back(std::vector<Type>());
            for(int iter2=0;iter2<nbCols;iter2++)
            {
                matrix[iter].push_back(tab[idx++]);
            }
        }
    }

    /* \brief Destructor
     * \param nb of rows and columns
     * */
    ~Matrix(){}

    /* \brief getter
     * \param coordinates
     * \return a reference to the value stored in the matrix
     * */
    Type& get(int x, int y) { return matrix[x][y]; }

    /* \brief setter
     * \param coordinates and the value
     * */
    void set(int x, int y, const Type& value) { matrix[x][y] = value; }

    /* \brief getter nb rows
     * \return the number of rows
     * */
    int getNbRows() const { return nbRows; }

    /* \brief getter nb columns
     * \param coordinates
     * \return the number of columns
     * */
    int getNbCols() const { return nbCols; }
};




/* \brief operator << to ouput a matrix
 * \param output stream and a reference to the matrix
 * \return a reference to the stream
 * */
template<class Type>
std::ostream& operator<<(std::ostream& os, Matrix<Type>& m)
{
    for(int i=0; i<m.getNbRows(); i++)
    {
        for(int j=0;j<m.getNbCols(); j++)
            os<<m.get(i,j);
        os<<"\n";
    }
    return os;
}



#endif // MATRIX_H
