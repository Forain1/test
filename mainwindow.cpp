#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QPen>
#include<Qbrush>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen (Qt::DotLine);
    QBrush brush(Qt::blue);
    brush.setStyle(Qt::HorPattern);
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(50,50,200,200);
}
