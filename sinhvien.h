#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <QString>
#include <QDebug>
#include "getter_setter_auto.cpp"
using namespace Qt;

class SinhVien
{
private:
    PROPERTY(QString, mssv, Mssv);
    PROPERTY(QString, ho, Ho);
    PROPERTY(QString, ten, Ten);
    PROPERTY(qreal, diem, Diem);
public:
    SinhVien();
    SinhVien(const QString &mssv, const QString &ho, const QString &ten, qreal diem);
    void in_thong_tin();
    QString ten_dao_nguoc();
};


#endif // SINHVIEN_H
