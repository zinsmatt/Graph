#ifndef INCIDENCEMATRIX_H
#define INCIDENCEMATRIX_H
#include "matrix.h"
#include "graphcontainer.h"


//FAUSSE pour l'instant
class IncidenceMatrix : private Matrix<int>, public GraphContainer
{
public:
    IncidenceMatrix(int rows, int columns);
    virtual ~IncidenceMatrix();
};

#endif // INCIDENCEMATRIX_H
