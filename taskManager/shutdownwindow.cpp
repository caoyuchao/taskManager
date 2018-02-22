#include "shutdownwindow.h"
#include "ui_shutdownwindow.h"
#include<qinputdialog.h>
#include<iostream>
#include<unistd.h>
#include<pwd.h>
#include<shadow.h>
#include<qmessagebox.h>
shutdownWindow::shutdownWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shutdownWindow)
{
    ui->setupUi(this);
    connect(ui->btCancel,&QPushButton::clicked,this,&shutdownWindow::cancelButtonClicked);
    connect(ui->btShutdown,&QPushButton::clicked,this,&shutdownWindow::shutdownButtonClicked);
    connect(ui->btReboot,&QPushButton::clicked,this,&shutdownWindow::rebootButtonClicked);
}

shutdownWindow::~shutdownWindow()
{
    delete ui;
}


QString shutdownWindow::getInputPassword()
{
    bool isOk=false;
    QString password="";
    password = QInputDialog::getText(this,"注意","输入口令",QLineEdit::Password,"",&isOk);
    return password;
}

bool shutdownWindow::isPasswordCorrect(const QString& password)
{
    //    权限不足无法读取信息,死循环啊
    //    struct passwd* pwd;
    //    pwd=getpwuid(getuid());
    //    struct spwd* sp = getspnam(pwd->pw_name);
    //    if(sp!=NULL)
    //    {
    //        std::cout<<sp->sp_pwdp<<std::endl;
    //        QStringList cryptInfo=QString(sp->sp_pwdp).split('$');
    //        QString tmp=cryptInfo.at(1);
    //        QString cryptPassword=crypt(password.toStdString().c_str(),tmp.toStdString().c_str());//编译有错误
    //        return QString(cryptInfo.at(2)).compare(cryptPassword)==0;
    //    }
    return password.toStdString()=="123456";
}

void shutdownWindow::cancelButtonClicked()
{
    this->close();
}

void shutdownWindow::shutdownButtonClicked()
{
    QString password=getInputPassword();
    if(password.size()==0)
        return;
    if(isPasswordCorrect(password))
    {
        system("shutdown now");
    }
    else
    {
        QMessageBox::warning(this,"注意","口令错误");
    }
}

void shutdownWindow::rebootButtonClicked()
{
    QString password=getInputPassword();
    if(password.size()==0)
        return;
    if(isPasswordCorrect(password))
    {
        system("reboot");
    }
    else
    {
        QMessageBox::warning(this,"注意","口令错误");
    }
}
