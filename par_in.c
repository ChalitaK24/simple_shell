#include "main.h"


/**
 * parse_input - function to execute input command from string
 * @line: ponter to input string
 *
 * Return: void
 */

char **parse_input(char *line)
{
	int max_args = INIT_ARGS;
	int i = 0;
	char **argv = malloc(max_args * sizeof(char *));
	char *token;

	if (argv == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \n");

	while (token != NULL)
	{
		argv[i] = token;
		i++;
		if (i >= max_args)
		{
			max_args *= 2;
			argv = realloc(argv, max_args * sizeof(char *));
			if (argv == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, "\n");
	}
	argv[i] = NULL;
	return (argv);
}
