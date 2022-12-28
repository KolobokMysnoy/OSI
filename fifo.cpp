#include <iostream>

#include "fifo.hpp"

FifoSeq::FifoSeq() {
    _processQuant = 0;
}

std::string FifoSeq::getFirstProcessName() {
    if (_processQuant == 0) {
        return "";
    }

    return _processes.front()->getNameOfProcess();
}

IProcess* FifoSeq::getFirstProcess() {
    if (_processQuant == 0) {
        return nullptr;
    }

    _processQuant--;
    IProcess* result = _processes.front();
    _processes.pop();

    return result;
}

void FifoSeq::addNewProcess(std::string nameOfProcess, size_t timeOFProcess) {
    _processes.push(new Process(nameOfProcess, timeOFProcess));
    _processQuant++;
}

std::string FifoSeq::getFirstProcessAndRemoveIt() {
    if (_processQuant == 0) {
        return "";
    }
    std::string returnName = getFirstProcess()->getNameOfProcess();
    return returnName;
}

FifoSeq::~FifoSeq() {
    if (_processQuant != 0) {
        while (_processes.front()) {
            IProcess* deleteProcess = _processes.front();
            _processes.pop();

            delete deleteProcess;
        }
    }
}
