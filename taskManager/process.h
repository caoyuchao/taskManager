#ifndef PROCESS_H
#define PROCESS_H
#include<unistd.h>
#include<qmap.h>
struct processInfo
{
    std::string name;
    pid_t pid;
    pid_t ppid;
    size_t rss;
    int priority;
    processInfo();
};

void readProcessInfo(processInfo* const proInfo,const char* pid);
void getProcessesInfo(QMap<pid_t,processInfo*>& processes);
bool isProcessFile(const std::string& name);

#endif // PROCESS_H
