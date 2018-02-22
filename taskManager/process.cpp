#include"process.h"
#include<unistd.h>
#include<qmap.h>
#include<qregexp.h>
#include<dirent.h>
#include<qstringlist.h>
#include<qfile.h>

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
        QString content=QString(in.readLine());
        QString dataTail=content.mid(content.lastIndexOf(')')+2);
        QStringList data=dataTail.split(' ');

        proInfo->pid=content.split(' ').at(0).toShort();
        int startIndex=content.indexOf('(')+1;
        proInfo->name=content.mid(startIndex,content.lastIndexOf(')')-startIndex).toStdString();

        proInfo->ppid=data.at(1).toShort();
        proInfo->priority=data.at(16).toShort();
        proInfo->rss=data.at(21).toUInt();
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
