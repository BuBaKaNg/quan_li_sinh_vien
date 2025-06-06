/********************************************************************************
** Form generated from reading UI file 'multipledelete.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLEDELETE_H
#define UI_MULTIPLEDELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_multipleDelete
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *multi_delete_btn;
    QPushButton *huy_btn;
    QPushButton *pushButton_2;

    void setupUi(QWidget *multipleDelete)
    {
        if (multipleDelete->objectName().isEmpty())
            multipleDelete->setObjectName("multipleDelete");
        multipleDelete->resize(716, 531);
        widget = new QWidget(multipleDelete);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 30, 661, 481));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        tableWidget = new QTableWidget(widget);
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

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        multi_delete_btn = new QPushButton(widget);
        multi_delete_btn->setObjectName("multi_delete_btn");

        horizontalLayout->addWidget(multi_delete_btn);

        huy_btn = new QPushButton(widget);
        huy_btn->setObjectName("huy_btn");

        horizontalLayout->addWidget(huy_btn);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(multipleDelete);

        QMetaObject::connectSlotsByName(multipleDelete);
    } // setupUi

    void retranslateUi(QWidget *multipleDelete)
    {
        multipleDelete->setWindowTitle(QCoreApplication::translate("multipleDelete", "Form", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("multipleDelete", "Nh\341\272\255p m\303\243 s\341\273\221 sinh vi\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("multipleDelete", "MSSV", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("multipleDelete", "H\341\273\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("multipleDelete", "T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("multipleDelete", "L\341\273\233p", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("multipleDelete", "\304\220i\341\273\203m", nullptr));
        multi_delete_btn->setText(QCoreApplication::translate("multipleDelete", "X\303\263a", nullptr));
        huy_btn->setText(QCoreApplication::translate("multipleDelete", "H\341\273\247y", nullptr));
        pushButton_2->setText(QCoreApplication::translate("multipleDelete", "L\306\260u", nullptr));
    } // retranslateUi

};

namespace Ui {
    class multipleDelete: public Ui_multipleDelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLEDELETE_H
