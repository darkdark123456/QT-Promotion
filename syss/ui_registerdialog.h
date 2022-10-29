/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerDialog
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *nameText02;
    QLabel *name02;
    QLabel *age02;
    QLineEdit *ageText02;
    QComboBox *boxSex02;
    QLabel *sex02;
    QComboBox *boxDepartment02;
    QLabel *department02;
    QLabel *id;
    QLineEdit *idText;
    QToolButton *btnOK02;
    QToolButton *btnCancel02;

    void setupUi(QDialog *registerDialog)
    {
        if (registerDialog->objectName().isEmpty())
            registerDialog->setObjectName(QString::fromUtf8("registerDialog"));
        registerDialog->resize(657, 655);
        registerDialog->setStyleSheet(QString::fromUtf8("#registerDialog{background-image: url(:/backGround.png);}"));
        formLayoutWidget = new QWidget(registerDialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(380, 60, 211, 171));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        nameText02 = new QLineEdit(formLayoutWidget);
        nameText02->setObjectName(QString::fromUtf8("nameText02"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameText02);

        name02 = new QLabel(formLayoutWidget);
        name02->setObjectName(QString::fromUtf8("name02"));
        QFont font;
        font.setPointSize(15);
        name02->setFont(font);
        name02->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, name02);

        age02 = new QLabel(formLayoutWidget);
        age02->setObjectName(QString::fromUtf8("age02"));
        age02->setFont(font);
        age02->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        formLayout->setWidget(2, QFormLayout::LabelRole, age02);

        ageText02 = new QLineEdit(formLayoutWidget);
        ageText02->setObjectName(QString::fromUtf8("ageText02"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ageText02);

        boxSex02 = new QComboBox(formLayoutWidget);
        boxSex02->addItem(QString());
        boxSex02->addItem(QString());
        boxSex02->setObjectName(QString::fromUtf8("boxSex02"));

        formLayout->setWidget(3, QFormLayout::FieldRole, boxSex02);

        sex02 = new QLabel(formLayoutWidget);
        sex02->setObjectName(QString::fromUtf8("sex02"));
        sex02->setFont(font);
        sex02->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        formLayout->setWidget(3, QFormLayout::LabelRole, sex02);

        boxDepartment02 = new QComboBox(formLayoutWidget);
        boxDepartment02->addItem(QString());
        boxDepartment02->addItem(QString());
        boxDepartment02->addItem(QString());
        boxDepartment02->addItem(QString());
        boxDepartment02->addItem(QString());
        boxDepartment02->setObjectName(QString::fromUtf8("boxDepartment02"));

        formLayout->setWidget(4, QFormLayout::FieldRole, boxDepartment02);

        department02 = new QLabel(formLayoutWidget);
        department02->setObjectName(QString::fromUtf8("department02"));
        department02->setFont(font);
        department02->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        formLayout->setWidget(4, QFormLayout::LabelRole, department02);

        id = new QLabel(formLayoutWidget);
        id->setObjectName(QString::fromUtf8("id"));
        QFont font1;
        font1.setPointSize(13);
        id->setFont(font1);
        id->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, id);

        idText = new QLineEdit(formLayoutWidget);
        idText->setObjectName(QString::fromUtf8("idText"));

        formLayout->setWidget(1, QFormLayout::FieldRole, idText);

        btnOK02 = new QToolButton(registerDialog);
        btnOK02->setObjectName(QString::fromUtf8("btnOK02"));
        btnOK02->setGeometry(QRect(410, 310, 61, 31));
        btnOK02->setFont(font1);
        btnOK02->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        btnCancel02 = new QToolButton(registerDialog);
        btnCancel02->setObjectName(QString::fromUtf8("btnCancel02"));
        btnCancel02->setGeometry(QRect(520, 310, 71, 31));
        btnCancel02->setFont(font1);
        btnCancel02->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));

        retranslateUi(registerDialog);

        QMetaObject::connectSlotsByName(registerDialog);
    } // setupUi

    void retranslateUi(QDialog *registerDialog)
    {
        registerDialog->setWindowTitle(QApplication::translate("registerDialog", "Dialog", nullptr));
        name02->setText(QApplication::translate("registerDialog", "\345\247\223\345\220\215", nullptr));
        age02->setText(QApplication::translate("registerDialog", "\345\271\264\351\276\204", nullptr));
        boxSex02->setItemText(0, QApplication::translate("registerDialog", "\347\224\267", nullptr));
        boxSex02->setItemText(1, QApplication::translate("registerDialog", "\345\245\263", nullptr));

        sex02->setText(QApplication::translate("registerDialog", "\346\200\247\345\210\253", nullptr));
        boxDepartment02->setItemText(0, QApplication::translate("registerDialog", "\344\272\272\345\212\233\350\265\204\346\272\220\351\203\250", nullptr));
        boxDepartment02->setItemText(1, QApplication::translate("registerDialog", "\346\212\200\346\234\257\351\203\250", nullptr));
        boxDepartment02->setItemText(2, QApplication::translate("registerDialog", "\351\224\200\345\224\256\351\203\250", nullptr));
        boxDepartment02->setItemText(3, QApplication::translate("registerDialog", "\347\240\224\345\217\221\351\203\250", nullptr));
        boxDepartment02->setItemText(4, QApplication::translate("registerDialog", "\345\224\256\345\220\216", nullptr));

        department02->setText(QApplication::translate("registerDialog", "\351\203\250\351\227\250", nullptr));
        id->setText(QApplication::translate("registerDialog", "ID", nullptr));
        btnOK02->setText(QApplication::translate("registerDialog", "\347\241\256\345\256\232", nullptr));
        btnCancel02->setText(QApplication::translate("registerDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerDialog: public Ui_registerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
