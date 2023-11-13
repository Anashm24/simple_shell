#include "main.h"

extern char **environ;
int i = 0;
char *_getenv(const char *target_key)
{

while(environ[i])
{
    if (_strncmp(environ[i], target_key, _strlen(target_key)) == 0)
    {
        return (environ[i]);
    }
    i++;
}
return (NULL);
}