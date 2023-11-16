#include "main.h"

/**
 * main - Entry point for the simple shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *Return: O successful execution.
 */

int main(int argc, char *argv[])
{
if (argc == 1 && isatty(STDIN_FILENO))
{
interactive_mode();
}
else if (argc == 2)
{
non_interactive_mode(argv[1]);
}
else
{
print_error();
}

return (0);
}
