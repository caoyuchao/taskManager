#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qlayout.h>
#include<qlabel.h>
#include<qdatetime.h>
#include<QStringList>
#include<QSpacerItem>
#include<qscrollbar.h>
#include"sysinfo.h"
#include"memory.h"
#include"process.h"
#include<qevent.h>
#include<qprocess.h>
#include<qheaderview.h>
#include<iostream>
mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow),preCpuStat(new cpuUseState),curCpuStat(new cpuUseState)
  ,pidToBeKilled(-1)
  //    ,isEverSelectTabRecord(false)
{
    ui->setupUi(this);
    ui->tbrCpuInfo->setStyleSheet("border:0px;background-color:transparent");
    ui->tbrDetails->setStyleSheet("border:0px;background-color:transparent");
    ui->lnEdQuery->installEventFilter(this);
    timer=new QTimer(this);
    getCpuUseState(curCpuStat);
    createStatusBar();//中间要创建,需要在connect之前
    connect(timer,&QTimer::timeout,this,&mainWindow::updateTime);
    connect(timer,&QTimer::timeout,this,&mainWindow::updateCpuUseRate);
    connect(timer,&QTimer::timeout,this,&mainWindow::updateMemUseRate);
    connect(timer,&QTimer::timeout,this,&mainWindow::updateProcessesInfo);
    connect(ui->btQuery,&QPushButton::clicked,this,&mainWindow::queryProcessInfo);
    connect(ui->btNewPro,&QPushButton::clicked,this,&mainWindow::createANewProcess);
    connect(ui->tbwProInfo->horizontalHeader(),&QHeaderView::sectionClicked,this,&mainWindow::headerSectionClicked);
    connect(btEndTask,&QPushButton::clicked,this,&mainWindow::endTask);
    //    connect(ui->tbwProInfo,&QTableWidget::clicked,[=](){isEverSelectTabRecord=true;});
    fillSystemInfo();
    updateTime();
    updateCpuUseRate();
    updateMemUseRate();
    setTBWHeaders();
    timer->start(1000);
}

bool mainWindow::eventFilter(QObject* obj, QEvent* e)
{
    //Q_ASSERT(obj == ui->queryButton);//need Release
    if(ui->tabWidgets->currentIndex()!=2)
        return false;
    if (e->type() == QEvent::KeyPress)
    {
        QKeyEvent* event = static_cast<QKeyEvent*>(e);
        if (event->key() == Qt::Key_Return)
        {
            queryProcessInfo();
            return true;
        }
    }
    return false;
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

void mainWindow::setTBWHeaders()
{
    QStringList tbwProInfoHeaders;
    tbwProInfoHeaders << "进程名称" << "pid" << "ppid" << "内存占用/KB"<<"优先级(nice)";
    ui->tbwProInfo->setHorizontalHeaderLabels(tbwProInfoHeaders);
}

void mainWindow::headerSectionClicked(int index)
{
    std::cout<<index<<std::endl;
}

void mainWindow::insertARowIntoTable(const processInfo* const process,int rowsIndex)
{
    int rows = ui->tbwProInfo->rowCount();

    QTableWidgetItem* name=new QTableWidgetItem(process->name.c_str());
    QTableWidgetItem* pid=new QTableWidgetItem(QString("%1").arg(process->pid));
    QTableWidgetItem* ppid=new QTableWidgetItem(QString("%1").arg(process->ppid));
    QTableWidgetItem* rss=new QTableWidgetItem(QString("%1").arg(process->rss*getpagesize()/1024));
    QTableWidgetItem* priority=new QTableWidgetItem(QString("%1").arg(process->priority));

    if(rowsIndex>=rows)
    {
        ui->tbwProInfo->setRowCount(rows + 1);
        ui->tbwProInfo->setItem(rows, 0, name);
        ui->tbwProInfo->setItem(rows, 1, pid);
        ui->tbwProInfo->setItem(rows, 2, ppid);
        ui->tbwProInfo->setItem(rows, 3, rss);
        ui->tbwProInfo->setItem(rows, 4, priority);
    }
    else
    {
        ui->tbwProInfo->setItem(rowsIndex, 0, name);
        ui->tbwProInfo->setItem(rowsIndex, 1, pid);
        ui->tbwProInfo->setItem(rowsIndex, 2, ppid);
        ui->tbwProInfo->setItem(rowsIndex, 3, rss);
        ui->tbwProInfo->setItem(rowsIndex, 4, priority);
    }

}

void mainWindow::removeAllRows()
{
    size_t rows = ui->tbwProInfo->rowCount();
    for (size_t index = 0; index < rows; index++)
        ui->tbwProInfo->removeRow(0);
}

void mainWindow::updateProcessesInfo()
{
    //   if(ui->tabWidgets->currentIndex()!=1&&!isEverSelectTabRecord)
    //      return;
    int row=ui->tbwProInfo->currentIndex().row();
    int hvalue=ui->tbwProInfo->verticalScrollBar()->value();
    getProcessesInfo(processes);
    removeAllRows();
    int rowsIndex=0;
    for(auto iter=processes.begin();iter!=processes.end();++iter,++rowsIndex)
    {
        insertARowIntoTable(iter.value(),rowsIndex);
    }
    if(row<rowsIndex)
    {
        ui->tbwProInfo->setCurrentCell(row,QItemSelectionModel::Select);
        ui->tbwProInfo->verticalScrollBar()->setValue(hvalue);
    }
}

void mainWindow::showProcessInfo(const processInfo * const process)
{
    ui->tbrDetails->setText(QString("进程名      ： %1").arg(process->name.c_str()));
    ui->tbrDetails->append(QString("进程pid号   ： %1").arg(pidToBeKilled=process->pid));
    ui->tbrDetails->append(QString("父进程pid号 ： %1").arg(process->ppid));
    ui->tbrDetails->append(QString("进程占用内存： %1KB").arg(process->rss*getpagesize()/1024));
    ui->tbrDetails->append(QString("进程优先级  ： %1").arg(process->pid));
}

void mainWindow::queryProcessInfo()
{
    if(ui->rbutton->isChecked())
    {
        QString processName=ui->lnEdQuery->text().trimmed();
        for(auto iter=processes.begin();iter!=processes.end();++iter)
        {
            if(iter.value()->name==processName.toStdString())
            {
                showProcessInfo(iter.value());
                return;
            }
        }
    }
    else
    {
        pid_t pid=ui->lnEdQuery->text().trimmed().toShort();
        if(processes.contains(pid))
        {
            showProcessInfo(processes[pid]);
            return;
        }
    }
    ui->tbrDetails->setText("检查进程名或检查查询方式是否正确");
}

void mainWindow::createANewProcess()
{
    QString name=ui->lnEdNewPro->text().trimmed();
    QProcess* process=new QProcess(this);
    if(name.contains('&'))
    {
        QStringList names=name.split(' ');
        process->startDetached(names.at(0));
    }
    else
    {
        process->start(name);
    }
}

void mainWindow::killAProcess(pid_t pid)
{
    const char* command=QString("kill %1").arg(pid).toLatin1().data();
    system(command);
}

void mainWindow::endTask()
{
    if(ui->tabWidgets->currentIndex()==2)
    {
        if(pidToBeKilled!=-1)
        {
            killAProcess(pidToBeKilled);
        }
    }
    else if(ui->tabWidgets->currentIndex()==1)
    {
        int row=ui->tbwProInfo->currentIndex().row();
        killAProcess(ui->tbwProInfo->item(row,1)->text().toShort());
    }
}

mainWindow::~mainWindow()
{
    delete ui;
    delete preCpuStat;
    delete curCpuStat;
}
