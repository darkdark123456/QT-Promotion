/********************************************************************************
** Form generated from reading UI file 'answerdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANSWERDLG_H
#define UI_ANSWERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_answerDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QToolButton *btnOK;
    QToolButton *btnReturn;

    void setupUi(QDialog *answerDlg)
    {
        if (answerDlg->objectName().isEmpty())
            answerDlg->setObjectName(QString::fromUtf8("answerDlg"));
        answerDlg->resize(423, 896);
        QFont font;
        font.setPointSize(14);
        answerDlg->setFont(font);
        answerDlg->setStyleSheet(QString::fromUtf8("#answerDlg{\n"
"border-image: url(:/r3.jpg);\n"
"}\n"
""));
        gridLayout = new QGridLayout(answerDlg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(40);
        gridLayout->setVerticalSpacing(80);
        gridLayout->setContentsMargins(0, 0, 80, 120);
        label_1 = new QLabel(answerDlg);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        label_1->setFont(font1);
        label_1->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label_1, 0, 0, 1, 1);

        label_2 = new QLabel(answerDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(answerDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(answerDlg);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        label_5 = new QLabel(answerDlg);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(answerDlg);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label_6, 1, 1, 1, 1);

        label_7 = new QLabel(answerDlg);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label_7, 1, 2, 1, 1);

        label_8 = new QLabel(answerDlg);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label_8, 1, 3, 1, 1);

        label_9 = new QLabel(answerDlg);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        label_10 = new QLabel(answerDlg);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label_10, 2, 1, 1, 1);

        label_11 = new QLabel(answerDlg);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label_11, 2, 2, 1, 1);

        btnOK = new QToolButton(answerDlg);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Courier New"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        btnOK->setFont(font2);
        btnOK->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);\n"
"color: rgb(0, 170, 255);"));

        gridLayout->addWidget(btnOK, 3, 3, 1, 1);

        btnReturn = new QToolButton(answerDlg);
        btnReturn->setObjectName(QString::fromUtf8("btnReturn"));
        btnReturn->setFont(font2);
        btnReturn->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);\n"
"color: rgb(85, 170, 255);"));

        gridLayout->addWidget(btnReturn, 3, 4, 1, 1);


        retranslateUi(answerDlg);

        QMetaObject::connectSlotsByName(answerDlg);
    } // setupUi

    void retranslateUi(QDialog *answerDlg)
    {
        answerDlg->setWindowTitle(QApplication::translate("answerDlg", "Dialog", nullptr));
        label_1->setText(QApplication::translate("answerDlg", "1", nullptr));
        label_2->setText(QApplication::translate("answerDlg", "2", nullptr));
        label_3->setText(QApplication::translate("answerDlg", "3", nullptr));
        label_4->setText(QApplication::translate("answerDlg", "4", nullptr));
        label_5->setText(QApplication::translate("answerDlg", "5", nullptr));
        label_6->setText(QApplication::translate("answerDlg", "6", nullptr));
        label_7->setText(QApplication::translate("answerDlg", "7", nullptr));
        label_8->setText(QApplication::translate("answerDlg", "8", nullptr));
        label_9->setText(QApplication::translate("answerDlg", "9", nullptr));
        label_10->setText(QApplication::translate("answerDlg", "10", nullptr));
        label_11->setText(QApplication::translate("answerDlg", "11", nullptr));
        btnOK->setText(QApplication::translate("answerDlg", "\347\241\256\345\256\232", nullptr));
        btnReturn->setText(QApplication::translate("answerDlg", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class answerDlg: public Ui_answerDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANSWERDLG_H
