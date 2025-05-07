#include "mainwindow.h"
#include <QApplication>
#include "SinhVien.h"
#include "dslk_don.h"
#include <QList>
#include <QDebug>
#include "bits/stdc++.h"
#include "helper.h"
QList<SinhVien> danhSach = {
    SinhVien("SV001", "Nguyen", "An", 10),
    SinhVien("SV002", "Le", "Binh", 10),
    SinhVien("SV003", "Tran", "Cuong", 1),
    SinhVien("SV004", "Pham", "Dung", 10),
    SinhVien("SV005", "Ho", "Em", 10),
    SinhVien("SV006", "Dang", "Giang", 1),
    SinhVien("SV007", "Bui", "Hoa", 10),
    SinhVien("SV008", "Do", "Khanh", 10),
    SinhVien("SV009", "Trinh", "Lam", 10),
    SinhVien("SV010", "Ngo", "Minh", 10)
};
using namespace std;

void test() {
    dslk_don ds;
    for(auto x : danhSach){
        ds.them_sv(x);
    }
    Helper<nodeDSLKD, dslk_don> helper;
    dslk_don list = helper.liet_ke_sv_diem_thap(ds.get_first());
    helper.in_danh_sach(list.get_first());
}

int main(int argc, char *argv[])
{
    test();
    QApplication a(argc, argv);

    MainWindow w(danhSach);
    w.show();
    return a.exec();
}
