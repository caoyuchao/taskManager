#include"memory.h"
#include<qregexp.h>
#include<qstringlist.h>
#include<string>
#include<qfile.h>

//struct memUseState
//{
//    size_t memTotal;
//    size_t memFree;
//    size_t buffers;
//    size_t cached;
//    size_t getMemUsed();
//};

memUseState::memUseState()
{
    memTotal=memFree=buffers=cached=0;
}

size_t memUseState::getMemUnUsed()const
{
    return memTotal-memFree-buffers-cached;
}
//提供通用方式读取数据
void getMemUseState(memUseState * const curMem)
{
    QFile in("/proc/meminfo");
    in.open(QIODevice::ReadOnly);
    if(in.isOpen())
    {
        QStringList data;
        QString lines="";
        const int linesToRead=5;
        for(int i=0;i<linesToRead;i++)
        {
            lines.append(in.readLine());
        }

        QRegExp regExp("\\s+\\d+\\s");
        int pos=0;
        while((pos=regExp.indexIn(lines,pos))!=-1)
        {
            data<<regExp.cap(0).trimmed();
            pos+=regExp.matchedLength();
        }

        QString tmp;
        if(data.size()==linesToRead)
        {
            tmp=data.at(0);
            curMem->memTotal=tmp.toUInt();
            tmp=data.at(1);
            curMem->memFree=tmp.toUInt();
            tmp=data.at(3);
            curMem->buffers=tmp.toUInt();
            tmp=data.at(4);
            curMem->cached=tmp.toUInt();
        }
        in.close();
    }
}

double calcuMemMemRate(const memUseState * const curMemState)
{
    double memRate=0;
    if(curMemState->memTotal!=0)
    {
        memRate=curMemState->getMemUnUsed()*100.0/curMemState->memTotal;
    }
    return memRate;
}
