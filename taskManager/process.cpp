#include"process.h"
#include<unistd.h>
#include<qmap.h>
#include<qregexp.h>
#include<dirent.h>
#include<qstringlist.h>
#include<qfile.h>

#include<iostream>
//struct processInfo
//{
//    std::string name;
//    pid_t pid;
//    pid_t ppid;
//    size_t rss;
//    int priority;
//};

processInfo::processInfo():name("Exception"),pid(0),ppid(0),rss(0),priority(0)
{
}
void readProcessInfo(processInfo* const proInfo,const char* pid)
{
    QFile in(QString("/proc/%1/stat").arg(pid));
    if(in.open(QIODevice::ReadOnly))
    {
        QStringList data=QString(in.readLine()).split(' ');
        QString tmp;
        tmp=data.at(0);
        proInfo->pid=tmp.toShort();
        tmp=data.at(1);
        proInfo->name=tmp.toStdString().substr(1,tmp.size()-2);
        tmp=data.at(3);
        proInfo->ppid=tmp.toShort();
        tmp=data.at(18);
        proInfo->priority=tmp.toShort();
        tmp=data.at(23);
        proInfo->rss=tmp.toUInt();
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
