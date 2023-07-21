#include "widget.h"
#include "ui_widget.h"
#include <QPalette>
#include <QScreen>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QScreen *screen=QGuiApplication::primaryScreen();
    int w=screen->size().width();
    int h=screen->size().height();
    setFixedSize(w,h);

}


Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnPswdLoginIn_clicked()
{
   userLoginDialog=new loginDialog(this);  
   userLoginDialog->show();
//    subjectSelectDialog=new Dialog(this);
//    subjectSelectDialog->show();
}


void Widget::on_btnRegister_clicked()
{
    userDataDialog=new userDataDlg(this);
    userDataDialog->show();
}


void Widget::on_SMSCodeButton_clicked(){

}

