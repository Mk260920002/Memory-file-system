#include "filesystem.h"
#include <algorithm>

void FileSystem::rm(const std::string& path) {
    // Find the node to be removed by navigating through the path
    Node* nodeToRemove = findNodeInPath(path, currentDirectory);

    // Check if the node exists
    if (!nodeToRemove) {
        std::cout << "Error: Path not found" << std::endl;
        return;
    }

    // Check if the node is a directory and it has children
    if (nodeToRemove->isDirectory && !nodeToRemove->children.empty()) {
        std::cout << "Error: Directory is not empty" << std::endl;
        return;
    }

    // Remove the node from its parent's children
    auto it = std::remove(
        currentDirectory->children.begin(),
        currentDirectory->children.end(),
        nodeToRemove
    );
    currentDirectory->children.erase(it, currentDirectory->children.end());
    currentDirectory->children.shrink_to_fit();
    // Delete the node
    delete nodeToRemove;
}
