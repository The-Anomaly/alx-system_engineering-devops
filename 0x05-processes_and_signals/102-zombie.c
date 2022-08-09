#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * infinite_while - infinite while loop
 * Return: 0 on success, 1 otherwise
*/
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - main function to create zombie processes
 *
 * Return: 0 on success, 1 otherwise
*/
int main(void)
{
	int ch = 0;
	pid_t child_pid;

	while (ch < 5)
	{
		child_pid = fork();
		if (!child_pid)
			break;
		printf("Zombie process created, PID: %d\n", child_pid);
		ch++;
	}

	if (child_pid != 0)
		infinite_while();
	return (0);
}
