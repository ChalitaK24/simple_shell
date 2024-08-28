#include "main.h"

/**
 * main - simple shell program to receive and execute commands
 *
 * Return: 0
 */


int main(void)
{
	char *in_line;
	pid_t ch_pid;
	char **argv;
	char *cmd_path;
	
	while (1)
	{
		argv = ls_input(in_line);
		cmd_path = find_path(argv[0]);
		
		printf("s_shell0$ ");

		in_line = read_input();
		
					
		if (argv[0] == NULL)
		{
			free(argv);
		}

			
		if (cmd_path == NULL)
		{
			fprintf(stderr, "cmd not found: %s\n", argv[0]);
			free(argv);
		}

		ch_pid = fork();

		if (ch_pid == -1)
		{
			perror("Error: fork");
			return (1);
		}
		else if (ch_pid == 0)
		{
			execve(cmd_path, argv, NULL);
        	        perror("execve Error: ");
                	free(argv);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	
		free(argv);
		free(in_line);	
	}
	free(in_line);
	return (0);
}
