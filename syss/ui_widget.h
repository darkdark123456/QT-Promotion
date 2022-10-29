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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QToolButton *userRegisterBtn;
    QPushButton *btnPunch;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *Name;
    QLabel *label_5;
    QLabel *sexName;
    QLabel *label_7;
    QLabel *ageName;
    QLabel *label_9;
    QLabel *Department;
    QLabel *ID;
    QLineEdit *idText;
    QPushButton *pushButton_2;
    QToolButton *userRegisterBtn_2;
    QLabel *photo;
    QLabel *timeLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        Widget->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 0, 311, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label->setContextMenuPolicy(Qt::DefaultContextMenu);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);\n"
""));
        userRegisterBtn = new QToolButton(Widget);
        userRegisterBtn->setObjectName(QString::fromUtf8("userRegisterBtn"));
        userRegisterBtn->setGeometry(QRect(510, 320, 241, 31));
        QFont font1;
        font1.setPointSize(12);
        userRegisterBtn->setFont(font1);
        userRegisterBtn->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(65, 182, 255);"));
        btnPunch = new QPushButton(Widget);
        btnPunch->setObjectName(QString::fromUtf8("btnPunch"));
        btnPunch->setGeometry(QRect(510, 360, 241, 31));
        btnPunch->setFont(font1);
        btnPunch->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 182, 255);"));
        formLayoutWidget = new QWidget(Widget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(510, 130, 271, 171));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setPointSize(14);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        Name = new QLabel(formLayoutWidget);
        Name->setObjectName(QString::fromUtf8("Name"));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        Name->setFont(font3);
        Name->setStyleSheet(QString::fromUtf8("background-color: rgb(202, 202, 202);\n"
""));

        formLayout->setWidget(1, QFormLayout::FieldRole, Name);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        sexName = new QLabel(formLayoutWidget);
        sexName->setObjectName(QString::fromUtf8("sexName"));
        sexName->setFont(font3);
        sexName->setStyleSheet(QString::fromUtf8("background-color: rgb(202, 202, 202);\n"
""));

        formLayout->setWidget(2, QFormLayout::FieldRole, sexName);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        ageName = new QLabel(formLayoutWidget);
        ageName->setObjectName(QString::fromUtf8("ageName"));
        ageName->setFont(font3);
        ageName->setStyleSheet(QString::fromUtf8("background-color: rgb(202, 202, 202);\n"
""));

        formLayout->setWidget(3, QFormLayout::FieldRole, ageName);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_9);

        Department = new QLabel(formLayoutWidget);
        Department->setObjectName(QString::fromUtf8("Department"));
        Department->setFont(font3);
        Department->setStyleSheet(QString::fromUtf8("background-color: rgb(202, 202, 202);\n"
""));

        formLayout->setWidget(4, QFormLayout::FieldRole, Department);

        ID = new QLabel(formLayoutWidget);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setFont(font1);
        ID->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, ID);

        idText = new QLineEdit(formLayoutWidget);
        idText->setObjectName(QString::fromUtf8("idText"));
        idText->setFont(font3);
        idText->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(0, QFormLayout::FieldRole, idText);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 400, 241, 31));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 182, 255);"));
        userRegisterBtn_2 = new QToolButton(Widget);
        userRegisterBtn_2->setObjectName(QString::fromUtf8("userRegisterBtn_2"));
        userRegisterBtn_2->setGeometry(QRect(510, 440, 241, 31));
        userRegisterBtn_2->setFont(font1);
        userRegisterBtn_2->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(65, 182, 255);"));
        photo = new QLabel(Widget);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setGeometry(QRect(90, 80, 300, 400));
        photo->setAutoFillBackground(true);
        timeLabel = new QLabel(Widget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(90, 500, 351, 31));
        timeLabel->setFont(font3);
        timeLabel->setLayoutDirection(Qt::LeftToRight);
        timeLabel->setAutoFillBackground(false);
        timeLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "\346\231\272 \350\203\275 \347\255\276 \345\210\260 \347\263\273 \347\273\237", nullptr));
        userRegisterBtn->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        btnPunch->setText(QApplication::translate("Widget", "\346\211\223\345\215\241", nullptr));
        label_3->setText(QApplication::translate("Widget", "\345\247\223\345\220\215", nullptr));
        Name->setText(QString());
        label_5->setText(QApplication::translate("Widget", "\346\200\247\345\210\253", nullptr));
        sexName->setText(QString());
        label_7->setText(QApplication::translate("Widget", "\345\271\264\351\276\204", nullptr));
        ageName->setText(QString());
        label_9->setText(QApplication::translate("Widget", "\346\211\200\345\261\236\351\203\250\351\227\250", nullptr));
        Department->setText(QString());
        ID->setText(QApplication::translate("Widget", "ID", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "\345\270\256\345\212\251\357\274\237", nullptr));
        userRegisterBtn_2->setText(QApplication::translate("Widget", "\346\211\253\346\217\217\344\272\214\347\273\264\347\240\201\347\231\273\345\275\225", nullptr));
        photo->setText(QString());
        timeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
