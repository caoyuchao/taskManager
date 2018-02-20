#ifndef SYSINFO_H
#define SYSINFO_H

#include<fstream>
#include<string>

struct cpuUseState
{
    std::string name;
    size_t user;
    size_t nice;
    size_t system;
    size_t idle;
    size_t irq;
    size_t softirq;
    size_t stealstolen;
    size_t guest;
    size_t other;
    cpuUseState();
    size_t getTotalTime()const;
};

//
std::string getHostname();
std::string getOsType();
double getRunTimeSeconds();
void getCpuUseState(cpuUseState* const curCpu);
double calcuCpuRate(const cpuUseState* const cpu1,const cpuUseState* const cpu2);
std::string getProcessor();
std::string getBasicFrequency();
#endif // SYSINFO_H
