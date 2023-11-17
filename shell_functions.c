#include "main.h"

/**
 * exit_status - Handles the exit status for a command.
 * @my_status: The status to check.
 * @single_command: The command arguments.
 * @token: A pointer to dynamically allocated memory.
 * @status: A pointer to an int to hold the status value.
 *
 * Return: void.
 */
void exit_status(int my_status, char **single_command, char **token,
						int *status)
{
	if (my_status == -1 ||
		(my_status == 0 && single_command[1][0] != '0') ||
		my_status < 0)
	{
		write_exit_error(single_command[1]);
		*status = 2;
	}
	else
	{
		free(*token);
		free_arr(single_command);
		exit(my_status);
	}
}

/**
 * custom_exit - Handles custom exit statuses for a command.
 * @my_status: The exit status to check.
 * @commands: The array containing the command and its arguments.
 * @line: A pointer to the input line.
 * @status: A pointer to an int to hold the return status value.
 *
 * Return: void.
 */
void custom_exit(int my_status, char **commands,
						char *line, int *status)
{
	if (my_status == -1 ||
		(my_status == 0 && commands[1][0] != '0') ||
		my_status < 0)
	{
		perror("commands[1]");
		*status = 2;
	}
	else
	{
		free(line);
		free_arr(commands);
		exit(my_status);
	}
}
/**
 * _getline_error - Handles getline() error.
 * @line: A pointer to the input line.
 *
 * Return: void.
 */
void _getline_error(char *line)
{
	perror("getline");
	free(line);
	line = NULL;
	exit(EXIT_FAILURE);
}

/**
 * _getline - Reads a line of text from a file descriptor.
 * @line: A pointer to the buffer where the line will be stored.
 * @n_ch: A pointer to the size of the buffer.
 * @fd: The file descriptor to read from.
 *
 * Return: If the line is read successfully, returns the number of characters
 *         read. If an error occurs, returns -1. If the end of the file is
 *         reached before any characters are read, returns 0.
 */

ssize_t _getline(char **line, size_t *n_ch, int fd)
{
char character;
size_t i = 0;
int ret;

if (*line == NULL || n_ch == NULL)
{
*n_ch = 80;
*line = malloc(sizeof(char) * (*n_ch));

if (*line == NULL)
{
perror("malloc failed");
return (-1);
}
}

while ((ret = read(fd, &character, 1)) > 0)
{
(*line)[i] = character;
i++;

if (i > *n_ch)
{
*n_ch *= 2;
*line = realloc(*line, *n_ch);
if (*line == NULL)
{
perror("realloc failed");
return (-1);
}
}
if (character == '\n')
break;
}
if (ret == 0 && i == 0)
return (-1);

(*line)[i] = '\0';
return (i);
}
