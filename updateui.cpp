#include "updateui.h"
#include "ui_updateui.h"



updateui::updateui(SinhVien &sv, QSet<QString> &mssvSet, MainWindow *parent)
    : mainWin(parent)
    , ui(new Ui::updateui), sv(sv), mssvSet(mssvSet)
{
    ui->setupUi(this);

    ui->lineEditMssv->setText(sv.mssv);
    ui->lineEditHo->setText(sv.ho);
    ui->lineEditTen->setText(sv.ten);
    ui->lineEditLop->setText(sv.lop);
    ui->doubleSpinBoxDiem->setValue(sv.diem);
    ui->doubleSpinBoxDiem->setMinimum(0);
    ui->doubleSpinBoxDiem->setMaximum(10);

}

updateui::~updateui()
{
    delete ui;
}

void updateui::on_pushButtonCancel_clicked()
{
    this->close();
}


void updateui::on_pushButtonSave_clicked()
{
    QString mssv = ui->lineEditMssv->text();
    QString ho = ui->lineEditHo->text();
    QString ten = ui->lineEditTen->text();
    QString lop = ui->lineEditLop->text();
    qreal diem = ui->doubleSpinBoxDiem->value();
    SinhVien newSv = SinhVien(mssv, ho, ten, lop, diem);
    switch(mainWin->selectedIndex){
    case 0:
        break;
    case 1:
        mainWin->ds_mang.sua_sv(mssv, newSv);
        break;
    case 2:
        mainWin->ds_don.sua_sv(mssv, newSv);
        break;
    case 3:
        mainWin->ds_kep.sua_sv(mssv, newSv);
        break;
    case 4:
        mainWin->ds_vong.sua_sv(mssv, newSv);
        break;
    default:
        break;
    }
    if(mssv != newSv.mssv){
        mssvSet.remove(mssv);
        mssvSet.insert(newSv.mssv);
    }
    mainWin->updateTable();
    this->close();
}

