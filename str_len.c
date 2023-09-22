#include "shell.h"
/**
 * _strlen - checks the length of string
 * @str: string passed to the function
 * Return: int count
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	if (str != NULL)
	{
		while (str[length] != '\0')
		{
			length++;
		}
	}
	return (length);
}
