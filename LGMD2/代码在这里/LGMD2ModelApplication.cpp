#include "LGMD2ModelApplication.h"

/**取i=1时刻的情形*/
const static double coefficientAboutPcell = LGMD2ModelApplication::getCoefficientAboutPcell(1);
/**假设图像的速度是匀速采取的，摄像头的采取帧数是25帧每秒，那么两帧的间隔时间为40ms*/
const static float frameSpacing = 40;



LGMD2ModelApplication::LGMD2ModelApplication(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LGMD2ModelApplicationClass())
{
    ui->setupUi(this);
    QObject::connect(ui->btnCalculateLGMD2, SIGNAL(clicked()), this, SLOT(btnCalculateLGMD2Clicked()));
    
}

LGMD2ModelApplication::~LGMD2ModelApplication(){
    delete ui;
}


/*定义一个测试的全局函数，用来除以255*/
void normalizedMatrix(cv::Mat& inputMatrix) {
    inputMatrix.convertTo(inputMatrix, CV_32F);
    for (size_t row = 0; row < inputMatrix.rows; row++){
        for (size_t column = 0; column < inputMatrix.cols; column++){
            inputMatrix.at<float>(row, column) /= 255.;
        }
    }
}



void LGMD2ModelApplication::btnCalculateLGMD2Clicked() {
    QString filename = QFileDialog::getOpenFileName(this, "File Open Widget", "", "*.mp4");
    cv::VideoCapture videoFileCapture;
    videoFileCapture.open(filename.toStdString());
    if (!videoFileCapture.isOpened()) {
        QMessageBox::critical(this, "", "file" + filename + "opened fail");
        return;
    }
    QMessageBox::information(this, "", "file" + filename + "opened success");
    while (true) {
        /*每次读取时都要刷新帧，不可定义在循环外边*/
        cv::Mat originalVideoFrame;
        cv::Mat grayVideoFrame;
        videoFileCapture >> originalVideoFrame;
        if (originalVideoFrame.empty()) { break; }
        cv::cvtColor(originalVideoFrame, grayVideoFrame, cv::COLOR_BGR2GRAY);
        normalizedMatrix(grayVideoFrame);
        allFrameVector.push_back(grayVideoFrame);
        cv::imshow("frame", grayVideoFrame);
        Sleep(frameSpacing);
        int breakKeyAscia = cv::waitKey(5);
        if (breakKeyAscia == 81 || breakKeyAscia == 113) {
            break;
        }
    }
    videoFileCapture.release();
    beforeTimePonOutput = getInitOnPCellOutput();     /*初始化Pon的开端记作[p(1)]+*/
    beforeTimmePoffOutput = getInitOffPCellOutput();  /*初始化Poff的开端记作[p(1)]-*/
    cv::destroyAllWindows();
    getPcellsOutput();
}



/**用来获得αi=(1+e^i)^-1 用来表示上一刻时间的残留所占的权重系数*/
double LGMD2ModelApplication::getCoefficientAboutPcell(size_t i) {
    return pow(1 + pow(2.72, i), -1);
}


/**向磁盘写入每层输出的视频文件的函数*/
bool LGMD2ModelApplication::writeVideoToDisk(std::vector<cv::Mat>& storageVideoOutputVector) {
    char buffer[128];
    for (int number=0;number<storageVideoOutputVector.size();number++){
        sprintf_s(buffer, "C://data//Output//%d.jpg", number);
        cv::Mat image = storageVideoOutputVector.at(number);
        cv::normalize(image, image, 0, 255, cv::NORM_MINMAX, CV_8U);
        //image.convertTo(image, CV_32F, 1);
        cv::imwrite(buffer, image);
    }
    return true;

}



