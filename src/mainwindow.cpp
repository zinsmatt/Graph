#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graph.h"
#include <QGraphicsEllipseItem>

#include <iostream>

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

    g = new Graph();
    Node *node1 = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();
    Edge* e = new Edge(node1, node2, true);

    node1->setProperties(10,10,"#00ff00", "#aaffaa", 25);
    node2->setProperties(-25,-30,"#ff0000", "#ffaaaa", 50);
    node3->setProperties(50,10,"#0000ff", "#aaaaff", 75);

    g->addNode(node1);
    g->addNode(node2);
    g->addNode(node3);
    g->addEdge(e);
    g->draw(scene);




    for(auto i : g->getNodes())
        ui->nodes->addItem(QString::fromStdString(std::to_string(i->getId())));
    for(auto i : g->getEdges())
    {
        QString str = QString::fromStdString(std::to_string(i->getNode1()->getId()) + " -> " + std::to_string(i->getNode2()->getId()));
        ui->edges->addItem(str);

    QObject::connect(ui->edgeInput, SIGNAL(returnPressed()), this, SLOT(inputEdge())) ;
    }

}

void MainWindow::inputEdge()
{
    std::cout << "ol" << std::endl;
    std::string base = ui->edgeInput->text().toStdString();
    std::string first = "";
    int counter = 0;
    while(base[counter] != '-')
    {
        first += base[counter];
        ++counter;
    }
    counter++;
    counter++;
    std::string sec = "";
    for(int i = counter; i < base.size(); ++i)
    {
        sec += base[i];
    }
    std::cout << first << " " << sec << std::endl;

}




MainWindow::~MainWindow()
{
    delete ui;
}
