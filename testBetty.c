#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


/**
* Testbetty - Entry point of the program.
* Return: Always 0 (Success).
*/

int Testbetty(void)
{
write(STDOUT_FILENO, "Hello world!", 12);
return (0);
}
