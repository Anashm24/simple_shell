#include "main.h"

void free_array(char **arr) {
    int i;
    if (arr == NULL)
        return;

    for (i = 0; arr[i] != NULL; i++) {
        free(arr[i]); 
    }

    free(arr);  
}

void exit_status(char **args) {
    if (args == NULL || args[0] == NULL) {
        return; 
    }

    if (strcmp(args[0], "exit") == 0) {
        if (args[1] == NULL) {
           
            free_array(args);
            exit(EXIT_SUCCESS);
        } else {
           
            char *endptr;
            long status = strtol(args[1], &endptr, 10);

            if (*endptr != '\0' && *endptr != '\n') {
                fprintf(stderr, "exit: numeric argument required\n");
            } else {
                free_array(args);
                exit((int)status);
            }
        }
    }
}




void execute(char **args) {
    pid_t pid;

    if (args == NULL || args[0] == NULL) {
        return;
    }

    if (strcmp(args[0], "exit") == 0) {
        exit_status(args);
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            free_array(args);
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } else if (pid < 0) {
        perror("simple_shell");
    } else {
        wait(NULL);
        free_array(args);
    }
}


/**
 *find_newline - Finds the position of
 *the first newline character in a string.
 *@str: The input string.
 *Return: The position of the first newline character
 *or the length of the string if not found.
 */

size_t find_newline(char *str)
{
size_t i;
size_t len = _strlen(str);
for (i = 0; i < len; i++)
{
if (str[i] == '\n')
{
return (i);
}
}
return (len);
}

/**
 *splite_command - Splits a string into
 *an array of tokens based on whitespace characters.
 *@line: The input string to be split.
 *Return: An array of tokens.
 */

char **splite_command(char *line)
{
int buffer_size = MAX_INPUT_SIZE;
int index = 0;
char **tokens = malloc(buffer_size * sizeof(char *));
char *token;

if (!tokens)
{
perror("malloc");
exit(EXIT_FAILURE);
}

token = strtok(line, " \t\n\r\a");

while (token != NULL)
{
tokens[index] = token;
index++;

if (index >= buffer_size)
{
buffer_size += MAX_INPUT_SIZE;
tokens = realloc(tokens, buffer_size * (sizeof(char *)));
if (!tokens)
{
perror("realloc");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, " \t\n\r\a");
}

tokens[index] = NULL;
return (tokens);
}

/**
 *execute - Executes a command with its arguments
 *@args: An array of strings representing the command and its arguments.
 */
/**void execute(char **args)
{
pid_t pid;


pid = fork();

if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("execvp");
exit(EXIT_FAILURE);
}
exit(EXIT_SUCCESS);
}
else if (pid < 0)
{
perror("simple_shell");
}
else
{
    int i;
wait(NULL);
for (i = 0; args[i] != NULL; i++)
        
            free(args[i]);
        
}
}

 *interactive_mode - Runs the shell in interactive
 *mode, accepting commands from the user.
 */

/**void interactive_mode(void)
{
char *line = NULL;
size_t lenght_line = 0;
size_t newline_pos;

while (1)
{
char **args;
write(STDOUT_FILENO, "$ ", 2);

if (getline(&line, &lenght_line, stdin) == -1)
{
write(STDOUT_FILENO, "\n", 1);
free(line);
exit(EXIT_SUCCESS);
}

newline_pos = find_newline(line);
if (newline_pos < lenght_line)
{
line[newline_pos] = '\0';
}

args = splite_command(line);
execute(args);

free(args);
}
}


 