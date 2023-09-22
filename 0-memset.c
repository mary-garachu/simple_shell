#include "shell.h"

/**
 * _memset - fills the first n bytes of memory
 * @s: pointer to char
 * @b: char variable
 * @n: integer for the number of times
 * Return: char
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
