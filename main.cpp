#include "mainwindow.h"
#include <QApplication>
#include "SinhVien.h"
#include <QList>
#include <QDebug>

QList<SinhVien> danhSach = {
    SinhVien("SV001", "Nguyen", "An", 8),
    SinhVien("SV002", "Le", "Binh", 7),
    SinhVien("SV003", "Tran", "Cuong", 9),
    SinhVien("SV004", "Pham", "Dung", 6),
    SinhVien("SV005", "Ho", "Em", 10),
    SinhVien("SV006", "Dang", "Giang", 7),
    SinhVien("SV007", "Bui", "Hoa", 5),
    SinhVien("SV008", "Do", "Khanh", 8),
    SinhVien("SV009", "Trinh", "Lam", 9),
    SinhVien("SV010", "Ngo", "Minh", 6)
};


void test() {

}

int main(int argc, char *argv[])
{
    test();
    QApplication a(argc, argv);
    MainWindow w(danhSach);
    w.show();
    return a.exec();
}
