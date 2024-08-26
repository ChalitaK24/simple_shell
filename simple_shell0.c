#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

int main(void)
{
	char *in_line = NULL;
	size_t ln = 0;
	int nread;
	pid_t ch_pid;
	int status;

	while (1)
	{
		printf("s_shell0$ ");

		nread = getline(in_line, &ln, stdin);

		if (nread == -1)
		{
			perror("Error: getline");
			return (1);
		}
	}

	if (in_line[nread - 1] == '\n')
	{
		in_line[nread - 1] = '\0';
	}

	pid = fork();
	
	if (pid == -1)
	{
		perror("Error: fork");
		return (1);
	}
	else if (pid == 0)
	{
		char *argv[2];
		argv[0] = in_line;
		argv[1] = NULL;

		if (execve(in_line, argv, environ) == -1)
		{
			perror(" ");
		}
	}
	else
	{
		wait(NULL);

		if (wait(status) == -1)
		{
			perror(" w");
		}
	}
	free(in_line);
	return(0);


}
