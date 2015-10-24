#include <QApplication>
#include <iostream>
//#include "squarematrix.h"
#include "adjacencymatrix.h"
#include "mainwindow.h"
#include "graph.h"
#include "node2d.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow win;

    Graph g;
    g.addNode("A", 0, 0, 25, 2, "blue");
    g.addNode("B", 100, 50, 25, 2, "yellow");

    QPen pen(QColor(Qt::black), 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    QLine line(g.getNodes().at(0).getNode2D().x(), g.getNodes().at(0).getNode2D().y(),
               g.getNodes().at(1).getNode2D().x(), g.getNodes().at(1).getNode2D().y());
    win.getScene().addLine(line, pen);
    g.addEdge(&g.getNodes().at(0), &g.getNodes().at(1), false, "black" );
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

//    Graph g;



 //  AdjacencyMatrix adj;
 //  cout << adj << endl;

    /*
   Node *n1 = new Node();
   Node *n2 = new Node();
   Node *n3 = new Node();
   Node *n4 = new Node();

   g.addNode(n1);
   g.addNode(n2);
   g.addNode(n3);
   g.addNode(n4);

   Edge *e1 = new Edge(n1,n2,true,"");
   Edge *e2 = new Edge(n2,n1,true,"");
   Edge *e3 = new Edge(n1,n3,true,"");
   Edge *e4 = new Edge(n2,n4,true,"");
   Edge *e5 = new Edge(n3,n4,true,"");

   g.addEdge(e1);
   g.addEdge(e2);
   g.addEdge(e3);
   g.addEdge(e4);
   g.addEdge(e5);

   cout << g << endl;

   //cout << (int)g.removeEdge(e2)<<endl;
    g.removeNode(n4);

   cout << g << endl;

   delete n1;
   delete n2;
*/
    //Matrix<int> *m = new SquareMatrix<int>(5);


  /* adj.addNode(n1);
   adj.addNode(n2);
   cout << adj << endl;

   Edge *e1 = new Edge(n1,n2,false,"");
   adj.addEdge(e1);
   cout << adj<<endl;

   Edge *ret = adj.getEdge(n2,n1);
   cout << "ret id = "<<ret->getId()<<endl;

   adj.removeEdge(ret);

   cout << adj << endl;

   adj.removeNode(n1);

   cout << adj << endl;*/
   //TODO initialisation adjacency Matrix avec les nodes
   // TODO removeNode a tester

    return a.exec();

}
