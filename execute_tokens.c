#include "shell.h"
/**
 * execute_tokens - performs the exec function on the array
 * of strings passed onto it.
 * @tokenarr: array of tokens passed
 * @program_name: program name
 * Return: void
 */
void execute_tokens(char **tokenarr, char *program_name)
{
	int i = 0;

	if (tokenarr[0] == NULL)
	{
		exit(EXIT_FAILURE);
		free(tokenarr);
	}
	if (execve(tokenarr[0], tokenarr, NULL) == -1)
	{
		perror(program_name);
		exit(EXIT_FAILURE);
	}
	while (tokenarr[i] != NULL)
	{
		free(tokenarr[i]);
		i++;
	}
	free(tokenarr);
}
