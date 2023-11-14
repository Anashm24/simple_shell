#include "main.h"

void handle_env(char *args[])
{
char **env = environ;


while (*env != NULL)
{
write(STDOUT_FILENO, *env, _strlen(*env));
write(STDOUT_FILENO, "\n", 1);
env++;
}
_exit(EXIT_SUCCESS);
}


void handle_setenv(char *args[], int count_arg)
{
char error_message[] = "Usage: setenv VARIABLE VALUE\n";

if (count_arg != 3)
{
write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
}
else
{
if (setenv(args[1], args[2], 1) == -1)
{
perror("setenv failed");
}

for (int i = 0; environ[i] != NULL; i++)
{
printf("%s\n", environ[i]);
}
}
_exit(EXIT_SUCCESS);
}

void handle_unsetenv(char *args[], int count_arg)
{
char error_message[] = "Usage: unsetenv VARIABLE\n";

if (count_arg != 2)
{
write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
}
else
{
if (unsetenv(args[1]) == -1)
{
perror("unsetenv failed");
}
for (int i = 0; environ[i] != NULL; i++)
{
printf("%s\n", environ[i]);
}
}
_exit(EXIT_SUCCESS);
}
