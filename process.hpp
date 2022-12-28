#pragma once

#include <string>

class IProcess {
    public:
    virtual std::string getNameOfProcess() = 0;
    virtual size_t getTimeOfProcess() = 0;
    virtual bool subtractFromTimeOfProcess(size_t subtractTime) = 0;
};

class Process : public IProcess {
    public:
    Process(std::string nameOfProcess, size_t timeOfProcess);

    std::string getNameOfProcess() override;
    size_t getTimeOfProcess() override;

    bool subtractFromTimeOfProcess(size_t subtractTime) override;

    private:
    std::string _name;
    size_t _timeOfProcess;
};