/**获得P层的输出,P层将输出的连续的三个frame Lt Lt+1 Lt+2,由于t=0时的产生的电脉冲一定为0，所以只考虑t>0的情况*/
void LGMD2ModelApplication::getPcellsOutput() {
    normalizedVideoFrameDeque.push_back(allFrameVector.at(0));
    normalizedVideoFrameDeque.push_back(allFrameVector.at(1));
    normalizedVideoFrameDeque.push_back(allFrameVector.at(2));

    for (std::vector<cv::Mat>::iterator iter=allFrameVector.begin()+3;iter!=allFrameVector.end();iter++){
        /*利用一个循环队列确保连续读取3个frame且不发生任何内存越界，如果公式余项需要多个时刻前的frame，将3改为N，变为N循环队列*/
        /*为了计算方便，认为p(x,y,t-1)时刻的矩阵为相邻两个frame之差，这种思想取之LGMD1*/
        cv::Mat beforePCellOutputArray = normalizedVideoFrameDeque.at(1) - normalizedVideoFrameDeque.at(0);
        cv::Mat nextPCellOuputArray    = (normalizedVideoFrameDeque.at(2) - normalizedVideoFrameDeque.at(1)) + coefficientAboutPcell * beforePCellOutputArray;

        storagePonOutputVector.push_back(beforeTimePonOutput);
        /*得到半波整流的Pon的结果,beforeTimePonOutput代表t-1时刻的Pon的输出，postTimePonOutput代表t时刻的Pon的输出*/
        cv::Mat postTimePonOutput = getOnPCellsOuptput(beforeTimePonOutput, nextPCellOuputArray);
        beforeTimePonOutput = postTimePonOutput;

        /*同理如法炮制Poff的输出 得到半波整流Poff的结果,beforeTimePoffOutput代表t-1时刻的Poff的输出,postTimePoffOutput代表t时刻的pos的输出*/
        
        storagePoffOutputVector.push_back(beforeTimmePoffOutput);
        cv::Mat postTimePoffOutput = getOffPCellsOutput(beforeTimmePoffOutput, nextPCellOuputArray);
        beforeTimmePoffOutput = postTimePoffOutput;
        normalizedVideoFrameDeque.pop_front();
        normalizedVideoFrameDeque.push_back(*iter);
    }



    /*创建一个线程 Pon(x, y, t - 1), Pon(x, y, t)开始进入on通道进行计算*/
    std::thread firstThread(&LGMD2ModelApplication::getIntoOnEntrance,this);
    firstThread.join();
    /*t同理，创建一个线程 进入off通道计算*/
    std::thread secondThread(&LGMD2ModelApplication::getIntoOffEntrance, this);
    secondThread.join();
    /*写一个线程等待函数，等待Son和Soff的线程结束*/
    while (true){
        if (storageSonOutputVector.size() == storagePonOutputVector.size() && storageSoffOutputVector.size() == storagePonOutputVector.size()) {
            break;
        }
    }
    /*计算s(x,y,t)几乎和LGMD1一样的计算方式*/
    std::vector<cv::Mat> t_timeGCellOutputVector;
    cv::Mat defaultCoefficientMatrix = cv::Mat::zeros(3, 3, CV_32F);
    

    for (size_t i = 0; i < storageSonOutputVector.size(); i++){
        cv::Mat t_timeSCellOutput = 0.7 * storageSonOutputVector.at(i) + 0.3 * storageSoffOutputVector.at(i);
        cv::Mat postConvolutionSCellOutput = convolutionFrame(t_timeSCellOutput, defaultCoefficientMatrix, 4);
        t_timeGCellOutputVector.push_back(postConvolutionSCellOutput);
    }

    size_t rows   = t_timeGCellOutputVector.at(0).rows;
    size_t columns = t_timeGCellOutputVector.at(0).cols;
    for (size_t i = 0; i < t_timeGCellOutputVector.size(); i++){
        for (size_t row = 0; row < rows; row++){
            for (size_t column = 0; column < columns; column++){
                if (t_timeGCellOutputVector.at(i).at<float>(row, column) < 0.0001) {
                    t_timeGCellOutputVector.at(i).at<float>(row, column) = 0;
                }
            }
        }
    }







    /*计算最终的输出 sum*/
    std::vector<float> finalOutputVector;
    for (size_t i = 0; i < t_timeGCellOutputVector.size(); i++) {
        float finalOutput = 0;
        for (size_t row = 0; row < rows; row++) {
            for (size_t column = 0; column < columns; column++) {
                finalOutput += t_timeGCellOutputVector.at(i).at<float>(row, column);
            }
        }
        finalOutputVector.push_back(finalOutput);
    }

    /*将结果写入磁盘中*/
    QString fileName = "c://data//output.txt";
    QFile fileObject(fileName);
    bool writeFlag = fileObject.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
    if (writeFlag) {
        QTextStream writeStream(&fileObject);
        for (size_t i = 0; i < finalOutputVector.size(); i++){
            writeStream << finalOutputVector.at(i) << "\n";
        }
    }

    std::cout << "程序执行完毕" << std::endl;
}


