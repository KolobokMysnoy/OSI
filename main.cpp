#include <iostream>

#include "sjf.hpp"

int main() {

    SjfSeq sjfSystem;

    std::string command;

    std::string processName;
    std::string processTime;

    std::cin >> command;
    while (command != "s") {
        
        char commandChar = command[0];
        switch (commandChar)
        {
        case 'i':
            std::cin >> processName;
            std::cin >> processTime;
            
            sjfSystem.addNewProcess(processName, std::stoul(processTime));

            break;
        
        case 'v':
            std::cout << "View first process name" << std::endl;
            std::cout << sjfSystem.getFirstProcessName() << std::endl;

            break;

        case 'g':
            std::cout << "Remove element: " << std::endl << sjfSystem.getFirstProcessAndRemoveIt() << std::endl;

            break;
        
        default:
            break;
        }

        std::cin >> command;
    }

    return 0;
}
