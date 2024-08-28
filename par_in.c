#include "main.h"


/**
 * execve_cmd - function to execute inout commpant from string
 * @in_line: ponter to input string
 * Return: void
 *
 */
char **ls_input(char *in_line)
{
	int arg_size = 1;
	int i = 0;
	char **argv;

	argv = malloc(arg_size * sizeof(char *));
	
	argv[i] = strtok(in_line, " ");

	while (argv[i] != NULL)
	{
		i++;
		if (i >= arg_size)
		{
			arg_size = arg_size * 2;
			argv = realloc(argv, arg_size * sizeof(char *));
		}

		argv[i] = strtok(NULL, " ");
	}
	argv[i] = NULL;

	return (argv);
}
