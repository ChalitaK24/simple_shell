#include "main.h"

/**
 * read_input - function to receive input commands
 * @line: pointer to buffer storing the input string
 * @len: pointer to size of the buffer
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
