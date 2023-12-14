#include "filesystem.h"

void FileSystem::ls() const {
    for (Node* child : currentDirectory->children) {
       bool ok=false;
        std::cout << child->name;
        if (child && child->isDirectory) {
           
            std::cout << "/";
            ok=true;
        }
       if(ok) std::cout <<"\n";
    }
    
}
