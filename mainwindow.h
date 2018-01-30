#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsRectItem>
//#include <QGraphicsScene>
//#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QGraphicsRectItem *q;
    QGraphicsRectItem *r;
    QGraphicsRectItem *n;
    QGraphicsRectItem *d;


    void keyPressEvent(QKeyEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    //void keyPressEvent(QKeyEvent *r);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //QGraphicsScene *scene;
};


#endif // MAINWINDOW_H
