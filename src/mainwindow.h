#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphscene.h"
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
    GraphScene scene;
    ElementManager* element_manager;

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
