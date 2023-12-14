#include "filesystem.h"

void FileSystem::cd(const std::string& path) {
    if (path == "/" || path=="~") {
        currentDirectory = root;
    } else if (path == "..") {
        if (currentDirectory != root) {
            currentDirectory =currentDirectory->parent;
        }
    } else {
        std::vector<std::string> components = splitPath(path);
        Node* temp = currentDirectory;
        for (const std::string& component : components) {
            Node* child = findNode(component, temp);
            if (child && child->isDirectory) {
                temp = child;
            } else {
                std::cout << "Error: Invalid path" << std::endl;
                return;
            }
        }
        currentDirectory = temp;
    }
}

