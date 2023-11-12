#include "main.h"

/**
 * _strcmp - Custom implementation of string comparison.
 * @str1: First string to compare.
 * @str2: Second string to compare.
 * Return: An integer less than, equal to, or greater than zero if str1
 * is found to be less than, equal to, or greater than str2, respectively.
 */

int _strcmp(char *str1, char *str2)
{
if (*str1 && *str2 && *str1 == *str2)
{
*str1++;
*str2++;
}
return (*str1 - *str2);
}

/**
 * _strcpy - Custom implementation of string copy.
 * @dest: Destination buffer to copy the string into.
 * @src: Source string to be copied.
 */

void _strcpy(char *dest, const char *src)
{
while (*src != '\0')
{
*dest = *src;
dest++;
src++;
}
*dest = '\0';
}

/**
 * _strcat - Custom implementation of string concatenation.
 * @dest: Destination buffer to concatenate the string into.
 * @src: Source string to be concatenated.
 */

void _strcat(char *dest, const char *src)
{
while (*dest != '\0')
{
dest++;
}
while (*src != '\0')
{
*dest = *src;
dest++;
src++;
}
*dest = '\0';
}

/**
 * _strlen - Custom implementation of string length calculation.
 * @str: Input string.
 * Return: The length of the string.
 */

size_t _strlen(const char *str)
{
size_t length = 0;
while (*str != '\0')
{
length++;
str++;
}
return (length);
}

