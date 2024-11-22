# pipex

**Pipex** is a minimal implementation of the UNIX pipeline operator `|` and redirections `<` and `>`. This project is an exercise in understanding process creation, file descriptors, and inter-process communication using pipes.

## Overview
The **pipex** project mimics the behavior of a simple shell pipeline. It takes input from a file, passes it through a chain of commands, and writes the output to another file. Pipex demonstrates the use of system calls such as `pipe()`, `fork()`, `execve()`, and `dup2()`.

For example:
```bash
< infile command1 | command2 > outfile
```

Would be executed in **pipex** as:
```bash
./pipex infile "command1" "command2" outfile
```

## Features
- Support for two commands connected via a pipe.
- Input redirection from a file.
- Output redirection to a file.
- Error handling for invalid inputs, permissions, and command failures.
- Minimal implementation using standard library functions.

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your_username/pipex.git
   cd pipex
   ```

2. Compile the program:
   ```bash
   make
   ```

This will generate the `pipex` executable in the project directory.

## Usage
The general syntax for **pipex**:
```bash
./pipex infile "command1" "command2" outfile
```

- **infile**: The input file to read from.
- **command1**: The first command to execute.
- **command2**: The second command to execute.
- **outfile**: The output file to write to.

## Examples

1. **Basic pipeline**:
   ```bash
   ./pipex input.txt "cat -e" "wc -l" output.txt
   ```
   This is equivalent to:
   ```bash
   cat -e < input.txt | wc -l > output.txt
   ```

2. **Handling invalid commands**:
   If a command is invalid, the program will display an appropriate error message and exit.

### Key Functions Used

- **`pipe()`**: Create a pipe for inter-process communication.
- **`fork()`**: Create child processes for command execution.
- **`dup2()`**: Duplicate file descriptors for input/output redirection.
- **`execve()`**: Execute the given commands.

## Testing

You can test the program with various input files, commands, and scenarios to ensure it behaves as expected.

1. **Run example commands**:
   ```bash
   ./pipex infile "ls -l" "grep pipex" outfile
   ```

2. **Compare outputs**:
   Use `diff` to compare **pipex**'s output with the shell's output:
   ```bash
   diff <(cat infile | command1 | command2) outfile
   ```
