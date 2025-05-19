#ifndef MANG_H
#define MANG_H
#include "sinhvien.h"
#include <QList>
class mang
{
public:
    QList<SinhVien> arr;
public:
    mang();
    int size();
    bool isEmpty();
    SinhVien tim_vet_can(QString &mssv);
    SinhVien them_sv(SinhVien &sv);
    SinhVien sua_sv(QString &mssv,SinhVien &sv);
    bool xoa_sv(QString mssv );
    void output();
   mang danh_sach_diem_thap();
   mang danh_sach_diem_cao();
    qreal tinh_tb(QString& lop);
    int menu_lua_chon_sap_xep();
    bool cmp(int choose, SinhVien a, SinhVien b);
    bool cmp_merge(int choose, SinhVien a, SinhVien b);
    void bubble_sort(int choose);
    void selection_sort(int choose);
    void insertion_sort(int choose);
    int partition(int choose, int low, int higt);
    void quick_sort(int choose, int l, int r);      // l=0, r = A.size()-1, choose: lựa chọn sắp xếp theo tiêu chí
    void merge(int choose, int l, int m, int r);
    void merge_sort(int choose, int l, int r);      // l=0, r = A.size()-1, choose: lựa chọn sắp xếp theo tiêu chí
    void heap(int choose, int n, int i);
    void heap_sort(int choose, int n);              // n = A.size(), choose: lựa chọn sắp xếp theo tiêu chí
    int menu_lua_chon_tim_kiem();
    QString lower_case(QString s);
    QString thong_tin_tieu_chi_tim_kiem();
    QList<int> tim_vet_can_ds_sv(int choose, QString tieu_chi);
    QList<int> tim_kiem_nhi_phan_ds_sv(int choose, QString tieu_chi);
    int search(int choose, SinhVien x, QString tieu_chi);
};

#endif // MANG_H
