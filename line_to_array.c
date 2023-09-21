#include "shell.h"
/**
 * line_to_array - takes user input then turns it into a string
 * of arrays to be processed
 * @user_input: string of user input
 * @program_name: name of program
 * Return: void
 */
void line_to_array(char *user_input, char *program_name)
{
	char *user_input_cp = NULL;
	char *token = NULL;
	char *token_count = NULL;
	char **tokenarr;
	int i = 0;

	user_input_cp = _strdp(user_input); /* write a function to copy string */
	if (user_input_cp == NULL)
		exit(1);
	token_count = strtok(user_input, " \t\n");
	while (token_count != NULL)
	{
		i++;
		token_count = strtok(NULL, " \t\n");
	}
	tokenarr = malloc(sizeof(char *) * (i + 1));
	if (tokenarr == NULL)
	{
		perror("Memory allocation failed");
		free(user_input);
		exit(1);
	}
	i = 0;
	token = strtok(user_input_cp, " \t\n");
	while (token != NULL)
	{
		tokenarr[i] = token;
		if (tokenarr[i] == NULL)
		{
			perror("Memory allocation failed");
			free_tokenarr(tokenarr, i, user_input_cp);
			exit(1);
		}
		token = strtok(NULL, " \t\n");
		i++;
	}
	tokenarr[i] = NULL;
	execute_tokens(tokenarr, program_name);
	free_tokenarr(tokenarr, i, user_input_cp);
}

/**
 * free_tokenarr - function to free tokenarr array
 * @tokenarr: token array
 * @i: number of strings in array
 * @user_input_cp: copy of the user input string
 * Return: void
*/
void free_tokenarr(char **tokenarr, int i, char *user_input_cp)
{
	int j = 0;

	free(user_input_cp);
	for (j = 0; j < i; j++)
	{
		free(tokenarr[j]);
		tokenarr[j] = NULL;
	}
	free(tokenarr);
}
