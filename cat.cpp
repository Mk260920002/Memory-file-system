#include "filesystem.h"

void FileSystem::cat(const std::string& fileName) const {
    // Find the file node with the specified name in the current directory
    Node* file = findNode(fileName, currentDirectory);

    // Check if the file exists and is not a directory
    if (file && !file->isDirectory) {
        // Display the content of the file
        std::cout << file->content << std::endl;
    } else {
        // Print an error message if the file is not found or is a directory
        std::cout << "Error: File not found or specified path is a directory." << std::endl;
    }
}

