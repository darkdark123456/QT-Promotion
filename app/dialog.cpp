#include "dialog.h"
#include "ui_dialog.h"
#include <QScreen>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QScreen *screen=QGuiApplication::primaryScreen();
    int w=screen->size().width();
    int h=screen->size().height();
    setFixedSize(w,h);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnDataStruct_clicked()
{
    questionYearDlg =new questionYearDialog(this,ui->btnDataStruct->text());
    questionYearDlg->show();

}


void Dialog::on_btnComputerComposition_clicked()
{
    questionYearDlg =new questionYearDialog(this,ui->btnComputerComposition->text());
    questionYearDlg->show();
}


void Dialog::on_btnOS_clicked()
{
    questionYearDlg =new questionYearDialog(this,ui->btnOS->text());
    questionYearDlg->show();
}


void Dialog::on_btnNET_clicked()
{
    questionYearDlg=new questionYearDialog(this,ui->btnNET->text());
    questionYearDlg->show();
}

