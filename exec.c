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
	/**
	 * prompt function
	*/
	if (argc == 2)
	{
		line_to_array(argv[1], argv[0]);
	}
	else
	{
		get_line_function(argv[0]);
	}

	return (0);
}
/**
 * process_user_input - responsible for handling user input
 * execution.
 * @user_input: a string containing a users input.
 * @program_name: equivalent to argv[0]
 * Return: void
*/
void process_user_input(char *user_input, char *program_name)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		handle_error(user_input);
	}
	else if (child_pid == 0)
	{
		line_to_array(user_input, program_name);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
	}
}
/**
 * get_line_function - gets the line from getline function
 * @program_name: equivalent to argv[0]
 * Return: void
*/

void get_line_function(char *program_name)
{
	ssize_t read_input;
	char *user_input = NULL;
	size_t input_size = 0;
	int term = isatty(0), is_pipe = !term;

	while (1)
	{
		if (term == 1)
		{
			write(1, "$ ", 2);
		}
		read_input = getline(&user_input, &input_size, stdin);
		if (strcmp(user_input, "exit\n") == 0)
		{
			free(user_input);
			exit(EXIT_SUCCESS);
		}
		if (read_input == -1)
		{
			if (is_pipe)
			{
				free(user_input);
				exit(EXIT_SUCCESS);
			}
			else
			{
				handle_error(user_input);
			}
		}
		process_user_input(user_input, program_name);
		free(user_input);
		user_input = NULL;
		input_size = 0;
	}
}


/**
 * handle_error - repetitive code that frees user_input
 * @user_input: string of user input
 * Return: void
*/

void handle_error(char *user_input)
{
	perror("Exit");
	free(user_input);
	exit(EXIT_FAILURE);
}
