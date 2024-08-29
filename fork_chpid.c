#include "main.h"

/**
 * fork_and_execute - child process to execute command
 *
 *
 * Return: void
 */

void fork_and_execute(char *command_path, char **argv)
{
	pid_t pid = fork();

	if(pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(command_path, argv, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}
}
