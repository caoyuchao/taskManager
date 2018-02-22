#include"process.h"
#include<unistd.h>
#include<qmap.h>
#include<qregexp.h>
#include<dirent.h>
#include<qstringlist.h>
#include<qfile.h>

//struct processInfo
//{
//    pid_t pid;
//    std::string name;
//    char taskState;
//    pid_t ppid;
//    pid_t pgid;
//    size_t rss;
//    int priority;
//    int nice;
//    int taskPolicy;
//    processInfo();
//};

processInfo::processInfo():pid(0),name("Exception"),taskState('S'),
    ppid(0),pgid(0),rss(0),priority(0),nice(0),taskPolicy(0)
{
}
void readProcessInfo(processInfo* const proInfo,const char* pid)
{
    QFile in(QString("/proc/%1/stat").arg(pid));
    if(in.open(QIODevice::ReadOnly))
    {
        QString content=QString(in.readLine());
        QString dataTail=content.mid(content.lastIndexOf(')')+2);
        QStringList data=dataTail.split(' ');

        proInfo->pid=content.split(' ').at(0).toShort();
        int startIndex=content.indexOf('(')+1;
        proInfo->name=content.mid(startIndex,content.lastIndexOf(')')-startIndex).toStdString();

        proInfo->taskState=data.at(0).at(0).toLatin1();
        proInfo->ppid=data.at(1).toShort();
        proInfo->pgid=data.at(2).toShort();
        proInfo->priority=data.at(15).toShort();
        proInfo->nice=data.at(16).toShort();
        proInfo->rss=data.at(21).toUInt();
        proInfo->taskPolicy=data.at(40).toInt();
        in.close();
    }
}
void getProcessesInfo(QMap<pid_t,processInfo*>& processes)
{
    DIR* dp;
    struct dirent* entry;
    if((dp=opendir("/proc"))!=NULL)
    {
        processes.clear();
        while((entry=readdir(dp))!=NULL)
        {
            if(isProcessFile(entry->d_name))
            {
                processInfo* proInfo=new processInfo();
                readProcessInfo(proInfo,entry->d_name);
                processes.insert(QString(entry->d_name).toShort(),proInfo);
            }
        }
    }
}

bool isProcessFile(const std::string& name)
{
    QRegExp regExp("^\\d+$");
    return regExp.indexIn(name.c_str())!=-1;
}

QString taskStateToString(char taskState)
{
    switch (taskState)
    {
    case 'R':return "running";
    case 'S':return "sleeping(TASK_INTERRUPTIBLE)";
    case 'D':return "disk sleep (TASK_UNINTERRUPTIBLE)";
    case 'T':return "stopped";
    case 'Z':return "zombie";
    case 'X':return "dead";
    default :return "other state";
    }
}

QString taskPolicyToString(int taskPolicy)
{
    switch (taskPolicy)
    {
    case 0:return "非实时进程";
    case 1:return "FIFO实时进程";
    case 2:return "RR实时进程";
    default:return "不识别进程";
    }
}
