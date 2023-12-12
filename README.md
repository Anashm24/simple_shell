# Simple Shell

A custom simple shell program that can execute commands and handle arguments.

## Description

This project is a C program that creates a simple UNIX shell that can run commands from the standard input or from a file. The shell can handle arguments, built-in commands, environment variables, and redirections. The shell also supports some features such as history, aliases, and comments.

## Features

* Execute commands and handle arguments
* Support built-in commands: exit, env, setenv, unsetenv, cd, help, history, alias, unalias
* Support interactive and non-interactive mode
* Handle errors and signals
* TODO: Implement job control and background processes

## Getting Started

### Dependencies

* Linux operating system
* GCC compiler
* GNU make

### Installing

* Clone this repository to your local machine
* Navigate to the project directory
* Run `make` to compile the program

### Executing program

* To run the program in interactive mode, type `./hsh` and press enter
* To run the program in non-interactive mode, type `echo "command" | ./hsh` or `./hsh file` where command is the command you want to execute and file is the file that contains the commands
* To exit the program, type `exit` or press Ctrl-D
