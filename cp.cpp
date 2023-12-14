#include "filesystem.h"
#include <algorithm>

void FileSystem::cp(const std::string& source, const std::string& destination) {
    // Find the source node by navigating through the source path
    Node* sourceNode = findNodeInPath(source, currentDirectory);

    // Check if the source node exists
    if (!sourceNode) {
        std::cout << "Error: Source not found" << std::endl;
        return;
    }

    // Find the destination directory
    Node* destDirectory = currentDirectory;
    std::vector<std::string> destComponents = splitPath(destination);
    if (!destComponents.empty()) {
        destDirectory = currentDirectory;
        for (const std::string& component : destComponents) {
            Node* child = findNode(component, destDirectory);
            if (child && child->isDirectory) {
                destDirectory = child;
            } else {
                std::cout << "Error: Invalid destination path" << std::endl;
                return;
            }
        }
    }

    // Check if the destination already contains a node with the same name
    Node* destNode = findNode(sourceNode->name, destDirectory);
    if (destNode) {
        std::cout << "Error: Destination already contains a node with the same name" << std::endl;
        return;
    }

    // Create a copy of the source node and add it to the destination directory
    Node* copyNode = new Node(sourceNode->name, sourceNode->isDirectory);
    copyNode->content = sourceNode->content;  // Assuming content needs to be copied for files
    destDirectory->children.push_back(copyNode);
}

