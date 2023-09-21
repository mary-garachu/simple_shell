#include <stdio.h>
#include <stdlib.h>
/**
 * main - 
 * Return:
 */
int main(void)
{
	char *lineptr;
	size_t n;
	ssize_t read;

	read = getline(&lineptr, &n, stdin);
	if (read == -1)
	{
		perror("Memory allocation error");
		return (1);
	}
	printf("%s", lineptr);
	free(lineptr);
	return (0);
}
