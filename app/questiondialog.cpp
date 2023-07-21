#include "questiondialog.h"
#include "ui_questiondialog.h"
#include<QScreen>


questionDialog::questionDialog(QWidget *parent,QString name) :
    QDialog(parent),
    ui(new Ui::questionDialog)
{
    subjectName=name;
    ui->setupUi(this);
    QScreen *screen=QGuiApplication::primaryScreen();
    int w=screen->size().width();
    int h=screen->size().height();
    setFixedSize(w,h);
    getQuestionTextlineAndAnswer();
    iterator=hashQuestionAnswer.begin();
    vectorQuestion.push_back(iterator.key());
    ui->textEdit->setText(iterator.key());
    image.loadFromData(hashQuestionAndImage.find(iterator.key()).value());
    ui->imageLabel->setPixmap(image);
    ui->imageLabel->setStyleSheet("background-color: transparent");
}


questionDialog::~questionDialog()
{
    delete ui;
}


/*Get the text of the button*/
void questionDialog::on_btnA_clicked(){  newAnswer=ui->btnA->text();    }


void questionDialog::on_btnB_clicked(){  newAnswer=ui->btnB->text();   }


void questionDialog::on_btnC_clicked(){  newAnswer=ui->btnC->text();    }


void questionDialog::on_btnD_clicked(){  newAnswer=ui->btnD->text();    }


/*Comparison of answers when the submit button is clicked*/
void questionDialog::on_btnHandOn_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this,"","是否确认交卷");
    if(reply==QMessageBox::Yes){
        contrastQuestionAnswer(vectorAnswer,vectorBtnAnswer);
    }
    else{
        return;
    }
}


void questionDialog::contrastQuestionAnswer(QVector<QString> &vectorAnswer, QVector<QString> &vectorBtnAnswer){
    Q_UNUSED(vectorAnswer);
    answerDlg *answerDialog=new answerDlg(this);
    size_t questionNumbers=vectorBtnAnswer.size();
    Q_UNUSED(questionNumbers);
    for(size_t questionNumber=0;questionNumber<questionNumbers;questionNumber++){
        if(vectorBtnAnswer[questionNumber]== hashQuestionAnswer.find(vectorQuestion[questionNumber]).value()){
            (answerDialog->labelVector[questionNumber])->setStyleSheet("color: rgb(85, 255, 0);");
        }
        else{
            (answerDialog->labelVector[questionNumber])->setStyleSheet("color: rgb(255, 0, 0);");
        }
    }
    answerDialog->show();
}


/*How the interface reacts when the button is clicked*/
void questionDialog::on_btnNextQuestion_clicked()
{
    if(newAnswer!=NULL){
        vectorBtnAnswer.push_back(newAnswer);
    }
    else{
        /*Replaced with asterisks when the user did not click on the answer */
        vectorBtnAnswer.push_back("*");
    }
    if(++iterator!=hashQuestionAnswer.end()){
        ui->textEdit->clear();
        ui->textEdit->setText(iterator.key());
        image.loadFromData(nullptr);
        image.loadFromData(hashQuestionAndImage.find(iterator.key()).value());
        ui->imageLabel->setPixmap(image);
        ui->imageLabel->setStyleSheet("background-color: transparent");
        vectorQuestion.push_back(iterator.key());
        refreshButtonSelection();
    }
    else {
        --iterator;
        if(vectorAnswer.size()<vectorBtnAnswer.size()){
            vectorBtnAnswer.pop_front();
        }
        QMessageBox::information(this,"","当前已经是最后一题");
        /* remove redundant * */

    }
}



/*Functions that are not currently used*/
void questionDialog::displayQuestuonText(const QString &question){
    Q_UNUSED(question);
}


bool questionDialog::getRequestionPermission(){
    QtAndroid::PermissionResult permissionResult=QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE");
    if(permissionResult==QtAndroid::PermissionResult::Denied){
        QtAndroid::requestPermissionsSync(QStringList()<<"android.permission.WRITE_EXTERNAL_STORAGE");
        permissionResult = QtAndroid::checkPermission("android.permission.CAMERA");
        if(permissionResult == QtAndroid::PermissionResult::Denied) {
             return false;
        }
    }
    return true;
}


/*Get permission for android phone*/
bool questionDialog::getQuestionTextlineAndAnswer(){
    getRequestionPermission();
    QString question;
    QString getAnswer;
    QSqlDatabase dataBase=QSqlDatabase::addDatabase("QSQLITE");
    QFile file("assets:/database/data.db");/*在安卓手机后台使用这个路径获取数据*/ /*安卓手机访问本地数据库时看这里*/
    if(file.exists()){
        QSqlDatabase dataBase=QSqlDatabase::addDatabase("QSQLITE");
        file.copy("./data2.db");/*将assets下的数据库复制一份访问它的副本*/
        QFile::setPermissions("./data2.db",QFile::WriteOwner | QFile::ReadOwner);
        dataBase.setDatabaseName("data2.db");
        if(!dataBase.open()){
            QMessageBox::information(this,"","题库未打开");
            return false;
        }
        QSqlQuery query(dataBase);
        QString sqlQuery=QString("select * from %1 ").arg(this->subjectName);
        query.exec(sqlQuery);
        while(query.next()){
            question=query.value(0).toString();
            getAnswer=query.value(1).toString();
            imageByteArray=query.value(2).toByteArray();
            hashQuestionAndImage.insert(question,imageByteArray);
            hashQuestionAnswer.insert(question,getAnswer);
            vectorAnswer.push_back(getAnswer);
        }
    return true;
}
    return false;
}


/*Refresh the current state of the button*/
void questionDialog::refreshButtonSelection(){
    if(ui->btnA->isChecked()){
        ui->btnA->setAutoExclusive(false);
        ui->btnA->setChecked(false);
        ui->btnA->setAutoExclusive(true);
    }
    else if(ui->btnB->isChecked()){

        ui->btnB->setAutoExclusive(false);
        ui->btnB->setChecked(false);
        ui->btnB->setAutoExclusive(true);
    }
    else if(ui->btnC->isChecked()){
        ui->btnC->setAutoExclusive(false);
        ui->btnC->setChecked(false);
        ui->btnC->setAutoExclusive(true);
    }
    else{
        ui->btnD->setAutoExclusive(false);
        ui->btnD->setChecked(false);
        ui->btnD->setAutoExclusive(true);}
}













