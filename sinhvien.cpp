#include "sinhvien.h"
#include <QLocale>
#include <QTextStream>
#include "bits/stdc++.h"
using namespace std;
SinhVien::SinhVien(){
    mssv = "";
    ten = "";
    ho = "";
    diem = 0;
}
SinhVien::SinhVien(const QString &mssv, const QString &ho, const QString &ten, qreal diem) : mssv(mssv), ho(ho), ten(ten), diem(diem){}

void SinhVien::in_thong_tin() {
    qDebug() << "MSSV:" << mssv;
    qDebug() << "Họ"  << ho;
    qDebug() << "Tên:" << ten;
    qDebug() << "Điểm:" << diem;
}

