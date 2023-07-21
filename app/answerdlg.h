#ifndef ANSWERDLG_H
#define ANSWERDLG_H

#include <QDialog>
#include <QLabel>
namespace Ui {
class answerDlg;
}

class answerDlg : public QDialog
{
    Q_OBJECT
public:
    explicit answerDlg(QWidget *parent = nullptr);
    ~answerDlg();
private:
    Ui::answerDlg *ui;
public:
    QVector<QLabel *> labelVector;
private slots:
    void on_btnOK_clicked();
    void on_btnReturn_clicked();
};

#endif // ANSWERDLG_H
