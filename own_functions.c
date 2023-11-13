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
