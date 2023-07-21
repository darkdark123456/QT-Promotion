#ifndef QUESTIONDIALOG_H
#define QUESTIONDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <QtAndroid>
#include <QHash>
#include <QVector>
#include <answerdlg.h>

namespace Ui {
class questionDialog;
}


class questionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit questionDialog(QWidget *parent = nullptr,QString name=NULL);
    ~questionDialog();
public:
    bool getRequestionPermission();
    bool getQuestionTextlineAndAnswer();
    void displayQuestuonText(const QString &question);
    void refreshButtonSelection();
    void contrastQuestionAnswer(QVector<QString> & vectorAnswer,QVector<QString> &vectorBtnAnswer);
private slots:
    void on_btnNextQuestion_clicked();
    void on_btnA_clicked();
    void on_btnB_clicked();
    void on_btnC_clicked();
    void on_btnD_clicked();
    void on_btnHandOn_clicked();
private:
    Ui::questionDialog *ui;
    QSqlDatabase dataBase;
    QHash<QString ,QString > hashQuestionAnswer;
    QHash<QString,QByteArray> hashQuestionAndImage;
    QVector<QString> vectorAnswer;
    QVector<QString> vectorBtnAnswer;
    QVector<QString> vectorQuestion;
    QString newAnswer;
    QHash<QString,QString>::Iterator iterator;
    QByteArray imageByteArray;
    QPixmap image;
    QString subjectName;
};

#endif // QUESTIONDIALOG_H
