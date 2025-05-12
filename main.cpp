#include "mainwindow.h"
#include <QApplication>
#include "SinhVien.h"
#include "dslk_don.h"
#include <QList>
#include <QDebug>
#include "bits/stdc++.h"
#include "helper.h"
#include "read_write.h"

using namespace std;

QList<SinhVien> danhSach = {};

void test() {
    QList<SinhVien> temp = loadDuLieu("E:\\learnLongLife\\c++\\quan_li_sinh_vien\\DSSV.csv");
    dslk_don ds;
    for(auto x : temp){
        ds.them_sv(x);
    }
    Helper<nodeDSLKD, dslk_don> helper;
    helper.insertion_sort(ds.getFirst());
    helper.in_danh_sach(ds.getFirst());
}

int main(int argc, char *argv[])
{
    test();
    QApplication a(argc, argv);

    MainWindow w(danhSach);
    w.show();
    return a.exec();
}
