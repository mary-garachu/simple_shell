#include "shell.h"
/**
 * trim_whitespace - trims whitespace
 * @str: string
 * Return: void
 */
void trim_whitespace(char *str)
{
	char *end = NULL;

	while (*str == ' ' || *str == '\t')
	{
		str++;
	}
	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
	{
		end--;
	}
	end[1] = '\0';
}
/**
 * is_empty_input - checks if string is empty
 * @user_input: string input
 * @is_pipe: integer
 * Return: integer
 */
int is_empty_input(const char *user_input, int is_pipe)
{
	if (*user_input == '\0')
	{
		if (is_pipe)
			return (1);
		else
			return (1);
	}
	return (0);
}
