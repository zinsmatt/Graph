#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graph2dscene.h"
#include "graph2d.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    Graph2dScene* scene;
    //ElementManager* element_manager;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene& getScene(){return *scene;}
    void draw(){scene->drawGraph2d();}
    void updateLists();
    void setScene(Graph2dScene* _scene);

public slots:
    void inputEdge();
    void inputNode();

};

#endif // MAINWINDOW_H
