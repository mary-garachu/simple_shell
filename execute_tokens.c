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
	char *path_env = getenv("PATH");
	char *path, *dir, *full_path;
	struct stat st;

	if (path_env == NULL)
		exit(EXIT_FAILURE);
	path = strdup(path_env);
	if (path == NULL)
		exit(EXIT_FAILURE);
	dir = strtok(path, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + 1 + strlen(tokenarr[0]) + 1);
		if (full_path == NULL)
			exit(EXIT_FAILURE);
		sprintf(full_path, "%s/%s", dir, tokenarr[0]);
		if (stat(full_path, &st) == 0)
		{
			if (execve(full_path, tokenarr, NULL) == -1)
			{
				perror(program_name);
				exit(EXIT_FAILURE);
			}
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	fprintf(stderr, "%s: command not found\n", tokenarr[0]);
	exit(EXIT_FAILURE);
}
