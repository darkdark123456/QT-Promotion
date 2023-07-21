#include "questionyeardialog.h"
#include "ui_questionyeardialog.h"
#include <QScreen>


questionYearDialog::questionYearDialog(QWidget *parent,QString name) :
    QDialog(parent),
    ui(new Ui::questionYearDialog)
{   /*get you select subject name*/
    subjectName=name;
    if(subjectName=="数据结构")             {subjectName="data";}
    else if(subjectName=="计算机组成原理")   {subjectName="computerCom";}
    else if(subjectName=="操作系统")        {subjectName="os";}
    else                                   {subjectName="net";}

    ui->setupUi(this);

    QScreen *screen=QGuiApplication::primaryScreen();
    int w=screen->size().width();
    int h=screen->size().height();
    setFixedSize(w,h);
}

questionYearDialog::~questionYearDialog()
{
    delete ui;
}


/*Go to the corresponding question when the button is clicked*/
void questionYearDialog::on_btn2021_clicked()
{   QString tableName=subjectName+ui->btn2021->text();
    questionDlg =new questionDialog(this,tableName);
    questionDlg->show();
}

void questionYearDialog::on_btn2020_clicked()
{   QString tableName=subjectName+ui->btn2020->text();
    questionDlg =new questionDialog(this,tableName);
    questionDlg->show();
}

void questionYearDialog::on_btn2019_clicked()
{   QString tableName=subjectName+ui->btn2019->text();
    questionDlg =new questionDialog(this,tableName);
    questionDlg->show();
}


void questionYearDialog::on_btn2018_clicked()
{   QString tableName=subjectName+ui->btn2018->text();
    questionDlg =new questionDialog(this,tableName);
    questionDlg->show();
}


void questionYearDialog::on_btn2017_clicked()
{   QString tableName=subjectName+ui->btn2017->text();
    questionDlg =new questionDialog(this,tableName);
    questionDlg->show();
}


void questionYearDialog::on_btn2016_clicked()
{   QString tableName=subjectName+ui->btn2016->text();
    questionDlg =new questionDialog(this,tableName);
    questionDlg->show();
}


void questionYearDialog::on_btn2015_clicked()
{   QString tableName=subjectName+ui->btn2015->text();
    questionDlg =new questionDialog(this,tableName);
    questionDlg->show();
}


void questionYearDialog::on_btn2014_clicked()
{   QString tableName=subjectName+ui->btn2014->text();
    questionDlg =new questionDialog(this,tableName);
    questionDlg->show();
}


void questionYearDialog::on_btn2013_clicked()
{   QString tableName=subjectName+ui->btn2013->text();
    questionDlg =new questionDialog(this,tableName);
    questionDlg->show();
}


void questionYearDialog::on_btn2012_clicked()
{   QString tableName=subjectName+ui->btn2012->text();
    questionDlg =new questionDialog(this,tableName);
    questionDlg->show();
}


void questionYearDialog::on_btn2011_clicked()
{   QString tableName=subjectName+ui->btn2011->text();
    questionDlg =new questionDialog(this,tableName);
    questionDlg->show();
}

void questionYearDialog::on_btn2010_clicked()
{   QString tableName=subjectName+ui->btn2010->text();
    questionDlg =new questionDialog(this,tableName);
    questionDlg->show();
}
