#ifndef QUESTIONYEARDIALOG_H
#define QUESTIONYEARDIALOG_H

#include <QDialog>
#include <questiondialog.h>
namespace Ui {
class questionYearDialog;
}

class questionYearDialog : public QDialog
{
    Q_OBJECT

public:
    explicit questionYearDialog(QWidget *parent = nullptr,QString name=NULL);
    ~questionYearDialog();

private slots:
    void on_btn2010_clicked();

    void on_btn2020_clicked();

    void on_btn2021_clicked();

    void on_btn2019_clicked();

    void on_btn2018_clicked();

    void on_btn2017_clicked();

    void on_btn2016_clicked();

    void on_btn2015_clicked();

    void on_btn2014_clicked();

    void on_btn2013_clicked();

    void on_btn2012_clicked();

    void on_btn2011_clicked();

private:
    Ui::questionYearDialog *ui;
    questionDialog *questionDlg;
public:
    QString subjectName;
};

#endif // QUESTIONYEARDIALOG_H
