#include "process.hpp"

Process::Process(std::string nameOfProcess, size_t timeOfProcess) {
    _name = nameOfProcess;
    _timeOfProcess = timeOfProcess;
}

std::string Process::getNameOfProcess() {
    return _name;
}

size_t Process::getTimeOfProcess() {
    return _timeOfProcess;
}

bool Process::subtractFromTimeOfProcess(size_t subtractTime) {
    if (_timeOfProcess >= subtractTime) {
        _timeOfProcess -= subtractTime;
        return true;
    }
    return false;
}
