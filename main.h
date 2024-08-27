#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void execve_cmd(char *in_line);
ssize_t read_input(char **in_line, size_t *len);

#endif
