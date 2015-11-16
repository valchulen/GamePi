#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "thread.h"

Thread *t;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    t = new Thread(ui->myLabel, "/Users/valchu/Documents/GamePi/GamePi/GamePi/dk.nes");
    t->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
