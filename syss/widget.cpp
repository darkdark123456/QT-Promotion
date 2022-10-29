#include "widget.h"
#include "ui_widget.h"
#include <windows.h>
#include <QPainter>
#include <QMessageBox>
#include <dlib/image_processing.h>
#include <opencv2/opencv.hpp>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(800,600);
    setWindowIcon(QIcon("://icon6.ico"));
    connect(ui->userRegisterBtn,SIGNAL(clicked()),this,SLOT(onlyOneUserRegisterMoment()));
    connect(regDialog,SIGNAL(destroyed()),this,SLOT(recoverUseRegisterBtn()));
    localTimer =new QTimer(this);
    connect(localTimer,SIGNAL(timeout()),this,SLOT(updateLocalTime()));
    localTimer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::updateLocalTime(){
    QDateTime time=QDateTime::currentDateTime();
    QString strTime=time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->timeLabel->setText(strTime);
    /* 到晚上8点自动刷新flag*/
    int hours=(QString("%1%2").arg(strTime[11]).arg(strTime[12])).toInt();
    int minutes=(QString("%1%2").arg(strTime[14]).arg(strTime[15])).toInt();

    if(hours==20 && minutes==0){
        QString querySQL;
        querySQL=QString("UPDATE usrData SET flag=%1").arg(0);
        QSqlDatabase dataBase=QSqlDatabase::addDatabase("QSQLITE");
        dataBase.setDatabaseName("./data.db");
        if(!dataBase.open()){
           QMessageBox::information(this,"error","errorOpenDataBase!");

        }
        QSqlQuery query(dataBase);
        query.exec(querySQL);
        query.finish();
    }

}


void Widget::on_userRegisterBtn_clicked()
{
    regDialog =new registerDialog(this);
    regDialog->show();
}


void Widget::on_pushButton_2_clicked()
{
    QDialog *dialog=new QDialog();
    dialog->setFixedSize(600,400);
    dialog->setWindowTitle("帮助");
    QLabel *label=new QLabel(dialog);
    label->setText("**************本软件由作者孟振川开发,属于开源项目，\n"
                   "详细操作请转至**************");
    QFont font;
    font.setBold(true);
    font.setItalic(true);
    label->setFont(font);
    label->setStyleSheet("color:blue;");
    dialog->show();
}


void Widget::on_pushButton_clicked(){
ui->userRegisterBtn->setEnabled(true);
}


void Widget::onlyOneUserRegisterMoment(){
    ui->userRegisterBtn->setEnabled(true);
}

void Widget::recoverUseRegisterBtn(){
    ui->userRegisterBtn->setEnabled(true);
}

void Widget::on_userRegisterBtn_2_clicked()
{
    QMessageBox::information(this,"二维码登录","此功能暂未开放，请返回 ");
}


