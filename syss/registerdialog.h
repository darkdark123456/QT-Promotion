#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QtSql>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
namespace Ui {
class registerDialog;
}

class registerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit registerDialog(QWidget *parent = nullptr);
    ~registerDialog();

private slots:
    void on_btnOK02_clicked();

    void on_btnCancel02_clicked();
public:
    void registerInfo();
    void regster();
private:
    Ui::registerDialog *ui;
    QPixmap photo;
private:
    QSqlDatabase dataBase;
    QSqlQueryModel *queryModel;
    QItemSelectionModel *selectModel;
};

#endif // REGISTERDIALOG_H
