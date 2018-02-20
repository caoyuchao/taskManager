#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qlabel.h>
#include<QPushButton>
#include<QTimer>
#include<qevent.h>
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
    QLabel* lbCurTime;
    QLabel* lbCpuUse;
    QLabel* lbMemUse;
    QPushButton* btShutdown;
    QPushButton* btEndTask;
    QTimer* timer;
    Ui::mainWindow *ui;
    cpuUseState* preCpuStat;
    cpuUseState* curCpuStat;
    QMap<pid_t,processInfo*> processes;
    pid_t pidToBeKilled;
//    size_t sortColumnIndex;排序很坑,按照字符串字典序排
//    bool isEverSelectTabRecord;
private:

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
//    void removeAllRows();
    void updateProcessesInfo();
    void queryProcessInfo();
    void showProcessInfo(const processInfo* const process);
    void createANewProcess();
    void killAProcess(pid_t pid);
    void endTask();
    void updateCompletedList();
    void setCompletedList();
protected:
    bool eventFilter(QObject* obj, QEvent* e);
};

#endif // MAINWINDOW_H
