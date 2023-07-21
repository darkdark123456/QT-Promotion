#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <questionyeardialog.h>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:
    void on_btnDataStruct_clicked();
    void on_btnComputerComposition_clicked();
    void on_btnOS_clicked();
    void on_btnNET_clicked();
private:
    Ui::Dialog *ui;
    questionYearDialog *questionYearDlg;
};

#endif // DIALOG_H
