#include "main.h"

/**
 * read_input - is function to receive input commands
 *
 * Return: line
 */

char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