void Widget::on_btnPunch_clicked()
{

    /*获取系统的当前时间，只允许在6:00-8:00内签到*/
    QString sysNowTime=ui->timeLabel->text();
    int years=(QString("%1%2%3%4").arg(sysNowTime[0]).arg(sysNowTime[1]).arg(sysNowTime[2]).arg(sysNowTime[3])).toInt();
    int months=(QString("%1%2").arg(sysNowTime[5]).arg(sysNowTime[6])).toInt();
    int day=(QString("%1%2").arg(sysNowTime[8]).arg(sysNowTime[9])).toInt();
    int hours=(QString("%1%2").arg(sysNowTime[11]).arg(sysNowTime[12])).toInt();
    int minutes=(QString("%1%2").arg(sysNowTime[14]).arg(sysNowTime[15])).toInt();

    Q_UNUSED(months);
    Q_UNUSED(day);
    Q_UNUSED(minutes);

    if(years < 2022){   return; }
    /*只允许在[6:00,8:00]内签到*/
//    if(hours>8 ||  hours<6) {
//        QMessageBox::critical(this,"错误","已过签到时间，无法签到！");
//        return ;}

    /*提示输入用户ID*/
    if(ui->idText->text()==NULL){
        QMessageBox::critical(this,"出错","请输入用户ID");
        return ;
    }
    QString ID=ui->idText->text();
    QString querySQL;
    querySQL=QString("select * from usrData where ID=%1").arg(ID);
    QSqlDatabase dataBase=QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("./data.db");
    if(!dataBase.open()){
       QMessageBox::information(this,"error","error  ");

    }
    QSqlQuery query(dataBase);
    query.exec(querySQL);
    query.next();
    QString name=query.value(1).toString();
    QString age=query.value(2).toString();
    QString sex=query.value(3).toString();
    QString department=query.value(4).toString();
    int punchTime=query.value(6).toInt();
    QByteArray byteArray=query.value(5).toByteArray();
    bool flag=query.value(7).toBool();

    /*如果用户在规定时间已经签到，又再次签到，禁止，直接返回*/
    if(flag==1){
        QMessageBox::warning(this,"警告","你今天已经完成签到，今天内无法再次签到！");
        return ;
    }

    QPixmap oldPixmap;
    oldPixmap.loadFromData(byteArray);
    cv::Mat resultFaceImage001;
    cv::Mat resultFaceImage002;
    static cv::CascadeClassifier cscadeClassifier("./haarcascade_frontalface_alt.xml");
    QImage image;
    double Scale=0.6;
    cv::Mat Frame;

    Q_UNUSED(Scale);

    ui->Name->setText(name);
    ui->ageName->setText(age);
    ui->sexName->setText(sex);
    ui->Department->setText(department);
    ui->photo->setPixmap(oldPixmap);


    cv::VideoCapture capture(0);
    std::vector<cv::Rect> rect;
    QString photoName=QString("./%1.jpg").arg(ui->ID->text());

    while(capture.isOpened()){
        cv::Mat frame;
        capture>>frame;
        cv::imshow("register window",frame);
        cv::resize(frame,frame,cv::Size(300,400));
        cv::imwrite(photoName.toStdString(),frame);
        cv::waitKey(1);
        if(cv::getWindowProperty("register window",cv::WND_PROP_VISIBLE)<1){
            break;
        }
    }
    capture.release();

    QPixmap newPixmap(photoName);
    QImage newFaceImage=newPixmap.toImage().convertToFormat(QImage::Format_RGB888);
    QImage oldFaceImage=oldPixmap.toImage().convertToFormat(QImage::Format_RGB888);
    cv::Mat newMatFaceImage(newFaceImage.height(),newFaceImage.width(),CV_8UC3,(uchar*)newFaceImage.bits(),newFaceImage.bytesPerLine());
    cv::Mat oldMatFaceImage(oldFaceImage.height(),oldFaceImage.width(),CV_8UC3,(uchar*)oldFaceImage.bits(),oldFaceImage.bytesPerLine());

    /*检测数据库的人脸*/
    cv::Mat resultOldMatFaceImage;
    cv::cvtColor(oldMatFaceImage,resultOldMatFaceImage,cv::COLOR_BGR2GRAY);
    cscadeClassifier.detectMultiScale(resultOldMatFaceImage,rect,1.1,2,0,cv::Size(80,30));
    for(size_t number=0;number<rect.size();number++){
        cv::rectangle(oldMatFaceImage,rect[number],cv::Scalar(0,0,255));
        resultFaceImage002=oldMatFaceImage(cv::Rect(rect[number].x,rect[number].y,rect[number].width,rect[number].height));/*裁剪数据库中的人脸区域*/
    }

    /*检测摄像头中的人脸*/
    cv::Mat resultNewMatFaceImage;
    cv::cvtColor(newMatFaceImage,resultNewMatFaceImage,cv::COLOR_BGR2GRAY);
    cscadeClassifier.detectMultiScale(resultNewMatFaceImage,rect,1.1,2,0,cv::Size(80,40));
    for(size_t number=0;number<rect.size();number++){
        cv::rectangle(newMatFaceImage,rect[number],cv::Scalar(0,0,255));
        resultFaceImage001=newMatFaceImage(cv::Rect(rect[number].x,rect[number].y,rect[number].width,rect[number].height));/*裁剪摄像头中的人脸区域*/
    }

    std::vector<int>newFaceImageHashFingers=templateImageHashFingers(newMatFaceImage);
    std::vector<int>oldFaceImageHashFingers=templateImageHashFingers(oldMatFaceImage);
    double imageContrastSimilarityRatio=imageContrastRatio(newFaceImageHashFingers,oldFaceImageHashFingers,getImageShape(newMatFaceImage),oldMatFaceImage);
    if(imageContrastSimilarityRatio>0.65){
        ui->idText->clear();
        ui->Name->clear();
        ui->ageName->clear();
        ui->sexName->clear();
        ui->Department->clear();
        ui->photo->clear();

        /*数据库签到次数加1并更新每日的签到标记*/
        if(flag==0){
            QMessageBox::information(this,"","签到成功");
            ++punchTime;
            flag=1;
            querySQL=QString("UPDATE usrData SET punchTime=%1, flag=%2 where ID=%3").arg(punchTime).arg(flag).arg(ID);
            query.exec(querySQL);
            query.finish();
        }


    }
    else{
        QMessageBox::critical(this,"ERROR","打卡失败，请重新打卡！");
    }


}


