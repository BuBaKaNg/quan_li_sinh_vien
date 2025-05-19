/********************************************************************************
** Form generated from reading UI file 'addui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUI_H
#define UI_ADDUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addUi
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelMssv;
    QLabel *labelHo;
    QLabel *labelTen;
    QLabel *labelLop;
    QLabel *labelDiem;
    QLineEdit *lineEditMssv;
    QLineEdit *lineEditHo;
    QLineEdit *lineEditTen;
    QLineEdit *lineEditLop;
    QPushButton *pushButtonAdd;
    QDoubleSpinBox *doubleSpinBoxDiem;
    QTableWidget *tableWidget;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *addUi)
    {
        if (addUi->objectName().isEmpty())
            addUi->setObjectName("addUi");
        addUi->resize(829, 300);
        formLayoutWidget = new QWidget(addUi);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 10, 231, 221));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelMssv = new QLabel(formLayoutWidget);
        labelMssv->setObjectName("labelMssv");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelMssv);

        labelHo = new QLabel(formLayoutWidget);
        labelHo->setObjectName("labelHo");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelHo);

        labelTen = new QLabel(formLayoutWidget);
        labelTen->setObjectName("labelTen");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelTen);

        labelLop = new QLabel(formLayoutWidget);
        labelLop->setObjectName("labelLop");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelLop);

        labelDiem = new QLabel(formLayoutWidget);
        labelDiem->setObjectName("labelDiem");

        formLayout->setWidget(4, QFormLayout::LabelRole, labelDiem);

        lineEditMssv = new QLineEdit(formLayoutWidget);
        lineEditMssv->setObjectName("lineEditMssv");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditMssv);

        lineEditHo = new QLineEdit(formLayoutWidget);
        lineEditHo->setObjectName("lineEditHo");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditHo);

        lineEditTen = new QLineEdit(formLayoutWidget);
        lineEditTen->setObjectName("lineEditTen");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditTen);

        lineEditLop = new QLineEdit(formLayoutWidget);
        lineEditLop->setObjectName("lineEditLop");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditLop);

        pushButtonAdd = new QPushButton(formLayoutWidget);
        pushButtonAdd->setObjectName("pushButtonAdd");

        formLayout->setWidget(5, QFormLayout::FieldRole, pushButtonAdd);

        doubleSpinBoxDiem = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBoxDiem->setObjectName("doubleSpinBoxDiem");

        formLayout->setWidget(4, QFormLayout::FieldRole, doubleSpinBoxDiem);

        tableWidget = new QTableWidget(addUi);
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
        tableWidget->setGeometry(QRect(330, 20, 471, 211));
        pushButtonSave = new QPushButton(addUi);
        pushButtonSave->setObjectName("pushButtonSave");
        pushButtonSave->setGeometry(QRect(620, 260, 83, 29));
        pushButtonCancel = new QPushButton(addUi);
        pushButtonCancel->setObjectName("pushButtonCancel");
        pushButtonCancel->setGeometry(QRect(720, 260, 83, 29));

        retranslateUi(addUi);

        QMetaObject::connectSlotsByName(addUi);
    } // setupUi

    void retranslateUi(QWidget *addUi)
    {
        addUi->setWindowTitle(QCoreApplication::translate("addUi", "Form", nullptr));
        labelMssv->setText(QCoreApplication::translate("addUi", "MSSV", nullptr));
        labelHo->setText(QCoreApplication::translate("addUi", "H\341\273\215", nullptr));
        labelTen->setText(QCoreApplication::translate("addUi", "T\303\252n", nullptr));
        labelLop->setText(QCoreApplication::translate("addUi", "L\341\273\233p", nullptr));
        labelDiem->setText(QCoreApplication::translate("addUi", "\304\220i\341\273\203m", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("addUi", "Th\303\252m", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("addUi", "Mssv", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("addUi", "H\341\273\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("addUi", "T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("addUi", "L\341\273\233p", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("addUi", "\304\220i\341\273\203m", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("addUi", "L\306\260u", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("addUi", "H\341\273\247y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addUi: public Ui_addUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUI_H
