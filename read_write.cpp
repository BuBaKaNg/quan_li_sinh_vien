#include <cstdlib>
#include <QString>
#include <sinhvien.h>
#include <QChar>
#include <QIODevice>
#include <QFile>
#include "read_write.h"
#include "DanhSach.h"
#include "dslk_don.h"
#include <QMessageBox>
// #include "dslk_vong.h"
// #include "dslk_kep.h"
using namespace std;



SinhVien process_substring(const QString& s) {
    SinhVien x;

    QStringList parts = s.split(';');

    QString msv = parts.value(0).trimmed();
    QString ho = parts.value(1).trimmed();
    QString ten = parts.value(2).trimmed();
    QString lop = parts.value(3).trimmed();
    QString diemStr = parts.value(4).trimmed();

    diemStr.replace(",", ".");  // đổi dấu phẩy thành chấm (nếu có)

    x.setMssv(msv);
    x.setHo(ho);
    x.setTen(ten);
    x.setLop(lop);
    bool ok;
    qreal diem = diemStr.toDouble(&ok);
    diem = ok ? diem : -1.0;
    x.setDiem(diem);
    return x;
}

bool check_msv(QString msv){
    for (QChar c : msv){
        if (c == ' ') return false;
    }
    return true;
}

bool check_lop(QString lop){
    for (QChar c : lop){
        if (c == ' ') return false;
    }
    return true;
}

bool check_data_null(SinhVien x){
    if (x.getDiem() < 0 || x.getHo().length() == 0 || x.getLop().length() == 0 || x.getMssv().length() == 0 || x.getTen().length() == 0)
        return false;
    return true;
}

template<typename ListType>
QStringList loadDuLieu(const QString& filePath, ListType& danhSach) {
    QStringList errors;
    QSet<QString> mssvSet;
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        errors << "Không thể mở file: " + file.errorString();
        return errors;
    }

    QTextStream in(&file);
    int lineNumber = 0;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        lineNumber++;

        if (lineNumber == 1) continue; // Bỏ dòng tiêu đề
        if (line.isEmpty()) continue;

        SinhVien sv = process_substring(line);
        bool hasError = false;

        if (!check_msv(sv.getMssv())) {
            errors << QString("Dòng %1: Mã sinh viên chứa ký tự trắng hoặc không hợp lệ!").arg(lineNumber);
            hasError = true;
        }

        if (!check_lop(sv.getLop())) {
            errors << QString("Dòng %1: Lớp chứa ký tự trắng hoặc không hợp lệ!").arg(lineNumber);
            hasError = true;
        }

        if (!check_data_null(sv)) {
            errors << QString("Dòng %1: Thiếu thông tin bắt buộc!").arg(lineNumber);
            hasError = true;
        }

        if (mssvSet.contains(sv.getMssv())) {
            errors << QString("Dòng %1: Trùng mã sinh viên: %2").arg(lineNumber).arg(sv.getMssv());
            hasError = true;
        }

        if (!hasError) {
            mssvSet.insert(sv.getMssv());
            danhSach.them_sv(sv);
        }

    }

    return errors;
}

