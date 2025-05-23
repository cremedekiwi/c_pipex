# Pipex

A C program that reproduces the behavior of shell pipes between two commands, mimicking the functionality of `< file1 cmd1 | cmd2 > file2` in bash.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Implementation Details](#implementation-details)
- [Examples](#examples)
- [Error Handling](#error-handling)
- [Memory Management](#memory-management)

## Overview

Pipex implements inter-process communication using pipes. The program takes two commands and executes them in sequence, where the output of the first command becomes the input of the second command, reading from an input file and writing to an output file.

## Features

- **Process Management**: Creates child processes using `fork()`
- **Pipe Communication**: Implements pipes for inter-process communication
- **File I/O Redirection**: Handles input/output file redirection
- **Path Resolution**: Automatically finds executables in the system PATH
- **Error Handling**: Comprehensive error management with cleanup
- **Memory Safety**: Proper memory allocation and deallocation

## Installation

### Prerequisites

- GCC compiler
- Make
- Unix/Linux environment

### Build

```bash
# Clone the repository
git clone <repository-url>
cd pipex

# Compile the project
make

# Clean object files
make clean

# Clean all generated files
make fclean

# Recompile everything
make re
```

## Usage

```bash
./pipex file1 cmd1 cmd2 file2
```

**Parameters:**
- `file1`: Input file to read from
- `cmd1`: First command to execute
- `cmd2`: Second command to execute  
- `file2`: Output file to write to

**Shell equivalent:**
```bash
< file1 cmd1 | cmd2 > file2
```

## Project Structure

```
pipex/
├── Makefile
├── includes/
│   └── pipex.h           # Header file with structures and function declarations
├── libft/                # Custom C library
│   ├── Makefile
│   ├── includes/
│   │   ├── libft.h
│   │   └── ft_printf.h
│   └── srcs/             # Library source files
└── srcs/
    ├── main.c            # Main program entry point
    ├── pipex.c           # Core pipex functionality
    ├── path.c            # Path resolution functions
    └── utils.c           # Utility functions and error handling
```

## Implementation Details

### Core Structure

The program uses a `t_context` structure to manage all necessary data:

```c
typedef struct s_context
{
    char    **args;     // Command arguments
    char    *path;      // Command path
    int     infile;     // Input file descriptor
    int     outfile;    // Output file descriptor
    int     fd[2];      // Pipe file descriptors
}   t_context;
```

### Process Flow

1. **Argument Validation**: Checks for exactly 4 arguments
2. **Pipe Creation**: Creates a pipe for inter-process communication
3. **Process Forking**: Creates two child processes
4. **First Child Process**:
   - Opens input file for reading
   - Redirects stdout to pipe write end
   - Redirects stdin to input file
   - Executes first command
5. **Second Child Process**:
   - Opens output file for writing
   - Redirects stdin to pipe read end
   - Redirects stdout to output file
   - Executes second command
6. **Parent Process**: Waits for both children to complete

### Path Resolution

The program includes sophisticated path resolution:

- **Absolute Path Check**: Detects commands with '/' character
- **PATH Variable Search**: Searches through system PATH directories
- **Executable Verification**: Uses `access()` to verify executable permissions

## Examples

### Basic Usage

```bash
# Equivalent to: < input.txt grep "pattern" | wc -l > output.txt
./pipex input.txt "grep pattern" "wc -l" output.txt

# Equivalent to: < file.txt cat | sort > sorted.txt
./pipex file.txt "cat" "sort" sorted.txt

# Equivalent to: < data.txt cut -d: -f1 | sort -u > users.txt
./pipex data.txt "cut -d: -f1" "sort -u" users.txt
```

### Advanced Examples

```bash
# Text processing
./pipex input.txt "grep -v '^#'" "sed 's/old/new/g'" output.txt

# Log analysis
./pipex access.log "grep '404'" "awk '{print $1}'" error_ips.txt
```

## Error Handling

The program handles various error conditions:

- **Invalid Arguments**: Wrong number of command-line arguments
- **File Errors**: Cannot open input/output files
- **Command Errors**: Command not found or not executable
- **System Errors**: Fork, pipe, or memory allocation failures

Error messages are written to stderr using `perror()` for system errors.

## Memory Management

- **Automatic Cleanup**: `error_exit()` function ensures proper cleanup
- **Resource Management**: File descriptors and allocated memory are properly freed
- **Split Argument Cleanup**: Command arguments from `ft_split()` are properly deallocated

### Memory Safety Features

- Null pointer checks before operations
- Proper free of allocated memory in error conditions
- File descriptor cleanup in all exit paths

## Technical Details

### System Calls Used

- `pipe()`: Create pipe for inter-process communication
- `fork()`: Create child processes
- `execve()`: Execute commands
- `dup2()`: Duplicate file descriptors for redirection
- `wait()`: Wait for child processes to complete
- `access()`: Check file permissions

### Custom Library Integration

The project uses a custom `libft` library that includes:
- String manipulation functions
- Memory management utilities
- Custom `printf` implementation
- Linked list operations

## Compilation Flags

- `-Wall -Wextra -Werror`: Strict compilation warnings
- `-I./libft/includes`: Include path for libft headers
- `-L./libft -lft`: Link with libft library

## Testing

Test the program with various scenarios:

```bash
# Test with simple commands
echo "Hello World" > test.txt
./pipex test.txt "cat" "wc -w" output.txt
cat output.txt  # Should show word count

# Test with complex commands
./pipex /etc/passwd "grep root" "cut -d: -f1" root_users.txt

# Test error handling
./pipex nonexistent.txt "cat" "wc" output.txt  # Should handle missing input file
```
