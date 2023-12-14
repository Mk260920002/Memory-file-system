#include "filesystem.h"

void FileSystem::touch(const std::string& fileName) {
    // Check if the file already exists in the current directory
    Node* existingFile = findNode(fileName, currentDirectory);
    if (existingFile) {
        std::cout << "Error: File already exists" << std::endl;
        return;
    }

    // Create a new file node and add it to the current directory
    Node* newFile = new Node(fileName, false);  // The second parameter 'false' indicates it's not a directory
    currentDirectory->children.push_back(newFile);
}
