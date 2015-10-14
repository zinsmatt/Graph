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
     * \param nb of rows and columns and an initial value
     * */
    Matrix(int rows, int cols, Type initValue) : nbRows(rows), nbCols(cols)
    {
        for(int iter=0; iter<nbRows; iter++)
        {
            matrix.push_back(std::vector<Type>());
            for(int iter2=0;iter2<nbCols;iter2++)
            {
                matrix[iter].push_back(initValue);
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

    /* \brief Suppress a row
     * \param index of the row to remove
     * \return boolean
     * */
    bool suppressRow(int row){
        if(row>=nbRows)
            return false;
        typename std::vector<std::vector<Type> >::iterator it = matrix.begin();
        for(int i=0;i<row;i++)  it++;
        matrix.erase(it);
        nbRows--;
        return true;
    }

    /* \brief Suppress a column
     * \param index of the column to remove
     * \return boolean
     * */
    bool suppressColumn(int col){
        if(col>=nbCols)
            return false;
        for(int row=0; row<nbRows; row++)
        {
            typename std::vector<Type>::iterator it = matrix[row].begin();
            for(int i=0;i<col;i++)  it++;
            matrix[row].erase(it);
        }
        nbCols--;
        return true;
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

    /* \brief const getter
     * \param coordinates
     * \return a const reference to the value stored in the matrix
     * */
    const Type& get(int x, int y) const { return matrix[x][y]; }

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

    /* \brief Add a column
     * \param init value
     * */
    void addRow(Type initValue){
        matrix.push_back(std::vector<Type>());
        nbRows++;
        for(int iter=0; iter<nbCols; iter++)
        {
            matrix[nbRows-1].push_back(initValue);
        }
    }

    /* \brief Add a row
     * \param init value
     * */
    void addColumn(Type initValue){
        for(int iter=0; iter<nbRows; iter++)
        {
            matrix[iter].push_back(initValue);
        }
        nbCols++;
    }
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
