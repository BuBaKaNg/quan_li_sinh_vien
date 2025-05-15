#include "dslk_don.h"
#include <QString>


dslk_don::dslk_don() {
    first = nullptr;
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

dslk_don::node* dslk_don::create_new_node(SinhVien &sv) {
    node* p = new node();
    p->next = nullptr;
    p->sv = sv;
    return p;
}

dslk_don::node* dslk_don::tim_vet_can(QString &mssv){
    node* p;
    for (p = first;  p  != nullptr ; p=p->next )
        if ( p->sv.getMssv() == mssv  ) return p;
    return nullptr;
}

dslk_don::node* dslk_don::them_sv(SinhVien &sv){
    node *p = create_new_node(sv);
    p->next = first;
    first = p;
    qDebug() << p;
    return p;
}

dslk_don::node* dslk_don::sua_sv(QString &mssv, SinhVien &sv){
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

void dslk_don::clear() {
    node* temp = first;
    while(temp != nullptr){
        node* p = temp;
        temp = temp->next;
        delete p;
    }
    first = nullptr;
}

dslk_don::~dslk_don() {
    // nếu không cần làm gì, để trống cũng được
}

