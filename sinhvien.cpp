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
    cout << "Họ"  << ho.toStdString() << endl;
    qDebug() << "Tên:" << ten;
    qDebug() << "Điểm:" << diem;
}

// Getter
QString SinhVien::getMssv() const {
    return mssv;
}

QString SinhVien::getHo() const {
    return ho;
}

QString SinhVien::getTen() const {
    return ten;
}

qreal SinhVien::getDiem() const {
    return diem;
}

// Setter
void SinhVien::setMssv(const QString &value) {
    mssv = value;
}

void SinhVien::setHo(const QString &value) {
    ho = value;
}

void SinhVien::setTen(const QString &value) {
    ten = value;
}

void SinhVien::setDiem(qreal value) {
    diem = value;
}
