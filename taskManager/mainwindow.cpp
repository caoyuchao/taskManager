#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qlayout.h>
#include<qlabel.h>
#include<qdatetime.h>
#include<QStringList>
#include<QSpacerItem>
#include"sysinfo.h"
#include"memory.h"

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow),preCpuStat(new cpuUseState),curCpuStat(new cpuUseState)
{
    ui->setupUi(this);
    ui->tbrCpuInfo->setStyleSheet("border:0px;background-color:transparent");
    timer=new QTimer(this);
    getCpuUseState(curCpuStat);
    connect(timer,&QTimer::timeout,this,&mainWindow::updateTime);
    connect(timer,&QTimer::timeout,this,&mainWindow::updateCpuUseRate);
    connect(timer,&QTimer::timeout,this,&mainWindow::updateMemUseRate);
    fillSystemInfo();
    createStatusBar();
    updateTime();
    updateCpuUseRate();
    updateMemUseRate();
    timer->start(1000);
}

QString mainWindow::secTransToDHMS(int seconds)
{
    QString time="";
    int tmp=seconds/86400;
    seconds%=86400;
    if(tmp!=0)
    {
        time.append(QString("%1天").arg(tmp));
    }
    tmp=seconds/3600;
    seconds%=3600;
    if(tmp!=0)
    {
        time.append(QString("%1小时").arg(tmp));
    }
    tmp=seconds/60;
    seconds%=60;
    if(tmp!=0)
    {
        time.append(QString("%1分钟").arg(tmp));
    }
    time.append(QString("%1秒").arg(seconds));
    return time;
}


QString mainWindow::getStartTime()
{
    uint curSeconds=QDateTime::currentDateTime().toTime_t();
    uint runSeconds=(uint)getRunTimeSeconds();
    return QDateTime::fromTime_t(curSeconds-runSeconds).toString("yyyy-MM-dd hh:mm:ss dddd");

}

void mainWindow::fillSystemInfo()
{
    ui->lbDevName->setText(getHostname().c_str());
    ui->lbStartTime->setText(getStartTime());
    ui->lbRunTime->setText(QString("%1").arg(secTransToDHMS((int)getRunTimeSeconds())));
    ui->lbSysVersion->setText(getOsType().c_str());

    QString cpuInfo(getBasicFrequency().c_str());
    QStringList cores=cpuInfo.split("#");
    for(QString core:cores)
    {
        ui->tbrCpuInfo->append(core);
        ui->tbrCpuInfo->append("");
    }
}

QLabel* mainWindow::getAGeneralLabel(int minw)
{
    QLabel* label=new QLabel(this);
    label->setMinimumWidth(minw);
//    abel->setFrameShape(QFrame::WinPanel);
    return label;
}

QPushButton* mainWindow::getAGeneralButton(const QString& text)
{
    QPushButton* button=new QPushButton(text,this);
    button->setMinimumWidth(120);
    return button;
}

void mainWindow::createStatusBar()
{
    QStatusBar* status=statusBar();
    status->addWidget(lbCurTime=getAGeneralLabel(280));
    status->addWidget(lbCpuUse=getAGeneralLabel(180));
    status->addWidget(lbMemUse=getAGeneralLabel(180));
    status->addPermanentWidget(btEndTask=getAGeneralButton("结束任务"));
    status->addPermanentWidget(btShutdown=getAGeneralButton("关机"));
    status->setStyleSheet("font-size:18px;font-family:SimSun");
}

void mainWindow::updateTime()
{
    ui->lbRunTime->setText(QString("%1").arg(secTransToDHMS((int)getRunTimeSeconds())));
    lbCurTime->setText("  "+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
}

void mainWindow::updateCpuUseRate()
{
    *preCpuStat=*curCpuStat;
    getCpuUseState(curCpuStat);
    double cpuRate=calcuCpuRate(preCpuStat,curCpuStat);
    lbCpuUse->setText(QString("CPU使用率 ").append(QString::number(cpuRate,'f',2).append("%")));
}

void mainWindow::updateMemUseRate()
{
    memUseState mem;
    getMemUseState(&mem);
    double memRate=calcuMemMemRate(&mem);
    lbMemUse->setText(QString("内存使用率 ").append(QString::number(memRate,'f',2)).append("%"));
}

mainWindow::~mainWindow()
{
    delete ui;
    delete preCpuStat;
    delete curCpuStat;
}
