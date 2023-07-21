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


/**�������*/
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
    double threshold = 0.02;                          /**������ֵ*/
    size_t number = 0;                                   /**�����ƺ���Ҫһ��������������*/
    std::deque<cv::Mat> normalizedVideoFrameDeque;      /**�ϱ���֮ǰ�ĳ���dequeÿ�յ�����������frame���������ģ�ͣ�ֱ���ɼ�����*/
    std::vector<cv::Mat> allFrameVector;                /**���֡������*/
    std::vector<double> sCellOutputVector;              /**������յ�S���������*/
    std::vector<cv::Mat> storageVideoOutputVector;      /**����һ��vector�������Ion�����������MP4��ʽ����ڴ�����*/
    cv::Mat beforeTimePonOutput;                        /**��Ҫһ����ʼ��Pon��Ա������ѭ���Ŀ���*/
    cv::Mat beforeTimmePoffOutput;                      /**��Ҫһ����ʼ��Poff��Ա������ѭ���Ŀ���*/    
    std::vector<cv::Mat> storagePoffOutputVector;       /**�洢Poff�����*/
    std::vector<cv::Mat> storagePonOutputVector;        /**�洢Pon�����*/
    std::vector<cv::Mat> storageSonOutputVector;        /**�洢Son�����*/
    std::vector<cv::Mat> storageSoffOutputVector;        /**�洢Soff�����*/

public:
    void                           getPcellsOutput();
    cv::Mat                        getOnPCellsOuptput(cv::Mat& beforeVideoFrame,cv::Mat& nextVideoFrame);
    cv::Mat                        getOffPCellsOutput(cv::Mat& beforeVideoFrame, cv::Mat& nextVideoFrame);
    std::pair<cv::Mat,cv::Mat>    getExcitabilityOnCellOutput(cv::Mat& beforeTimePonOutput,cv::Mat& postTimePonOutput);
    bool                           getIntoOnEntrance();
    bool                           getIntoOffEntrance();
    cv::Mat                        getOnInhibitionOutput(cv::Mat& beforeTimeExacitability, cv::Mat& postTimeExactitability);
    cv::Mat                        getOffInhibitionOutput(cv::Mat& beforeTimeExcitability, cv::Mat& postTimeExcitability);
    cv::Mat                        getInitOnPCellOutput();
    cv::Mat                        getInitOffPCellOutput();
protected:
    cv::Mat                        firstHalfWaveRectification(cv::Mat pOnPCellOutput);
    cv::Mat                        secondHalfWaveRectification(cv::Mat pOffPCellOutput);                                      /**��ó�ʼ��w1,w2*/
    std::pair<float,float>         getCoefficient(const cv::Mat& t_TimeExcitability, float& beforePM,bool flag=1);      /**���Sonʹ�õ�w1(t),w2(tϵ��)*/
    bool                           writeVideoToDisk(std::vector<cv::Mat>& storageVideoOutputVector);                           /**�����д����Ƶ�ļ�*/

public:
    static  double                      getCoefficientAboutPcell(size_t i);
public:
    cv::Mat convolutionFrame(cv::Mat inputFrame, cv::Mat coefficientMatrix, size_t flag);  /**����������*/
    cv::Mat maxPoolingFrame(cv::Mat& convolutionPostFrame);                                 /**�������ػ�����*/
public:
    void testFuncation();

};
