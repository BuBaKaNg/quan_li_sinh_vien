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

    qreal tinh_tb(NodeType* first, bool isVong = false) {
        if (!first) return -1.0;

        NodeType* p = first;
        qreal tong = 0.0;
        int dem = 0;

        do {
            tong += p->sv.getDiem();  // hoặc p->sv.diem nếu bạn dùng public field
            ++dem;
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

    void buble_sort(NodeType *first, bool isVong = false, bool(*cmp)(NodeType* a, NodeType *b) = cmp_bang_mssv) {
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

    void selection_sort(NodeType* first, bool isVong = false, bool(*cmp)(NodeType* a, NodeType* b) = cmp_bang_mssv) {
        if (!first || !first->next) return;

        NodeType* start = first;
        bool done = false;

        NodeType* i = first;
        while (i && !(isVong && done)) {
            NodeType* minNode = i;
            NodeType* j = i->next;

            // Với danh sách vòng, dừng khi quay lại đầu
            while (j && (!isVong || j != start)) {
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

    NodeType* sortedInsert(NodeType* sorted, NodeType* newNode, bool(*cmp)(NodeType* a, NodeType* b) = cmp_bang_mssv) {
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

        // Nếu là danh sách vòng: ngắt vòng trước
        if (isVong) {
            NodeType* tail = first;
            while (tail->next != first) {
                tail = tail->next;
            }
            tail->next = nullptr; // Ngắt vòng
        }

        NodeType* sorted = nullptr;
        NodeType* current = first;

        while (current != nullptr) {
            NodeType* next = current->next;
            current->next = nullptr;
            sorted = sortedInsert(sorted, current, cmp);
            current = next;
        }

        // Khôi phục danh sách vòng nếu cần
        if (isVong && sorted) {
            NodeType* tail = sorted;
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = sorted;  // Nối lại vòng
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
            case 3:
                return cmp_bang_ho;
            case 4:
                return cmp_bang_lop;
        }
    }

    NodeType* tim_kiem_linear(NodeType* first, bool isVong = false, bool(*cmp)(NodeType* a, NodeType* b) = cmp_bang_mssv){

    }
};

#endif // HELPER_H
