#include <QApplication>
#include <iostream>
//#include "squarematrix.h"
#include "adjacencymatrix.h"
#include "mainwindow.h"
#include "graph.h"
#include "node2d.h"
#include "fordalgorithm.h"
#include "manager.h"

using namespace std;

int main(int argc, char *argv[])
{

    Node* n = Manager<Node>::instanciate();
    Manager<Node> man;
    man.add(n);
    /*QApplication a(argc, argv);

    MainWindow win;
    Graph g;

    Node *node1 = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();

    Edge* e = new Edge(node1, node2, true);

    node1->setProperties(10,10,"#00ff00", "#aaffaa", 25);
    node2->setProperties(-25,-30,"#ff0000", "#ffaaaa", 50);
    node3->setProperties(50,10,"#0000ff", "#aaaaff", 75);

    g.addNode(node1);
    g.addNode(node2);
    g.addNode(node3);
    g.addEdge(e);



    g.draw(win.getScene());

    win.show();
*/

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

   Graph g;






 //  AdjacencyMatrix adj;
 //  cout << adj << endl;

   Node *n0 = new Node();
   Node *n1 = new Node();
   Node *n2 = new Node();
   Node *n3 = new Node();
   Node *n4 = new Node();

   g.addNode(n0);
   g.addNode(n1);
   g.addNode(n2);
   g.addNode(n3);
   g.addNode(n4);

   Edge *e1 = new Edge(n0,n1,true);
   Edge *e2 = new Edge(n1,n3,true);
   Edge *e3 = new Edge(n1,n4,true);
   Edge *e4 = new Edge(n0,n2,true);
   Edge *e5 = new Edge(n3,n2,true);
   Edge *e6 = new Edge(n2,n4,true);

   Edge *e7 = new Edge(n4,n1,true);

   e1->addFloatAttribute("cost",2);
   e2->addFloatAttribute("cost",1);
   e3->addFloatAttribute("cost",7);
   e4->addFloatAttribute("cost",5);
   e5->addFloatAttribute("cost",1);
   e6->addFloatAttribute("cost",4);

   g.addEdge(e1);
   g.addEdge(e2);
   g.addEdge(e3);
   g.addEdge(e4);
   g.addEdge(e5);
   g.addEdge(e6);

   g.addEdge(e7);

   cout << g << endl;

   g.removeEdge(e7);
   cout << g << endl;

   g.removeNode(n0);
   cout << g << endl;
   g.removeEdge(e7);





   FordAlgorithm algo(&g,n0,"cost");
   algo.run();

   std::vector<Node*> succ;
   std::vector<Node*> pred;
   std::vector<Node*> successors;
   std::vector<Node*> predecessors;


   n1->getDirectSuccessors(succ);
   n1->getDirectPredecessors(pred);

   n4->getSuccessors(successors);
   n0->getPredecessors(predecessors);

   std::cout << "Direct Successors \n";
   for(int i=0;i<succ.size();i++)
       std::cout << succ[i]->getId() << std::endl;
    std::cout << "Direct Predecessors \n";
   for(int i=0;i<pred.size();i++)
       std::cout << pred[i]->getId() << std::endl;

   std::cout << "Successors\n";
  for(int i=0;i<successors.size();i++)
      std::cout << successors[i]->getId() << std::endl;
  std::cout << "Predecessors\n";
 for(int i=0;i<predecessors.size();i++)
     std::cout << predecessors[i]->getId() << std::endl;








   //cout << (int)g.removeEdge(e2)<<endl;
//    g.removeNode(n4);

 //  cout << g << endl;


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

    //return a.exec();
   return 0;

}