void LGMD2ModelApplication::testFuncation() {
}


std::pair<float,float> LGMD2ModelApplication::getCoefficient(const cv::Mat& t_TimeExcitability,float& beforePM,bool flag) {
    float sum = 0;
    float tTimePM = 0;
    float newPM = 0;
    float t3 = 0;/*计算α4时的时间延迟常量取兴奋矩阵的延迟系数矩阵的均值*/
    float delayMatrixAverage;
    float w1 = 0;
    float coefficient = 0;
    float (*array)[3];
    if (flag == 1) {
        float excitabilityDelayMatrixCopy[3][3] = { {45,30,45},
                                                     {30,15,30},
                                                     {45,30,45} };
        array = excitabilityDelayMatrixCopy;
         
    }
    else {
        float excitabilityDelayMatrixCopy[3][3] = { {180,120,180},
                                                     {120,60,120},
                                                     {180,120,180} };
        array = excitabilityDelayMatrixCopy;
    }


    cv::Mat excitabilityDelayMatrix(3,3,CV_32F,array);

    for (size_t row = 0; row < t_TimeExcitability.rows;row++) {
        for (size_t column = 0; column < t_TimeExcitability.cols; column++) {
            if (t_TimeExcitability.at<float>(row, column) > 0) {
                sum += t_TimeExcitability.at<float>(row, column);
            } 
        }
    }
    tTimePM = sum / (t_TimeExcitability.rows * t_TimeExcitability.cols);

    sum = 0;
    for (size_t row = 0; row < excitabilityDelayMatrix.rows;row++) {
        for (size_t column = 0; column < excitabilityDelayMatrix.cols; column++) {
            sum += excitabilityDelayMatrix.at<float>(row, column);
        }
    }
    delayMatrixAverage = sum / (excitabilityDelayMatrix.rows + excitabilityDelayMatrix.cols);


    coefficient = frameSpacing / (frameSpacing + delayMatrixAverage);
    newPM = coefficient * tTimePM + (1 - coefficient) * beforePM;
    
    /*不知道w3,w4的具体值,这里设置为0，w3=w4=0*/
    w1  = newPM / threshold;
    return std::make_pair(w1,tTimePM);
}


/*进入On通道计算依次计算出Eon，Eon^ Ion*/
bool LGMD2ModelApplication::getIntoOnEntrance() {
    /*得到Eon的输出，beforeTimeExcitability 代表t-1时刻的兴奋矩阵,postTimeExcitability 代表t时刻的兴奋矩阵*/
    std::vector<cv::Mat> storageOnExcitabilitVector;
    /*以下的计算为得到Ion的输出*/
    std::vector<cv::Mat> storageOnInhibitionVector;
    float beforePM = 0;/*存放PM(t-1)*/
    cv::Mat defaultCoefficientMatrix=cv::Mat::zeros(3, 3, CV_32F);

    cv::Mat t_timeExcitabilityCopy = convolutionFrame(storagePonOutputVector.at(0), defaultCoefficientMatrix, 0);
    auto width = t_timeExcitabilityCopy.rows;
    auto height = t_timeExcitabilityCopy.cols;
    storageOnExcitabilitVector= storagePonOutputVector;

    for (size_t index = 0; index < storageOnExcitabilitVector.size(); index++){
        cv::resize(storageOnExcitabilitVector.at(index), storageOnExcitabilitVector.at(index),cv::Size(height,width));
    }





    /*计算第一个Ion的输出,使得Ion和Eon的输出尺寸相同*/
    cv::Mat tempInputVector = cv::Mat::zeros(storagePonOutputVector.at(0).rows, storagePonOutputVector.at(0).cols, CV_32F);
    cv::Mat t_timeInhibitionCopy = getOnInhibitionOutput(tempInputVector, storagePonOutputVector.at(0));
    storageOnInhibitionVector.push_back(t_timeInhibitionCopy);
    for (size_t i = 0; i+1 < storagePonOutputVector.size(); i++){
        cv::Mat t_timeInhibition = getOnInhibitionOutput(storagePonOutputVector.at(i), storagePonOutputVector.at(i+1));
        storageOnInhibitionVector.push_back(t_timeInhibition);
    } 

    /*得到Son*/
    std::pair<float, float> pair;    
    for (size_t i = 0; i< storageOnExcitabilitVector.size(); i++){
        pair = getCoefficient(storageOnExcitabilitVector.at(i),beforePM,1);
        cv:: Mat tempMat = storageOnExcitabilitVector.at(i) -  pair.first* storageOnInhibitionVector.at(i);
        cv::Mat  newTempMat = firstHalfWaveRectification(tempMat);
        storageSonOutputVector.push_back(newTempMat);
        beforePM = pair.second;
    }

    return true;
}



