#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* main - Entry point of the program.
* Description: This function tokenizes a string
* @void: No input parameter.
* Return: Always 0 (Success).
*/

int main(void)
{
char str[] = "exit 98";
char *token;
int i = 0, x = 0;
char **args = malloc(sizeof(char *) * 2);

token = strtok(str, " ");

while (token)
{
args[x] = token;
x++;
token = strtok(NULL, " ");
}
return (0);
}
