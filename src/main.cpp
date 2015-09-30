#include <QApplication>
#include <iostream>
#include "squarematrix.h"
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow win;
   // win.show();


    std::cout << "LOSC" << std::endl;


    Matrix<int> m(2,2);

    cout << "Matrix = \n" << m;
    m.set(0,0,1);
    m.set(1,1,5);
    cout << "Matrix = \n" << m;

    char tab[] = {'a','b','c','d','e','f','g','h','i'};
    SquareMatrix<char> square(3, tab);
    square.set(1,1,'x');

    cout << "Square Matrix = \n" << square << endl;


    return a.exec();
}