/*进入Off通道计算依次计算出Eoff Ioff Soff*/
bool  LGMD2ModelApplication::getIntoOffEntrance() {
    std::vector<cv::Mat> storageOffExcitabilityVector;
    std::vector<cv::Mat> storageOffInhibitionVector;
    cv::Mat defaultCoefficientMatrix = cv::Mat::zeros(3,3, CV_32F);
    float coefficient = 0;
    float beforePM = 0;
    /*计算Eoff*/
    cv::Mat t_timeExcitabilityCopy = convolutionFrame(storagePoffOutputVector.at(0), defaultCoefficientMatrix, 0);
    auto width = t_timeExcitabilityCopy.rows;
    auto height = t_timeExcitabilityCopy.cols;
    storageOffExcitabilityVector = storagePoffOutputVector;

    for (size_t index = 0; index < storageOffExcitabilityVector.size(); index++){
        cv::resize(storageOffExcitabilityVector.at(index), storageOffExcitabilityVector.at(index),cv::Size(height,width));
    }

    /*计算Ioff，先计算第一个Ioff*/
    cv::Mat tempInputVector = cv::Mat::zeros(storagePoffOutputVector.at(0).rows, storagePoffOutputVector.at(0).cols, CV_32F);
    cv::Mat t_timeInhibitionCopy = getOffInhibitionOutput(tempInputVector, storagePoffOutputVector.at(0));
    storageOffInhibitionVector.push_back(t_timeInhibitionCopy);
    for (size_t i = 0; i+1< storagePoffOutputVector.size(); i++){
        cv::Mat t_timeInhibition= getOffInhibitionOutput(storagePoffOutputVector.at(i), storagePoffOutputVector.at(i + 1));
        storageOffInhibitionVector.push_back(t_timeInhibition);
    }

    /*计算Soff的输出*/
    std::pair<float, float> pair;
    for (size_t i = 0; i < storageOffExcitabilityVector.size(); i++){
        pair = getCoefficient(storageOffExcitabilityVector.at(i), beforePM, 0);
        cv::Mat tempMat = storageOffExcitabilityVector.at(i) - pair.first * storageOffInhibitionVector.at(i);
        cv::Mat newTempMat = firstHalfWaveRectification(tempMat);
        storageSoffOutputVector.push_back(newTempMat);
        beforePM = pair.second;
    }
    //std::cout << "**************正在执行写入操作***************" << std::endl;
    ///******************************************************************************/
    //char buffer1[128];
    ///*将Pon 和Poff的结果输出到磁盘里*/
    //for (int index = 0; index < (int)storagePoffOutputVector.size(); index++) {
    //    sprintf(buffer1, "c://data//Eoff_output//%d.jpg", index);
    //    cv::Mat image = storagePoffOutputVector.at(index);
    //    cv::normalize(image, image, 0, 255, cv::NORM_L1, CV_8U);
    //    cv::imwrite(buffer1, image);
    //}
    //std::cout << "**************写入完毕***************" << std::endl;
    return true;
}




/**用于Pon(x,y,t)的半波整流函数 可寻找规律，进行循环*/
cv::Mat LGMD2ModelApplication::firstHalfWaveRectification(cv::Mat pOnPCellOutput) {
    for (size_t row = 0; row < pOnPCellOutput.size().height;row++){
        for (size_t column = 0; column < pOnPCellOutput.size().width;column++) {
            if (pOnPCellOutput.at<float>(row, column) < 0) {
                pOnPCellOutput.at<float>(row, column) = 0;
            }
        }
    }
    return pOnPCellOutput;
}


/**用于Poff(x,y,t)的半波整流函数*/
cv::Mat LGMD2ModelApplication::secondHalfWaveRectification(cv::Mat pOffPCellOutput) {
    for (size_t row = 0; row < pOffPCellOutput.size().height; row++){
        for (size_t column = 0; column < pOffPCellOutput.size().width; column++){
            if (pOffPCellOutput.at<float>(row, column) > 0) {
                pOffPCellOutput.at<float>(row, column) = 0;
            }
        }
    }
    pOffPCellOutput *= -1;
    return pOffPCellOutput;
}



