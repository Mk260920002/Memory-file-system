#include "filesystem.h"

void trim(std::string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');

    if (first != std::string::npos && last != std::string::npos) {
        str = str.substr(first, last - first + 1);
    } else {
        str.clear();
    }
}
void FileSystem::echo(const std::string& command) {
    // Find the position of '>'
    size_t pos = command.find('>');

    if (pos != std::string::npos) {
        // Extract the filename and text
        std::string text = command.substr(0, pos);
        std::string filename = command.substr(pos + 1);

        // Trim leading and trailing whitespaces
        trim(text);
        trim(filename);

        // Check if the filename is not empty
        if (!filename.empty()) {
            // Find the file node with the specified name in the current directory
            Node* file = findNode(filename, currentDirectory);

            // Check if the file exists and is not a directory
            if (file && !file->isDirectory) {
                // Write the text to the file's content
                file->content = text;
                std::cout << "Text written to file: " << filename << std::endl;
            } else {
                // Print an error message if the file is not found or is a directory
                std::cerr << "Error: File not found or specified path is a directory." << std::endl;
            }
        } else {
            std::cerr << "Error: Empty filename." << std::endl;
        }
    } else {
        std::cerr << "Error: '>' not found in the command." << std::endl;
    }
}

// Helper function to trim whitespaces from the beginning and end of a string

