#include "main.h"



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
 * _strlen - Calculates the length of a string
 * @str: The string to measure
 *
 * Return: Returns the length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
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
 * _strcmp - Compares two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: The difference between the ASCII values of the first unmatched
 * characters, 0 if the strings are identical.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}

	return (s1[i] - s2[i]);
}


/**
 * _strto_i - convert a string into an integer.
 *
 * @s: the string to use.
 *
 * Return: integer.
 */
int _strto_i(char *s)
{
	int sign = 1, i = 0;
	unsigned int res = 0;

	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}

/**
 * _strdup - Duplicates a string
 * @src: The source string to duplicate
 *
 * Return: Returns a pointer(str)
 */
char *_strdup(const char *src)
{
	char *str;
	char *ptr;
	int len = 0;

	while (src[len])
		len++;

	str = malloc(len + 1);
	if (!str)
		return (NULL);

	ptr = str;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (str);
}
