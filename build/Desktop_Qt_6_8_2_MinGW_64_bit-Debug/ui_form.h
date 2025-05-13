/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *mainLayout;
    QHBoxLayout *importLayout;
    QPushButton *btnImportFile;
    QLabel *labelFilePath;
    QHBoxLayout *storageMethodLayout;
    QLabel *labelStorageMethod;
    QComboBox *comboBoxStorageMethod;
    QHBoxLayout *actionLayout;
    QPushButton *btnLoadData;
    QPushButton *btnExit;
    QTableWidget *tableWidget;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(670, 505);
        mainLayout = new QVBoxLayout(MainWindow);
        mainLayout->setObjectName("mainLayout");
        importLayout = new QHBoxLayout();
        importLayout->setObjectName("importLayout");
        btnImportFile = new QPushButton(MainWindow);
        btnImportFile->setObjectName("btnImportFile");

        importLayout->addWidget(btnImportFile);

        labelFilePath = new QLabel(MainWindow);
        labelFilePath->setObjectName("labelFilePath");

        importLayout->addWidget(labelFilePath);


        mainLayout->addLayout(importLayout);

        storageMethodLayout = new QHBoxLayout();
        storageMethodLayout->setObjectName("storageMethodLayout");
        labelStorageMethod = new QLabel(MainWindow);
        labelStorageMethod->setObjectName("labelStorageMethod");

        storageMethodLayout->addWidget(labelStorageMethod);

        comboBoxStorageMethod = new QComboBox(MainWindow);
        comboBoxStorageMethod->addItem(QString());
        comboBoxStorageMethod->addItem(QString());
        comboBoxStorageMethod->addItem(QString());
        comboBoxStorageMethod->setObjectName("comboBoxStorageMethod");

        storageMethodLayout->addWidget(comboBoxStorageMethod);


        mainLayout->addLayout(storageMethodLayout);

        actionLayout = new QHBoxLayout();
        actionLayout->setObjectName("actionLayout");
        btnLoadData = new QPushButton(MainWindow);
        btnLoadData->setObjectName("btnLoadData");

        actionLayout->addWidget(btnLoadData);

        btnExit = new QPushButton(MainWindow);
        btnExit->setObjectName("btnExit");

        actionLayout->addWidget(btnExit);


        mainLayout->addLayout(actionLayout);

        tableWidget = new QTableWidget(MainWindow);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");

        mainLayout->addWidget(tableWidget);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qu\341\272\243n l\303\275 Sinh vi\303\252n", nullptr));
        btnImportFile->setText(QCoreApplication::translate("MainWindow", "Nh\341\272\255p t\341\273\207p", nullptr));
        labelFilePath->setText(QCoreApplication::translate("MainWindow", "Ch\306\260a ch\341\273\215n t\341\273\207p", nullptr));
        labelStorageMethod->setText(QCoreApplication::translate("MainWindow", "Ph\306\260\306\241ng th\341\273\251c l\306\260u tr\341\273\257:", nullptr));
        comboBoxStorageMethod->setItemText(0, QCoreApplication::translate("MainWindow", "M\341\272\243ng", nullptr));
        comboBoxStorageMethod->setItemText(1, QCoreApplication::translate("MainWindow", "Danh s\303\241ch li\303\252n k\341\272\277t \304\221\306\241n", nullptr));
        comboBoxStorageMethod->setItemText(2, QCoreApplication::translate("MainWindow", "Danh s\303\241ch li\303\252n k\341\272\277t v\303\262ng", nullptr));

        btnLoadData->setText(QCoreApplication::translate("MainWindow", "T\341\272\243i d\341\273\257 li\341\273\207u", nullptr));
        btnExit->setText(QCoreApplication::translate("MainWindow", "Tho\303\241t", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "MSSV", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "H\341\273\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "L\341\273\233p", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\304\220i\341\273\203m", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
