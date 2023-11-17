#include "main.h"

/**
* main - Entry point for the shell program
*
* Return: Returns 0 on success, or status of the non_interactive_mode
*/
int main(void)
{
	size_t size_line = 0;
	char *line = NULL;

	int status = 0;

	if (!isatty(0))
	{
		while (getline(&line, &size_line, stdin) != -1)
		{
			non_inter_md(line, &status);
		}
		if (line)
		{
			free(line);
			line = NULL;
		}
		return (status);
	}
	_myshell();
	return (0);
}
/**
* non_inter_md - Executes shell commands in non_nteractive_mode
* @token: The string containing commands separated by newline characters
* @status: integer store the number
* Return: Returns status.
*/
void non_inter_md(char *token, int *status)
{
	char **single_command;

	char *envp[] = {NULL};

	token[strlen(token) - 1] = '\0';
	single_command = split_cmd(token, " \t");
	if (single_command[0])
	{
		if (!_strcmp(single_command[0], "exit"))
		{
			if (single_command[1])
			{
				int my_status = str_to_int(single_command[1]);

				exit_status(my_status, single_command, &token, status);
			}
			else
			{
				free(token);
				free_array(single_command);
				exit(*status);
			}
		}
		else if (!_strcmp(single_command[0], "env"))
		{
			print_env_var();
			*status = 0;
		}
		else if (!_strcmp(single_command[0], "setenv"))
		{
			if (single_command[1] && single_command[2])
			{
				_setenv(single_command[1], single_command[2]);
			}
			else
			{
				fprintf(stderr, "setenv: Invalid syntax\n");
			}
		}
		else if (!_strcmp(single_command[0], "unsetenv"))
		{
			if (single_command[1])
			{
				_unsetenv(single_command[1]);
			}
			else
			{
				fprintf(stderr, "unsetenv: Missing variable\n");
			}
		}
		else
		_execvep(single_command, envp, status);
	}
	free_array(single_command);
}

/**
* **split_cmd - Splits a string into tokens
* @str: The string to tokenize
* @delimiters: The delimiters to use for tokenization
*
* Return: Returns result.
*/
char **split_cmd(char *str, char *delimiters)
{
	int count = 0;

	char *token;

	char **result = malloc(20 * sizeof(char *));

	if (result == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, delimiters);
	while (token != NULL)
	{
		result[count] = _strdup(token);
		count++;
		token = strtok(NULL, delimiters);
	}
	while (count < 20)
	{
		result[count] = NULL;
		count++;
	}

	return (result);
}
