#ifndef INCIDENCEMATRIX_H
#define INCIDENCEMATRIX_H


class IncidenceMatrix : private Matrix, public GraphContainer
{
public:
    IncidenceMatrix();
    ~IncidenceMatrix();
};

#endif // INCIDENCEMATRIX_H
