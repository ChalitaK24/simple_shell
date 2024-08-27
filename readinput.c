#include "main.h"

/**
 * read_input - function to receive input commands
 * @in_line: pointer to buffer storing the input string
 * @len: pointer to size of the buffer
 * Return: readcm
 */

ssize_t read_input(char **in_line, size_t *len)
{
	ssize_t readcm;
	size_t i;

	readcm = getline(in_line, len, stdin);

	if (readcm == -1)
	{
		if (in_line == NULL || readcm == -1)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(*in_line);
			perror("getline Error: ");

		}
	}

	i = strcspn(*in_line, "\n");

	if (i < strlen(*in_line))
	{
		(*in_line)[i] = '\0';
	}

	return (readcm);
}
