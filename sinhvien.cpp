#include "sinhvien.h"
#include <QLocale>
#include <QTextStream>
SinhVien::SinhVien(const QString &mssv, const QString &ho, const QString &ten, qint32 diem) : mssv(mssv), ho(ho), ten(ten), diem(diem){}
void SinhVien::in_thong_tin() {
    qDebug() << QString::fromUtf8("MSSV: ") << mssv;
    qDebug() << QString::fromUtf8("Họ: ") << ho;
    qDebug() << QString::fromUtf8("Tên: ") << ten;
    qDebug() << QString::fromUtf8("Điểm: ") << diem;
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

qint32 SinhVien::getDiem() const {
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

void SinhVien::setDiem(qint32 value) {
    diem = value;
}
