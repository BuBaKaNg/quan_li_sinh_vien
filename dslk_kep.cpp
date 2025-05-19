#include "dslk_kep.h"
#include "helper.h"
using node = dslk_kep::node;

dslk_kep::dslk_kep() {
    first = nullptr;
    last = nullptr;
    length = 0;
}

bool dslk_kep::isEmpty(){

    return first == nullptr;
};

// Tạo node mớimới
node* dslk_kep::create_new_node(SinhVien& sv) {
    node* p = new node;
    p->sv = sv;
    p->prev = nullptr;
    p->next = nullptr;
    return p;
}

// Thêm sinh viênviên
node* dslk_kep::them_sv(SinhVien& sv) {
    if (tim_vet_can(sv.mssv) != nullptr)
        return nullptr;

    node* p = create_new_node(sv);
    if (isEmpty()) {
        first = last = p;
    } else {
        last->next = p;
        p->prev = last;
        last = p;
    }
    length++;
    return p;
}

node* dslk_kep::tim_vet_can(QString &msv) {
    node* p = first;
    while (p != nullptr) {
        if (p->sv.mssv == msv)
            return p;
        p = p->next;
    }
    return nullptr;
}

SinhVien dslk_kep::sua_sv(QString &msv, SinhVien& sv_moi) {
    node* p = tim_vet_can(msv);
    if (p == nullptr) {
        return {};
    }
    p->sv = sv_moi;
    return sv_moi;
}

bool dslk_kep::xoa_sv(QString& msv) {
    node* p = tim_vet_can(msv);
    if (p == nullptr) return false;

    if (p == first) first = p->next;
    if (p == last) last = p->prev;
    if (p->prev) p->prev->next = p->next;
    if (p->next) p->next->prev = p->prev;

    delete p;
    length--;
    return true;
}


bool dslk_kep::cmp_bang_diem(node* a, node* b) {
    return a->sv.diem < b->sv.diem;
}

bool dslk_kep::cmp_bang_ten(node* a, node* b) {
    return a->sv.ten < b->sv.ten;
}

bool dslk_kep::cmp_bang_mssv(node* a, node* b) {
    return a->sv.mssv < b->sv.mssv;
}
// Sắp xếp theo Bubble sortsort
void dslk_kep::bubble_sort(bool (*cmp)(node *, node *)) {

    // Nếu danh sách rỗng hoặc chỉ có một phần tử thì không cần sắp xếp
    if (isEmpty() || first == last) return;

    bool swapped;
    node* end = nullptr;

    do {
        swapped = false;
        node* p = first;

        //Duyệt qua danh sách đến phần chưa được sắp xếp
        while (p->next != end) {
            if (cmp(p->next, p)) {
                std::swap(p->sv, p->next->sv);
                swapped = true;
            }
            p = p->next;
        }
        end = p;
    } while (swapped);
}

void dslk_kep::insertion_sort(bool (*cmp)(node* a, node* b)) {
    if (isEmpty() || first == last) return;

    node* current = first->next;

    while (current != nullptr) {
        node* next = current->next;
        node* insert_pos = current->prev;

        // Di chuyển insert_pos lùi lại để tìm vị trí đúng
        while (insert_pos != nullptr && cmp(current, insert_pos)) {
            insert_pos = insert_pos->prev;
        }

        // Nếu đã ở đúng vị trí thì bỏ qua
        if (insert_pos == current->prev) {
            current = next;
            continue;
        }

        // Gỡ current ra khỏi vị trí hiện tại
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        if (current == last) last = current->prev;

        // Chèn current vào sau insert_pos
        if (insert_pos == nullptr) {
            // Chèn vào đầu danh sách
            current->next = first;
            first->prev = current;
            current->prev = nullptr;
            first = current;
        } else {
            current->next = insert_pos->next;
            if (insert_pos->next) insert_pos->next->prev = current;
            insert_pos->next = current;
            current->prev = insert_pos;

            if (insert_pos == last) last = current;
        }

        current = next;
    }
}


void dslk_kep::selection_sort(bool (*cmp)(node* a, node* b)) {
    if (isEmpty() || first == last) return;

    for (node* i = first; i != nullptr; i = i->next) {
        node* min_node = i;
        for (node* j = i->next; j != nullptr; j = j->next) { // Tìm node phù hợp (min hoặc max) trong phần còn lại
            if (cmp(j, min_node)) {
                min_node = j;
            }
        }

        // Nếu tìm được node nhỏ hơn/ lớn hơn thì hoán đổi
        if (min_node != i) {
            std::swap(i->sv, min_node->sv);
        }
    }
}

node* dslk_kep::getNodeAtIndex(int index){
    if(index < 0 || index >= length){
        return nullptr;
    }
    bool check = index > length / 2;
    if(check == 0){
        node* p = first;
        for (int i = 0; i < index; ++i) {
            p = p->next;
        }
        return p;
    }
    else {
        node* p = last;
        for (int i = 0; i < length - index - 1; ++i) {
            p = p->prev;
        }
        return p;
    }
}


