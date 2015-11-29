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
    scene.addText("LYONNAIS", QFont("Arial"));
    ui->graphicsView->setScene(&scene);



}


MainWindow::~MainWindow()
{
    delete ui;
}
