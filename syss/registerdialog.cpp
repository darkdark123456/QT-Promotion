#include "registerdialog.h"
#include "ui_registerdialog.h"
#include <QMessageBox>
#include <QTimer>
#include <windows.h>

registerDialog::registerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerDialog)
{
    ui->setupUi(this);
    regster();
}


registerDialog::~registerDialog()
{
    delete ui;
}


void registerDialog::regster(){
    QFont *font=new  QFont();
    font->setBold(true);
    font->setItalic(true);
    QHBoxLayout *hLayout=new QHBoxLayout();
    QLabel *labelImage=new   QLabel(this);
    QString photoName=QString(".//%1.jpg").arg(ui->idText->text());
    labelImage->setFixedSize(300,400);
    labelImage->setStyleSheet("color:blue;");
    labelImage->setText("图\n像\n显\n示\n区\n域");
    labelImage->setFont(*font);
    labelImage->setAlignment(Qt::AlignHCenter);
    setWindowTitle("用户注册界面");
    hLayout->addWidget(labelImage);
    cv::VideoCapture capture(0);
    std::vector<cv::Rect> rect;
    //static cv::CascadeClassifier cscadeClassifier(".//haarcascade_frontalface_alt.xml");
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
    QPixmap pixmap(photoName);
    labelImage->setPixmap(pixmap);
    photo=pixmap;
}


void registerDialog::registerInfo(){
    QString ID=ui->idText->text();
    QString name=ui->nameText02->text();
    QString age=ui->ageText02->text();
    QString sex=ui->boxSex02->currentText();
    QString dep=ui->boxDepartment02->currentText();
    /*将照片存在buffer里*/
    QPixmap usrPhoto=photo;
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    usrPhoto.save(&buffer,"jpg");

    if(name==NULL || age==NULL|| sex==NULL ||  dep==NULL || ID==NULL ){
        QMessageBox::information(this,"注册信息","信息注册失败，请输入完整信息！");
    }
    else{
        QMessageBox::information(this,"注册信息","注册成功,请返回打卡");
        dataBase=QSqlDatabase::addDatabase("QSQLITE");
        dataBase.setDatabaseName("./data.db");
        if(!dataBase.open()){
            QMessageBox::warning(this,"error","cant open usErData");
        }
        QSqlQuery query(dataBase);
        query.prepare("insert into usrData(ID,Name,Age,Sex,Department,Photo) values(:id,:name,:age,:sex,:department,:photo)");
        query.bindValue(":id",ID);
        query.bindValue(":name",name);
        query.bindValue(":age",age.toInt());
        query.bindValue(":sex",sex);
        query.bindValue(":department",dep);
        query.bindValue(":photo",byteArray);/*将图片二进制存放*/
        query.exec();
        Sleep(1000);
        this->close();
    }
}


void registerDialog::on_btnOK02_clicked()
{
    registerInfo();
}


void registerDialog::on_btnCancel02_clicked()
{

    this->close();
}