/*用来记录Pon的初始输出,构成循环的开端**/
cv::Mat LGMD2ModelApplication::getInitOnPCellOutput() {
    return firstHalfWaveRectification( allFrameVector.at(1)-allFrameVector.at(0));
}


/**进行半波整流操作获得Pon的输出,返回一个pair ，第一个元素Pon(x,y,t)，第二个元素Pon(x,y,t-1)*/
cv::Mat LGMD2ModelApplication::getOnPCellsOuptput(cv::Mat& beforeVideoFrame, cv::Mat& nextVideoFrame) {
    /*max{p(x,y,t),0}如何比较，我的理解是将矩阵的每个元素都与0比 n较，比0大为自身，比0小赋值为0,如果逻辑不对，修改firstHalfWaveRectification*/
    cv::Mat  postPonOutput = firstHalfWaveRectification(nextVideoFrame) + coefficientAboutPcell * beforeVideoFrame;
    return postPonOutput;
}


/*用来记录Poff的初始输出,构成循环的开端**/
cv::Mat LGMD2ModelApplication::getInitOffPCellOutput() {
    return secondHalfWaveRectification(allFrameVector.at(1)-allFrameVector.at(0));
}




/**进行半波整流操作获得Poff的输出*/
cv::Mat LGMD2ModelApplication::getOffPCellsOutput(cv::Mat& beforeVideoFrame, cv::Mat& nextVideoFrame) {
    /*min{p(x,y,t),0}如何比较，我的理解是将矩阵的每个元素都与0比较，比0小为自身，比0大赋值为0*/
    cv::Mat postPoffOutput= secondHalfWaveRectification(nextVideoFrame) + coefficientAboutPcell *beforeVideoFrame;
    return postPoffOutput;
}



/**得到Eon的输出 beforeTimePonOutput代表t-1时刻的兴奋矩阵，postTimePonOutput代表t时刻的兴奋矩阵*/
std::pair<cv::Mat,cv::Mat> LGMD2ModelApplication::getExcitabilityOnCellOutput(cv::Mat& beforeTimePonOutput,cv::Mat& postTimePonOutput) {
    return std::make_pair(beforeTimePonOutput, postTimePonOutput);
}




cv::Mat LGMD2ModelApplication::getOnInhibitionOutput(cv::Mat& beforeTimeOnExacitability, cv::Mat& postTimeOnExactitability) {
    /**卷积核里的每个参数都有时间α2的延迟，中心的参数占比权重大，时间延迟短，边围的参数占比权重小，延迟高，类似于人的视野
 对视野中心的物体反应延迟底，对视野边框的物体反应延迟高?  延迟矩阵 单位ms [[45,30,45],
                                                                [30,15,30],
                                                                [45,30,45]]*/
    float firstDelayMatrixCopy[3][3] = { {45,30,45},
                                          {30,15,30},
                                          {45,30,45} };

    cv::Mat firstDelayMatrix(3,3,CV_32F,firstDelayMatrixCopy);
    /**假设采取的数据时是匀速的，两帧之间的间隔恒定为40ms frameSpacing=40，在获取延迟矩阵后，根据α2的计算公式，立马可以得到α2的系数矩阵，
由于α2时变化的这里采取一个3*3的矩阵存储*/
    cv::Mat firstCoefficientMatrix = cv::Mat::zeros(3, 3, CV_32F);/*定义一个常系数矩阵,在进行卷积时这个系数是变化的*/
    for (size_t row = 0; row <firstDelayMatrix.size().width; row++) {
        for (size_t column = 0; column < firstDelayMatrix.size().height; column++) {
            firstCoefficientMatrix.at<float>(row, column) = frameSpacing / (firstDelayMatrix.at<float>(row, column) + frameSpacing);
        }
    }
    cv::Mat fisrtConvolutionFrame = convolutionFrame(postTimeOnExactitability,firstCoefficientMatrix , 2);    /*得到ΣΣα2*Eon^(x,y,t)⊗W的结果*/
 //   cv::imshow("before", fisrtConvolutionFrame);
 //   cv::waitKey(0);
    cv::Mat secondCoefficientMatrix = cv::Mat::zeros(3, 3, CV_32F);                                             /*第二个系数矩阵为第一个系数矩阵每个元素-1**/
    for (size_t row = 0; row < firstDelayMatrix.size().width; row++) {
        for (size_t column = 0; column < firstDelayMatrix.size().height; column++) {
            secondCoefficientMatrix.at<float>(row, column) = 1. - firstCoefficientMatrix.at<float>(row, column);
        }
    }
    cv::Mat secondConvolutionFrame = convolutionFrame(beforeTimeOnExacitability, secondCoefficientMatrix, 2);  /*得到ΣΣ(1-α2)*Eon^(x,y,t-1)⊗W 的结果**/
    return fisrtConvolutionFrame+secondConvolutionFrame;
}