double Widget::imageContrastRatio(std::vector<int> &newFaceImageHashFingers,std::vector<int> &oldFaceImageHashFingers,
                                  std::vector<int> imageShape,
                                  cv::Mat image){
    int width=imageShape[1];
    int pixNum=imageShape[2];
    cv::Mat result=image.clone();
    int differentNum=0;
    for(int number=0;number<pixNum;number++){
        if(newFaceImageHashFingers[number]!=oldFaceImageHashFingers[number]){
            ++differentNum;
            int col=int(number%width);
            int row=int((number-col)/width);
            result.at<cv::Vec3b>(row,col)=cv::Vec3b(0,0,255);
        }
    }
    double imageContrastRatio=( 1-  (double(differentNum) / double(pixNum)));
    return imageContrastRatio;
}


std::vector<int> Widget::getImageShape(cv::Mat &matSrcImage){
    std::vector<int> shapeVector;
    cv::Mat matResultImage;
    cv::cvtColor(matSrcImage,matResultImage,cv::COLOR_BGR2GRAY);
    int widget=matResultImage.cols;
    int height=matResultImage.rows;
    int pixelNum=widget*height;
    shapeVector.push_back(height);
    shapeVector.push_back(widget);
    shapeVector.push_back(pixelNum);
    return shapeVector;
}


std::vector<int> Widget:: templateImageHashFingers(cv::Mat &matSrcImage){
    std::vector<int> imageShapeVector=getImageShape(matSrcImage);
    std::vector<int> imageFingers;
    cv::Mat matResultImage;
    int pixSum=0;
    int height=imageShapeVector[0];
    int widget=imageShapeVector[1];
    int pixelNum=imageShapeVector[2];
    cv::cvtColor(matSrcImage,matResultImage,cv::COLOR_BGR2GRAY);
    cv::resize(matResultImage,matResultImage,cv::Size(widget,height));
    uchar *current=matResultImage.data;
    for(;current!=matResultImage.dataend;current++){
        int pixValue=int(*current);
        pixSum+=pixValue;
    }
    double templateGrayAverage=double(pixSum)/pixelNum;
    for(uchar *number=matResultImage.data;number!=matResultImage.dataend;number++){
        int imagefingers=0;
        if(*number>=templateGrayAverage){
            imagefingers=1;
        }
        imageFingers.push_back(imagefingers);
    }
    return imageFingers;
}


