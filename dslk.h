#ifndef DSLK_H
#define DSLK_H

template<typename NodeType>

class dslk
{

public:
    void in_danh_sach(); // In danh sách sinh viên
    virtual ~dslk() {} // Destructor ảo để có thể hủy đối tượng lớp con đúng cách
};

#endif // DSLK_H