/**计算Ioff*/
cv::Mat LGMD2ModelApplication::getOffInhibitionOutput(cv::Mat& beforeTimeExcitability, cv::Mat& postTimeExcitability) {
    float secondDealyMatrixCopy[3][3] = { {180,120,180},
                                           {120,60,120},
                                           {180,120,180} };
    cv::Mat secondDelayMatrix(3, 3, CV_32F, secondDealyMatrixCopy);
    cv::Mat firstCoefficientMatrix = cv::Mat::zeros(3, 3, CV_32F);
    for (size_t row = 0; row < secondDelayMatrix.rows; row++){
        for (size_t column = 0; column < secondDelayMatrix.cols; column++){
            firstCoefficientMatrix.at<float>(row, column) = frameSpacing / (secondDelayMatrix.at<float>(row, column) + frameSpacing);
        }
    }

    cv::Mat firstConvoLutionFrame = convolutionFrame(postTimeExcitability, firstCoefficientMatrix, 3);
    cv::Mat secondCoefficientMatrix = cv::Mat::zeros(3, 3, CV_32F);
    for (size_t row = 0; row <secondDelayMatrix.rows; row++){
        for (size_t column = 0; column < secondDelayMatrix.cols; column++){
            secondCoefficientMatrix.at<float>(row, column) = 1.- firstCoefficientMatrix.at<float>(row, column);
        }
    }
    cv::Mat secondConvolutionFrame = convolutionFrame(beforeTimeExcitability, secondCoefficientMatrix, 3);
    return firstConvoLutionFrame + secondConvolutionFrame;
}




/*一个延时函数*/
void delayTime(float time) {
    clock_t delayTime = time;
    clock_t startTime = clock();
    while (clock()-startTime<delayTime){

    }
}



