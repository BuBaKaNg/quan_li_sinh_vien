#ifndef DSLK_VONG_H
#define DSLK_VONG_H
#include "SinhVien.h"
#include <QList>



class dslk_vong
{
public:
    struct node {
        SinhVien sv;
        node *next;
    };
    node* first;
    node* last;
public:
    dslk_vong();
    bool isEmpty(); // Kiểm tra dslk có rỗng không
    node* tim_vet_can(QString &mssv); //Tìm được thì trả về node* không thì trả về null
    node* create_new_node(SinhVien &sv);
    node* them_sv(SinhVien &sv); // Trả về node* vừa thêm, hoặc trả về null nếu thêm thất bại
    node* sua_sv(QString &mssv, SinhVien &sv);
    bool xoa_sv(QString &mssv); // Trả về true nếu xóa thành công và false nếu thất bại
    dslk_vong liet_ke_diem_thap(); // Trả về danh sách rỗng nếu không có sinh viên
    //Và ngược lại trả về danh sách các sv điểm thấp nhất , ví dụ các sv có cùng điểm 4
    dslk_vong liet_ke_diem_cao(); // tương tự
    qreal tinh_tb(QString &lop); // Trả về -1.0 lấy độ chính xác 1 chữ số thập phân nếu thất bại, thành công thì đưa ra điểm trung bình
    void buble_sort(bool(*cmp)(node* &a, node* &b));
    void insertion_sort(bool(*cmp)(node* &a, node* &b));
    // void quick_sort(); // Chỉ áp dụng mảng hoặc dslk kép
    void selection_sort(bool(*cmp)(node* &a, node* &b));
    // void heap_sort(); // Chỉ áp dụng mảng hoặc dslk kép
    void merge_sort(bool(*cmp)(node* &a, node* &b));
    bool cmp(int choose, node* a, node* b);
    void swap_node(node* &a, node* &b);
    node*& getFirst();
};

#endif // DSLK_VONG_H
