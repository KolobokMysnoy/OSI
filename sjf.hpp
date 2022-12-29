#pragma once

#include <string>
#include <queue>
#include <vector>

#include "process.hpp"

class ISjfSeq {
    public:
    virtual std::string getFirstProcessName() = 0;
    virtual IProcess* getFirstProcess() = 0;
    virtual std::string getFirstProcessAndRemoveIt() = 0;

    virtual void addNewProcess(std::string nameOfProcess, size_t timeOFProcess) = 0;
};

struct cmp {
    bool operator() (IProcess* l, IProcess* r) { 
        return l->getTimeOfProcess() > r->getTimeOfProcess(); 
    }
};

class SjfSeq : public ISjfSeq {
    public:
    SjfSeq();

    std::string getFirstProcessName() override;
    IProcess* getFirstProcess() override;
    std::string getFirstProcessAndRemoveIt() override;

    void addNewProcess(std::string nameOfProcess, size_t timeOFProcess) override;

    ~SjfSeq();

    private:
    size_t _processQuant;
    std::priority_queue<IProcess*, std::vector<IProcess*>, cmp> _processes;
};
