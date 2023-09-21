#include <stdio.h>
#include <unistd.h>
/**
 * main - getting PID
 * Return: Always 0
 */
int main(void)
{
	pid_t pid;

	printf("%u\n", getpid());
	printf("%u\n", getppid());
	while (1){};
	return (0);
}
