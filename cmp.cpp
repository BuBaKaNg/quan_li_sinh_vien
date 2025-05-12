template <typename NodeType>

bool cmp_bang_diem(NodeType* a, NodeType* b){
    return a->sv.getDiem() < b->sv.getDiem();
}

template <typename NodeType>
bool cmp_bang_ten(NodeType* a, NodeType* b){
    return a->sv.getTen() < b->sv.getTen();
}

template <typename NodeType>
bool cmp_bang_mssv(NodeType* a, NodeType* b){
    return a->sv.getMssv() < b->sv.getMssv();
}
