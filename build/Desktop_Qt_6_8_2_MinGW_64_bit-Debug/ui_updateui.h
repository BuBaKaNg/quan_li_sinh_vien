/********************************************************************************
** Form generated from reading UI file 'updateui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEUI_H
#define UI_UPDATEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_updateui
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
    QDoubleSpinBox *doubleSpinBoxDiem;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonSave;

    void setupUi(QWidget *updateui)
    {
        if (updateui->objectName().isEmpty())
            updateui->setObjectName("updateui");
        updateui->resize(293, 237);
        formLayoutWidget = new QWidget(updateui);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 10, 271, 181));
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
        lineEditMssv->setEnabled(false);

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

        doubleSpinBoxDiem = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBoxDiem->setObjectName("doubleSpinBoxDiem");

        formLayout->setWidget(4, QFormLayout::FieldRole, doubleSpinBoxDiem);

        pushButtonCancel = new QPushButton(updateui);
        pushButtonCancel->setObjectName("pushButtonCancel");
        pushButtonCancel->setGeometry(QRect(100, 200, 83, 29));
        pushButtonSave = new QPushButton(updateui);
        pushButtonSave->setObjectName("pushButtonSave");
        pushButtonSave->setGeometry(QRect(190, 200, 83, 29));

        retranslateUi(updateui);

        QMetaObject::connectSlotsByName(updateui);
    } // setupUi

    void retranslateUi(QWidget *updateui)
    {
        updateui->setWindowTitle(QCoreApplication::translate("updateui", "Form", nullptr));
        labelMssv->setText(QCoreApplication::translate("updateui", "MSSV : ", nullptr));
        labelHo->setText(QCoreApplication::translate("updateui", "H\341\273\215 : ", nullptr));
        labelTen->setText(QCoreApplication::translate("updateui", "T\303\252n : ", nullptr));
        labelLop->setText(QCoreApplication::translate("updateui", "L\341\273\233p : ", nullptr));
        labelDiem->setText(QCoreApplication::translate("updateui", "\304\220i\341\273\203m : ", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("updateui", "H\341\273\247y", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("updateui", "L\306\260u", nullptr));
    } // retranslateUi

};

namespace Ui {
    class updateui: public Ui_updateui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEUI_H
