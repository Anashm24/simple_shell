#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

/**
 * executeCommand - Executes a command with specified arguments.
 * @command: Input command line.
 */

void executeCommand(char *command)
{
char *args[MAX_ARGS];
int count_arg = 0;
char *token = _strtok(command, " ");

if (command == NULL)
{
perror("Invalid command");
_exit(EXIT_FAILURE);
}
while (token != NULL && count_arg < MAX_ARGS - 1)
{
args[count_arg] = token;
token = _strtok(NULL, " ");
count_arg++;
}

if (count_arg >= MAX_ARGS - 1 && token != NULL)
{
perror("Too many arguments");
_exit(EXIT_FAILURE);
}
args[count_arg] = NULL;


if (_strcmp(args[0], "setenv") == 0)
{
handle_setenv(args, count_arg);
}
else if (_strcmp(args[0], "unsetenv") == 0)
{
handle_unsetenv(args, count_arg);
}
else
{
execute_cmd(command, args);
}
}

/**
 * readInput - Reads a command line of input from the user.
 * Return: A pointer to the string containing user input.
 */

char *readInput()
{
char *command = NULL;
size_t len = 0;
int length;
int n;
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "$ ", 2);
}
n = _getline(&command, &len, STDIN_FILENO);

if (n == -1 || (n == 0 && command[0] == '\n'))
{
write(STDOUT_FILENO, "\n", 1);
free(command);
_exit(EXIT_FAILURE);
}

length = n;

if (command[length - 1] == '\n')
{
command[length - 1] = '\0';
}
return (command);
}

/**
 * handleCommands - Handles user commands in a loop.
 */

void handleCommands(void)
{
pid_t pid;
while (1)
{
char *command = readInput();
if (!isatty(STDIN_FILENO) && command[0] == '\0')
{
free(command);
break;
}
pid = fork();

if (pid == -1)
{
perror("Fork failed");
free(command);
_exit(EXIT_FAILURE);
}
if (isatty(STDIN_FILENO) && _strcmp(command, "exit") == 0)
{
exit_status(command);
free(command);
break;
}
if (pid == 0)
{
executeCommand(command);
free(command);
_exit(EXIT_SUCCESS);
}
else
{
int status;
wait(&status);
free(command);
}
}
}
