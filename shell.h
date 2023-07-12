#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_command(char **argv, char *str);
void get_command(char **lineptr, size_t *n);
char **split_str(char *strng);
void free_list_str(char **list);

#endif
