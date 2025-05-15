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


template <typename NodeType>
bool src_bang_diem(NodeType* a, NodeType* b){
    return a->sv.getDiem() == b->sv.getDiem();
}

template <typename NodeType>
bool src_bang_ten(NodeType* a, NodeType* b){
    return a->sv.getTen() == b->sv.getTen();
}

template <typename NodeType>
bool src_bang_mssv(NodeType* a, NodeType* b){
    return a->sv.getMssv() == b->sv.getMssv();
}

template <typename NodeType>
bool src_bang_ho(NodeType* a, NodeType* b){
    return a->sv.getHo() == b->sv.getHo();
}

template <typename NodeType>
bool src_bang_lop(NodeType* a, NodeType* b){
    return a->sv.getLop() == b->sv.getLop();
}



