#ifndef ADDUI_H
#define ADDUI_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class addUi;
}

class addUi : public QWidget
{
    Q_OBJECT

public:
    explicit addUi(QSet<QString> &mssvSet, MainWindow *parent = nullptr);
    ~addUi();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonCancel_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::addUi *ui;
    QList<SinhVien> list;
    MainWindow* mainWin;  // con trỏ tới MainWindow
public:
    void insertToTable(SinhVien &sv);
    void showTableContextMenu(const QPoint &pos);
    void handleXoaSv(QString &mssv);
    bool validateThemSv(SinhVien &sv, QSet<QString> &mssvSet);
public:
    QSet<QString> mssvSet;
};

#endif // ADDUI_H