int dslk_kep::search_theo_ma(node* a, node* b){
    if(a->sv.mssv == b->sv.mssv) return 0;
    if(a->sv.mssv > b->sv.mssv) return 1;
    if(a->sv.mssv < b->sv.mssv) return -1;
}

int dslk_kep::search_theo_ho(node* a, node* b){
    if(a->sv.ho == b->sv.ho) return 0;
    if(a->sv.ho > b->sv.ho) return 1;
    if(a->sv.ho < b->sv.ho) return -1;
}


int dslk_kep::search_theo_ten(node* a, node* b){
    if(a->sv.ten == b->sv.ten) return 0;
    if(a->sv.ten > b->sv.ten) return 1;
    if(a->sv.ten < b->sv.ten) return -1;
}


bool areEqual(qreal a, qreal b, qreal epsilon = 1e-3) {
    return qAbs(a - b) < epsilon;
}

int dslk_kep::search_theo_diem(node* a, node* b){
    if(areEqual(a->sv.diem, b->sv.diem)) return 0;
    if(a->sv.diem > b->sv.diem) return 1;
    if(a->sv.diem < b->sv.diem) return -1;
}


int dslk_kep::search_theo_lop(node* a, node* b){
    if(a->sv.lop == b->sv.lop) return 0;
    if(a->sv.lop > b->sv.lop) return 1;
    if(a->sv.lop < b->sv.lop) return -1;
}


QList<int> dslk_kep::binary_search(int(*cmp)(node* a, node* b), node* des){
    int l = 0;
    int r = length - 1;
    QList<int> ans;
    while(l <= r){
        int m = (l + r) >> 1;
        node* p = getNodeAtIndex(m);
        qDebug() << p->sv.diem << " " << m;
        if(cmp(p, des) == 0){
            int lindex = m - 1;
            node* temp = p;
            ans.append(m);
            while(temp->prev != nullptr && cmp(temp->prev, des) == 0){
                ans.append(lindex);
                lindex--;
                temp = temp->prev;
            }
            int rindex = m + 1;
            temp = p;
            while(temp->next != nullptr && cmp(temp->next, des) == 0){
                ans.append(rindex);
                rindex++;
                temp = temp->next;
            }
            for(auto x : ans){
                qDebug() << "index " << x;
            }
            return ans;
        }
        else if(cmp(p, des) == -1){
            l = m + 1;
        }
        else{
            r = m - 1;

        }
    }
    return ans;
}

void dslk_kep::swapNodes(node* node1, node* node2) {
    if (!node1 || !node2 || node1 == node2) return;
    std::swap(node1->sv, node2->sv);
}

void dslk_kep::heap(int n, int i, bool(*cmp)(node* a, node* b)) {
    node* root = getNodeAtIndex(i);
    int largest = i;
    int left = 2*i + 1, right = 2*i + 2;
    node* left_node = getNodeAtIndex(2*i + 1);
    node* right_node = getNodeAtIndex(2*i + 2);
    if(left < n && left_node != nullptr && cmp(getNodeAtIndex(largest), left_node)){
        largest = left;
    }
    if(right < n && right_node != nullptr && cmp(getNodeAtIndex(largest), right_node)){
        largest = right;
    }
    if(largest != i){
        swapNodes(getNodeAtIndex(largest), root);
        heap(n, largest, cmp);
    }
}

void dslk_kep::heap_sort(bool(*cmp)(node* a, node* b)) {
    for(int i = length / 2 - 1; i >= 0; i--){
        heap(length, i, cmp);
    }

    for(int i = length - 1; i >= 0; i--){
        swapNodes(getNodeAtIndex(0), getNodeAtIndex(i));
        heap(i, 0, cmp);
    }
}


int dslk_kep::partition(int low, int high, bool(*cmp)(node* a, node* b)) {
    node* pivot = getNodeAtIndex(high);
    node* j = getNodeAtIndex(low);
    node* i = getNodeAtIndex(low - 1);
    int index = low - 1;
    while(j != nullptr && j != pivot){
        if(cmp(j, pivot)){
            index++;
            if(i == nullptr){
                i = getNodeAtIndex(low);
            }
            else i = i->next;
            swapNodes(i, j);
        }
        j = j->next;
    }

    if(i == nullptr){
        i = getNodeAtIndex(low);
        swapNodes(i, pivot);
    }
    else swapNodes(i->next, pivot);
    return index + 1;
}

void dslk_kep::quick_sort(int low, int high, bool(*cmp)(node* a, node* b)){
    if(low < high){
        int p = partition(low, high, cmp);
        quick_sort(low, p - 1, cmp);
        quick_sort(p + 1, high, cmp);
    }
}

