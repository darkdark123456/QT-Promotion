#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QtAndroid>
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>
#include "dialog.h"

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit loginDialog(QWidget *parent = nullptr);
    ~loginDialog();
private slots:
    void on_btnOK_clicked();
    void on_btnReturn_clicked();
private:
    Ui::loginDialog *ui;
    Dialog *subjectSelectDialog;
};

#endif // LOGINDIALOG_H
