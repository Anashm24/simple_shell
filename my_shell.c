#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
*main - Entry point of the program.
*Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
*/

int main(void)
{
char *path_env = _getenv("PATH");

if (path_env == NULL)
{
perror("Error: PATH variable not found in the environment.");
return (EXIT_FAILURE);
}

char *path[MAX_ARGS];
int i = 0;
char *token = _strtok(path_env, ":");

while (token != NULL && i < MAX_ARGS - 1)
{
path[i++] = token;
token = _strtok(NULL, ":");
}
path[i] = NULL;

handleCommands(path);
return (EXIT_SUCCESS);
}
