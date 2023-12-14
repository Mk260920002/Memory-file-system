#include "filesystem.h"
#include "filesystem.cpp"
#include "mkdir.cpp"
#include "cd.cpp"
#include "ls.cpp"
#include "cat.cpp"
#include "touch.cpp"
#include "echo.cpp"
#include "mv.cpp"
#include "cp.cpp"
#include "rm.cpp"
#include "grep.cpp"


int main() {
   FileSystem fileSystem;

    while (true) {
        std::string command;
        std::cout << "$ :";
        std::getline(std::cin, command);
       if(command=="exit")break;
        fileSystem.executeCommand(command);
    }
    // std::cout<<"Hello from main "<<"\n";

    return 0;
}
