#include "main.h"

/**
 * find_inpath - takes in single arguemnt command and looks for it in PATH
 *
 * Return: fnd_path
 */

char *find_path(char *command)
{
	char *path_cmd = getenv("PATH");
	char *path_cpy = strdup(path_cmd);
	char *cmd_nm = strtok(path_cpy, ":");
	char *fnd_path = NULL;
	
	while (cmd_nm != NULL)
	{
		fnd_path = malloc(strlen(cmd_nm) + strlen(command) +2);
		if (fnd_path == NULL)
		{
			fprintf(stderr, "Error: Memory allocation failed for full path.\n");
			free(path_cpy);
			return (NULL);
		}

		snprintf(fnd_path, strlen(cmd_nm) + strlen(command) + 2, "%s/%s", cmd_nm, command);

	
		if (access(fnd_path, X_OK) == 0) 
		{
			free(path_cpy);
			return (fnd_path);
		}
		free(fnd_path);
		cmd_nm = strtok(NULL, ":");
	}
	fprintf(stderr, "Error: Command '%s' not found in PATH.\n", command);
	free(path_cpy);
	return (NULL);
}