/**用cplusplus重写python的卷积操作,inputframe为归一化后的灰度图*/
cv::Mat LGMD2ModelApplication::convolutionFrame(cv::Mat inputFrame, cv::Mat coefficientMatrix,size_t flag) {
    cv::Mat normalizedInputFrame;
    inputFrame.convertTo(normalizedInputFrame, CV_32F);     /*将inputFrame数组元素转换为float*/
    size_t step = 1;                                         /*设置步长为1*/
    cv::Mat kernelArray;                                    /*定义一个卷积核的copy*/
    size_t kernelSize = 3;                                  /*定义卷积核的尺寸*/
    size_t row = normalizedInputFrame.size().height;       /*原始图的高度*/
    size_t column = normalizedInputFrame.size().width;     /*原始图的宽度*/
    /*根据flag的标记选择kernal*/
    if (flag == 0) {
        /*简单的卷积核*/
        float originalKernelArray[3][3] = { {0.01, 0.01, 0.01},
                                             {0.01, 0.1,  0.001},
                                             {0.001,0.05, 0.01} };
        cv::Mat kernelArrayCopy(3, 3, CV_32F, originalKernelArray);
        kernelArray = kernelArrayCopy;

    }
    else if (flag == 1) {
        /*将得到的系数矩阵和kernel相乘 得到经过α2参数处理后的矩阵*/
        float originalKernelArray[3][3] = { {0.125,0.25,0.125},
                                             {0.25, 0,   0.25},
                                             {0.125,0.25,0.125} };
        cv::Mat kernelArrayCopy(3, 3, CV_32F, originalKernelArray);
        kernelArray = kernelArrayCopy;
    }

    else if(flag==2){
        float originalKernelArray[3][3] = { {0.25,0.5,0.25},
                                             {0.5, 2,  0.5},
                                             {0.25,0.5,0.25} };
        cv::Mat kernelArrayCopy(3, 3, CV_32F, originalKernelArray);
        kernelArray = kernelArrayCopy*coefficientMatrix;
        //kernelArray = kernelArrayCopy;
    }
    else if(flag==3){
        float originalKernelArray[3][3] = { {0.125,0.25,0.125},
                                             {0.25,1,0.25},
                                             {0.125,0.25,0.125} };
        cv::Mat kernelArrayCopy(3, 3, CV_32F, originalKernelArray);
        kernelArray = kernelArrayCopy * coefficientMatrix;
    }
    /*用于计算S(x,y,t)的均匀分布的卷积核*/
    else if (flag == 4){
        float originalKernelArray[3][3] = { {0.111,0.111,0.111},
                                             {0.111,0.111,0.111},
                                             {0.111,0.111,0.111} };
            cv::Mat kernelArrayCopy(3, 3, CV_32F, originalKernelArray);
            kernelArray = kernelArrayCopy;
    }


    else{
        std::cout << "没有对应的卷积矩阵 flag应为 1 2 3" << std::endl;
    }
    cv::Mat tempArray = cv::Mat::zeros(3, 3, CV_32F);                       /*存放扫描到的原始图的数据*/
    size_t featureMapHeight = (row - kernelSize) / step + 1;               /*卷积后特征图的高度*/
    size_t featureMapWidth = (column - kernelSize) / step + 1;             /*卷积后特征图的长度*/
    cv::Mat featureMap = cv::Mat::zeros(featureMapHeight, featureMapWidth, CV_32F); /*初始化featureMap*/

    for (size_t i = 0; i < featureMapHeight; i += 2) {
        for (size_t j = 0; j < featureMapWidth; j += 2) {

            if (i + 1 >= featureMapHeight || j + 1 >= featureMapWidth) {
                continue;
            }
            /*问题.............................在进行计算时写上延时函数太慢了..............*/


            /**计算Ion时用到的时间的卷积,中间的卷积用到的时间短，两边的卷积用到的时间长，模拟生物反应时间差的特性？*/
            tempArray.at<float>(0, 0) = normalizedInputFrame.at<float>(i, j);
          //  Sleep(30);
            tempArray.at<float>(0, 1) = normalizedInputFrame.at<float>(i, j + 1);
         // Sleep(45);
            tempArray.at<float>(0, 2) = normalizedInputFrame.at<float>(i, j + 2);

        //  Sleep(30);
            tempArray.at<float>(1, 0) = normalizedInputFrame.at<float>(i + 1, j);
        //  Sleep(15);
            tempArray.at<float>(1, 1) = normalizedInputFrame.at<float>(i + 1, j + 1);
        //  Sleep(30);
            tempArray.at<float>(1, 2) = normalizedInputFrame.at<float>(i + 1, j + 2);

           // Sleep(45);
            tempArray.at<float>(2, 0) = normalizedInputFrame.at<float>(i + 2, j);
           // Sleep(30);
            tempArray.at<float>(2, 1) = normalizedInputFrame.at<float>(i + 2, j + 1);
           // Sleep(45);
            tempArray.at<float>(2, 2) = normalizedInputFrame.at<float>(i + 2, j + 2);

            if (i >= featureMapHeight || j >= featureMapWidth) {
                continue;
            }

            featureMap.at<float>(i, j) = kernelArray.dot(tempArray);
        }
    }
    return featureMap;
}



cv::Mat LGMD2ModelApplication::maxPoolingFrame(cv::Mat& convolutionPostFrame) {
    /*找到2*2的核的最大值*/
    float firstValue, secondValue, thirdValue, fourthValue;
    const float *pointerToMaxValue;
    /*将每次找到的最大值保存起来*/
    std::vector<float> maxValueVector;
    /*池化的步长*/
    size_t step = 2;
    /*filtter的大小*/
    size_t kernelSize = 2;
    /*原始图片的大小行数*/
    size_t featureMapRow = convolutionPostFrame.size().height;
    /*原始图片的列数*/
    size_t featureMapColumn = convolutionPostFrame.size().width;
    /*池化后图片的函数*/
    size_t poolingFeatureMapHeight = (featureMapRow - kernelSize) / step + 1;
    /*池化后图片的列数*/
    size_t poolingFeatureMapWidth = (featureMapColumn - kernelSize) / step + 1;
    /*初始化池化的图像*/
    cv::Mat poolingFeatureMap = cv::Mat::zeros(poolingFeatureMapHeight,poolingFeatureMapWidth,CV_32F);

   
    for (size_t i = 0; i < featureMapRow; i += 2) {
        for (size_t j = 0; j < featureMapColumn; j += 2) {
            if (i + 1 >= featureMapRow || j + 1 >= featureMapColumn) {
                continue;
            }
            firstValue = convolutionPostFrame.at<float>(i, j);
            secondValue = convolutionPostFrame.at<float>(i, j + 1);
            thirdValue = convolutionPostFrame.at<float>(i + 1, j);
            fourthValue = convolutionPostFrame.at<float>(i + 1, j + 1);
            std::initializer_list<float> valueList{ firstValue,secondValue,thirdValue,fourthValue };
            pointerToMaxValue = std::max_element(valueList.begin(), valueList.end());
            maxValueVector.push_back(*pointerToMaxValue);
        }
    }

    /*得到池化后的特征图*/
    size_t tempTimer = 0;
    for (size_t i = 0; i < poolingFeatureMapHeight; i ++) {
        for (size_t j = 0; j < poolingFeatureMapWidth; j ++) {
            if (tempTimer >= maxValueVector.size()) {
                break;
            }
            poolingFeatureMap.at<float>(i, j) = maxValueVector[tempTimer++];
        }
    }
    return convolutionPostFrame;
}



