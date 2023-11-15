#include "main.h"

/**
 * _getenv - Retrieves the value of an environment variable.
 * @target_key: The name of the environment variable to retrieve.
 *
 * Return: If the environment variable is found, returns a pointer to the
 *         "name=value" string. Otherwise, returns NULL.
 */

char *_getenv(const char *target_key)
{
int i = 0;

while (environ[i])
{
if (_strncmp(environ[i], target_key, _strlen(target_key)) == 0)
{
return (environ[i]);
}
i++;
}
return (NULL);
}

/**
 * _strpbrk - Searches a string for any character from a specified set.
 * @str: The input string to be searched.
 * @delimiter: The set of characters to search for in the input string.
 *
 * Return: A pointer to the first matching character in the input string.
 *         If no match is found, returns NULL.
 */

char *_strpbrk(char *str, const char *delimiter)
{
while (*str)
{
const char *delim = delimiter;
while (*delim)
{
if (*str == *delim)
{
return ((char *)str);
}
delim++;
}
str++;
}
return (NULL);
}

/**
 * _strtok - Breaks a string into tokens based on a specified delimiter.
 * @str: The string to be tokenized.
 * @delimiter: The set of delimiter characters.
 *
 * Return: A pointer to the next token in the string. If no more tokens are
 *         found, returns NULL.
 */

char *_strtok(char *str, const char *delimiter)
{
char *token;
static char *start_token;
char *end_of_token;

if (str != NULL)
{
start_token = str;
}

if (start_token == NULL)
{
return (NULL);
}

end_of_token = _strpbrk(start_token, delimiter);

if (end_of_token != NULL)
{
*end_of_token = '\0';
token = start_token;
start_token = end_of_token + 1;
return (token);
}
else
{
char *token = start_token;
start_token = NULL;
return (token);
}
}

/**
 * execute_cmd - Execute a command by searching for its executable file
 *                in the specified paths.
 * @command: An array of strings representing the directories to search for
 *        the executable file.
 * @args: An array of strings representing the command and its arguments.
 */

void execute_cmd(char *command, char *args[])
{
char **env = environ;

if (access(command, X_OK) != -1 && execve(command, args, env) == -1)
{
_exit(EXIT_FAILURE);
}
_exit(EXIT_FAILURE);
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

if (i > *n_ch - 1)
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
