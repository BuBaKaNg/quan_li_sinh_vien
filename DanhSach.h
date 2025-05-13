#ifndef DANHSACH_H
#define DANHSACH_H
#include "sinhvien.h"
#include "getter_setter_auto.cpp"
struct BaseNode {
public:
    BaseNode* next;
    SinhVien sv;
    virtual ~BaseNode() {}
};

class DanhSach {
    PROPERTY(BaseNode*, first, First);
public:
    virtual ~DanhSach() {}
    virtual BaseNode* them_sv(SinhVien &sv) = 0;
    virtual BaseNode* sua_sv(QString &mssv, SinhVien &sv) = 0;
    virtual bool xoa_sv(QString &mssv) = 0;
};

#endif // DANHSACH_H
