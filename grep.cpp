#include "filesystem.h"

void FileSystem::grep(const std::string& pattern) const {
    bool patternFound = false;

    // Iterate through each file in the current directory
    for (Node* child : currentDirectory->children) {
        // Check if the child is a file
        if (!child->isDirectory) {
            // Search for the pattern in the file content
            size_t found = child->content.find(pattern);
            
            // If the pattern is found, print the file name
            if (found != std::string::npos) {
                std::cout << child->name << std::endl;
                patternFound = true;
            }
        }
    }

    // If no files with the pattern were found, print a message
    if (!patternFound) {
        std::cout << "Pattern not found in any file." << std::endl;
    }
}
