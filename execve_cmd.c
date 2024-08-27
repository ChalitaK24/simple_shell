#include "main.h"

/**
 * execve_cmd - function to execute inout commpant from string
 * @in_line: ponter to input string
 * Return: void
 *
 */

void execve_cmd(char *in_line)
{
	char *argv[2];

	argv[0] = in_line;
	argv[1] = NULL;

	if (execve(in_line, argv, NULL) == -1)
	{
		perror("execve Error: ");
		exit(EXIT_FAILURE);
	}
}
