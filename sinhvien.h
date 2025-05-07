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
    qreal diem;
public:
    SinhVien();
    SinhVien(const QString &mssv, const QString &ho, const QString &ten, qreal diem);
    void in_thong_tin();
    QString ten_dao_nguoc();
    // Getter
    QString getMssv() const;
    QString getHo() const;
    QString getTen() const;
    qreal getDiem() const;

    // Setter
    void setMssv(const QString &value);
    void setHo(const QString &value);
    void setTen(const QString &value);
    void setDiem(qreal value);
};


#endif // SINHVIEN_H
