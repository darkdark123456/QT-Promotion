#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "registerdialog.h"
#include <QLabel>
#include <QTimer>
#include <QDateTime>
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
    void on_userRegisterBtn_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void onlyOneUserRegisterMoment();

    void recoverUseRegisterBtn();

    void on_userRegisterBtn_2_clicked();

    void on_btnPunch_clicked();

    void updateLocalTime();

private:
    Ui::Widget *ui;
    QTimer *localTimer;
public:
    registerDialog *regDialog=NULL;
public:
    std::vector<int> templateImageHashFingers(cv::Mat &matSrcImage);
    std::vector<int> getImageShape(cv::Mat &matSrcImage);
    double imageContrastRatio(std::vector<int> &newFaceImageHashFingers,
                              std::vector<int> &oldFaceImageHashFingers,
                              std::vector<int> imageShape,
                              cv::Mat image);
};
#endif // WIDGET_H
