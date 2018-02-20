#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qlabel.h>
#include<QPushButton>
#include<QTimer>
#include"sysinfo.h"
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
};

#endif // MAINWINDOW_H
