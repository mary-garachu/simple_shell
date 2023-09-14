#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
/**
 * main - demontrate simple shell using /bin/ls
 * @argc: count of strings entered in input
 * @argv: strings entered in terminal
 * Return: 0 success 1 failure
*/
int main(int argc, char **argv)
{
	char *user_input = NULL;
	size_t input_size = 0;
	ssize_t read_input;
	/**
	 * prompt function
	*/
	while (1)
	{
		printf("$ ");
		read_input = getline(&user_input, &input_size, stdin);
		if (read_input == -1)
		{
			perror("Error handling input");
			free(user_input);
			exit(EXIT_FAILURE);
		}
		printf("%s", user_input);
		/**
		 * tokenization of the string function
		 * passing the line into an array of strings
		*/
		line_to_array(user_input, argv[argc - argc]);
		free(user_input);
		user_input = NULL;
		input_size = 0;
	}
	return (0);
}
