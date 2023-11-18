#include "main.h"

/**
*_myshell - Main function for a custom shell implementation
*@void: This function does not take any parameters
*Note: This function does not return a value errors are handled internally
*/
void _myshell(void)
{
char *line = NULL, **commands, *envp[] = {NULL};
size_t size_line = 0;
ssize_t nread;
int status = 0;
while (1)
{
nread = read_input(&line, &size_line);
if (nread == -1)
_getline_error(line);

commands = split_cmd(line, " \n\t");
if (commands[0])
{
if (!_strcmp(commands[0], "exit"))
{
handle_exit(commands, line, &status);
}
else if (!_strcmp(commands[0], "env"))
{
handle_env(&status);
}
else if (!_strcmp(commands[0], "cd"))
{
handle_cd(commands, &status);
}
else if (!_strcmp(commands[0], "setenv"))
{
handle_setenv(commands);
}
else
{
_execvep(commands, envp, &status);
}
}

free_array(commands);
free(line);
line = NULL;
}
}

/**
* read_input - Reads a line of command from the user
* @line: The line buffer to store command
* @size_line: The size of the line buffer
* Return: Returns the number of characters read.
*/
ssize_t read_input(char **line, size_t *size_line)
{
write(STDOUT_FILENO, "$ ", 2);
return (getline(line, size_line, stdin));
}

/**
* _exit_error - Writes an error message to STDERR
*
* @number: number
*/
void _exit_error(char *number)
{
write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
write(STDERR_FILENO, number, _strlen(number));
write(STDERR_FILENO, "\n", 1);
}


/**
* write_error - Writes an error message to STDERR
*
* @command: command
*/
void write_error(char *command)
{
write(STDERR_FILENO, "./hsh: 1: ", 10);
write(STDERR_FILENO, command, _strlen(command));
write(STDERR_FILENO, ": not found\n", 12);
}

/**
* free_array - Frees memory allocated for an array of strings.
* @array: A pointer to the dynamically allocated array of strings.
*
*/
void free_array(char **array)
{
int i;

if (!array)
return;
for (i = 0; array[i] != NULL; i++)
{
free(array[i]);
}
free(array);
}

