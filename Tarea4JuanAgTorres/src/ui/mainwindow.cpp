#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./../../lib/include/producto.h"
#include "./../../lib/include/tienda.h"

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


void MainWindow::on_btnImportarBin_clicked()
{

}

