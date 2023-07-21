/********************************************************************************
** Form generated from reading UI file 'userdatadlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDATADLG_H
#define UI_USERDATADLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_userDataDlg
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelUserName;
    QLabel *labelPasswd;
    QLineEdit *textUserName;
    QLineEdit *textPasswd;
    QToolButton *btnOK;
    QToolButton *btnCancel;
    QLabel *labelConfirmPasswd;
    QLineEdit *textConfirmPasswd;
    QLabel *lableRegisterCode;
    QLineEdit *textRegisterCode;

    void setupUi(QDialog *userDataDlg)
    {
        if (userDataDlg->objectName().isEmpty())
            userDataDlg->setObjectName(QString::fromUtf8("userDataDlg"));
        userDataDlg->resize(414, 896);
        userDataDlg->setStyleSheet(QString::fromUtf8("#userDataDlg{border-image: url(:/login.jpg);}\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(userDataDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 300, -1, -1);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(8);
        formLayout->setContentsMargins(0, 340, -1, 12);
        labelUserName = new QLabel(userDataDlg);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        labelUserName->setFont(font);
        labelUserName->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelUserName);

        labelPasswd = new QLabel(userDataDlg);
        labelPasswd->setObjectName(QString::fromUtf8("labelPasswd"));
        labelPasswd->setFont(font);
        labelPasswd->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelPasswd);

        textUserName = new QLineEdit(userDataDlg);
        textUserName->setObjectName(QString::fromUtf8("textUserName"));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        textUserName->setFont(font1);
        textUserName->setMouseTracking(false);
        textUserName->setAutoFillBackground(false);
        textUserName->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 0);"));
        textUserName->setMaxLength(11);
        textUserName->setFrame(true);
        textUserName->setEchoMode(QLineEdit::Normal);
        textUserName->setReadOnly(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, textUserName);

        textPasswd = new QLineEdit(userDataDlg);
        textPasswd->setObjectName(QString::fromUtf8("textPasswd"));
        textPasswd->setFont(font1);
        textPasswd->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 0);"));
        textPasswd->setMaxLength(50);
        textPasswd->setReadOnly(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, textPasswd);

        btnOK = new QToolButton(userDataDlg);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setFont(font);
        btnOK->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"background-color: rgb(170, 170, 255);"));

        formLayout->setWidget(4, QFormLayout::LabelRole, btnOK);

        btnCancel = new QToolButton(userDataDlg);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setFont(font);
        btnCancel->setAutoFillBackground(false);
        btnCancel->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"background-color: rgb(170, 170, 255);"));

        formLayout->setWidget(4, QFormLayout::FieldRole, btnCancel);

        labelConfirmPasswd = new QLabel(userDataDlg);
        labelConfirmPasswd->setObjectName(QString::fromUtf8("labelConfirmPasswd"));
        labelConfirmPasswd->setFont(font);
        labelConfirmPasswd->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelConfirmPasswd);

        textConfirmPasswd = new QLineEdit(userDataDlg);
        textConfirmPasswd->setObjectName(QString::fromUtf8("textConfirmPasswd"));
        textConfirmPasswd->setFont(font1);
        textConfirmPasswd->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 0);"));
        textConfirmPasswd->setReadOnly(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, textConfirmPasswd);

        lableRegisterCode = new QLabel(userDataDlg);
        lableRegisterCode->setObjectName(QString::fromUtf8("lableRegisterCode"));
        lableRegisterCode->setFont(font);
        lableRegisterCode->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lableRegisterCode);

        textRegisterCode = new QLineEdit(userDataDlg);
        textRegisterCode->setObjectName(QString::fromUtf8("textRegisterCode"));
        textRegisterCode->setFont(font1);
        textRegisterCode->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 0);"));
        textRegisterCode->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, textRegisterCode);


        verticalLayout->addLayout(formLayout);


        retranslateUi(userDataDlg);

        QMetaObject::connectSlotsByName(userDataDlg);
    } // setupUi

    void retranslateUi(QDialog *userDataDlg)
    {
        userDataDlg->setWindowTitle(QApplication::translate("userDataDlg", "Dialog", nullptr));
        labelUserName->setText(QApplication::translate("userDataDlg", "\347\224\250\346\210\267\345\220\215(\346\211\213\346\234\272\345\217\267/QQ\345\217\267)", nullptr));
        labelPasswd->setText(QApplication::translate("userDataDlg", "\345\257\206\347\240\201", nullptr));
        btnOK->setText(QApplication::translate("userDataDlg", "\347\241\256\345\256\232", nullptr));
        btnCancel->setText(QApplication::translate("userDataDlg", "\350\277\224\345\233\236", nullptr));
        labelConfirmPasswd->setText(QApplication::translate("userDataDlg", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        lableRegisterCode->setText(QApplication::translate("userDataDlg", "\346\277\200\346\264\273\347\240\201", nullptr));
        textRegisterCode->setText(QApplication::translate("userDataDlg", "kRck9k1xMU3qlnkc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userDataDlg: public Ui_userDataDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDATADLG_H
