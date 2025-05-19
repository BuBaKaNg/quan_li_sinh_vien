/********************************************************************************
** Form generated from reading UI file 'dialogadd.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADD_H
#define UI_DIALOGADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogAdd
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelMssv;
    QLabel *labelHo;
    QLabel *labelTen;
    QLabel *labelLop;
    QLineEdit *lineEditMssv;
    QLineEdit *lineEditHo;
    QLineEdit *lineEditTen;
    QLineEdit *lineEditLop;
    QLabel *labelDiem;
    QDoubleSpinBox *doubleSpinBoxDiem;
    QPushButton *pushButtonThem;
    QPushButton *pushButton_2;

    void setupUi(QDialog *DialogAdd)
    {
        if (DialogAdd->objectName().isEmpty())
            DialogAdd->setObjectName("DialogAdd");
        DialogAdd->setEnabled(true);
        DialogAdd->resize(563, 339);
        QFont font;
        font.setKerning(true);
        DialogAdd->setFont(font);
        formLayoutWidget = new QWidget(DialogAdd);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(219, 19, 291, 221));
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

        labelDiem = new QLabel(formLayoutWidget);
        labelDiem->setObjectName("labelDiem");

        formLayout->setWidget(4, QFormLayout::LabelRole, labelDiem);

        doubleSpinBoxDiem = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBoxDiem->setObjectName("doubleSpinBoxDiem");

        formLayout->setWidget(4, QFormLayout::FieldRole, doubleSpinBoxDiem);

        pushButtonThem = new QPushButton(DialogAdd);
        pushButtonThem->setObjectName("pushButtonThem");
        pushButtonThem->setGeometry(QRect(330, 260, 83, 29));
        pushButton_2 = new QPushButton(DialogAdd);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(420, 260, 83, 29));

        retranslateUi(DialogAdd);

        QMetaObject::connectSlotsByName(DialogAdd);
    } // setupUi

    void retranslateUi(QDialog *DialogAdd)
    {
        DialogAdd->setWindowTitle(QCoreApplication::translate("DialogAdd", "Dialog", nullptr));
        labelMssv->setText(QCoreApplication::translate("DialogAdd", "MSSV :", nullptr));
        labelHo->setText(QCoreApplication::translate("DialogAdd", "H\341\273\215 :", nullptr));
        labelTen->setText(QCoreApplication::translate("DialogAdd", "T\303\252n : ", nullptr));
        labelLop->setText(QCoreApplication::translate("DialogAdd", "L\341\273\233p :", nullptr));
        labelDiem->setText(QCoreApplication::translate("DialogAdd", "\304\220i\341\273\203m :", nullptr));
        pushButtonThem->setText(QCoreApplication::translate("DialogAdd", "Th\303\252m", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DialogAdd", "H\341\273\247y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAdd: public Ui_DialogAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADD_H
