#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>

char **ls_input(char *in_line);
void execve_cmd(char *in_line);
char *find_path(char *command);
char *read_input(void);

#endif
