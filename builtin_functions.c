#include "main.h"

/**
*handle_env - Display the current environment variables.
*/

void handle_env(void)
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

/**
 *handle_setenv - Handle the "setenv" command and set environment variables.
 *@args: An array of strings representing
 *the "setenv" command and its arguments.
 *@count_arg: The number of arguments provided.
 */

void handle_setenv(char *args[], int count_arg)
{
int i;
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

for (i = 0; environ[i] != NULL; i++)
{
printf("%s\n", environ[i]);
}
}
_exit(EXIT_SUCCESS);
}

/**
 *handle_unsetenv - Remove an environment variable.
 *@args: An array of strings representing the command and its arguments.
 *@count_arg: The number of arguments provided with the command.
 */
void handle_unsetenv(char *args[], int count_arg)
{
int i;
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
for (i = 0; environ[i] != NULL; i++)
{
printf("%s\n", environ[i]);
}
}
_exit(EXIT_SUCCESS);
}

/**
 *exit_status - Handle the "exit" command and set the exit status.
 *@command: A string representing the "exit" command and its arguments.
 */

void exit_status(char *command)
{
char *token;
int x = 0;
int status;
char *second_word;
char **args = malloc(sizeof(char *) * 2);

token = _strtok(command, " ");

while (token)
{
args[x] = token;
x++;
token = _strtok(NULL, " ");
}
second_word = args[1];

if (strcmp(args[0], "exit") == 0 && second_word == NULL)
{
free(args);
_exit(EXIT_SUCCESS);
}
status = 0;
if (second_word != NULL)
{
while (*second_word != '\0')
{
if (*second_word < '0' || *second_word > '9')
{
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
