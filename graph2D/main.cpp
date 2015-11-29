#include <QApplication>
#include <iostream>
#include "mainwindow.h"
#include "graph2d.h"


using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Graph2d g;
    Graph2dScene scene(&g);
    MainWindow win;

    g.addNode2d("O", 25, "red", 10, 10);
    g.addNode2d("L", 25, "blue", -10, -10);

    g.addEdge2d("e", "O", "L");
    win.setScene(&scene);
    win.draw();
    win.updateLists();



    win.show();
    return a.exec();





   return 0;


}
