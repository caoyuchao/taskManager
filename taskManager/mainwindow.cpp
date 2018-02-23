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
#include<qcompleter.h>
#include<qmessagebox.h>
#include"shutdownwindow.h"
#include<qpixmap.h>
#include<qpainter.h>
#include<qlist.h>

#include<iostream>


mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow),preCpuStat(new cpuUseState),curCpuStat(new cpuUseState)
  ,pidToBeKilled(-1),isEverTabRecordClicked(false)
{
    ui->setupUi(this);
    ui->tbrCpuInfo->setStyleSheet("border:0px;background-color:transparent");
    ui->tbrDetails->setStyleSheet("border:0px;background-color:transparent");
    ui->lnEdQuery->installEventFilter(this);
    timer=new QTimer(this);
    QTimer* longTimer=new QTimer(this);
    getCpuUseState(curCpuStat);
    createStatusBar();//中间要创建,需要在connect之前
    connect(timer,&QTimer::timeout,this,&mainWindow::updateTime);
    connect(timer,&QTimer::timeout,this,&mainWindow::updateCpuUseRate);
    connect(timer,&QTimer::timeout,this,&mainWindow::updateMemUseRate);
    connect(timer,&QTimer::timeout,this,&mainWindow::updateProcessesInfo);
    connect(timer,&QTimer::timeout,this,&mainWindow::updateCpuHisLine);
    connect(timer,&QTimer::timeout,this,&mainWindow::updateMemHisLine);
    connect(longTimer,&QTimer::timeout,this,&mainWindow::updateCompletedList);
    connect(ui->btQuery,&QPushButton::clicked,this,&mainWindow::queryProcessInfo);
    connect(ui->btNewPro,&QPushButton::clicked,this,&mainWindow::createANewProcess);
    //    点击表格头部，按当前点击的列进行字典排序
    //    connect(ui->tbwProInfo->horizontalHeader(),&QHeaderView::sectionClicked,this,&mainWindow::headerSectionClicked);
    connect(btEndTask,&QPushButton::clicked,this,&mainWindow::endTask);
    connect(btShutdown,&QPushButton::clicked,this,&mainWindow::processShutdown);
    connect(ui->rbutton,&QRadioButton::clicked,this,&mainWindow::updateCompletedList);
    connect(ui->tabWidgets,&QTabWidget::tabBarClicked,this,&mainWindow::processTabClicked);

    initPointsY();
    fillSystemInfo();
    updateTime();
    updateCpuUseRate();
    updateMemUseRate();
    updateProcessesInfo();//要在setCompletedList之前
    setCompletedList();
    setTBWHeaders();
    timer->start(1000);
    longTimer->start(5000);
}

void mainWindow::initPointsY()
{
    for(int i=0;i<=numOfPoints;i++)
    {
        cpuPointsY.append(0);
        memPointsY.append(0);
        swapPointsY.append(0);
    }
}

bool mainWindow::eventFilter(QObject* obj, QEvent* e)
{

    if (e->type() == QEvent::KeyPress
            &&ui->tabWidgets->currentIndex()==2)
    {
        QKeyEvent* event = static_cast<QKeyEvent*>(e);
        if (event->key() == Qt::Key_Return)
        {
            queryProcessInfo();
            return true;
        }
    }
    return QWidget::eventFilter(obj,e);
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
    curCpuRate=calcuCpuRate(preCpuStat,curCpuStat);
    lbCpuUse->setText(QString("CPU使用率 ").append(QString::number(curCpuRate,'f',2).append("%")));
}

void mainWindow::updateMemUseRate()
{
    memUseState mem;
    getMemUseState(&mem);
    curMemRate=calcuMemMemRate(&mem);
    lbMemUse->setText(QString("内存使用率 ").append(QString::number(curMemRate,'f',2)).append("%"));
}

void mainWindow::setTBWHeaders()
{
    QStringList tbwProInfoHeaders;
    tbwProInfoHeaders << "进程名称" << "pid" << "ppid" << "内存占用/KB"<<"优先级(nice)";
    ui->tbwProInfo->horizontalHeader()->setStyleSheet("font-size:18px;font-family:SimSun");
    ui->tbwProInfo->setHorizontalHeaderLabels(tbwProInfoHeaders);
}

//void mainWindow::headerSectionClicked(int index)
//{会被刷新刷掉,由于排序方式很坑,因此决定不进行排序，仅按照pid的自然数顺序排序
//    ui->tbwProInfo->sortByColumn(index,Qt::AscendingOrder);
//}

