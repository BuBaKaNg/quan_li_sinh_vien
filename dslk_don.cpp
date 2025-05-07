#include "dslk_don.h"
#include <QString>

dslk_don::dslk_don() {
    first = nullptr;
}

// Getter: trả về con trỏ first
node* dslk_don::get_first() const {
    return first;
}

// Setter: gán giá trị cho con trỏ first
void dslk_don::set_first(node* newFirst) {
    first = newFirst;
}

bool dslk_don::xoa_dau(){
    node* p;
    if (isEmpty())
        return 0;
    p = first;    // nut can xoa la nut dau
    first = p->next;
    delete p;  // hủy node p, trả vùng nhớ về lại cho memory heap
    return 1;
}

bool dslk_don::xoa_sau(node* p) {
    node* q;
    if((p == NULL) || (p->next == NULL))	     // nếu p là NULL hoặc sau p không có nút
        return 0;
    q = p->next;  // q là node cần xóa
    p->next = q->next;
    delete q;   // hủy node q , trả vùng nhớ về lại cho memory heap
    return 1;
}

bool dslk_don::isEmpty(){
    return first == nullptr;
}

node* dslk_don::create_new_node(SinhVien &sv) {
    node* p = new node();
    p->next = nullptr;
    p->sv = sv;
    return p;
}

node* dslk_don::tim_vet_can(QString &mssv){
    node* p;
    for (p = first;  p  != nullptr ; p=p->next )
        if ( p->sv.getMssv() == mssv  ) return p;
    return nullptr;
}

node* dslk_don::them_sv(SinhVien &sv){
    node *p = create_new_node(sv);
    p->next = first;
    first = p;
    return p;
}

node* dslk_don::sua_sv(QString &mssv, SinhVien &sv){
    node* p = tim_vet_can(mssv);
    if(p != nullptr){
        p->sv = sv;
        return p;
    }
    return nullptr;
}

bool dslk_don::xoa_sv(QString &mssv){
    node* p = first;
    if (first== nullptr ) return 0;
    if (first->sv.getMssv() == mssv ) {
        xoa_dau(); return 1;
    }
    for ( p=first;
         p->next!=NULL && p->next->sv.getMssv() != mssv;
         p=p->next)   ;
    if (p->next!= NULL ) {
        xoa_sau(p);  return 1;
    }
    return 0;
}

dslk_don dslk_don::liet_ke_diem_thap(){

}

dslk_don dslk_don::liet_ke_diem_cao(){
    if(isEmpty()) return {};
    qreal ma = -1;
    node* p = first;
    while(p != nullptr){
        ma = qMax(ma, p->sv.getDiem());
        p = p->next;
    }
    p = first;
    dslk_don ans;
    while(p != nullptr){
        if(ma == p->sv.getDiem()){
            ans.them_sv(p->sv);
        }
        p = p->next;
    }
    return ans;
}



