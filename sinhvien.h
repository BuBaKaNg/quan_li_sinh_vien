#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <QString>
#include <QDebug>
using namespace Qt;

class SinhVien
{
private:
    QString mssv;
    QString ho;
    QString ten;
    qint32 diem;
public:
    SinhVien(const QString &mssv, const QString &ho, const QString &ten, qint32 diem);
    void in_thong_tin();
    QString ten_dao_nguoc();
    // Getter
    QString getMssv() const;
    QString getHo() const;
    QString getTen() const;
    qint32 getDiem() const;

    // Setter
    void setMssv(const QString &value);
    void setHo(const QString &value);
    void setTen(const QString &value);
    void setDiem(qint32 value);
};


#endif // SINHVIEN_H
