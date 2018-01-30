#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>
#include <vector>
#include <QWidget>
#include <QDebug>
//#include <QColor>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QColor>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QGraphicsScene scene;
    //QGraphicsRectItem *rect = scene.addRect(QRectF(0, 400, 1180, 680));


    ui->graphicsView->setScene(new QGraphicsScene);
    int hx = 50, hy = 70, hw = 50;
    q = ui->graphicsView->scene()->addRect(0 , 400, 1180, 680);
    r = ui->graphicsView->scene()->addRect(hx + 200, hy + 400, 200, 200);
    n = ui->graphicsView->scene()->addRect(270, 490, 50, 70);
    d = ui->graphicsView->scene()->addRect(400, 550, 50, 120);


    ui->graphicsView->scene()->setSceneRect(0, 0, 1180, 680);

    ui->graphicsView->scene()->addLine(hx + 200, hy + 400, hw + 50 + 250, 70 - 20 + 400);
    ui->graphicsView->scene()->addLine(hx + hw + 250, 70 - 20 + 400, 50 + 100 + 300, 70 + 400);

    ui->graphicsView->scene()->addLine(600 , 550, 570, 600);
    ui->graphicsView->scene()->addLine(600 , 550, 620, 600);
    ui->graphicsView->scene()->addLine(600 , 550, 600, 500);
    ui->graphicsView->scene()->addLine(550 , 520, 600, 500);
    ui->graphicsView->scene()->addLine(650 , 520, 600, 500);

    ui->graphicsView->scene()->addLine(295 , 490, 295, 560);
    ui->graphicsView->scene()->addLine(270 , 525, 320, 525);

    show();
    auto *ellipse = ui->graphicsView->scene()->addEllipse(500, 0, 100, 100);
    auto *ell = ui->graphicsView->scene()->addEllipse(575, 450, 50, 50);
    auto *e = ui->graphicsView->scene()->addEllipse(435, 610, 10, 10);
    int dx = 3;
    std::vector<QColor> colors{Qt::blue, Qt::green, Qt::red, "orange","brown"};
    ui->graphicsView->scene()->setBackgroundBrush(Qt::cyan);
    q->setBrush(QBrush(colors[1 % colors.size()]));
    ell->setBrush(QBrush(colors[3 % colors.size()]));
    e->setBrush(QBrush(Qt::black));
    n->setBrush(QBrush(Qt::cyan));
    d->setBrush(QBrush(Qt::white));
    r->setBrush(QBrush(colors[4 % colors.size()]));
    r->setFlag(QGraphicsItem::ItemIsFocusable);
    r->setFocus();

    int colorIndex = 0;
    while(1)
    {
        ellipse->moveBy(dx,0);
        usleep(100 * 10);
        repaint();
        QApplication::processEvents();
        if (ellipse->x() > 500 || ellipse->x() < 0)
        {
            dx = -dx;
            ellipse->setBrush(QBrush(colors[colorIndex % colors.size()]));
            colorIndex++;
        }
    }

}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "MyRect knows you pressed";
    if (event->key() == Qt::Key_Left){
        r->setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        r->setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up){
        r->setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        r->setPos(x(),y()+10);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
