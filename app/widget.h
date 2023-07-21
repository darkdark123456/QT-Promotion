#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <dialog.h>
#include "userdatadlg.h"
#include "logindialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnPswdLoginIn_clicked();

    void on_btnRegister_clicked();

    void on_SMSCodeButton_clicked();

private:
    Ui::Widget *ui;
    Dialog *subjectSelectDialog;
    userDataDlg * userDataDialog;
    loginDialog * userLoginDialog;

};
#endif // WIDGET_H
