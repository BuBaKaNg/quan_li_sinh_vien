#include "mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "read_write.cpp"
#include "dslk_don.h"
#include "helper.h"
#include <QElapsedTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    selectedIndex = 0;
    path = "";
    ui->setupUi(this);
    // Set độ rộng các cột (theo chỉ số cột)
    ui->tableWidget->setColumnWidth(0, 120); // MSSV
    ui->tableWidget->setColumnWidth(1, 150); // Họ
    ui->tableWidget->setColumnWidth(2, 100); // Tên
    ui->tableWidget->setColumnWidth(3, 100); // Lớp
    ui->tableWidget->setColumnWidth(4, 80);  // Điểm
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_importBtn_clicked()
{
    // Mở hộp thoại chọn tệp
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Chọn tệp",
                                                    "",
                                                    "CSV Files (*.csv);;All Files (*.*)");

    // Kiểm tra nếu người dùng đã chọn tệp
    if (!filePath.isEmpty()) {
        // Hiển thị đường dẫn tệp
        QMessageBox::information(this, "Tệp đã chọn", "Đường dẫn tệp: " + filePath);
    }
    path = filePath;
    ui->labelFilePath->setText(filePath);
    qDebug() << path;
}





void MainWindow::on_exitBtn_clicked()
{
    this->close();

}


void MainWindow::initDs() {
    if(!ds_don.isEmpty()){
    }
}

void MainWindow::initData() {
    loadDuLieu(path, ds_don);
}

template <typename ListType>
void loadToTable(ListType& ds, QTableWidget* tableWidget) {
    tableWidget->clear();                      // Xóa nội dung cũ
    tableWidget->setRowCount(0);               // Đặt lại số hàng

    tableWidget->setHorizontalHeaderLabels(QStringList() << "Mã số sinh viên" << "Họ" << "Tên" << "Lớp" << "Điểm" << "");
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    int row = 0;

    // Duyệt danh sách (phụ thuộc cách bạn tổ chức)
    for (auto node = ds.getFirst(); node != nullptr; node = node->next) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(node->sv.getMssv()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(node->sv.getHo()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(node->sv.getTen()));
        tableWidget->setItem(row, 3, new QTableWidgetItem(node->sv.getLop()));
        tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(node->sv.getDiem())));
        tableWidget->setItem(row, 5,new QTableWidgetItem(""));

        ++row;
    }
}

void MainWindow::on_downloadBtn_clicked()
{
    selectedIndex = ui->methodBox->currentIndex();
    if(path == "" || selectedIndex == 0){
        QMessageBox::information(this, "Thông tin", "Bạn chưa chọn file hoặc chọn cách lưu trữ");
    }
    initDs();
    initData();
    QMessageBox::information(this, "Thông báo", "Bạn đã import thành công");
    loadToTable(ds_don, ui->tableWidget);
    isImport = true;
}




void MainWindow::handleBubbleSort(){
    switch (selectedIndex){
        case 0:

            break;
        case 1:
            break;
        case 2: {
            QElapsedTimer timer;
            timer.start();  // Bắt đầu đếm thời gian
            Helper<dslk_don::node, dslk_don> helper;
            helper.buble_sort(ds_don.getFirst());
            qint64 nanos = timer.nsecsElapsed();  // Thời gian đã trôi qua (ms)
            QString result;

            result = QString::number(nanos / 1'000'000.0, 'f', 3) + " ms";
            ui->timeSortView->setText(result);
            loadToTable(ds_don, ui->tableWidget);
            break;
        }
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }
}

void MainWindow::on_sortBtn_clicked()
{
    switch(sortIndex) {
    case 0:
        QMessageBox::critical(this, "Lỗi", "Vui lòng chọn phương thức sort");
        break;
    case 1:
        handleBubbleSort();
        break;
    case 2:
        // handleSelectionSort();
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
}


void MainWindow::on_caculateBtn_clicked()
{
    if(!isImport || !selectedIndex) {
        QMessageBox::critical(this,"Lỗi", "Hãy import dữ liệu trước khi tính điểm trung bình");
        return;
    }

    switch (selectedIndex){
    case 1:
        break;
    case 2: {
        Helper<dslk_don::node, dslk_don> helper;
        qreal result = helper.tinh_tb(ds_don.getFirst());
        ui->lableAverageView->setText(QString::number(result));
        break;
    }
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
}




void MainWindow::on_comboBoxSort_currentIndexChanged(int index)
{
    sortIndex = index;
}

