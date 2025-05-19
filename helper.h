#ifndef HELPER_H
#define HELPER_H
#include <QDebug>
#include "cmp.cpp"
#include "SinhVien.h"
template <typename NodeType, typename ListType>

class Helper
{
public:
    Helper(){};
    ~Helper(){};
    void in_danh_sach(NodeType* first, bool isVong = false) {
        if (!first) {
            qDebug() << "Danh sách rỗng.";
            return;
        }

        NodeType* p = first;
        do {
            p->sv.in_thong_tin();
            p = p->next;
        } while (p != nullptr && (!isVong || p != first));
    }

    qreal tinh_tb(NodeType* first, QString &lop , bool isVong = false) {
        if (!first) return -1.0;

        NodeType* p = first;
        qreal tong = 0.0;
        int dem = 0;

        do {
            if(p->sv.lop == lop){
                tong += p->sv.diem;
                dem++;
            }
            p = p->next;
        } while (p != nullptr && (!isVong || p != first));

        return dem > 0 ? tong / dem : -1.0;
    }

    ListType liet_ke_sv_diem_thap(NodeType *first, bool isVong = false){
        if(!first) return {};
        qreal mi = 11;
        NodeType* p = first;
        while(p != nullptr && (!isVong || p != first)){
            mi = qMin(mi, p->sv.getDiem());
            p = p->next;
        }
        p = first;
        ListType ans;
        while(p != nullptr && (!isVong || p != first)){
            if(mi == p->sv.getDiem()){
                ans.them_sv(p->sv);
            }
            p = p->next;
        }
        return ans;
    }

    ListType liet_ke_sv_diem_cao(NodeType *first, bool isVong = false){
        if(!first) return {};
        qreal ma = -1;
        NodeType* p = first;
        while(p != nullptr && (!isVong || p != first)){
            ma = qMax(ma, p->sv.getDiem());
            p = p->next;
        }
        p = first;
        ListType ans;
        while(p != nullptr && (!isVong || p != first)){
            if(ma == p->sv.getDiem()){
                ans.them_sv(p->sv);
            }
            p = p->next;
        }
        return ans;
    }

