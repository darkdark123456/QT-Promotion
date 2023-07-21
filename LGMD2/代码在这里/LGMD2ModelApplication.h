#pragma once
#include <QtWidgets/QWidget>
#include <opencv.hpp>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <qdebug.h>
#include <qstring.h>
#include <vector>
#include <deque>
#include <math.h>
#include <Windows.h>
#include <algorithm>
#include <thread>
#include <ctime>
#include <initializer_list>
#include "ui_LGMD2ModelApplication.h"


/**类的声明*/
QT_BEGIN_NAMESPACE
namespace Ui { class LGMD2ModelApplicationClass; };
QT_END_NAMESPACE


class LGMD2ModelApplication : public QWidget{
    friend void normalizedMatrix(cv::Mat& inputMatrix);
    friend void delayTime(float time);
    Q_OBJECT
public:
    LGMD2ModelApplication(QWidget *parent = nullptr);
    ~LGMD2ModelApplication();
private:
    Ui::LGMD2ModelApplicationClass *ui;
private slots:
    void btnCalculateLGMD2Clicked();
private:
    double threshold = 0.02;                          /**定义阈值*/
    size_t number = 0;                                   /**程序似乎需要一个计数器来工作*/
    std::deque<cv::Mat> normalizedVideoFrameDeque;      /**较比于之前的程序，deque每收到连续的三个frame便把其送入模型，直到采集结束*/
    std::vector<cv::Mat> allFrameVector;                /**存放帧差数组*/
    std::vector<double> sCellOutputVector;              /**存放最终的S层的输出结果*/
    std::vector<cv::Mat> storageVideoOutputVector;      /**定义一个vector用来存放Ion的输出，将以MP4格式存放在磁盘中*/
    cv::Mat beforeTimePonOutput;                        /**需要一个初始的Pon成员来进行循环的开端*/
    cv::Mat beforeTimmePoffOutput;                      /**需要一个初始的Poff成员来进行循环的开端*/    
    std::vector<cv::Mat> storagePoffOutputVector;       /**存储Poff的输出*/
    std::vector<cv::Mat> storagePonOutputVector;        /**存储Pon的输出*/
    std::vector<cv::Mat> storageSonOutputVector;        /**存储Son的输出*/
    std::vector<cv::Mat> storageSoffOutputVector;        /**存储Soff的输出*/

public:
    void                           getPcellsOutput();
    cv::Mat                        getOnPCellsOuptput(cv::Mat& beforeVideoFrame,cv::Mat& nextVideoFrame);
    cv::Mat                        getOffPCellsOutput(cv::Mat& beforeVideoFrame, cv::Mat& nextVideoFrame);
    std::pair<cv::Mat,cv::Mat>     getExcitabilityOnCellOutput(cv::Mat& beforeTimePonOutput,cv::Mat& postTimePonOutput);
    bool                           getIntoOnEntrance();
    bool                           getIntoOffEntrance();
    cv::Mat                        getOnInhibitionOutput(cv::Mat& beforeTimeExacitability, cv::Mat& postTimeExactitability);
    cv::Mat                        getOffInhibitionOutput(cv::Mat& beforeTimeExcitability, cv::Mat& postTimeExcitability);
    cv::Mat                        getInitOnPCellOutput();
    cv::Mat                        getInitOffPCellOutput();
protected:
    cv::Mat                        firstHalfWaveRectification(cv::Mat pOnPCellOutput);
    cv::Mat                        secondHalfWaveRectification(cv::Mat pOffPCellOutput);                                      /**获得初始的w1,w2*/
    std::pair<float,float>         getCoefficient(const cv::Mat& t_TimeExcitability, float& beforePM,bool flag=1);      /**获得Son使用的w1(t),w2(t系数)*/
    bool                           writeVideoToDisk(std::vector<cv::Mat>& storageVideoOutputVector);                           /**向磁盘写入视频文件*/

public:
    static  double                      getCoefficientAboutPcell(size_t i);
public:
    cv::Mat convolutionFrame(cv::Mat inputFrame, cv::Mat coefficientMatrix, size_t flag);  /**定义卷积操作*/
    cv::Mat maxPoolingFrame(cv::Mat& convolutionPostFrame);                                 /**定义最大池化操作*/
public:
    void testFuncation();

};
