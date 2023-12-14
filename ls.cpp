#include "filesystem.h"

void FileSystem::ls() const {
    for (Node* child : currentDirectory->children) {
        std::cout << child->name;
        if (child->isDirectory) {
            std::cout << "/";
        }
        std::cout <<"\n";
    }
    
}
