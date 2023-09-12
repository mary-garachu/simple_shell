#include "shell.h"
#include <errno.h>

/**
 * display_prompt -reads and processes user input.
 * @user_input:a pointer to a pointer to a character.
 * @input_size:a pointer to a size_t variable.
 */

void display_prompt(char **user_input, size_t *input_size)
{
	ssize_t input_length;

	input_length = getline(user_input, input_size, stdin);
	if (input_length == -1)
	{
		if (*input_size > 0)
		{
			/*printf("\nexiting!\n");*/
			write(1, "exiting\n", 8);
		}
		free(*user_input);
		*user_input = NULL;
	}
	else
	{
		(*user_input)[input_length - 1] = '\0';
	}
}
/**
 * execute_prompt - a function that created a child process.
 * @command:the command to be executed.
 */

void execute_prompt(char *command)
{
	char *env_variables[] = {NULL};
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char **argv = (char **)malloc(2 * sizeof(char *));

		if (argv == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		argv[0] = command;
		argv[1] = NULL;

		if (execve(command, argv, env_variables) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		free(argv);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * parseArguments- a function that splits the
 * input into an array of arguments.
 * @input: function input.
 * @args:arguments.
 */
void parseArguments(char *input, char **args)
{
	char *token = strtok(input, " ");
	int i = 0;

	while (token != NULL && i < MAX_ARGS)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
