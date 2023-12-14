#include "filesystem.h"
#include <sstream>

FileSystem::FileSystem()
{
    root = new Node("/", true);
    currentDirectory = root;
}

// Rest of the code remains unchanged
// ...

FileSystem::Node::Node(const std::string &n, bool isDir) : name(n), isDirectory(isDir) {}

std::vector<std::string> FileSystem::splitPath(const std::string &path) const
{
    std::vector<std::string> components;
    std::istringstream iss(path);
    std::string component;
    while (std::getline(iss, component, '/'))
    {
        if (!component.empty())
        {
            components.push_back(component);
        }
    }
    return components;
}

FileSystem::Node *FileSystem::findNode(const std::string &name, Node *current) const
{
    for (Node *child : current->children)
    {
        if (child->name == name)
        {
            return child;
        }
    }
    return nullptr;
}

FileSystem::Node *FileSystem::findNodeInPath(const std::string &path, Node *current) const
{
    std::vector<std::string> pathComponents = splitPath(path);

    // Navigate through the path components
    Node *temp = current;
    for (const std::string &component : pathComponents)
    {
        Node *child = findNode(component, temp);
        if (child)
        {
            temp = child;
        }
        else
        {
            // If any component is not found or is not a directory, return nullptr
            return nullptr;
        }
    }

    return temp;
}

void FileSystem::executeCommand(const std::string &command)
{
    std::istringstream iss(command);
    std::string cmd, arg1, arg2;

    // Parse the command and arguments
    iss >> cmd >> arg1 >> arg2;

    if (cmd == "mkdir")
    {
        mkdir(arg1);
        // std::cout << arg1 << "\n";
    }
    else if (cmd == "cd")
    {
        cd(arg1);
        // std::cout << arg1 << "\n";
    }
    else if (cmd == "ls")
    {
        ls();
    }
    else if (cmd == "grep")
    {
        if (!arg1.empty())
        {
            std::string text;
            while (iss >> arg1)
            {
                text += arg1 + " ";
            }
            grep(text);
            // std::cout << text << "\n";
        }
        else
        {
            std::cout << "Error: Missing pattern for grep" << std::endl;
        }
    }
    else if (cmd == "cat")
    {
        cat(arg1);
        // std::cout << arg1 << "\n";
    }
    else if (cmd == "touch")
    {
        touch(arg1);
        // std::cout << arg1 << "\n";
    }
    else if (cmd == "echo")
    {
        // Combine the remaining arguments into a single string
        std::string text;
        while (iss >> arg1)
        {
            text += arg1 + " ";
        }
        // std::cout << text << "\n";
        echo(text);
    }
    else if (cmd == "mv")
    {
        // std::cout << arg1 << " " << arg2 << "\n";
        mv(arg1, arg2);
    }
    else if (cmd == "cp")
    {
        cp(arg1, arg2);
        // std::cout << arg1 << " " << arg2 << "\n";
    }
    else if (cmd == "rm")
    {
        rm(arg1);
        // std::cout << arg1 << "\n";
    }
    else
    {
        std::cout << "Error: Unknown command" << std::endl;
    }
}
