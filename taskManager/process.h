#ifndef PROCESS_H
#define PROCESS_H
#include<unistd.h>
#include<qmap.h>
struct processInfo
{
    pid_t pid;
    std::string name;
    char taskState;
    pid_t ppid;
    pid_t pgid;
    size_t rss;
    int priority;
    int nice;
    int taskPolicy;
    processInfo();
};

void readProcessInfo(processInfo* const proInfo,const char* pid);
void getProcessesInfo(QMap<pid_t,processInfo*>& processes);
bool isProcessFile(const std::string& name);
QString taskStateToString(char taskState);
QString taskPolicyToString(int taskPolicy);



#endif // PROCESS_H
