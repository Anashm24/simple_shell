#include "main.h"

/**
 * main - Entry point for the simple shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *Return: O successful execution.
 */

int main(int argc, char *argv[])
{


char *line = NULL;
size_t length_line = 0;
size_t newline_pos;
(void)argc;
(void)argv;

while (1)
{
char **args;
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, ":) ", 2);

if (getline(&line, &length_line, stdin) == -1)
{
free(line);
exit(EXIT_SUCCESS);
}

newline_pos = find_newline(line);
if (newline_pos < length_line)
{
line[newline_pos] = '\0';
}
args = splite_command(line);

execute(args);

free(args);
}
return (0);
}