void mainWindow::insertARowIntoTable(const processInfo* const process,int rowsIndex)
{
    int rows = ui->tbwProInfo->rowCount();

    QTableWidgetItem* name=new QTableWidgetItem(process->name.c_str());
    QTableWidgetItem* pid=new QTableWidgetItem(QString("%1").arg(process->pid));
    QTableWidgetItem* ppid=new QTableWidgetItem(QString("%1").arg(process->ppid));
    QTableWidgetItem* rss=new QTableWidgetItem(QString("%1").arg(process->rss*getpagesize()/1024));
    QTableWidgetItem* nice=new QTableWidgetItem(QString("%1").arg(process->nice));

    if(rowsIndex>=rows)
    {
        ui->tbwProInfo->setRowCount(rows + 1);
        ui->tbwProInfo->setItem(rows, 0, name);
        ui->tbwProInfo->setItem(rows, 1, pid);
        ui->tbwProInfo->setItem(rows, 2, ppid);
        ui->tbwProInfo->setItem(rows, 3, rss);
        ui->tbwProInfo->setItem(rows, 4, nice);
    }
    else
    {
        ui->tbwProInfo->setItem(rowsIndex, 0, name);
        ui->tbwProInfo->setItem(rowsIndex, 1, pid);
        ui->tbwProInfo->setItem(rowsIndex, 2, ppid);
        ui->tbwProInfo->setItem(rowsIndex, 3, rss);
        ui->tbwProInfo->setItem(rowsIndex, 4, nice);
    }

}

