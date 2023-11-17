#include "main.h"

/**
 * main - Entry point for the shell program
 *
 * Return: Returns 0 on success, or status of the non_interactive_mode
 */
int main(void)
{
	size_t s_input = 0;
	char *input = NULL;
	int status = 0;

	if (!isatty(0))
	{
		if (input)
		{
			free(input);
			input = NULL;
		}
        while (_getline(&input, &s_input, STDIN_FILENO) != -1)
		{
			non_inter_md(input, &status);
		}
		return (status);
	}
	_myshell();
	return (0);
}

/**
 * split - Splits a string into tokens
 * @string: The string to tokenize
 * @delim: The delim to use for tokenization
 *
 * Return: Returns result.
 */
char **split_cmd(char *string, char *delim)
{
	int n_count = 0;
	char *token;
	char **tokens = malloc(22 * sizeof(char *));

	if (tokens == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(string, delim);
	while (token != NULL)
	{
		tokens[n_count] = _strdup(token);
		n_count++;
		token = strtok(NULL, delim);
	}
	while (n_count < 20)
	{
		tokens[n_count] = NULL;
		n_count++;
	}

	return (tokens);
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

	token[_strlen(token) - 1] = '\0';
	single_command = split_cmd(token, " \t");
	if (single_command[0])
	{
		if (!_strcmp(single_command[0], "exit"))
		{
			if (single_command[1])
			{
				int my_status = _strto_i(single_command[1]);

				exit_status(my_status, single_command, &token, status);
			}
			else
			{
				free(token);
				free_arr(single_command);
				exit(*status);
			}
		}
		else if (!_strcmp(single_command[0], "env"))
		{
			_env();
			*status = 0;
		}
		else
		excute_cmd(single_command, envp, status);
	}
	free_arr(single_command);
}


void cd_command(char **args)
{
    char cwd[1024];
    static char *last_dir = NULL;
    char *home_dir = getenv("HOME");

    if (args[1] == NULL || strcmp(args[1], "~") == 0) {
        chdir(home_dir);
    } else if (strcmp(args[1], "-") == 0) {
        if (last_dir) {
            chdir(last_dir);
        }
    } else {
        last_dir = getcwd(cwd, sizeof(cwd));
        if (chdir(args[1]) != 0) {
            perror("cd");
        }
    }

    printf("Current directory: %s\n", getcwd(cwd, sizeof(cwd)));
}

/*int main(int argc, char **argv)
{

    char *args1[] = {"cd", NULL};
    cd_command(args1);

    char *args2[] = {"cd", "/tmp", NULL};
    cd_command(args2);

    char *args3[] = {"cd", "-", NULL};
    cd_command(args3);

    return 0;
}
*/