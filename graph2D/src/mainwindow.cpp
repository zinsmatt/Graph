#include "mainwindow.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QGraphicsEllipseItem>
#include <iostream>

#include "graph2d.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->edgeInput, SIGNAL(returnPressed()), this, SLOT(inputEdge())) ;
    QObject::connect(ui->nodeInput, SIGNAL(returnPressed()), this, SLOT(inputNode())) ;

}

void MainWindow::setScene(Graph2dScene* _scene){
    scene = _scene;
    ui->graphicsView->setScene(scene);
}

void MainWindow::updateLists()
{
    if(scene != NULL){
        ui->edges->clear();
        ui->nodes->clear();

        for(auto i : scene->getGraph2d().getNodes())
        {
            ui->nodes->addItem(i.second->getId());
        }


        for(auto i : scene->getGraph2d().getEdges())
        {
            QString str = i.second->getSource().getId() + " -> " + i.second->getDest().getId();
            ui->edges->addItem(str);
        }
    }
}

void MainWindow::inputEdge()
{
    QString base = ui->edgeInput->text();
    QStringList list = base.split(" ");
    scene->getGraph2d().addEdge2d(list.at(0).toStdString(), list.at(1).toStdString(), list.at(2).toStdString());
    scene->drawGraph2d();
    updateLists();
}

void MainWindow::inputNode()
{
    QString base = ui->nodeInput->text();
    QStringList list = base.split(" ");
    scene->getGraph2d().addNode2d(list.at(0).toStdString(), list.at(1).toInt(), list.at(2).toStdString());
    scene->drawGraph2d();
    updateLists();
}


MainWindow::~MainWindow()
{
    delete ui;
}