//void LGMD2ModelApplication::buttonTestClicked() {
//
//    cv::Mat inputFrame = cv::imread("c:/data/eon55.jpg");
//    inputFrame.convertTo(inputFrame, CV_32F);
//
//
//    cv::Mat grayInputFrame;
//    cv::Mat normalizedInputFrame;
//    cv::cvtColor(inputFrame, grayInputFrame, cv::COLOR_BGR2GRAY);
//    cv::normalize(grayInputFrame, normalizedInputFrame, 1., 0, cv::NORM_MINMAX, CV_32F);
//
//    size_t step = 1;/*设置步长为1*/
//    cv::Mat kernelArrayCopy;/*定义一个卷积核的copy*/
//    size_t kernelSize = 3;/*定义卷积核的尺寸*/
//    size_t row = normalizedInputFrame.size().height;/*原始图的高度*/
//    size_t column = normalizedInputFrame.size().width;/*原始图的宽度*/
//  
//    float originalKernelArray[3][3] = { {0.01, 0.01, 0.01},
//                                        {0.01, 0.1,  0.001},
//                                        {0.001,0.05, 0.01} };
//
//
//    cv::Mat kernelArray(3, 3, CV_32F, originalKernelArray);
//
//
//    cv::Mat tempArray = cv::Mat::zeros(3, 3, CV_32F);/*存放扫描到的原始图的数据*/
//
//
//    size_t featureMapHeight = (row - kernelSize) / step + 1;/*卷积后特征图的高度*/
//    size_t featureMapWidth = (column - kernelSize) / step + 1;/*卷积后特征图的长度*/
//    cv::Mat featureMap = cv::Mat::zeros(featureMapHeight, featureMapWidth, CV_32F);/*初始化featureMap*/
//
//    
//    for (size_t i = 0; i < featureMapHeight; i += 2) {
//        for (size_t j = 0; j < featureMapWidth; j += 2) {
//
//            if (i + 1 >= featureMapHeight || j + 1 >= featureMapWidth) {
//                continue;
//            }
//
//            tempArray.at<float>(0,0) =  normalizedInputFrame.at<float>(i, j);
//            tempArray.at<float>(0, 1) = normalizedInputFrame.at<float>(i, j + 1);
//            tempArray.at<float>(0, 2) = normalizedInputFrame.at<float>(i, j + 2);
//
//            tempArray.at<float>(1, 0) = normalizedInputFrame.at<float>(i + 1, j);
//            tempArray.at<float>(1, 1) = normalizedInputFrame.at<float>(i + 1, j + 1);
//            tempArray.at<float>(1, 2) = normalizedInputFrame.at<float>(i + 1, j + 2);
//
//            tempArray.at<float>(2, 0) = normalizedInputFrame.at<float>(i + 2, j);
//            tempArray.at<float>(2, 1) = normalizedInputFrame.at<float>(i + 2, j + 1);
//            tempArray.at<float>(2, 2) = normalizedInputFrame.at<float>(i + 2, j + 2);
//
//            if (i >= featureMapHeight || j >= featureMapWidth) {
//                continue;
//            }
//            featureMap.at<float>(i,j)= (float)kernelArray.dot(tempArray);
//        }
//    }
//    cv::imshow("convon1", featureMap);
//    cv::waitKey(0);
//    maxPoolingFrame(featureMap);
//    
//}


