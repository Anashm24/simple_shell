#include "main.h"

/**
*environ_size - Counts the number of environment variables
*Return: The number of environment variables.
*/

int environ_size(void)
{
int size = 0;
char **env = environ;

while (*env != NULL)
{
size++;
env++;
}
return (size);
}

/**
*_unsetenv - Unset an environment variable.
*@variable: The name of the environment variable to unset.
*Return: Returns 0 on success, -1 on failure.
*/

int _unsetenv(const char *variable)
{

int variable_length;

int i, j;

if (!variable)
{
perror("unsetenv");
return (-1);
}

variable_length = _strlen(variable);

for (i = 0; environ[i] != NULL; i++)
{
if (!strncmp(variable, environ[i], variable_length))
{
for (j = i; environ[j] != NULL; j++)
{
environ[j] = environ[j + 1];
}

return (0);
}
}

fprintf(stderr, "unsetenv: %s: not found\n", variable);
return (-1);
}



/**
 *cd_builtin - Change current working directory.
 *@path: The directory path to change to.
 *Return: 0 on success, -1 on failure.
 */

int cd_builtin(char *path)
{
if (path == NULL)
{
path = _getenv("HOME");
if (path == NULL)
{
write(STDERR_FILENO, "cd: No home directory\n", 22);
return (-1);
}
}
if (chdir(path) != 0)
{
perror("cd");
return (-1);
}
return (0);
}

/**
 *_setenv_update - Updates the value of an existing environment variable
 *@variable: The name of the environment variable to update
 *@value: The new value for the environment variable
 *@existing_value: The current value of the environment variable
 *@variable_length: The length of the variable name
 *Return: Returns 0 on success, -1 on failure
 */

int _setenv_update(const char *variable, const char *value,
char *existing_value, int variable_length)
{
char **new_environment;
int existing_value_length = _strlen(existing_value), i;
char *new_entry = malloc(variable_length + 1 + existing_value_length + 1);

if (!new_entry)
{
perror("setenv");
return (-1);
}
strcpy(new_entry, variable);
strcat(new_entry, "=");
strcat(new_entry, value);
for (i = 0; environ[i] != NULL; i++)
{
if (!strncmp(variable, environ[i], variable_length))
{
free(environ[i]);
environ[i] = new_entry;
free(existing_value);
return (0);
}
}
new_environment = malloc((environ_size() + 2) * sizeof(char *));
if (!new_environment)
{
perror("setenv");
free(existing_value);
free(new_entry);
return (-1);
}
for (i = 0; environ[i] != NULL; i++)
new_environment[i] = environ[i];
new_environment[environ_size()] = new_entry;
new_environment[environ_size() + 1] = NULL;
environ = new_environment;
return (0);
}

/**
*_setenv_add - Adds a new environment variable
*@variable: The name of the environment variable to add
*@value: The value for the new environment variable
*Return: Returns 0 on success, -1 on failure
*/

int _setenv_add(const char *variable, const char *value)
{
int variable_length = _strlen(variable);
int value_length = _strlen(value);
char **new_environment;
int i;

char *new_entry = malloc(variable_length + 1 + value_length + 1);
if (!new_entry)
{
perror("setenv");
return (-1);
}
strcpy(new_entry, variable);
strcat(new_entry, "=");
strcat(new_entry, value);

new_environment = malloc((environ_size() + 2) * sizeof(char *));
if (!new_environment)
{
perror("setenv");
free(new_entry);
return (-1);
}
for (i = 0; environ[i] != NULL; i++)
{
new_environment[i] = environ[i];
}
new_environment[environ_size()] = new_entry;
new_environment[environ_size() + 1] = NULL;
environ = new_environment;
free(new_environment);
free(new_entry);
return (0);
}
