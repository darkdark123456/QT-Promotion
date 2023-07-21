#include "userdatadlg.h"
#include "ui_userdatadlg.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtAndroid>
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>
#include <QDebug>

userDataDlg::userDataDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userDataDlg)
{
    ui->setupUi(this);
    QScreen *screen=QGuiApplication::primaryScreen();
    int w=screen->size().width();
    int h=screen->size().height();
    setFixedSize(w,h);
    ui->textPasswd->setEchoMode(QLineEdit::Password);
    ui->textConfirmPasswd->setEchoMode(QLineEdit::Password);
}

userDataDlg::~userDataDlg()
{
    delete ui;
}

void userDataDlg::on_btnOK_clicked()
{
    QString userName=ui->textUserName->text();
    if(userName==NULL){
        QMessageBox::warning(this,"","用户名不能为空！");
        return ;
    }

    QString passwd001=ui->textPasswd->text();
    QString passwd002=ui->textConfirmPasswd->text();



    std::string stdPassed001=passwd001.toStdString();
    std::string stdPasswd002=passwd002.toStdString();


    this->username=userName;
    this->passwd=passwd001;
    this->registerCode=ui->textRegisterCode->text();
    this->registerCode=this->registerCode.trimmed();


    /*if registerCode < 16 bit ,return*/

    if(registerCode.length()<16){
        QMessageBox::critical(this,"","激活码错误！");
        return;
    }


    /*if encode's length < 8 bit ,return */

    if(passwd001.length()<8 || passwd002.length()<8){
        QMessageBox::critical(this,"","密码长度应该大于8位");
        return;
    }

    if(passwd001 != passwd002){
        QMessageBox::critical(this,"","两次输入的密码不一致，请重新输入！");
        return  ;
    }


    size_t passwdLocatioNumber=0;

    for (;passwdLocatioNumber<stdPassed001.length() ;passwdLocatioNumber++ ) {
        char currentChar=stdPassed001[passwdLocatioNumber];
        if((int)currentChar<58 && int(currentChar)>47){
            continue;
        }
        else{
            break;
        }
    }

    if(passwdLocatioNumber==stdPassed001.length()){
        QMessageBox::critical(this,"","密码组合过于简单,密码包括数字，字符，其他字符至少两种");
        return;
    }

    QAndroidJniObject mactivity= QtAndroid::androidActivity();
    QAndroidJniObject USERNAME = QAndroidJniObject::fromString(this->username);
    QAndroidJniObject PASSWD   = QAndroidJniObject::fromString(this->passwd);
    QAndroidJniObject REGISTERCODE=QAndroidJniObject::fromString(this->registerCode);
    jstring jUSERNAME=USERNAME.object<jstring>();
    jstring jPASSWD = PASSWD.object<jstring>();
    jstring jREGISTERCODE=REGISTERCODE.object<jstring>();
    mactivity.callStaticObjectMethod("com/javaForcpp/jdbcForCplusCplus","setInfoRegisterCode","(Ljava/lang/String;)Ljava/lang/String;",jREGISTERCODE);
    mactivity.callStaticObjectMethod("com/javaForcpp/jdbcForCplusCplus","setInfoUsername","(Ljava/lang/String;)Ljava/lang/String;",jUSERNAME);
    mactivity.callStaticObjectMethod("com/javaForcpp/jdbcForCplusCplus","setInfoPASSWD","(Ljava/lang/String;)Ljava/lang/String;",jPASSWD);
    QAndroidJniObject JavaActivationFlag=mactivity.callStaticObjectMethod("com/javaForcpp/jdbcForCplusCplus","returnActivationFlag","(Ljava/lang/String;)Ljava/lang/String;",NULL);
    QString ActivationFlag=JavaActivationFlag.toString();
    QMessageBox::information(this,"",ActivationFlag);
    /*   得到java返回注册状态    如果状态为真，提示用户返回登录，如果为假则提示注册错误 */
    /*   这里假设得到的注册状态为真 */
    ActivationFlag="1";
    if(ActivationFlag=="1"){
        QMessageBox::information(this,"","注册成功,请返回登录界面进行登录！");
    }
    else{
        QMessageBox::critical(this,"","注册失败，请重新注册！");
    }

}


void userDataDlg::on_btnCancel_clicked()
{
    this->close();
}

