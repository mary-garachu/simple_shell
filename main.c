#include "shell.h"
/**
 * main - prints the date the project commenced.
 * Return: Always 0.
 */
int main(void)
{
	/*printf("This simple shell was created from the 10th of Sept 2023\n");*/

	char *user_input = NULL;
	size_t input_size = 0;
	char *args[MAX_ARGS];
	int ten = isatty(0);

	while (1)
	{
		if (ten == 1)
		write(1, "$ ", 2);
		/*printf("#simpleShell$ ");*/
		display_prompt(&user_input, &input_size);
		if (user_input == NULL)
		{
			break;
		}
		if (strlen(user_input) > 0)
		{
			parseArguments(user_input, args);
			execute_prompt(user_input);
		}
	}
	free(user_input);
	return (0);
}
