#include "main.h"

/**
 * execute_command -  function to handle overall execution process of a command including in child process
 *
 * Return: void
 */

void execute_command(char *line)
{
	char **argv;
	char *command_path;
	int exit_status = 0;

	argv = parse_input(line);

	if (argv[0] == NULL)
	{
		free(argv);
		return;
	}

	if (strcmp(argv[0], "exit") == 0)
	{
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

	if (strchr(argv[0], '/') != NULL)
	{
		command_path = argv[0];
		if (access(command_path, X_OK) != 0)
		{
			 fprintf(stderr, "Command not found: %s\n", argv[0]);
			 free(argv);
			 return;
		}
	}
	else
	{
		command_path = find_command_in_path(argv[0]);
		if (command_path == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", argv[0]);
			free(argv);
			return;
		}
	}

	fork_and_execute(command_path, argv);

	if (command_path != argv[0])
	{
		free(command_path);
	}
	free(argv);
}
