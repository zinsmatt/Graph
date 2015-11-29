#include <QApplication>
#include <iostream>
#include "mainwindow.h"
#include "graph2d.h"


using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow win;
    Graph2d g;

    g.addNode2d("O", 25, "red", 10, 10);
    g.addNode2d("L", 25, "blue", -10, -10);

    g.addEdge2d("e", g.getNode2d("O"), g.getNode2d("L"));
    win.setGraph2d(&g);
    win.draw();




    win.show();
    return a.exec();





   return 0;


}
