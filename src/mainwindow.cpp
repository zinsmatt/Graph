#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsEllipseItem>

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



}

MainWindow::~MainWindow()
{
    delete ui;
}
