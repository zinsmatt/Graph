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

}

MainWindow::~MainWindow()
{
    delete ui;
}
