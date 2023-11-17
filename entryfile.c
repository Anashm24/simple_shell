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
        nread = reader(&line, &size_line);
		if (nread == -1)
			_getline_error(line);
		commands = split_cmd(line, " \n\t");
		if (commands[0])
		{
			if (!_strcmp(commands[0], "exit"))
			{
				if (commands[1])
				{
					int my_status = _strto_i(commands[1]);

					custom_exit(my_status, commands, line, &status);
				}
				else
				{
					free(line);
					free_arr(commands);
					exit(status);
				}
			}
			else if (!_strcmp(commands[0], "env"))
			{
				_env();
				status = 0;
			}
			else
				excute_cmd(commands, envp, &status);
		}
		free_arr(commands);
		free(line);
		line = NULL;
	}
}


/**
 * reader - Reads a line of command from the user
 * @line: The line buffer to store command
 * @size_line: The size of the line buffer
 *
 * Return: Returns the number of characters read.
 */
ssize_t reader(char **line, size_t *size_line)
{
	write(STDOUT_FILENO, "$ ", 2);
	return (getline(line, size_line, stdin));
}
/**
 * handle_err - Writes an error message to STDERR
 *
 * @command: command
 * Description: Writes an error message
 */
void handle_err(char *command)
{
	write(STDERR_FILENO, "./hsh: 1: ", 10);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
}
/**
 * write_exit_error - Writes an error message to STDERR
 *
 * @number: number
 * Description: Writes an error message
 */
void write_exit_error(char *number)
{
	write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
	write(STDERR_FILENO, number, _strlen(number));
	write(STDERR_FILENO, "\n", 1);
}
/**
 * free_arr - Frees memory allocated for an array of strings.
 * @array: A pointer to the dynamically allocated array of strings.
 *
 * This function frees the memory allocated for an array of strings.
 */
void free_arr(char **array)
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