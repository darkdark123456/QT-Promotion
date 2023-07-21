/********************************************************************************
** Form generated from reading UI file 'questiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONDIALOG_H
#define UI_QUESTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_questionDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *questionWidget;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QLabel *imageLabel;
    QToolButton *btnNextQuestion;
    QToolButton *btnHandOn;
    QWidget *answerWidget;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *btnA;
    QRadioButton *btnB;
    QRadioButton *btnC;
    QRadioButton *btnD;

    void setupUi(QDialog *questionDialog)
    {
        if (questionDialog->objectName().isEmpty())
            questionDialog->setObjectName(QString::fromUtf8("questionDialog"));
        questionDialog->resize(414, 896);
        QFont font;
        font.setKerning(false);
        questionDialog->setFont(font);
        questionDialog->setLayoutDirection(Qt::RightToLeft);
        questionDialog->setStyleSheet(QString::fromUtf8("#questionDialog{border-image: url(:/r5.jpg);}\n"
""));
        verticalLayout_4 = new QVBoxLayout(questionDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(5, 5, 5, 50);
        questionWidget = new QWidget(questionDialog);
        questionWidget->setObjectName(QString::fromUtf8("questionWidget"));
        questionWidget->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        verticalLayout_2 = new QVBoxLayout(questionWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textEdit = new QTextEdit(questionWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        textEdit->setFont(font1);
        textEdit->setLayoutDirection(Qt::LeftToRight);
        textEdit->setAutoFillBackground(false);
        textEdit->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        textEdit->setReadOnly(true);

        verticalLayout_2->addWidget(textEdit);

        imageLabel = new QLabel(questionWidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setEnabled(true);
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        imageLabel->setFont(font2);
        imageLabel->setLayoutDirection(Qt::LeftToRight);
        imageLabel->setAutoFillBackground(false);
        imageLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        imageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(imageLabel);

        btnNextQuestion = new QToolButton(questionWidget);
        btnNextQuestion->setObjectName(QString::fromUtf8("btnNextQuestion"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Courier New"));
        font3.setPointSize(13);
        btnNextQuestion->setFont(font3);
        btnNextQuestion->setLayoutDirection(Qt::RightToLeft);
        btnNextQuestion->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        verticalLayout_2->addWidget(btnNextQuestion);

        btnHandOn = new QToolButton(questionWidget);
        btnHandOn->setObjectName(QString::fromUtf8("btnHandOn"));
        btnHandOn->setEnabled(true);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Courier New"));
        font4.setPointSize(13);
        font4.setKerning(false);
        btnHandOn->setFont(font4);
        btnHandOn->setLayoutDirection(Qt::RightToLeft);
        btnHandOn->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        verticalLayout_2->addWidget(btnHandOn);


        verticalLayout_4->addWidget(questionWidget);

        answerWidget = new QWidget(questionDialog);
        answerWidget->setObjectName(QString::fromUtf8("answerWidget"));
        answerWidget->setLayoutDirection(Qt::LeftToRight);
        answerWidget->setAutoFillBackground(false);
        answerWidget->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        verticalLayout_3 = new QVBoxLayout(answerWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, -1, 220);
        btnA = new QRadioButton(answerWidget);
        btnA->setObjectName(QString::fromUtf8("btnA"));
        QFont font5;
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setWeight(75);
        btnA->setFont(font5);
        btnA->setStyleSheet(QString::fromUtf8("QRadioButton::indicator:unchecked {\n"
"	background-color: rgb(170, 170, 255);\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"	\n"
"	\n"
"	background-color: rgb(255, 85, 0);\n"
"}"));
        btnA->setCheckable(true);
        btnA->setChecked(false);

        verticalLayout_3->addWidget(btnA);

        btnB = new QRadioButton(answerWidget);
        btnB->setObjectName(QString::fromUtf8("btnB"));
        btnB->setFont(font5);
        btnB->setAutoFillBackground(false);
        btnB->setStyleSheet(QString::fromUtf8("QRadioButton::indicator:unchecked {\n"
"	background-color: rgb(170, 170, 255);\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"	background-color: rgb(255, 85, 0);\n"
"}"));
        btnB->setCheckable(true);
        btnB->setChecked(false);

        verticalLayout_3->addWidget(btnB);

        btnC = new QRadioButton(answerWidget);
        btnC->setObjectName(QString::fromUtf8("btnC"));
        btnC->setFont(font5);
        btnC->setStyleSheet(QString::fromUtf8("QRadioButton::indicator:unchecked {\n"
"	background-color: rgb(170, 170, 255);\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"	background-color: rgb(255, 85, 0);\n"
"}"));
        btnC->setCheckable(true);

        verticalLayout_3->addWidget(btnC);

        btnD = new QRadioButton(answerWidget);
        btnD->setObjectName(QString::fromUtf8("btnD"));
        btnD->setEnabled(true);
        btnD->setFont(font5);
        btnD->setAutoFillBackground(false);
        btnD->setStyleSheet(QString::fromUtf8("QRadioButton::indicator:unchecked {\n"
"	background-color: rgb(170, 170, 255);\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"	background-color: rgb(255, 85, 0);\n"
"}"));
        btnD->setCheckable(true);

        verticalLayout_3->addWidget(btnD);


        verticalLayout_4->addWidget(answerWidget);


        retranslateUi(questionDialog);

        QMetaObject::connectSlotsByName(questionDialog);
    } // setupUi

    void retranslateUi(QDialog *questionDialog)
    {
        questionDialog->setWindowTitle(QApplication::translate("questionDialog", "Dialog", nullptr));
        imageLabel->setText(QString());
        btnNextQuestion->setText(QApplication::translate("questionDialog", "\344\270\213\344\270\200\351\242\230", nullptr));
        btnHandOn->setText(QApplication::translate("questionDialog", "\344\272\244  \345\215\267", nullptr));
        btnA->setText(QApplication::translate("questionDialog", "A", nullptr));
        btnB->setText(QApplication::translate("questionDialog", "B", nullptr));
        btnC->setText(QApplication::translate("questionDialog", "C", nullptr));
        btnD->setText(QApplication::translate("questionDialog", "D", nullptr));
    } // retranslateUi

};

namespace Ui {
    class questionDialog: public Ui_questionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONDIALOG_H
