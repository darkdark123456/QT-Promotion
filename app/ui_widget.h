/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btnPswdLoginIn;
    QPushButton *SMSCodeButton;
    QPushButton *btnRegister;
    QPushButton *btnFindPaswd;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setEnabled(true);
        Widget->resize(414, 896);
        Widget->setLayoutDirection(Qt::LeftToRight);
        Widget->setAutoFillBackground(false);
        Widget->setStyleSheet(QString::fromUtf8("#Widget{background-color: rgb(170, 170, 255);}"));
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_2->setContentsMargins(0, 250, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 500, -1, 9);
        btnPswdLoginIn = new QPushButton(Widget);
        btnPswdLoginIn->setObjectName(QString::fromUtf8("btnPswdLoginIn"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setBold(true);
        font.setWeight(75);
        btnPswdLoginIn->setFont(font);
        btnPswdLoginIn->setAutoFillBackground(true);
        btnPswdLoginIn->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(0, 170, 255);\n"
""));

        verticalLayout->addWidget(btnPswdLoginIn);

        SMSCodeButton = new QPushButton(Widget);
        SMSCodeButton->setObjectName(QString::fromUtf8("SMSCodeButton"));
        SMSCodeButton->setFont(font);
        SMSCodeButton->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(0, 170, 255);\n"
""));

        verticalLayout->addWidget(SMSCodeButton);

        btnRegister = new QPushButton(Widget);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));
        btnRegister->setFont(font);
        btnRegister->setAutoFillBackground(true);
        btnRegister->setStyleSheet(QString::fromUtf8("color:rgb(0, 170, 255)"));

        verticalLayout->addWidget(btnRegister);

        btnFindPaswd = new QPushButton(Widget);
        btnFindPaswd->setObjectName(QString::fromUtf8("btnFindPaswd"));
        btnFindPaswd->setFont(font);
        btnFindPaswd->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);"));

        verticalLayout->addWidget(btnFindPaswd);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        btnPswdLoginIn->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\257\206\347\240\201\347\231\273\345\275\225", nullptr));
        SMSCodeButton->setText(QApplication::translate("Widget", "\347\237\255\344\277\241\351\252\214\350\257\201\347\240\201\347\231\273\345\275\225", nullptr));
        btnRegister->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
        btnFindPaswd->setText(QApplication::translate("Widget", "\345\277\230\350\256\260\345\257\206\347\240\201\357\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
