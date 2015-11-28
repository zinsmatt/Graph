#include "graph.h"
#include "adjacencymatrix.h"
#include "graph.h"
#include "fordalgorithm.h"
#include "elementmanager.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{






    Graph g(new AdjacencyMatrix);


    ElementManager *manager = ElementManager::getInstance();



 //  AdjacencyMatrix adj;
 //  cout << adj << endl;


    Node *n0 = manager->getNewNode();// new Node();
    Node *n1 = manager->getNewNode();// new Node();
    Node *n2 = manager->getNewNode();// new Node();
    Node *n3 = manager->getNewNode();// new Node();
    Node *n4 = manager->getNewNode();// new Node();


    g.addNode(n0);
    g.addNode(n1);
    g.addNode(n2);
    g.addNode(n3);
    g.addNode(n4);

    Edge *e1 = manager->getNewEdge(n0,n1,true); //new Edge(n0,n1,true);
    Edge *e2 = manager->getNewEdge(n1,n3,true); //new Edge(n1,n3,true);
    Edge *e3 = manager->getNewEdge(n1,n4,true); //new Edge(n1,n4,true);
    Edge *e4 = manager->getNewEdge(n0,n2,true); //new Edge(n0,n2,true);
    Edge *e5 = manager->getNewEdge(n3,n2,true); //new Edge(n3,n2,true);
    Edge *e6 = manager->getNewEdge(n2,n4,true); //new Edge(n2,n4,true);
    Edge *e7 = manager->getNewEdge(n4,n1,true); //new Edge(n4,n1,true);

    e1->setFloatAttribute("cost",2);
    e2->setFloatAttribute("cost",1);
    e3->setFloatAttribute("cost",7);
    e4->setFloatAttribute("cost",5);
    e5->setFloatAttribute("cost",1);
    e6->setFloatAttribute("cost",4);

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
    n4->getDirectPredecessors(pred);

    n1->getSuccessors(successors);
    n4->getPredecessors(predecessors);

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

   std::cout << "Allez le LOSC !!!! \n";
   return 0;


}
