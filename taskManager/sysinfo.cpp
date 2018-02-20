#include"sysinfo.h"

//struct cpuUseState
//{
//    std::string name;
//    size_t user;
//    size_t nice;
//    size_t system;
//    size_t idle;
//    size_t irq;
//    size_t softirq;
//    size_t stealstolen;
//    size_t guest;
//    size_t ohter;
//    size_t getTotalTime();
//};

cpuUseState::cpuUseState():name("Exception")
{
    user=nice=system=idle=irq=softirq=stealstolen=guest=other=0;
}

size_t cpuUseState::getTotalTime()const
{
    return user+nice+system+idle+irq+softirq+stealstolen+guest+other;
}

std::string getHostname()
{
    std::ifstream in("/proc/sys/kernel/hostname");
    std::string hostname="There is something wrong";
    if(in.is_open())
    {
        in>>hostname;
    }
    return hostname;
}

std::string getOsType()
{
    std::ifstream in("/proc/sys/kernel/ostype");
    std::string osType="There is something wrong";
    std::string osRelease="There is something wrong";
    if(in.is_open())
    {
        in>>osType;
    }
    in.close();
    in.open("/proc/sys/kernel/osrelease");
    if(in.is_open())
    {
        in>>osRelease;
    }
    return osType+" "+osRelease;
}

double getRunTimeSeconds()
{
    std::ifstream in("/proc/uptime");
    double runTime=-1;
    if(in.is_open())
    {
        in>>runTime;
    }
    return runTime;
}

void getCpuUseState(cpuUseState* const curCpu)
{
    std::ifstream in("/proc/stat");
    if(in.is_open())
    {
        in>>curCpu->name>>curCpu->user>>curCpu->nice>>curCpu->system
                >>curCpu->idle>>curCpu->irq>>curCpu->softirq>>curCpu->stealstolen
                >>curCpu->guest>>curCpu->other;
    }
}

double calcuCpuRate(const cpuUseState* const cpu1,const cpuUseState* const cpu2)
{
    size_t totalCpu1=cpu1->getTotalTime();
    size_t totalCpu2=cpu2->getTotalTime();
    double cpuRate=0;
    if(totalCpu1!=totalCpu2)
    {
        cpuRate=100-(cpu2->idle-cpu1->idle)*100.0/(totalCpu2-totalCpu1);
    }
    return cpuRate;
}

std::string getProcessor()
{
    return "";
}

std::string getBasicFrequency()
{
    std::ifstream in("/proc/cpuinfo");
    std::string result="";
    std::string line;
    if(in.is_open())
    {
        while(std::getline(in,line))
        {
            size_t pos;
            if((pos=line.find("model name",0))!=line.npos)
            {
                result.append(line.substr(line.find(":",0)+1)).append("#");
            }
        }
    }
    if(result!="")
    {
        result.pop_back();
    }
    return result;
}
