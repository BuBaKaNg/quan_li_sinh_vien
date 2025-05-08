#ifndef HELPER_H
#define HELPER_H
#include <QDebug>
template <typename NodeType, typename ListType>
class Helper
{
public:
    Helper(){};

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
            ma = qMin(ma, p->sv.getDiem());
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
};

#endif // HELPER_H
