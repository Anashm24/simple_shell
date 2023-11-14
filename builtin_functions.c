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

void exit_status(char *command)
{
       char *token;
    int i = 0, x = 0;
    char **args = malloc(sizeof(char *) * 2);

    token = strtok(command," ");

    while (token)
    {
        args[x] = token;
        x++;
        token = strtok(NULL, " ");
    }
    char *second_word = args[1];



    if (strcmp(args[0], "exit") == 0 && second_word == NULL)
    {
        free(args);
        _exit(EXIT_SUCCESS);
    }

    int status = 0;
    if (second_word != NULL)
    {
        while (*second_word != '\0')
        {
            if (*second_word < '0' || *second_word > '9') {
                perror("exit: numeric argument required\n");
            }
            status = status * 10 + *second_word - '0';
            second_word++;
        }
    }
    if (second_word != NULL)
    {
        free(args);
        _exit(status);
    }
    free(args);
}