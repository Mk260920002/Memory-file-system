#include "filesystem.h"

void FileSystem::mkdir(const std::string& dirName) {
    // Check if the directory already exists in the current directory
    Node* existingDir = findNode(dirName, currentDirectory);
    if (existingDir) {
        std::cout << "Error: Directory already exists" << std::endl;
        return;
    }

    // Create a new directory node
    Node* newDir = new Node(dirName, true);
    newDir->parent=currentDirectory;
    // Add the new directory to the current directory
    currentDirectory->children.push_back(newDir);
}
