#include "main.h"

/**
* _myshell - Starts the shell's main loop
*
* Description: Initializes the shell, handles user input,
* tokenizes commands and executes them.
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
if (commands[1])
{
int my_status = str_to_int(commands[1]);

_exit_(my_status, commands, line, &status);
}
else
{
free(line);
free_array(commands);
exit(status);
}
}
else if (!_strcmp(commands[0], "env"))
{
print_env_var();
status = 0;
}
else if (!_strcmp(commands[0], "setenv"))
{
if (commands[1] && commands[2])
{
_setenv(commands[1], commands[2]);
}
else
{
fprintf(stderr, "setenv: Invalid syntax\n");
}
}
else if (!_strcmp(commands[0], "unsetenv"))
{
if (commands[1])
{
_unsetenv(commands[1]);
}
else
{
fprintf(stderr, "unsetenv: Missing variable\n");
}
}
else
_execvep(commands, envp, &status);
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
*
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
* Description: Writes an error message
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
* Description: Writes an error message
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
* This function frees the memory allocated for an array of strings.
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

