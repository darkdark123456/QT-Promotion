/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *labUsername;
    QLabel *labPasswd;
    QLineEdit *textUsername;
    QLineEdit *textPasswd;
    QToolButton *btnOK;
    QToolButton *btnReturn;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QString::fromUtf8("loginDialog"));
        loginDialog->resize(414, 896);
        loginDialog->setStyleSheet(QString::fromUtf8("#loginDialog{border-image: url(:/r6.jpg);}\n"
""));
        horizontalLayout = new QHBoxLayout(loginDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(-1, 600, 0, 0);
        labUsername = new QLabel(loginDialog);
        labUsername->setObjectName(QString::fromUtf8("labUsername"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        labUsername->setFont(font);
        labUsername->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"\n"
""));

        formLayout->setWidget(0, QFormLayout::LabelRole, labUsername);

        labPasswd = new QLabel(loginDialog);
        labPasswd->setObjectName(QString::fromUtf8("labPasswd"));
        labPasswd->setFont(font);
        labPasswd->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labPasswd);

        textUsername = new QLineEdit(loginDialog);
        textUsername->setObjectName(QString::fromUtf8("textUsername"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier New"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        textUsername->setFont(font1);
        textUsername->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 0);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, textUsername);

        textPasswd = new QLineEdit(loginDialog);
        textPasswd->setObjectName(QString::fromUtf8("textPasswd"));
        textPasswd->setFont(font1);
        textPasswd->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 0);"));
        textPasswd->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, textPasswd);

        btnOK = new QToolButton(loginDialog);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setFont(font);
        btnOK->setStyleSheet(QString::fromUtf8("#btnOK{color: rgb(85, 170, 255);\n"
"background-color: rgb(170, 170, 255);\n"
"}\n"
""));

        formLayout->setWidget(2, QFormLayout::LabelRole, btnOK);

        btnReturn = new QToolButton(loginDialog);
        btnReturn->setObjectName(QString::fromUtf8("btnReturn"));
        btnReturn->setFont(font);
        btnReturn->setStyleSheet(QString::fromUtf8("#btnReturn{color: rgb(85, 170, 255);\n"
"background-color: rgb(170, 170, 255);\n"
"\n"
"}\n"
""));

        formLayout->setWidget(2, QFormLayout::FieldRole, btnReturn);


        horizontalLayout->addLayout(formLayout);


        retranslateUi(loginDialog);

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QApplication::translate("loginDialog", "Dialog", nullptr));
        labUsername->setText(QApplication::translate("loginDialog", "\347\224\250\346\210\267\345\220\215(\346\211\213\346\234\272\345\217\267/QQ)", nullptr));
        labPasswd->setText(QApplication::translate("loginDialog", "\345\257\206\347\240\201", nullptr));
        btnOK->setText(QApplication::translate("loginDialog", "\347\241\256\345\256\232", nullptr));
        btnReturn->setText(QApplication::translate("loginDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
