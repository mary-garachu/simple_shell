#include "shell.h"
/**
 * execute_tokens - performs the exec function on the array
 * of strings passed onto it.
 * @tokenarr: array of tokens passed
 * @program_name: program name
 * @envp: array of environment strings
 * Return: void
 */
void execute_tokens(char **tokenarr, char *program_name, char **envp)
{
	int i = 0;
	char *str = NULL;

	str = check_environment(tokenarr[0], envp);
	if (str == NULL)
	{
		free(tokenarr);
		exit(EXIT_FAILURE);
	}
	if (execve(str, tokenarr, envp) == -1)
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
/**
 * check_environment - checks if the command is found in environment
 * @command: command passed
 * @envp: environment variables
 * Return: full command or NULL
*/
char *check_environment(char *command, char **envp)
{
	char *path_variable = NULL, *path_token = NULL;
	char *full_path = NULL;
	int i = 0;

	if (command == NULL || envp == NULL)
		return (NULL);
	for (i = 0; envp[i] != NULL; i++)
	{
		if (_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_variable = envp[i] + 5;
			break;
		}
	}
	if (path_variable == NULL)
		return (NULL);
	path_token = strtok(path_variable, ":");
	while (path_token != NULL)
	{
		full_path = malloc(_strlen(path_token) + _strlen(command) + 2);
		if (full_path == NULL)
			return (NULL);
		sprintf(full_path, "%s/%s", path_token, command);
		if (access(full_path, F_OK) != -1)
			return (full_path);
		free(full_path);
		path_token = strtok(NULL, ":");
	}
	return (command);
}
/**
 * _strncmp - similar to strncmp
 * @s1: first string
 * @s2: second string
 * @n: size to check
 * Return: 0 success -1 fail
*/
int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (n > 0 && *s1 && (*s1 == *s2))
		{
			s1++;
			s2++;
			n--;
		}
		if (n == 0)
			return (0);
		return (*s1 - *s2);
	}
	return (0);
}
