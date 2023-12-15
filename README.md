# Memory File System

## Overview
This is  implementation of a memory file system in C++. The system provides basic file operations and command-line interaction.

## Features
- **mkdir**: Create a new directory.
- **cd**: Change the current directory.
- **ls**: List files and directories in the current directory.
- **grep**: Search for a pattern in files.
- **cat**: Display the contents of a file.
- **touch**: Create an empty file.
- **echo**: Write text to a file.
- **mv**: Move a file or directory to a new location.
- **cp**: Copy a file or directory to a new location.
- **rm**: Remove a file or directory.

## How to Use
1. **Run Docker Container**
    ```bash
    docker run -it mukesh2002/my-cpp-app:latest
    ```

2. **Interact with the Memory File System**
   - Use the provided commands to interact with the memory file system.

## Example Commands
- Create a directory:
    ```bash
    $: mkdir my_directory
    ```

- Change directory:
    ```bash
    $: cd my_directory
    ```

- List files and directories:
    ```bash
    $: ls
    ```

- Search for a pattern in files:
    ```bash
    $: grep pattern file.txt
    ```

- Display the contents of a file:
    ```bash
    $: cat file.txt
    ```

- Create an empty file:
    ```bash
    $: touch new_file.txt
    ```

- Write text to a file:
    ```bash
    $: echo "Hello, world!" > greeting.txt
    ```

- Move a file or directory:
    ```bash
    $: mv source.txt destination/
    ```

- Copy a file or directory:
    ```bash
    $: cp source.txt copy_of_source.txt
    ```

- Remove a file or directory:
    ```bash
    $: rm unwanted_file.txt
    ```

## License
This project is licensed under the [MIT License](LICENSE).
