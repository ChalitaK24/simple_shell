#include "main.h"

/**
 * main - simple shell program to receive and execute commands
 *
 * Return: 0
 */


int main(void)
{
	size_t len = 0;
	char *in_line = NULL;
	pid_t ch_pid;

	while (1)
	{
		printf("s_shell0$ ");

		if (read_input(&in_line, &len) > 0)
		{

			ch_pid = fork();

			if (ch_pid == -1)
			{
				perror("Error: fork");
				return (1);
			}
			else if (ch_pid == 0)
			{
				execve_cmd(in_line);
			}
			else
			{
			wait(NULL);
			}
		}
	}
	free(in_line);
	return (0);
}
