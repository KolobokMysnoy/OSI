#pragma once

#include <string>
#include <queue>

#include "process.hpp"

class IFifoSeq {
    public:
    virtual std::string getFirstProcessName() = 0;
    virtual IProcess* getFirstProcess() = 0;
    virtual std::string getFirstProcessAndRemoveIt() = 0;

    virtual void addNewProcess(std::string nameOfProcess, size_t timeOFProcess) = 0;
};

class FifoSeq : public IFifoSeq {
    public:
    FifoSeq();

    std::string getFirstProcessName() override;
    IProcess* getFirstProcess() override;
    std::string getFirstProcessAndRemoveIt() override;

    void addNewProcess(std::string nameOfProcess, size_t timeOFProcess) override;

    ~FifoSeq();

    private:
    size_t _processQuant;
    std::queue<IProcess*> _processes;
};

