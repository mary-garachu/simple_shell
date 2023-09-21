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
	extern char **environ;
	if (execve(tokenarr[0], tokenarr, environ) == -1)
	{
		perror(program_name);
		exit(EXIT_FAILURE);
	}
}
