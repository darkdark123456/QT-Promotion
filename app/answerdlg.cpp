#include "answerdlg.h"
#include "ui_answerdlg.h"
#include<QScreen>
answerDlg::answerDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::answerDlg)
{
    ui->setupUi(this);
    QScreen *screen=QGuiApplication::primaryScreen();
    int w=screen->size().width();
    int h=screen->size().height();
    setFixedSize(w,h);
    labelVector.push_back(ui->label_1);
    labelVector.push_back(ui->label_2);
    labelVector.push_back(ui->label_3);
    labelVector.push_back(ui->label_4);
    labelVector.push_back(ui->label_5);
    labelVector.push_back(ui->label_6);
    labelVector.push_back(ui->label_7);
    labelVector.push_back(ui->label_8);
    labelVector.push_back(ui->label_9);
    labelVector.push_back(ui->label_10);
    labelVector.push_back(ui->label_11);
}

answerDlg::~answerDlg()
{
    delete ui;
}


void answerDlg::on_btnOK_clicked()
{
    this->close();
}


void answerDlg::on_btnReturn_clicked()
{
    this->close();
}

