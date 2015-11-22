#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "graph.h"
#include "elementmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    ElementManager* element_manager;
    Graph* g;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene& getScene(){return scene;}

    void updateLists();


public slots:
    void inputEdge();
    void inputNode();

};

#endif // MAINWINDOW_H
