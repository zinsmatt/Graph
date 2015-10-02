#include <QApplication>
#include <iostream>
//#include "squarematrix.h"
#include "adjacencymatrix.h"
#include "mainwindow.h"
#include "graph.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow win;

    Graph g;
    g.addNode(50.0,50.0,"A",0,20,"blue");
    g.draw(win.getScene());



    win.show();


/*
    std::cout << "LOSC" << std::endl;
/*

    Matrix<int> m(2,2);

    cout << "Matrix = \n" << m;
    m.set(0,0,1);
    m.set(1,1,5);
    cout << "Matrix = \n" << m;

    char tab[] = {'a','b','c','d','e','f','g','h','i'};
    SquareMatrix<char> square(3, tab);
    square.set(1,1,'x');

    cout << "Square Matrix = \n" << square << endl;
*/

    AdjacencyMatrix adj(3);
   // cout << adj << endl;
//TODO initialisation adjacency Matrix avec les nodes
//TODO type de retour de MAtrix::get(x,y)


    return a.exec();
}
