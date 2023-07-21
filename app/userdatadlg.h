#ifndef USERDATADLG_H
#define USERDATADLG_H

#include <QDialog>
#include <QScreen>
#include <QLineEdit>
namespace Ui {
class userDataDlg;
}

class userDataDlg : public QDialog
{
    Q_OBJECT

public:
    explicit userDataDlg(QWidget *parent = nullptr);
    ~userDataDlg();

private slots:
    void on_btnOK_clicked();

    void on_btnCancel_clicked();

private:
    Ui::userDataDlg *ui;
    QString username;
    QString passwd;
    QString registerCode;
};

#endif // USERDATADLG_H
