#include <stdio.h>
/**
 * main - 
 * @argc: number of arguments passed in term
 * @argv: string of arrays
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; argv[i] != NULL; ++i)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
