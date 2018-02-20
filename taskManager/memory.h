#ifndef MEMORY_H
#define MEMORY_H
#include<string>

struct memUseState
{
    size_t memTotal;
    size_t memFree;
    size_t buffers;
    size_t cached;
    memUseState();
    size_t getMemUnUsed()const;
};

void getMemUseState(memUseState* const curMem);
double calcuMemMemRate(const memUseState* const curMemState);

#endif // MEMORY_H
