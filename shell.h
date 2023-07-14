#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **environ;

void execute_command(char **argv, char *str);
void get_command(char **lineptr, size_t *n);
char **split_str(char *strng);
void free_list_str(char **list);

/* String and number manipulation functions */
int _putchar(char c);
int _strlen(const char *s);
void _puts(char *s);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *src);
char *_strcat(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);
int _atoi(const char *nstr);
void print_num(int num);

/* Shell Command Functions */
void print_err(int count, char *cmd);
char *_getenv(char *name);
char *build_path(char *cmd);

#endif
