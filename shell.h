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

void build_path_and_execute(char **cmd_arr, char **argv, int count, char *ptr);
int check_delim(char a, const char *delim);
char *_strtok(char *str, const char *delim);
char *_strchr(char *s, int c);
extern char **environ;
int err_no;
char *remove_leading_whitespaces(char *lineptr);
void execute_command(char **argv, char *str, char *cmd);
int get_command(char **lineptr, size_t *n);
char **split_str(char *strng);
void free_list_str(char **list);

/* String and number manipulation functions */
int _putchar(char c);
int _strlen(const char *s);
void _puts(char *s);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
int _atoi(const char *nstr);
void print_num(int num);
int _puterr(char c);
void _puts_err(char *s);

/* Shell Command Functions */
void print_err(int count, char *cmd, char *arg);
char *_getenv(char *name);
char *build_path(char *cmd);
int exec_cmd(char *cmd, char **argv);
void sig_cntrl(int signal);
void processor(int count, char **cmd_arr, char *arg, char *lineptr);

/* Builtin command */
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
/*                  */
int check_builtin(char *cmd, char **argv, int count, char *executable_name);
int exit_shell(char *cmd, char **argv);
int print_env(void);

/**
 * struct built_in - builtin structure
 * @name: name of function
 * @f: the function to call
 */

typedef struct built_in
{
	char *name;
	int (*f)(char *, char **);
} builtin;

#endif
