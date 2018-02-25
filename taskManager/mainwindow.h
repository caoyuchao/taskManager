#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qlabel.h>
#include<qpushbutton.h>
#include<qtimer.h>
#include<qevent.h>
#include<qprocess.h>
#include<qlist.h>
#include<qpixmap.h>
#include"sysinfo.h"
#include"process.h"
namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();
private:
    const int numOfPoints = 120;
    const int ruler=1;

private:
    QLabel* lbCurTime;
    QLabel* lbCpuUse;
    QLabel* lbMemUse;
    QPushButton* btShutdown;
    QPushButton* btEndTask;
    QTimer* timer;
    QProcess* process;
    Ui::mainWindow *ui;
    cpuUseState* preCpuStat;
    cpuUseState* curCpuStat;
    QMap<pid_t,processInfo*> processes;
    pid_t pidToBeKilled;
    bool isEverTabRecordClicked;
    double curCpuRate;
    double curMemRate;
    QList<double> cpuPointsY;
    QList<double> memPointsY;
    QList<double> swapPointsY;
    //    size_t sortColumnIndex;排序很坑,按照字符串字典序排

private:
    QLabel* getAGeneralLabel(int minw);
    QPushButton* getAGeneralButton(const QString& text);
    QString secTransToDHMS(int seconds);
    QString getStartTime();
    void fillSystemInfo();
    void createStatusBar();
    void updateTime();
    void updateCpuUseRate();
    void updateMemUseRate();
    void setTBWHeaders();
    //    void headerSectionClicked(int index);
    void insertARowIntoTable(const processInfo* const process,int rowsIndex);
    void updateProcessesInfo();
    void queryProcessInfo();
    void showProcessInfo(const processInfo* const process);
    void createANewProcess();
    void killAProcess(pid_t pid);
    void endTask();
    void updateCompletedList();
    void setCompletedList();
    void processTabClicked(int index);
    void processShutdown();
    void drawBenchmark(QPixmap* const pix,const QList<double>& pointsY,const QColor& color=Qt::red);
    void updateCpuHisLine();
    void updateMemHisLine();
    void initPointsY();
    void getCpuPointsY();
    void getMemPointsY();
    void getSwapPointsY();
    void beforeDrawLine();
private:
    void warning(QProcess::ProcessError error);
protected:
    bool eventFilter(QObject* obj, QEvent* e);

};

#endif // MAINWINDOW_H
