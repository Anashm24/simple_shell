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
static char *start_token;

if (str != NULL)
{
start_token = str;
}

if (start_token == NULL)
{
return (NULL);
}

char *end_of_token = _strpbrk(start_token, delimiter);

if (end_of_token != NULL)
{
*end_of_token = '\0';
char *token = start_token;
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

void excute_cmd(char *path[], char *args[])
{
char **env = environ;
    for (int i = 0; path[i] != NULL; i++)
{
char command_path[1024];
_strcpy(command_path, path[i]);
_strcat(command_path, "/");
_strcat(command_path, args[0]);
if (access(command_path, X_OK) != -1 && execve(command_path, args, env) == -1)
{
_exit(EXIT_FAILURE);
}
}
}
