#include "main.h"

/**
*_setenv - Sets the value of an environment variable
*@variable: The name of the environment variable to set
*@value: The value for the environment variable
*Return: Returns 0 on success, -1 on failure
*/

int _setenv(const char *variable, const char *value)
{
char *existing_value;

if (!variable || !value)
{
perror("setenv");
return (-1);
}
existing_value = _getenv(variable);
if (existing_value != NULL)
{
int variable_length = _strlen(variable);
int result = _setenv_update(variable, value, existing_value, variable_length);
return (result);
}
else
{
int result = _setenv_add(variable, value);
return (result);
}
}

/**
*handle_exit - This function checks if an exit status was provided
*@commands: The array of command and arguments
*@line: The original command line input
*@status: The current shell status
*/

void handle_exit(char **commands, char *line, int *status)
{
if (commands[1])
{
int my_status = str_to_int(commands[1]);
_exit_(my_status, commands, line, status);
}
else
{
free(line);
free_array(commands);
exit(*status);
}
}

/**
*handle_env - This function prints the environment
*variables and sets the shell status to 0.
*@status: The current shell status
*/

void handle_env(int *status)
{
print_env_var();
*status = 0;
}

/**
*handle_cd - This function changes the current directory
*to the one specified in the commands array
*@commands: The array of command and arguments
*@status: The current shell status
*/

void handle_cd(char **commands, int *status)
{
if (commands[1])
{
if (cd_builtin(commands[1]) != 0)
*status = 2;
}
else
{
if (cd_builtin(NULL) != 0)
*status = 2;
}
}

/**
*handle_setenv - This function sets the value of an environment variable
*@commands: The array of command and arguments
*/

void handle_setenv(char **commands)
{
if (commands[1] && commands[2])
_setenv(commands[1], commands[2]);
else
perror("./hsh");
}

