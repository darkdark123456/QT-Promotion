/********************************************************************************
** Form generated from reading UI file 'questionyeardialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONYEARDIALOG_H
#define UI_QUESTIONYEARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_questionYearDialog
{
public:
    QGridLayout *gridLayout;
    QToolButton *btn2014;
    QToolButton *btn2016;
    QToolButton *btn2018;
    QToolButton *btn2020;
    QToolButton *btn2011;
    QToolButton *btn2012;
    QToolButton *btn2021;
    QToolButton *btn2010;
    QToolButton *btn2015;
    QToolButton *btn2013;
    QToolButton *btn2019;
    QToolButton *btn2017;

    void setupUi(QDialog *questionYearDialog)
    {
        if (questionYearDialog->objectName().isEmpty())
            questionYearDialog->setObjectName(QString::fromUtf8("questionYearDialog"));
        questionYearDialog->setWindowModality(Qt::ApplicationModal);
        questionYearDialog->resize(419, 896);
        QFont font;
        font.setPointSize(12);
        questionYearDialog->setFont(font);
        questionYearDialog->setStyleSheet(QString::fromUtf8("#questionYearDialog{border-image: url(:/r4.jpg);}\n"
""));
        questionYearDialog->setSizeGripEnabled(true);
        questionYearDialog->setModal(true);
        gridLayout = new QGridLayout(questionYearDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn2014 = new QToolButton(questionYearDialog);
        btn2014->setObjectName(QString::fromUtf8("btn2014"));
        btn2014->setFont(font);
        btn2014->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        gridLayout->addWidget(btn2014, 1, 2, 1, 1);

        btn2016 = new QToolButton(questionYearDialog);
        btn2016->setObjectName(QString::fromUtf8("btn2016"));
        btn2016->setFont(font);
        btn2016->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        gridLayout->addWidget(btn2016, 2, 0, 1, 1);

        btn2018 = new QToolButton(questionYearDialog);
        btn2018->setObjectName(QString::fromUtf8("btn2018"));
        btn2018->setFont(font);
        btn2018->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        gridLayout->addWidget(btn2018, 2, 2, 1, 1);

        btn2020 = new QToolButton(questionYearDialog);
        btn2020->setObjectName(QString::fromUtf8("btn2020"));
        btn2020->setFont(font);
        btn2020->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        gridLayout->addWidget(btn2020, 3, 1, 1, 1);

        btn2011 = new QToolButton(questionYearDialog);
        btn2011->setObjectName(QString::fromUtf8("btn2011"));
        btn2011->setFont(font);
        btn2011->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        gridLayout->addWidget(btn2011, 0, 1, 1, 1);

        btn2012 = new QToolButton(questionYearDialog);
        btn2012->setObjectName(QString::fromUtf8("btn2012"));
        btn2012->setFont(font);
        btn2012->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        gridLayout->addWidget(btn2012, 0, 2, 1, 1);

        btn2021 = new QToolButton(questionYearDialog);
        btn2021->setObjectName(QString::fromUtf8("btn2021"));
        btn2021->setFont(font);
        btn2021->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        gridLayout->addWidget(btn2021, 3, 2, 1, 1);

        btn2010 = new QToolButton(questionYearDialog);
        btn2010->setObjectName(QString::fromUtf8("btn2010"));
        btn2010->setFont(font);
        btn2010->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        gridLayout->addWidget(btn2010, 0, 0, 1, 1);

        btn2015 = new QToolButton(questionYearDialog);
        btn2015->setObjectName(QString::fromUtf8("btn2015"));
        btn2015->setFont(font);
        btn2015->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        gridLayout->addWidget(btn2015, 1, 1, 1, 1);

        btn2013 = new QToolButton(questionYearDialog);
        btn2013->setObjectName(QString::fromUtf8("btn2013"));
        btn2013->setFont(font);
        btn2013->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        gridLayout->addWidget(btn2013, 1, 0, 1, 1);

        btn2019 = new QToolButton(questionYearDialog);
        btn2019->setObjectName(QString::fromUtf8("btn2019"));
        btn2019->setFont(font);
        btn2019->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        gridLayout->addWidget(btn2019, 3, 0, 1, 1);

        btn2017 = new QToolButton(questionYearDialog);
        btn2017->setObjectName(QString::fromUtf8("btn2017"));
        btn2017->setFont(font);
        btn2017->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        gridLayout->addWidget(btn2017, 2, 1, 1, 1);


        retranslateUi(questionYearDialog);

        QMetaObject::connectSlotsByName(questionYearDialog);
    } // setupUi

    void retranslateUi(QDialog *questionYearDialog)
    {
        questionYearDialog->setWindowTitle(QApplication::translate("questionYearDialog", "Dialog", nullptr));
        btn2014->setText(QApplication::translate("questionYearDialog", "2014", nullptr));
        btn2016->setText(QApplication::translate("questionYearDialog", "2016", nullptr));
        btn2018->setText(QApplication::translate("questionYearDialog", "2018", nullptr));
        btn2020->setText(QApplication::translate("questionYearDialog", "2020", nullptr));
        btn2011->setText(QApplication::translate("questionYearDialog", "2011", nullptr));
        btn2012->setText(QApplication::translate("questionYearDialog", "2012", nullptr));
        btn2021->setText(QApplication::translate("questionYearDialog", "2021", nullptr));
        btn2010->setText(QApplication::translate("questionYearDialog", "2010", nullptr));
        btn2015->setText(QApplication::translate("questionYearDialog", "2015", nullptr));
        btn2013->setText(QApplication::translate("questionYearDialog", "2013", nullptr));
        btn2019->setText(QApplication::translate("questionYearDialog", "2019", nullptr));
        btn2017->setText(QApplication::translate("questionYearDialog", "2017", nullptr));
    } // retranslateUi

};

namespace Ui {
    class questionYearDialog: public Ui_questionYearDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONYEARDIALOG_H
