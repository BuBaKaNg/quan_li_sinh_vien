#ifndef DSLK_KEP_H
#define DSLK_KEP_H
#include "SinhVien.h"
#include <QList>
struct node {
    SinhVien sv;
    node* prev;
    node* next;
};

class dslk_kep
{
private:
    node *first;
    node *last;
public:
    dslk_kep();
    bool isEmpty(); // Kiểm tra dslk có rỗng không
    node tim_vet_can(QString &mssv); //Tìm được thì trả về node không thì trả về null
    node create_new_node(SinhVien &sv);
    node them_sv(SinhVien &sv); // Trả về node vừa thêm, hoặc trả về null nếu thêm thất bại
    SinhVien sua_sv(QString &mssv, SinhVien &sv);
    bool xoa_sv(QString &mssv); // Trả về true nếu xóa thành công và false nếu thất bại
    //Và ngược lại trả về danh sách các sv điểm thấp nhất , ví dụ các sv có cùng điểm 4
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

#endif // DSLK_KEP_H
