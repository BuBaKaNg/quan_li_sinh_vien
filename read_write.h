#ifndef READ_WRITE_H
#define READ_WRITE_H
#include "sinhvien.h"

SinhVien process_substring(const QString& s);  // Chỉ khai báo
bool check_msv(QString msv);
bool check_lop(QString lop);
bool check_data_null(SinhVien x);
QList<SinhVien> loadDuLieu(const QString& filePath);
#endif // READ_WRITE_H