    void buble_sort(NodeType* &first, bool isVong = false, bool(*cmp)(NodeType* a, NodeType *b) = cmp_bang_mssv) {
        if (!first || !first->next) return; // danh sách rỗng hoặc chỉ 1 phần tử
        bool swapped;
        do {
            swapped = false;
            NodeType* current = first;

            while (current->next && (!isVong || current->next != first)) {
                NodeType* next = current->next;

                if (cmp(next, current)) { // nếu thứ tự sai
                    // Hoán đổi dữ liệu, không phải node (đơn giản hơn nhiều)
                    SinhVien temp = current->sv;
                    current->sv = next->sv;
                    next->sv = temp;
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);

    }

    void selection_sort(NodeType* &first, bool isVong = false, bool(*cmp)(NodeType* a, NodeType* b) = cmp_bang_mssv) {
        if (!first || !first->next) return;

        NodeType* start = first;
        bool done = false;

        NodeType* i = first;
        while (i != nullptr && (!isVong || !done)) {
            NodeType* minNode = i;
            NodeType* j = i->next;

            // Với danh sách vòng, dừng khi quay lại đầu
            while (j != nullptr && (!isVong || j != start)) {
                if (cmp(j, minNode)) {
                    minNode = j;
                }
                j = j->next;
            }

            // Hoán đổi dữ liệu sv giữa i và minNode
            if (minNode != i) {
                SinhVien temp = i->sv;
                i->sv = minNode->sv;
                minNode->sv = temp;
            }

            i = i->next;
            if (isVong && i == start) done = true;
        }
    }

    NodeType* sortedInsert(NodeType* &sorted, NodeType* newNode, bool(*cmp)(NodeType* a, NodeType* b) = cmp_bang_mssv) {
        if (sorted == nullptr || cmp(newNode, sorted)) {
            newNode->next = sorted;
            return newNode;
        }

        NodeType* current = sorted;
        while (current->next != nullptr && cmp(current->next, newNode)) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        return sorted;
    }

    void insertion_sort(NodeType* &first, bool isVong = false, bool(*cmp)(NodeType* a, NodeType* b) = cmp_bang_mssv) {
        if (!first || !first->next) return;

        NodeType* sorted = nullptr;
        NodeType* current = first;
        if(isVong){
            NodeType* tail = first;
            while(tail->next != first){
                tail = tail->next;
            }
            tail->next = nullptr;
        }
        while (current != nullptr) {
            qDebug() << "đang xử lí";
            current->sv.in_thong_tin();
            NodeType* next = current->next;
            current->next = nullptr;
            sorted = sortedInsert(sorted, current, cmp);
            current = next;
        }

        if(isVong){
            NodeType* tail = sorted;
            while(tail->next != nullptr){
                tail = tail->next;
            }
            tail->next = sorted;
        }

        first = sorted; // Cập nhật lại con trỏ đầu
    }

    bool (*getCmp(int index))(NodeType* a, NodeType* b){
        switch(index){
            case 0:
                return cmp_bang_mssv;
            case 1:
                return cmp_bang_ten;
            case 2:
                return cmp_bang_diem;

        }
    }



    QList<int> tim_kiem_theo_ma(NodeType* first, QString mssv, bool isVong = false){
        NodeType* temp = first;
        int cnt = 0;
        QList<int> searched;
        if(!first) return {};
        do{
            if(temp->sv.getMssv() == mssv){
                searched.append(cnt);
            }
            qDebug() << temp->sv.getMssv() << " " << mssv;
            cnt++;
            temp = temp->next;
        }while(temp != nullptr && (!isVong || temp != first));
        return searched;
    }

    QList<int> tim_kiem_theo_ten(NodeType* first, QString ten, bool isVong = false){
        NodeType* temp = first;
        int cnt = 0;
        QList<int> searched;
        if(!first) return {};
        do{
            if(temp->sv.getTen() == ten){
                searched.append(cnt);
            }
            cnt++;
            temp = temp->next;
        }while(temp != nullptr && (!isVong || temp != first));
        return searched;
    }

    QList<int> tim_kiem_theo_ho(NodeType* first, QString ho, bool isVong = false){
        NodeType* temp = first;
        int cnt = 0;
        QList<int> searched;
        if(!first) return {};
        do{
            if(temp->sv.getHo() == ho){
                searched.append(cnt);
            }
            cnt++;
            temp = temp->next;
        }while(temp != nullptr && (!isVong || temp != first));
        return searched;
    }

    QList<int> tim_kiem_theo_diem(NodeType* first, qreal diem, bool isVong = false){
        NodeType* temp = first;
        int cnt = 0;
        QList<int> searched;
        if(!first) return {};
        do{
            if(temp->sv.getDiem() == diem){
                searched.append(cnt);

            }
            cnt++;
            temp = temp->next;
        }while(temp != nullptr && (!isVong || temp != first));
        return searched;
    }


    QList<int> tim_kiem_theo_lop(NodeType* first, QString lop, bool isVong = false){
        NodeType* temp = first;
        int cnt = 0;
        QList<int> searched;
        if(!first) return {};
        do{
            if(temp->sv.getLop() == lop){
                searched.append(cnt);
            }
            cnt++;
            temp = temp->next;
        }while(temp != nullptr && (!isVong || temp != first));
        return searched;
    }

    NodeType* merge(NodeType* a, NodeType* b, bool(*cmp)(NodeType* a, NodeType* b)) {
        if (!a) return b;
        if (!b) return a;

        NodeType* result = nullptr;

        if (cmp(a, b)) {
            result = a;
            result->next = merge(a->next, b, cmp);
        } else {
            result = b;
            result->next = merge(a, b->next, cmp);
        }

        return result;
    }

    void split(NodeType* source, NodeType** frontRef, NodeType** backRef) {
        NodeType* slow = source;
        NodeType* fast = source->next;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        *frontRef = source;
        *backRef = slow->next;
        slow->next = nullptr;
    }




    void noiVong(NodeType* head){
        NodeType* tail = head;
        while (tail->next)
            tail = tail->next;
        tail->next = head;  // tạo vòng lại
    }

    void splitVong(NodeType* source, NodeType** frontRef, NodeType** backRef) {
        NodeType* slow = source;
        NodeType* fast = source->next;

        while (fast != source && fast->next != source) {
            fast = fast->next->next;
            slow = slow->next;
        }

        *frontRef = source;
        *backRef = slow->next;
        slow->next = *frontRef;     // Kết thúc danh sách trước
        NodeType* temp = *backRef;
        while (temp->next != source) {
            temp = temp->next;
        }
        temp->next = *backRef;      // Kết thúc danh sách sau
    }

    void mergeSort(NodeType** headRef, bool(*cmp)(NodeType* a, NodeType* b)) {
        NodeType* head = *headRef;
        if (!head || !head->next) return;

        NodeType *a, *b;
        split(head, &a, &b);
        mergeSort(&a, cmp);
        mergeSort(&b, cmp);

        *headRef = merge(a, b, cmp);
    }

    void mergeSortVong_last(NodeType*& last, bool(*cmp)(NodeType* a, NodeType* b)) {
        if (!last || last->next == last) return;

        NodeType* head = last->next;
        last->next = nullptr;  // Ngắt vòng

        mergeSort(&head, cmp);
        // Tìm tail mới
        NodeType* tail = head;
        while (tail->next) {
            tail = tail->next;
        }


        tail->next = head;  // Nối vòng
        last = tail;        // Cập nhật lại con trỏ last
    }
};

#endif // HELPER_H
