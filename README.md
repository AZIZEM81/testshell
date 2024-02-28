# Simple Shell Project

This project implements a simple UNIX command line interpreter, also known as a shell. The shell supports basic functionality such as executing commands, handling errors, and providing an interactive prompt for user input.

## Task 0: Betty would be proud

Ensure that the code follows the Betty coding style by running the `betty_check.sh` script.

## Task 1: Simple shell 0.1

Write a UNIX command line interpreter.

Usage: simple_shell

Your Shell should:
- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- Handle the "end of file" condition (Ctrl+D).
- You don’t have to use the PATH or implement built-ins.

## Task 2: Simple shell 0.2

Handle command lines with arguments.

## Task 3: Simple shell 0.3

Handle the PATH. Fork must not be called if the command doesn’t exist.

## Task 4: Simple shell 0.4

Implement the exit built-in, that exits the shell.

Usage: exit

## Task 5: Simple shell 1.0

Implement the env built-in, that prints the current environment.

////////////////////////////////////////////////////////////////////////////////////////
After compiling, you can run the program using:
./custom_string_functions
////////////////////////////////////////////////////////////////////////////////////////

Functionality
The program provides the following functionalities:

Execution of commands with argument parsing.
Handling of exit and environment commands.
Tokenization of input for command execution.
Custom string functions for string manipulation.
Error handling for command execution.
Contribution
Contributions to this project are welcome. You can fork the repository,
make improvements, and create a pull request.
