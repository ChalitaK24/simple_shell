#include "main.h"

/**
 * read_input - function to receive input commands
 * @in_line: pointer to buffer storing the input string
 * @len: pointer to size of the buffer
 * Return: readcm
 */

char *read_input(void)
{
	char *in_line = NULL;
	size_t len = 0 ;
	ssize_t readcm;
	size_t i;

	readcm = getline(&in_line,&len, stdin);

	if (readcm == -1)
	{

			printf("\n");
			free(in_line);
			exit(EXIT_SUCCESS);
	}
	
	i = strcspn(in_line, "\n");

	if (i < strlen(in_line))
	{
		in_line[i] = '\0';
	}

	return (in_line);
}
