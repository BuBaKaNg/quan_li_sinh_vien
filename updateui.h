#ifndef UPDATEUI_H
#define UPDATEUI_H

#include <QWidget>
#include "SinhVien.h"
#include "mainwindow.h"
namespace Ui {
class updateui;
}

class updateui : public QWidget
{
    Q_OBJECT

public:
    updateui(SinhVien& sv,QSet<QString> &mssvSet, MainWindow *parent = nullptr) ;

    ~updateui();

private slots:
    void on_pushButtonCancel_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::updateui* ui;
    MainWindow* mainWin;
    SinhVien sv;
    QSet<QString> mssvSet;
};

#endif // UPDATEUI_H
