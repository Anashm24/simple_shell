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
 * @path: Array of paths to search for the executable.
 */

void executeCommand(char *command, char *path[])
{
char *args[MAX_ARGS];
int count_arg = 0;
char *token = strtok(command, " ");
while (token != NULL && count_arg < MAX_ARGS - 1)
{
args[count_arg] = token;
token = strtok(NULL, " ");
count_arg++;
}

if (count_arg >= MAX_ARGS - 1 && token != NULL)
{
perror("Too many arguments");
_exit(EXIT_FAILURE);
}
args[count_arg] = NULL;

if (_strcmp(args[0], "env") == 0)
{
char **env = environ;
while (*env != NULL)
{
write(STDOUT_FILENO, *env, _strlen(*env));
write(STDOUT_FILENO, "\n", 1);
env++;
}
_exit(EXIT_SUCCESS);
}
for (int i = 0; path[i] != NULL; i++)
{
char command_path[1024];
_strcpy(command_path, path[i]);
_strcat(command_path, "/");
_strcat(command_path, args[0]);
if (access(command_path, X_OK) != -1 && execve(command_path, args, NULL) == -1)
{
_exit(EXIT_FAILURE);
}
}
_exit(EXIT_FAILURE);
}
