#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <QString>

using namespace Qt;

class SinhVien
{
private:
    QString mssv;
    QString ho;
    QString ten;
    int diem;
public:
    SinhVien();
    void in_thong_tin();
    QString ten_dao_nguoc();
};


#endif // SINHVIEN_H
