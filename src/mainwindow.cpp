#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsEllipseItem>
#include <iostream>

#include "graph.h"
#include "elementmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene.addText("LYONNAIS", QFont("Arial"));
    ui->graphicsView->setScene(&scene);
//    QRect rectangle(QPoint(25,25), QPoint(150,150));
//    item = scene.addEllipse(rectangle);
//    item->moveBy(150,55);
    element_manager = ElementManager::getInstance();
    scene.setGraph(new Graph());
    Graph* g = &scene.getGraph();

    Node *node1 = element_manager->getNewNode();
    Node *node2 = element_manager->getNewNode();
    Node *node3 = element_manager->getNewNode();
    Edge* e = element_manager->getNewEdge(node1, node2, true);


    node1->setProperties(10,10,"#00ff00", "#aaffaa", 25);
    node2->setProperties(-25,-30,"#ff0000", "#ffaaaa", 50);
    node3->setProperties(50,10,"#0000ff", "#aaaaff", 75);

    g->addNode(node1);
    g->addNode(node2);
    g->addNode(node3);
    g->addEdge(e);
    g->draw(scene);





    QObject::connect(ui->edgeInput, SIGNAL(returnPressed()), this, SLOT(inputEdge())) ;
    QObject::connect(ui->nodeInput, SIGNAL(returnPressed()), this, SLOT(inputNode())) ;
    updateLists();
}

void MainWindow::updateLists()
{
    ui->edges->clear();
    ui->nodes->clear();
    Graph* g = &scene.getGraph();

    for(std::pair<unsigned int, Node*> i : g->getNodes())
        ui->nodes->addItem(QString::fromStdString(std::to_string(i.second->getId())));
    for(auto i : g->getEdges())
    {
        QString str = QString::fromStdString(std::to_string(i.second->getNode1()->getId()) + " -> " +
                                             std::to_string(i.second->getNode2()->getId()));
        ui->edges->addItem(str);
    }
}

void MainWindow::inputEdge()
{
    QString base = ui->edgeInput->text();
    QStringList list = base.split(" ");
    Node* n1, *n2;
    Graph* g = &scene.getGraph();
    n1 = g->getNodes()[list.at(0).toInt()];

    if(n1 != 0 && n2 != 0)
    {
        g->addEdge(element_manager->getNewEdge(n1, n2, true));

    }
    g->draw(scene);
    updateLists();
}

void MainWindow::inputNode()
{
    QString base = ui->nodeInput->text();
    QStringList list = base.split(" ");
    Node* n = element_manager->getNewNode();
    n->setProperties(0,0, list.at(0), "#ffffff", list.at(1).toFloat());
    Graph* g = &scene.getGraph();
    g->addNode(n);
    g->draw(scene);
    updateLists();
}


MainWindow::~MainWindow()
{
    delete ui;
}
