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
		_exit_error(single_command[1]);
		*status = 2;
	}
	else
	{
		free(*token);
		free_array(single_command);
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
void _exit_(int my_status, char **commands,

char *line, int *status)
{
	if (my_status == -1 ||
		(my_status == 0 && commands[1][0] != '0') ||
		my_status < 0)
	{
		_exit_error(commands[1]);
		*status = 2;
	}
	else
	{
		free(line);
		free_array(commands);
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
* _getline - Reads a line of input from the user.
* @line: A pointer to a string to hold the input line.
* @size: A pointer to a size_t to hold the size of the input line.
*
* Return: The number of characters read, including the null terminator,
*or -1 if EOF is encountered and no characters have been read.
*/

ssize_t _getline(char **line, size_t *size)
{
size_t pos = 0;
int c;

<<<<<<< HEAD
if (*line == NULL || *size == 0)
{
*size = 128;
*line = malloc(*size);
if (*line == NULL)
{
perror("malloc");
return (-1);
}
}
=======

    if (*line == NULL || *size == 0) {
        *size = 128;
        *line = malloc(*size);
        if (*line == NULL) {
            perror("malloc");
            return (-1);
        }
    }
>>>>>>> e9def865be8d8e67d1c448c175be121bcb7c3a53

while ((c = getchar()) != EOF && c != '\n')
{
if (pos == *size - 1)
{
*size *= 2;
*line = realloc(*line, *size);
if (*line == NULL)
{
perror("realloc");
return (-1);
}
}
(*line)[pos++] = c;
}

if (c == EOF && pos == 0)
{
return (-1);
}

(*line)[pos] = '\0';

<<<<<<< HEAD
return (pos + 1);
}
=======
    return (pos + 1);
}


int set_env_variable(const char *variable, const char *value, int overwrite)
{
    if (variable == NULL || value == NULL) {
        fprintf(stderr, "setenv: Missing argument\n");
        return -1;
    }

    if (setenv(variable, value, overwrite) == -1) {
        perror("setenv");
        return -1;
    }

    return 0;
}

int unset_env_variable(const char *variable)
{
    if (variable == NULL) {
        fprintf(stderr, "unsetenv: Missing argument\n");
        return -1;
    }

    if (unsetenv(variable) == -1) {
        perror("unsetenv");
        return -1;
    }

    return 0;
}
>>>>>>> e9def865be8d8e67d1c448c175be121bcb7c3a53
