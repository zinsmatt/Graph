#include "graph.h"
#include "adjacencymatrix.h"
#include "graph.h"
#include "fordalgorithm.h"
#include "elementmanager.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{


    Graph gr(false, new AdjacencyMatrix);

    ElementManager *manager = ElementManager::getInstance();

    Node* n1 = manager->getNewNode();
    Node* n2 = manager->getNewNode();
    Node* n3 = manager->getNewNode();

    gr.addNode(n1);
    gr.addNode(n2);
    gr.addNode(n3);

    Edge *e12 = manager->getNewEdge();
    Edge *e23 = manager->getNewEdge();
    Edge *e13 = manager->getNewEdge();

    gr.addEdge(e12,n1,n2);
    gr.addEdge(e23,n2,n3);
    gr.addEdge(e13,n1,n3);

    cout << gr << endl;

    gr.transformIntoOriented();

    cout << gr << endl;

    gr.transformIntoNonOriented();

    cout << gr << endl;

    gr.transformIntoOriented();

    cout << gr << endl;
/*

    Graph g(true, new AdjacencyMatrix);


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

    Edge *e1 = manager->getNewEdge(); //new Edge(n0,n1,true);
    Edge *e2 = manager->getNewEdge(); //new Edge(n1,n3,true);
    Edge *e3 = manager->getNewEdge(); //new Edge(n1,n4,true);
    Edge *e4 = manager->getNewEdge(); //new Edge(n0,n2,true);
    Edge *e5 = manager->getNewEdge(); //new Edge(n3,n2,true);
    Edge *e6 = manager->getNewEdge(); //new Edge(n2,n4,true);
    Edge *e7 = manager->getNewEdge(); //new Edge(n4,n1,true);

    e1->setFloatAttribute("cost",2);
    e2->setFloatAttribute("cost",1);
    e3->setFloatAttribute("cost",7);
    e4->setFloatAttribute("cost",5);
    e5->setFloatAttribute("cost",1);
    e6->setFloatAttribute("cost",4);

    g.addEdge(e1,n0,n1,true);
    g.addEdge(e2,n1,n3,true);
    g.addEdge(e3,n1,n4,true);
    g.addEdge(e4,n0,n2,true);
    g.addEdge(e5,n3,n2,true);
    g.addEdge(e6,n2,n4,true);
    g.addEdge(e7,n4,n1,true);

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
*/
   std::cout << "Allez le LOSC !!!! \n";
   return 0;


}
