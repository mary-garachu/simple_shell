#include "shell.h"
/**
 * is_whitespace_string - check is str contains spaces and tabs
 * @str: the string to check
 * Return: 1 consists of only spaces 0 no spaces only
 */
int is_whitespace_string(const char *str)
{
	while (*str != '\0')
	{
		if (*str != ' ' && *str != '\t')
		{
			return (0);
		}
		str++;
	}
	return (1);
}
