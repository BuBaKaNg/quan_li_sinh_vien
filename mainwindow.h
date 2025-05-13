#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "getter_setter_auto.cpp"

#include <QList>
#include <QMainWindow>
#include "DanhSach.h"
#include "dslk_don.h"
#include "helper.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    PROPERTY(int ,selectedIndex, SelectedIndex);
    PROPERTY(int , sortIndex, SortIndex);
    PROPERTY(QString, path, Path);
    PROPERTY(bool, isImport, IsImport);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_importBtn_clicked();


    void on_exitBtn_clicked();

    void on_downloadBtn_clicked();

    void initDs();

    void initData();

    void handleBubbleSort();


    void on_sortBtn_clicked();

    void on_caculateBtn_clicked();

    void on_comboBoxSort_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    dslk_don ds_don;
    // dslk_kep ds_kep;
    // dslk_vong ds_vong;
};
#endif // MAINWINDOW_H
