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
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_editStudent
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_id;
    QLineEdit *lineEdit_id;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_class;
    QLineEdit *lineEdit_class;
    QLabel *label_score;
    QLineEdit *lineEdit_score;
    QHBoxLayout *buttonLayout;
    QSpacerItem *spacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *editStudent)
    {
        if (editStudent->objectName().isEmpty())
            editStudent->setObjectName("editStudent");
        editStudent->resize(241, 195);
        verticalLayout = new QVBoxLayout(editStudent);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_id = new QLabel(editStudent);
        label_id->setObjectName("label_id");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_id);

        lineEdit_id = new QLineEdit(editStudent);
        lineEdit_id->setObjectName("lineEdit_id");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_id);

        label_name = new QLabel(editStudent);
        label_name->setObjectName("label_name");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_name);

        lineEdit_name = new QLineEdit(editStudent);
        lineEdit_name->setObjectName("lineEdit_name");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_name);

        label_class = new QLabel(editStudent);
        label_class->setObjectName("label_class");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_class);

        lineEdit_class = new QLineEdit(editStudent);
        lineEdit_class->setObjectName("lineEdit_class");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_class);

        label_score = new QLabel(editStudent);
        label_score->setObjectName("label_score");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_score);

        lineEdit_score = new QLineEdit(editStudent);
        lineEdit_score->setObjectName("lineEdit_score");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_score);


        verticalLayout->addLayout(formLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        spacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(spacer);

        btnSave = new QPushButton(editStudent);
        btnSave->setObjectName("btnSave");

        buttonLayout->addWidget(btnSave);

        btnCancel = new QPushButton(editStudent);
        btnCancel->setObjectName("btnCancel");

        buttonLayout->addWidget(btnCancel);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(editStudent);

        QMetaObject::connectSlotsByName(editStudent);
    } // setupUi

    void retranslateUi(QDialog *editStudent)
    {
        editStudent->setWindowTitle(QCoreApplication::translate("editStudent", "S\341\273\255a Sinh Vi\303\252n", nullptr));
        label_id->setText(QCoreApplication::translate("editStudent", "M\303\243 sinh vi\303\252n:", nullptr));
        label_name->setText(QCoreApplication::translate("editStudent", "H\341\273\215 t\303\252n:", nullptr));
        label_class->setText(QCoreApplication::translate("editStudent", "L\341\273\233p:", nullptr));
        label_score->setText(QCoreApplication::translate("editStudent", "\304\220i\341\273\203m:", nullptr));
        btnSave->setText(QCoreApplication::translate("editStudent", "S\341\273\255a", nullptr));
        btnCancel->setText(QCoreApplication::translate("editStudent", "H\341\273\247y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editStudent: public Ui_editStudent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
