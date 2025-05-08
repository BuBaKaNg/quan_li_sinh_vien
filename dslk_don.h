#ifndef DSLK_DON_H
#define DSLK_DON_H
#include "SinhVien.h"
#include <QList>
#include "getter_setter_auto.cpp"
struct nodeDSLKD {
    SinhVien sv;
    nodeDSLKD* next;
};

typedef nodeDSLKD node;

class dslk_don
{   
private:
    PROPERTY(nodeDSLKD*, first, First);
public:
    dslk_don();
    bool xoa_dau();
    bool xoa_sau(node* p);
    bool isEmpty(); // Kiểm tra dslk có rỗng không
    node* tim_vet_can(QString &mssv); //Tìm được thì trả về node không thì trả về null
    node* create_new_node(SinhVien &sv);
    node* them_sv(SinhVien &sv); // Trả về node vừa thêm, hoặc trả về null nếu thêm thất bại
    node* sua_sv(QString &mssv, SinhVien &sv);
    bool xoa_sv(QString &mssv); // Trả về true nếu xóa thành công và false nếu thất bại
    void buble_sort(bool(*cmp)(node &a, node &b));
    void insertion_sort(bool(*cmp)(node &a, node &b));
    // void quick_sort(); // Chỉ áp dụng mảng hoặc dslk kép
    void selection_sort(bool(*cmp)(node &a, node &b));
    // void heap_sort(); // Chỉ áp dụng mảng hoặc dslk kép
    void merge_sort(bool(*cmp)(node &a, node &b));
    bool cmp_bang_diem(node &a, node &b);
    bool cmp_bang_ten(node &a, node& b);
    bool cmp_bang_mssv(node &a, node& b);
};

#endif // DSLK_DON_H
