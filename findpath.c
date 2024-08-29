#include "main.h"

/**
 * find_command_in_path - takes in single arguemnt command
 * and looks for it in PATH
 * @command: pointer to command line string
 *
 * Return: fnd_path
 */

char *find_command_in_path(char *command)
{
	char *path = getenv("PATH");
	char *path_dup = strdup(path);
	char *dir = strtok(path_dup, ":");
	char *full_path = NULL;

	if (path == NULL || *path == '\0')
	{
		return (NULL);
	}

	while (dir != NULL)
	{
		full_path = malloc(PATH_MAX);

		if (!full_path)
		{
			perror("malloc");
			free(path_dup);
			return (NULL);
		}
		snprintf(full_path, PATH_MAX, "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_dup);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_dup);
	return (NULL);
}
