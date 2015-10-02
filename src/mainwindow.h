#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene& getScene(){return scene;}

};

#endif // MAINWINDOW_H
