#include "main.h"

/**
 * main - is simple shell program to receive and execute commands
 *
 * Return: 0
 */


int main(void)
{
	char *line;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("s_shell$ ");
		}
		line = read_input();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				printf("\n");
			}
			break;
		}
		if (strncmp(line, "PATH=", 5) == 0)
		{
			setenv("PATH", line + 5, 1);
			free(line);
			continue;
		}
		execute_command(line);
		free(line);
	}
	return (0);
}
