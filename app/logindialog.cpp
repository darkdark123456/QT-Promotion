#include "logindialog.h"
#include "ui_logindialog.h"
#include <QScreen>
#include <QMessageBox>
#include <QDebug>


loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);    QScreen *screen=QGuiApplication::primaryScreen();
    int w=screen->size().width();
    int h=screen->size().height();
    setFixedSize(w,h);
}


loginDialog::~loginDialog()
{
    delete ui;
}


void loginDialog::on_btnOK_clicked()
{
    QString inputUsername=ui->textUsername->text().trimmed();
    QString inputPasswd=ui->textPasswd->text().trimmed();
    if(inputUsername==NULL || inputPasswd==NULL){
        QMessageBox::warning(this,"","用户名或密码为空");
        return;
    }

    /*start 增加一个新的功能用来保存用户名到本地文件中，下次登录时，不用再输入用户名*/
    QFile file("assets:/database/username.txt");
    file.setPermissions(QFile::WriteUser);
    QByteArray usernameBytes=inputUsername.toUtf8();
    file.write(usernameBytes,usernameBytes.length());
    file.close();
    /*end*/

    QAndroidJniObject mactivity= QtAndroid::androidActivity();
    QAndroidJniObject USERNAME = QAndroidJniObject::fromString(inputUsername);
    QAndroidJniObject PASSWD   = QAndroidJniObject::fromString(inputPasswd);

    jstring jUSERNAME=USERNAME.object<jstring>();
    jstring jPASSWD = PASSWD.object<jstring>();
    mactivity.callStaticObjectMethod("com/javaForcpp/UserLogin","setUsername","(Ljava/lang/String;)Ljava/lang/String;",jUSERNAME);
    mactivity.callStaticObjectMethod("com/javaForcpp/UserLogin","setPasswd","(Ljava/lang/String;)Ljava/lang/String;",jPASSWD);
    mactivity.callStaticObjectMethod("com/javaForcpp/UserLogin","printUserInfo","(Ljava/lang/String;)Ljava/lang/String;",NULL);
    QAndroidJniObject loginStatus=mactivity.callStaticObjectMethod("com/javaForcpp/UserLogin","callgetConnectDatabase","(Ljava/lang/String;)Ljava/lang/String;",NULL);
    if(loginStatus.toString()=="1"){
            subjectSelectDialog=new Dialog(this);
            subjectSelectDialog->show();
    }
    else{
        QMessageBox::critical(this,"","登录失败，密码或用户错误，请重新登录！");
    }
}


void loginDialog::on_btnReturn_clicked()
{
    this->close();
}

