#include "main.h"

/**
 * handle_exit - Implements the exit built-in with an optional status code
 * @argv: array of command line argument stings
 * @line: input line
 * Return: void
 */

void handle_exit(char **argv, char *line)
{
	int exit_status = 0;

	if (argv[1] != NULL)
	{
		char *endptr;
		long status = strtol(argv[1], &endptr, 10);

		if (*endptr != '\0')
		{
			fprintf(stderr, "exit: numeric argument required\n");
			free(argv);
			free(line);
			exit(EXIT_FAILURE);
		}
		exit_status = (int)status;
	}
	free(argv);
	free(line);
	exit(exit_status);
}

