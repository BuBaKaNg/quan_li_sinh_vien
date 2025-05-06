#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QList<SinhVien> dssv, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),dssv(dssv)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label->setText(dssv[0].getMssv());
}

