#pragma once

#include <iostream>
#include <vector>
#include <sstream>

class FileSystem {
private:
    struct Node {
        std::string name;
        bool isDirectory;
        std::vector<Node*> children;
        std::string content;
        Node *parent;
        Node(const std::string& n, bool isDir = false);
    };

    Node* root;
    Node* currentDirectory;

    std::vector<std::string> splitPath(const std::string& path) const;
    Node* findNode(const std::string& name, Node* current) const;
    Node* findNodeInPath(const std::string& path, Node* current) const;

public:
    FileSystem();

    void mkdir(const std::string& dirName);
    void cd(const std::string& path);
    void ls() const;
    void grep(const std::string& pattern) const;
    void cat(const std::string& fileName) const;
    void touch(const std::string& fileName);
    void echo(const std::string& command);
    void mv(const std::string& source, const std::string& destination);
    void cp(const std::string& source, const std::string& destination);
    void rm(const std::string& path);
    void executeCommand(const std::string& command) ;
};
