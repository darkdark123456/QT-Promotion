/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btnDataStruct;
    QPushButton *btnComputerComposition;
    QPushButton *btnOS;
    QPushButton *btnNET;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(414, 896);
        Dialog->setStyleSheet(QString::fromUtf8("#Dialog{border-image: url(:/r1.png);}"));
        verticalLayout_2 = new QVBoxLayout(Dialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(29);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        btnDataStruct = new QPushButton(Dialog);
        btnDataStruct->setObjectName(QString::fromUtf8("btnDataStruct"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setBold(true);
        font.setWeight(75);
        btnDataStruct->setFont(font);
        btnDataStruct->setAutoFillBackground(false);
        btnDataStruct->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);\n"
"color: rgb(255, 0, 0);"));

        verticalLayout->addWidget(btnDataStruct);

        btnComputerComposition = new QPushButton(Dialog);
        btnComputerComposition->setObjectName(QString::fromUtf8("btnComputerComposition"));
        btnComputerComposition->setFont(font);
        btnComputerComposition->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);\n"
"\n"
"color: rgb(85, 170, 0);"));

        verticalLayout->addWidget(btnComputerComposition);

        btnOS = new QPushButton(Dialog);
        btnOS->setObjectName(QString::fromUtf8("btnOS"));
        btnOS->setFont(font);
        btnOS->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);\n"
"\n"
"color: rgb(170, 85, 255);"));

        verticalLayout->addWidget(btnOS);

        btnNET = new QPushButton(Dialog);
        btnNET->setObjectName(QString::fromUtf8("btnNET"));
        btnNET->setFont(font);
        btnNET->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 127);\n"
"color: rgb(0, 170, 255);"));
        btnNET->setAutoDefault(true);

        verticalLayout->addWidget(btnNET);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        btnDataStruct->setText(QApplication::translate("Dialog", "\346\225\260\346\215\256\347\273\223\346\236\204", nullptr));
        btnComputerComposition->setText(QApplication::translate("Dialog", "\350\256\241\347\256\227\346\234\272\347\273\204\346\210\220\345\216\237\347\220\206", nullptr));
        btnOS->setText(QApplication::translate("Dialog", "\346\223\215\344\275\234\347\263\273\347\273\237", nullptr));
        btnNET->setText(QApplication::translate("Dialog", "\350\256\241\347\256\227\346\234\272\347\275\221\347\273\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
