#include "mang.h"
#include "bits/stdc++.h"
mang::mang() {}

int mang::size(){
    return arr.size();
}

bool mang::isEmpty(){
    if (arr.size() == 0) return true;
    return false;
}

SinhVien mang::tim_vet_can(QString &mssv){
    SinhVien tmp;
    tmp.diem = -1; tmp.ho = ""; tmp.lop = ""; tmp.mssv = ""; tmp.ten = "";
    for (SinhVien x : arr){
        if (x.mssv == mssv){
            return x;
        }
    }
    return tmp;     //trả về sinh viên rỗng
}

SinhVien mang::them_sv(SinhVien &sv){
    if (tim_vet_can(sv.mssv).diem == -1){
        arr.push_back(sv);
        return sv;
    }
    return {};
}

SinhVien mang::sua_sv(QString &mssv, SinhVien &sv) {
    for(int i = 0; i < arr.size(); i++){
        if(arr[i].mssv == sv.mssv){
            arr[i] = sv;
            return arr[i];
        }
    }
    return {};
}

bool mang::xoa_sv(QString mssv){
    int idx = 0;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i].mssv == mssv){
            idx = i;
            break;
        }
    }

    for (int i = idx; i < arr.size()-1; i++){
        arr[i] = arr[i+1];
    }
    arr.pop_back();
    return true;
}

mang mang::danh_sach_diem_cao(){
    qreal high = 0;
    for (SinhVien x : arr){
        high = qMax(high, x.diem);
    }
    mang ans;
    for (SinhVien x : arr){
        if (x.diem == high){
            ans.them_sv(x);
        }
    }
    return ans;
}

mang mang::danh_sach_diem_thap(){
    qreal low = 11;
    for (SinhVien x : arr){
        low = qMin(low, x.diem);
    }
    mang ans;
    for (SinhVien x : arr){
        if (x.diem == low){
            ans.them_sv(x);
        }
    }
    return ans;
}

qreal mang::tinh_tb(QString &lop){
    float sum = 0;
    int dem = 0;
    for (SinhVien x : arr){
        if(lop == x.lop){
            sum += x.diem;
            dem++;
        }
    }
    return sum/dem;
}

bool mang::cmp(int choose, SinhVien a, SinhVien b){
    if (choose == 1){       //Sắp xếp theo điểm
        return a.mssv > b.mssv;
    }
    else{
        if (choose == 2){   // Sắp xếp theo MSV
            return a.ten > b.ten;
        }
        else return a.diem > b.diem;  // Sắp xếp theo tên
    }
}

void mang::bubble_sort(int choose){
    for (int i = 0; i < arr.size()-1; i++){
        for (int j = 0; j < arr.size()-i-1; j++){
            if (cmp(choose, arr[j], arr[j+1])) std::swap(arr[j], arr[j+1]);
        }
    }
}

void mang::selection_sort(int choose){
    for (int i = 0; i < arr.size()-1; i++){
        int idx_min = i;
        for (int j = i+1; j < arr.size(); j++){
            if (cmp(choose, arr[idx_min], arr[j])){
                idx_min = j;
            }
        }
        std::swap(arr[i], arr[idx_min]);
    }
}

