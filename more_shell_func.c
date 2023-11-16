#include "main.h"

/**
 * print_error - Prints an error message indicating incorrect command usage.
 */

void print_error(void)
{
const char usage_msg[] = "Usage: %s [script]\n";
write(STDERR_FILENO, usage_msg, sizeof(usage_msg) - 1);
exit(EXIT_FAILURE);
}
