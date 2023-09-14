#include "shell.h"
/**
 * execute_tokens - performs the exec function on the array
 * of strings passed onto it.
 * @tokenarr: array of tokens passed
 * @i: number of strings in the array passed from previous function
 * @program_name: program name
 * Return: void
 */
void execute_tokens(char **tokenarr, int i, char *program_name)
{
	int j;

	if (execve(tokenarr[0], tokenarr, NULL) == -1)
	{
		perror(program_name);
		for (j = 0; j < i; j++)
		{
			free(tokenarr[j]);
		}
		free(tokenarr);
		exit(1);
	}
}
