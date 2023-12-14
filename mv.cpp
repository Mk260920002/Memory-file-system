#include "filesystem.h"
#include <algorithm>
void FileSystem::mv(const std::string& source, const std::string& destination) {
    // Find the source node by navigating through the source path
    Node* sourceNode = findNodeInPath(source, currentDirectory);
     std::cout<<sourceNode->name<<"\n"<<destination<<"\n";
    // Check if the source node exists
    if (!sourceNode) {
        std::cout << "Error: Source not found" << std::endl;
        return;
    }
    if(sourceNode->isDirectory){
        std::cout<<"You are trying to move directory"<<"\n";
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
 std:: cout<<"dest= "<<destDirectory->name<<"\n";
 // Move the source node to the destination directory

Node* sourceParent = sourceNode->parent;
Node * temp=sourceNode;
 auto it = std::remove(
        sourceParent->children.begin(),
        sourceParent->children.end(),
        sourceNode
    );

sourceParent->children.erase(it, sourceParent->children.end());
sourceParent->children.shrink_to_fit(); // Reduce capacity to fit remaining elements
 std:: cout<<"dest= "<<destDirectory->name<<"\n";
destDirectory->children.push_back(temp);
temp->parent=destDirectory;
}
