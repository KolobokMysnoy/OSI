#include <iostream>

#include "sjf.hpp"

SjfSeq::SjfSeq() {
    _processQuant = 0;
}

std::string SjfSeq::getFirstProcessName() {
    if (_processQuant == 0) {
        return "";
    }

    return _processes.top()->getNameOfProcess();
}

IProcess* SjfSeq::getFirstProcess() {
    if (_processQuant == 0) {
        return nullptr;
    }

    _processQuant--;
    IProcess* result = _processes.top();
    _processes.pop();

    return result;
}

void SjfSeq::addNewProcess(std::string nameOfProcess, size_t timeOFProcess) {
    _processes.push(new Process(nameOfProcess, timeOFProcess));
    _processQuant++;
}

std::string SjfSeq::getFirstProcessAndRemoveIt() {
    if (_processQuant == 0) {
        return "";
    }
    std::string returnName = getFirstProcess()->getNameOfProcess();
    return returnName;
}

SjfSeq::~SjfSeq() {
    if (_processQuant != 0) {
        while (_processes.top()) {
            IProcess* deleteProcess = _processes.top();
            _processes.pop();

            delete deleteProcess;
        }
    }
}
