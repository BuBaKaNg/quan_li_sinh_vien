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

bool MainWindow::initData() {

    QStringList errors = loadDuLieu(path, ds_don);

    if (!errors.isEmpty()) {
        QString errorText = "Đã xảy ra lỗi trong quá trình import:\n\n" + errors.join("\n");

        QMessageBox msgBox;
        msgBox.setWindowTitle("Lỗi Import Dữ Liệu");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Import thất bại do dữ liệu không hợp lệ.");
        msgBox.setDetailedText(errorText);  // Mở rộng để xem chi tiết
        msgBox.exec();
        return false;
    } else {
        QMessageBox::information(this, "Thành công", "Import dữ liệu thành công!");
        return true;
    }
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


    qDebug() << 1;
}

void MainWindow::on_downloadBtn_clicked()
{
    selectedIndex = ui->methodBox->currentIndex();
    if(path == "" || selectedIndex == 0){
        QMessageBox::information(this, "Thông tin", "Bạn chưa chọn file hoặc chọn cách lưu trữ");
    }
    initDs();
    bool checkData = initData();
    if(checkData){
        loadToTable(ds_don, ui->tableWidget);
        isImport = true;
    }
    else {
        ds_don.clear();
    }
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
            int standardIndex = ui->comboBoxStandarSort->currentIndex();
            auto cmp = helper.getCmp(standardIndex);
            helper.buble_sort(ds_don.getFirst(), false, cmp);
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

void MainWindow::handleInsertionSort(){
    switch (selectedIndex){
    case 0:

        break;
    case 1:
        break;
    case 2: {
        QElapsedTimer timer;
        timer.start();  // Bắt đầu đếm thời gian
        Helper<dslk_don::node, dslk_don> helper;
        int standardIndex = ui->comboBoxStandarSort->currentIndex();
        auto cmp = helper.getCmp(standardIndex);
        helper.insertion_sort(ds_don.getFirst(), false, cmp);
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


void MainWindow::handleSelectionSort(){
    switch (selectedIndex){
    case 0:

        break;
    case 1:
        break;
    case 2: {
        QElapsedTimer timer;
        timer.start();  // Bắt đầu đếm thời gian
        Helper<dslk_don::node, dslk_don> helper;
        int standardIndex = ui->comboBoxStandarSort->currentIndex();
        auto cmp = helper.getCmp(standardIndex);
        helper.selection_sort(ds_don.getFirst(), false, cmp);
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
    if(!isImport){
        QMessageBox::critical(this, "Lỗi", "Vui lòng import trước khi sắp xếp");
        return;
    }

    switch(sortIndex) {
    case 0:
        QMessageBox::critical(this, "Lỗi", "Vui lòng chọn phương thức sort");
        break;
    case 1:
        handleBubbleSort();
        break;
    case 2:
        handleSelectionSort();
        break;
    case 3:
        handleInsertionSort();
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


void MainWindow::on_listMinBtn_clicked()
{
    if(!isImport){
        QMessageBox::critical(this, "Lỗi", "Vui lòng chọn chức năng này");
        return;
    }
    switch (selectedIndex){
    case 1:
        break;
    case 2: {
        Helper<dslk_don::node, dslk_don> helper;
        dslk_don list = helper.liet_ke_sv_diem_thap(ds_don.getFirst());
        loadToTable(list, ui->tableWidget);
        ui->huyMinBtn->setEnabled(true);
        break;
    }
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
    resert();
}


void MainWindow::on_listMaxBtn_clicked()
{
    if(!isImport){
        QMessageBox::critical(this, "Lỗi", "Vui lòng chọn chức năng này");
        return;
    }

    switch (selectedIndex){
    case 1:
        break;
    case 2: {
        Helper<dslk_don::node, dslk_don> helper;
        dslk_don list = helper.liet_ke_sv_diem_cao(ds_don.getFirst());
        loadToTable(list, ui->tableWidget);
        ui->huyMaxBtn->setEnabled(true);
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


void MainWindow::on_huyMaxBtn_clicked()
{
    resert();
        loadToTable(ds_don, ui->tableWidget);

}


void MainWindow::on_huyMinBtn_clicked()
{
    resert();
    loadToTable(ds_don, ui->tableWidget);

}

template<typename ListType>
void MainWindow::handleTimKiem(ListType &list) {
    int index = ui->comboBoxSearch->currentIndex();
    switch(index){
    case 0:{
        Helper<typename ListType::node, ListType> helper;
        QString input = ui->lineEdit->text();
        QElapsedTimer timer;
        timer.start();  // Bắt đầu đếm thời gian
        QList<int> indexes = helper.tim_kiem_theo_ma(list.getFirst(),input);
        qint64 nanos = timer.nsecsElapsed();  // Thời gian đã trôi qua (ms)
        QString result;
        result = QString::number(nanos / 1'000'000.0, 'f', 3) + " ms";
        ui->timeSearchView->setText(result);
        int colums = ui->tableWidget->columnCount();
        int rows = ui->tableWidget->rowCount();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < colums; j++){
                QTableWidgetItem* item = ui->tableWidget->item(i, j);
                if (item) {
                    item->setBackground(QBrush());  // Hoặc QColor("#ffeecc")
                    item->setForeground(QBrush());   // Màu chữ
                }
            }
        }
        for(auto x : indexes){
            int columnCount = ui->tableWidget->columnCount();
            for(int i = 0; i < columnCount; i++){
                QTableWidgetItem* item = ui->tableWidget->item(x, i);
                if (item) {
                    item->setBackground(Qt::red);  // Hoặc QColor("#ffeecc")
                    item->setForeground(Qt::black);   // Màu chữ
                }
            }
        }

        break;
    }

    case 1:{
        Helper<typename ListType::node, ListType> helper;
        QString input = ui->lineEdit->text();
        QElapsedTimer timer;
        timer.start();  // Bắt đầu đếm thời gian
        QList<int> indexes = helper.tim_kiem_theo_ten(list.getFirst(),input);
        qint64 nanos = timer.nsecsElapsed();  // Thời gian đã trôi qua (ms)
        QString result;
        result = QString::number(nanos / 1'000'000.0, 'f', 3) + " ms";
        ui->timeSearchView->setText(result);
        int colums = ui->tableWidget->columnCount();
        int rows = ui->tableWidget->rowCount();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < colums; j++){
                QTableWidgetItem* item = ui->tableWidget->item(i, j);
                if (item) {
                    item->setBackground(QBrush());  // Hoặc QColor("#ffeecc")
                    item->setForeground(QBrush());   // Màu chữ
                }
            }
        }
        for(auto x : indexes){
            int columnCount = ui->tableWidget->columnCount();
            for(int i = 0; i < columnCount; i++){
                QTableWidgetItem* item = ui->tableWidget->item(x, i);
                if (item) {
                    item->setBackground(Qt::red);  // Hoặc QColor("#ffeecc")
                    item->setForeground(Qt::black);   // Màu chữ
                }
            }
        }
        break;
    }
    case 2: {
        Helper<typename ListType::node, ListType> helper;
        QString text = ui->lineEdit->text();
        double input = text.toDouble();
        QElapsedTimer timer;
        timer.start();  // Bắt đầu đếm thời gian
        QList<int> indexes = helper.tim_kiem_theo_diem(list.getFirst(),input);
        qint64 nanos = timer.nsecsElapsed();  // Thời gian đã trôi qua (ms)
        QString result;
        result = QString::number(nanos / 1'000'000.0, 'f', 3) + " ms";
        ui->timeSearchView->setText(result);
        int colums = ui->tableWidget->columnCount();
        int rows = ui->tableWidget->rowCount();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < colums; j++){
                QTableWidgetItem* item = ui->tableWidget->item(i, j);
                if (item) {
                    item->setBackground(QBrush());  // Hoặc QColor("#ffeecc")
                    item->setForeground(QBrush());   // Màu chữ
                }
            }
        }
        for(auto x : indexes){
            int columnCount = ui->tableWidget->columnCount();
            for(int i = 0; i < columnCount; i++){
                QTableWidgetItem* item = ui->tableWidget->item(x, i);
                if (item) {
                    item->setBackground(Qt::yellow);  // Hoặc QColor("#ffeecc")
                    item->setForeground(Qt::black);   // Màu chữ
                }
                item->setBackground(Qt::yellow);  // Hoặc QColor("#ffeecc")
                item->setForeground(Qt::black);   // Màu chữ
            }
        }
        break;
    }
    case 3:{
        Helper<typename ListType::node, ListType> helper;
        QString input = ui->lineEdit->text();
        QElapsedTimer timer;
        timer.start();  // Bắt đầu đếm thời gian
        QList<int> indexes = helper.tim_kiem_theo_ho(list.getFirst(),input);
        qint64 nanos = timer.nsecsElapsed();  // Thời gian đã trôi qua (ms)
        QString result;
        result = QString::number(nanos / 1'000'000.0, 'f', 3) + " ms";
        ui->timeSearchView->setText(result);
        int colums = ui->tableWidget->columnCount();
        int rows = ui->tableWidget->rowCount();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < colums; j++){
                QTableWidgetItem* item = ui->tableWidget->item(i, j);
                if (item) {
                    item->setBackground(QBrush());  // Hoặc QColor("#ffeecc")
                    item->setForeground(QBrush());   // Màu chữ
                }
            }
        }
        for(auto x : indexes){
            int columnCount = ui->tableWidget->columnCount();
            for(int i = 0; i < columnCount; i++){
                QTableWidgetItem* item = ui->tableWidget->item(x, i);
                if (item) {
                    item->setBackground(Qt::red);  // Hoặc QColor("#ffeecc")
                    item->setForeground(Qt::black);   // Màu chữ
                }
            }
        }
        break;
    }
    case 4:
    {
        Helper<typename ListType::node, ListType> helper;
        QString input = ui->lineEdit->text();
        QElapsedTimer timer;
        timer.start();  // Bắt đầu đếm thời gian
        QList<int> indexes = helper.tim_kiem_theo_lop(list.getFirst(),input);
        qint64 nanos = timer.nsecsElapsed();  // Thời gian đã trôi qua (ms)
        QString result;
        result = QString::number(nanos / 1'000'000.0, 'f', 3) + " ms";
        ui->timeSearchView->setText(result);
        int colums = ui->tableWidget->columnCount();
        int rows = ui->tableWidget->rowCount();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < colums; j++){
                QTableWidgetItem* item = ui->tableWidget->item(i, j);
                if (item) {
                    item->setBackground(QBrush());  // Hoặc QColor("#ffeecc")
                    item->setForeground(QBrush());   // Màu chữ
                }
            }
        }
        for(auto x : indexes){
            int columnCount = ui->tableWidget->columnCount();
            for(int i = 0; i < columnCount; i++){
                QTableWidgetItem* item = ui->tableWidget->item(x, i);
                if (item) {
                    item->setBackground(Qt::red);  // Hoặc QColor("#ffeecc")
                    item->setForeground(Qt::black);   // Màu chữ
                }
            }
        }
        break;
    }
    default:
        break;
    }
}


void MainWindow::on_searchBtn_clicked()
{
    if(!isImport){
        QMessageBox::critical(this, "Lỗi", "Vui lòng import trước khi tìm kiếm");
        return;
    }
    switch(selectedIndex){
        case 0:
        break;
        case 1:
            break;
        case 2: {
            handleTimKiem(ds_don);
            break;
        }
        case 3:
            break;
        default:
            break;
    }
    ui->huySearchBtn->setEnabled(true);
}

void MainWindow::resert() {
    ui->huyMaxBtn->setEnabled(false);
    ui->huyMinBtn->setEnabled(false);
    ui->huySearchBtn->setEnabled(false);

}

void MainWindow::on_huySearchBtn_clicked()
{
    loadToTable(ds_don, ui->tableWidget);
    resert();
}

