#include "filesystem.h"
#include <algorithm>
void FileSystem::mv(const std::string& source, const std::string& destination) {
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

    // Move the source node to the destination directory
    destDirectory->children.push_back(sourceNode);
    currentDirectory=sourceNode->parent;
  

         currentDirectory->children.erase(std::remove(currentDirectory->children.begin(), currentDirectory->children.end(), sourceNode ), currentDirectory->children.end());
         currentDirectory->children.shrink_to_fit(); // Reduce capacity to fit remaining elements
      
}
