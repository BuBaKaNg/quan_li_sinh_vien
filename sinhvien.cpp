#include "sinhvien.h"
#include <QLocale>
#include <QTextStream>
#include "bits/stdc++.h"
using namespace std;
SinhVien::SinhVien(){
    mssv = "";
    ten = "";
    ho = "";
    lop = "";
    diem = 0;
}
SinhVien::SinhVien(const QString &mssv, const QString &ho, const QString &ten, const QString &lop , const qreal diem) : mssv(mssv), ho(ho), ten(ten), lop(lop), diem(diem){}

void SinhVien::in_thong_tin() {
    qDebug() << "MSSV:" << mssv;
    qDebug() << "Họ"  << ho;
    qDebug() << "Tên:" << ten;
    qDebug() << "Lớp"  << ho;
    qDebug() << "Điểm:" << diem;
}

