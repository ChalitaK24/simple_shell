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

#define INIT_ARGS 10

char *find_command_in_path(char *command);
char **parse_input(char *line);
void fork_and_execute(char *command_path, char **argv);
void execute_command(char *line);
char *read_input(void);
void handle_exit(char **argv, char *line);

#endif
