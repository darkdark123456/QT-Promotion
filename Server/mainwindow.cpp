#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(400,600);
    QString localIP=getLocalIP();
    ui->boxIP->addItem(localIP);

    tcpServer=new QTcpServer(this);
    QObject::connect(tcpServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
}


MainWindow::~MainWindow()
{
    delete ui;
}


QString MainWindow::getLocalIP(){
    QString hostName=QHostInfo::localHostName();
    QHostInfo hostInfo=QHostInfo::fromName(hostName);
    QString localIP;
    QList<QHostAddress>  addList=hostInfo.addresses();
    if(!addList.isEmpty()){
        for(int i=0;i<addList.count();i++){
            QHostAddress aHost=addList.at(i);
            if(aHost.protocol()==QAbstractSocket::IPv4Protocol){
                localIP=aHost.toString();
            }
        }
    }
    return localIP;
}



void MainWindow::onSocketStateChange(QAbstractSocket::SocketState socketState){

    switch (socketState) {
    case QAbstractSocket::UnconnectedState:
        ui->textSocketState->setText("socket state unconnected");
        break;
    case QAbstractSocket::ConnectingState:
        ui->textSocketState->setText("socket state connecting");
        break;
    case QAbstractSocket::ClosingState:
        ui->textSocketState->setText("socket state closing");
        break;
    case QAbstractSocket::ConnectedState:
        ui->textSocketState->setText("socket state connected");
        break;
    case QAbstractSocket::ListeningState:
        ui->textSocketState->setText("socket state listening");
        break;
}
}

void MainWindow::onSocketReadyRead(){
    while (tcpSocket->canReadLine()) {
        ui->plainTextEdit->appendPlainText("[server]"+tcpSocket->readLine());
    }
}


void MainWindow::on_actStart_triggered()
{
    QString ip=ui->boxIP->currentText();
    quint16 port=ui->boxPort->value();
    QHostAddress addr(ip);
    tcpServer->listen(addr,port);
    ui->plainTextEdit->appendPlainText("**????????????.....");
    ui->plainTextEdit->appendPlainText("**??????????????? "+tcpServer->serverAddress().toString());
    ui->plainTextEdit->appendPlainText("**??????????????? "+QString::number(tcpServer->serverPort()));
    ui->actStart->setEnabled(false);
    ui->actFinish->setEnabled(true);
    ui->textMonitorState->setText("????????????");
}


void MainWindow::onNewConnection(){
    tcpSocket=tcpServer->nextPendingConnection();
    onClientConnected();
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(onClientConnected()));
    connect(tcpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    onSocketStateChange(tcpSocket->state());
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(onSocketReadyRead()));
}


void MainWindow::onClientConnected(){
    ui->plainTextEdit->appendPlainText("**??????????????????");
    ui->plainTextEdit->appendPlainText("**ip "+tcpSocket->peerAddress().toString());
    ui->plainTextEdit->appendPlainText("**port"+QString::number(tcpSocket->peerPort()));
}



void MainWindow::onClientDisConnected(){
    ui->plainTextEdit->appendPlainText("**?????????????????????");
    tcpSocket->deleteLater();
}



void MainWindow::on_actFinish_triggered()
{
    if(tcpServer->isListening()){
        tcpServer->close();
        ui->actStart->setEnabled(false);
        ui->actFinish->setEnabled(true);
        ui->textMonitorState->setText("**????????????");
        ui->plainTextEdit->clear();
        ui->plainTextEdit->appendPlainText("**??????????????????");
    }
}


void MainWindow::on_actClear_triggered()
{
    ui->plainTextEdit->clear();
}


void MainWindow::on_actExit_triggered()
{
    this->close();
}


void MainWindow::on_btnSend_clicked()
{
    QString msg=ui->textInfo->text();
    ui->textInfo->clear();
    ui->textInfo->setFocus();
    QByteArray str=msg.toUtf8();
    str.append('\n');
    tcpSocket->write(str);
}

