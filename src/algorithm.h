#ifndef ALGORITHM_H
#define ALGORITHM_H

/* \brief Abstract class representing an algorithm
 * */
class Algorithm
{
public:
    Algorithm();
    ~Algorithm();


    virtual void run() = 0;

};

#endif // ALGORITHM_H