void mang::insertion_sort(int choose){
    for (int i = 0; i < arr.size(); i++){
        SinhVien key = arr[i];
        int j = i-1;
        while (j >= 0 && cmp(choose, arr[j], key)){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int mang::partition(int choose, int low, int high){
    SinhVien pivot = arr[high];
    int i = low-1;
    for (int j = low; j <= high-1; j++){
        if (cmp(choose, pivot, arr[j])){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    return (i+1);
}

void mang::quick_sort(int choose, int low, int high){
    if (low < high){
        int pi = partition(choose, low, high);
        quick_sort(choose, low, pi-1);
        quick_sort(choose, pi+1, high);
    }
}

void mang::merge(int choose, int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;
    SinhVien L[n1+1], R[n2+1];
    for (int i = 0; i < n1; i++) L[i] = arr[l+i];
    for (int j = 0; j < n2; j++) R[j] = arr[m+1+j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (!cmp(choose, L[i], R[j])){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++; k++;
    }
}

void mang::merge_sort(int choose, int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        merge_sort(choose, l, m);
        merge_sort(choose, m+1, r);
        merge(choose, l, m, r);
    }
}

void mang::heap(int choose, int n, int i){
    int largest = i;
    int l = 2*i+1, r = 2*i+2;
    if (l < n && cmp(choose, arr[l], arr[largest])) largest = l;
    if (r < n && cmp(choose, arr[r], arr[largest])) largest = r;
    if (largest != i){
        std::swap(arr[i], arr[largest]);
        heap(choose, n, largest);
    }
}

void mang::heap_sort(int choose, int n){
    for (int i = n/2-1; i >= 0; i--){
        heap(choose, n, i);
    }
    for (int i = n-1; i > 0; i--){
        std::swap(arr[0], arr[i]);
        heap(choose, i, 0);
    }
}

QString mang::lower_case(QString s){
    return s.toLower();
}

QList<int> mang::tim_vet_can_ds_sv(int choose, QString tieu_chi){
    QList<int> ans;
    for (int i = 0; i < arr.size(); i++){
        if (choose == 1)    //Tìm theo mã sinh viên
            if (lower_case(arr[i].mssv) == lower_case(tieu_chi)) ans.append(i);
        if (choose == 2)    //Tìm theo tên
            if (lower_case(arr[i].ten) == lower_case(tieu_chi)) ans.append(i);
        if (choose == 3)    //Tìm theo điểm
            if (arr[i].diem == tieu_chi.toDouble()) ans.append(i);
        if (choose == 4)    //Tìm theo họ
            if (lower_case(arr[i].ho) == lower_case(tieu_chi)) ans.append(i);
        if (choose == 5)    //Tìm theo lớp
            if (lower_case(arr[i].lop) == lower_case(tieu_chi)) ans.append(i);
    }
    return ans;
}

int mang::search(int choose, SinhVien x, QString tieu_chi){
    if (choose == 1){
        if (lower_case(x.mssv) == lower_case(tieu_chi)){
            return 0;
        }
        else{
            if (lower_case(x.mssv) > lower_case(tieu_chi)) return 1;
            else return -1;
        }
    }
    if (choose == 2){
        if (lower_case(x.ten) == lower_case(tieu_chi)){
            return 0;
        }
        else{
            if (lower_case(x.ten) > lower_case(tieu_chi)) return 1;
            else return -1;
        }
    }
    if (choose == 3){
        if (x.diem == tieu_chi.toDouble()){
            return 0;
        }
        else{
            if (x.diem > tieu_chi.toDouble()) return 1;
            else return -1;
        }
    }
    if (choose == 4){
        if (lower_case(x.ho) == lower_case(tieu_chi)){
            return 0;
        }
        else{
            if (lower_case(x.ho) > lower_case(tieu_chi)) return 1;
            else return -1;
        }
    }

    if (choose == 5){
        if (lower_case(x.lop) == lower_case(tieu_chi)){
            return 0;
        }
        else{
            if (lower_case(x.lop) > lower_case(tieu_chi)) return 1;
            else return -1;
        }
    }
}

QList<int> mang::tim_kiem_nhi_phan_ds_sv(int choose, QString tieu_chi){
    QList<int> ans;
    int l = 0, r = arr.size();
    int idx = 0;
    while (l < r){
        int m = (l+r)/2;
        int res = search(choose, arr[m], tieu_chi);
        if (res == 0){
            ans.push_back(m);
            idx = m;
            break;
        }
        else{
            if (res == -1) r = m-1;
            if (res == 1) l = m+1;
        }
    }
    int i = idx+1;
    //Dò qua phải
    while (i < arr.size()){
        if (choose == 1 && lower_case(arr[i].mssv) == lower_case(tieu_chi)) ans.push_back(i);
        if (choose == 2 && lower_case(arr[i].ho) == lower_case(tieu_chi)) ans.push_back(i);
        if (choose == 3 && lower_case(arr[i].ten) == lower_case(tieu_chi)) ans.push_back(i);
        if (choose == 4 && lower_case(arr[i].lop) == lower_case(tieu_chi)) ans.push_back(i);
        if (choose == 5 && arr[i].diem == tieu_chi.toDouble()) ans.push_back(i);
        i++;
    }
    i = idx-1;
    //Dò qua trái
    while (i > -1){
        if (choose == 1 && lower_case(arr[i].mssv) == lower_case(tieu_chi)) ans.push_back(i);
        if (choose == 2 && lower_case(arr[i].ho) == lower_case(tieu_chi)) ans.push_back(i);
        if (choose == 3 && lower_case(arr[i].ten) == lower_case(tieu_chi)) ans.push_back(i);
        if (choose == 4 && lower_case(arr[i].lop) == lower_case(tieu_chi)) ans.push_back(i);
        if (choose == 5 && arr[i].diem == tieu_chi.toDouble()) ans.push_back(i);
        i--;
    }
    return ans;
}
