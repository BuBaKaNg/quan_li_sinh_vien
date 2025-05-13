#include "mainwindow.h"
#include <QApplication>
#include <QList>
#include <QDebug>
#include "bits/stdc++.h"
using namespace std;

QList<SinhVien> danhSach = {};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();



    return a.exec();
}
