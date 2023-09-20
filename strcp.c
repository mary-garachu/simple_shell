#include "shell.h"
/**
 * _strdp - copies one string to the other
 * @str: string to be copied
 * Return: string copy
 */
char *_strdp(const char *str)
{
	size_t len = 0;
	char *new_str;
	size_t i;

	while (str[len] != '\0')
	{
		len++;
	}
	new_str = malloc(len + 1);
	if (new_str == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= len; i++)
	{
		new_str[i] = str[i];
	}
	return (new_str);
}