void mainWindow::updateProcessesInfo()
{
    int row=ui->tbwProInfo->currentIndex().row();
    int hvalue=ui->tbwProInfo->verticalScrollBar()->value();
    getProcessesInfo(processes);
    ui->tbwProInfo->clearContents();
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
    ui->tbrDetails->setText(QString("进程名        ：  %1").arg(process->name.c_str()));
    ui->tbrDetails->append(QString("进程pid号      ：  %1").arg(pidToBeKilled=process->pid));
    ui->tbrDetails->append(QString("进程状态       ：  %1").arg(taskStateToString(process->taskState)));
    ui->tbrDetails->append(QString("父进程pid号    ：  %1").arg(process->ppid));
    ui->tbrDetails->append(QString("(进)线程组号   ：  %1").arg(process->pgid));

    ui->tbrDetails->append(QString("进程占用内存   ：  %1KB").arg(process->rss*getpagesize()/1024));
    ui->tbrDetails->append(QString("进程动态优先级 ：  %1").arg(process->priority));
    ui->tbrDetails->append(QString("进程静态优先级 ：  %1").arg(process->nice));
    ui->tbrDetails->append(QString("进程调度策略   ：  %1").arg(taskPolicyToString(process->taskPolicy)));
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

void mainWindow::warning(QProcess::ProcessError error)
{
    QString errorString="";
    switch (error) {//来自F1
    case QProcess::FailedToStart:
        errorString="找不到该应用程序";
        //        errorString="The process failed to start."
        //                    " Either the invoked program is missing,"
        //                    " or you may have insufficient permissions"
        //                    " to invoke the program.";
        break;
    case QProcess::Crashed:
        errorString="已结束指定任务";
        //        errorString="The process crashed some time "
        //                    "after starting successfully.";
        break;
    case QProcess::Timedout:
        errorString="The last waitFor...() function timed out. "
                    "The state of QProcess is unchanged,"
                    " and you can try calling waitFor...() again.";
        break;
    case QProcess::WriteError:
        errorString="An error occurred when attempting to write to the process."
                    " For example, the process may not be running, "
                    "or it may have closed its input channel.";
        break;
    case QProcess::ReadError:
        errorString="An error occurred when attempting to read from the process."
                    " For example, the process may not be running.";
        break;
    case QProcess::UnknownError:
        errorString="An unknown error occurred.";
        break;
    default:
        break;
    }
    QMessageBox::warning(this,"注意",errorString);
}

void mainWindow::createANewProcess()
{
    QString name=ui->lnEdNewPro->text().trimmed();
    if(name.size()!=0)
    {
        process=new QProcess(this);
        if(name.contains('&'))
        {
            QStringList names=name.split(' ');
            if(process->startDetached(names.at(0)))
            {
                return;
            }
        }
        else
        {
            connect(process,&QProcess::errorOccurred,this,&mainWindow::warning);
            process->start(name);
            return;
        }
    }
    QMessageBox::warning(this,"注意","找不到该应用程序");
}

void mainWindow::killAProcess(pid_t pid)
{
    const char* command=QString("kill %1").arg(pid).toLatin1().data();
    system(command);
}

void mainWindow::endTask()
{
    auto lambda=[=]()-> void {
        ui->tbrDetails->clear();
        sleep(1);
        setCompletedList();
    };
    if(ui->tabWidgets->currentIndex()==2)
    {
        if(pidToBeKilled!=-1)
        {
            killAProcess(pidToBeKilled);
            pidToBeKilled=-1;
            lambda();
        }
    }
    else if(ui->tabWidgets->currentIndex()==1)
    {
        int row=ui->tbwProInfo->currentIndex().row();
        if(row!=-1)
        {
            killAProcess(ui->tbwProInfo->item(row,1)->text().toShort());
            lambda();
        }
    }
}

void mainWindow::setCompletedList()
{
    bool isChecked=ui->rbutton->isChecked();
    QStringList keyList;
    if(isChecked)
    {
        for(auto iter=processes.begin();iter!=processes.end();++iter)
        {
            keyList<<iter.value()->name.c_str();
        }
    }
    else
    {
        for(auto iter=processes.begin();iter!=processes.end();++iter)
        {
            keyList<<QString("%1").arg(iter.key());
        }
    }
    ui->lnEdQuery->setCompleter(new QCompleter(keyList));
}

void mainWindow::getCpuPointsY()
{
    cpuPointsY.pop_back();
    cpuPointsY.insert(0,curCpuRate/100);
}

void mainWindow::getMemPointsY()
{
    memPointsY.pop_back();
    memPointsY.insert(0,curMemRate/100);
}

void mainWindow::getSwapPointsY()
{
    swapPointsY.pop_back();
    swapPointsY.insert(0,(int)getSwapRate());
}

void mainWindow::drawBenchmark(QPixmap * const pix,const QList<double>& pointsY,const QColor& color)
{
    QPainter painter(pix);
    painter.setPen(QPen(Qt::black));
    for(int i=0;i<5;i++)
    {
        painter.drawLine(0,40*i+20,842,40*i+20);
    }
    int num=numOfPoints/2;
    int horiStep=840/num;
    for(int i=0;i<=num;i++)
    {
        if(i%10==0)
        {
            painter.drawLine(i*horiStep,180,i*horiStep,200);
        }
        else
        {
            painter.drawLine(i*horiStep,190,i*horiStep,200);
        }

    }
    painter.setPen(QPen(QBrush(color),3));
    for(int i=0;i<numOfPoints;i++)
    {
        int curHeight=(1-pointsY.at(i))*160+20;
        int nexHeight=(1-pointsY.at(i+1))*160+20;
        painter.drawLine(i*horiStep,curHeight,(i+1)*horiStep,nexHeight);
    }
}

void mainWindow::updateCpuHisLine()
{
    if(!isEverTabRecordClicked)
        return;
    QPixmap pix(842,200);
    pix.fill(Qt::white);
    getCpuPointsY();
    drawBenchmark(&pix,cpuPointsY,Qt::red);
    ui->lbCpuHisLine->setPixmap(pix);
}

void mainWindow::updateMemHisLine()
{
    if(!isEverTabRecordClicked)
        return;
    QPixmap pix(842,200);
    pix.fill(Qt::white);
    getMemPointsY();
    drawBenchmark(&pix,memPointsY,Qt::red);
    //ui->lbMemHisLine->setPixmap(pix);
    //QPixmap curPix=*(ui->lbMemHisLine->pixmap());
    drawBenchmark(&pix,swapPointsY,Qt::blue);
    ui->lbMemHisLine->setPixmap(pix);
}

void mainWindow::processTabClicked(int index)
{
    switch (index) {
    case 0:
        break;
    case 1:
        updateProcessesInfo();
        break;
    case 2:
        setCompletedList();
        break;
    case 3:
        isEverTabRecordClicked=true;
        break;
    default:
        break;
    }
}

void mainWindow::updateCompletedList()
{
    if(ui->tabWidgets->currentIndex()!=2)
        return;
    setCompletedList();
}

void mainWindow::processShutdown()
{
    shutdownWindow* win=new shutdownWindow(this);
    win->show();
}

mainWindow::~mainWindow()
{
    delete ui;
    delete preCpuStat;
    delete curCpuStat;
}
