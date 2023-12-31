#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
/**
 * main - demontrate simple shell using /bin/ls
 * @argc: count of strings entered in input
 * @argv: strings entered in terminal
 * @env: array of environment variables
 * Return: 0 success 1 failure
*/
int main(int argc, char **argv, char **env)
{
	/**
	 * prompt function
	 */
	if (argc != 1 && argc != 2)
	{
		perror("Enter a command after program name");
		return (1);
	}
	if (argc == 2)
	{
		line_to_array(argv[1], argv[0], env);
	}
	else if (argc == 3 && argv[1] != NULL && _strcmp(argv[1], "env") == 0)
	{
		env_builtin(env);
	}
	else
	{
		get_line_function(argv[0], env);
	}

	return (0);
}
/**
 * process_user_input - responsible for handling user input
 * execution.
 * @user_input: a string containing a users input.
 * @program_name: equivalent to argv[0]
 * @envp: array of environment variables
 * Return: void
*/
void process_user_input(char *user_input, char *program_name, char **envp)
{
	pid_t child_pid;
	int status;
	int is_pipe = !isatty(0);

	trim_whitespace(user_input);
	if (is_empty_input(user_input, is_pipe))
	{
		free(user_input);
		return;
	}
	if (user_input != NULL && _strcmp(user_input, "env\n") == 0)
	{
		env_builtin(envp);
		return;
	}
	child_pid = fork();
	if (child_pid == -1)
		handle_error(user_input);
	else if (child_pid == 0)
	{
		line_to_array(user_input, program_name, envp);
		exit(EXIT_SUCCESS);
	}
	else
		wait(&status);
}
/**
 * get_line_function - gets the line from getline function
 * @program_name: equivalent to argv[0]
 * @envp: array of environment variables
 * Return: void
*/

void get_line_function(char *program_name, char **envp)
{
	ssize_t read_input;
	char *user_input = NULL, *exit_func = "exit\n";
	size_t input_size = 0;
	int term = isatty(0), is_pipe = !term;
	int last_command_status = 0;

	while (1)
	{
		if (term == 1)
		{
			write(1, "$ ", 2);
		}
		read_input = getline(&user_input, &input_size, stdin);
		if (read_input == -1)
		{
			if (is_pipe)
			{
				free(user_input);
				exit(EXIT_SUCCESS);
			}
			else
				handle_error(user_input);
		}
		else if (read_input == 0)
			continue;
		else
		{
			if (user_input != NULL && _strcmp(user_input, exit_func) == 0)
			{
				free(user_input);
				exit(last_command_status);
			}
			process_user_input(user_input, program_name, envp);
			_memset(user_input, 0, input_size);
			input_size = 0;
			last_command_status = 2;
			free(user_input);
		}
	}
	free(user_input);
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

/**
 * env_builtin - Handle the 'env' built-in command to print the environment.
 * @envp: The array of environment variables.
 * Return: void
 */

void env_builtin(char **envp)
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		write(1, envp[i], _strlen(envp[i]));
		write(1, "\n", 1);
	}
}
