#include "shell.h"

/**
 * _getenv - to get the environmental variable
 * @name: the name of the environmental variable to get
 *
 * Return: char
 */

char *_getenv(char *name)
{
	int i = 0, len, j;
	char *val = NULL;

	if (name == NULL)
		return (NULL);
	len = _strlen(name);
	while (environ[i] != NULL)
	{
		for (j = 0; j < len; j++)
		{
			if (name[j] != environ[i][j])
				break;
		}
		if (j == len && environ[i][j] == '=')
		{
			val = environ[i] + len + 1;
			return (val);
		}
		i++;
	}
	return (NULL);
}

/**
 * check_builtin -  check if a command is a builtin
 * @cmd: the command
 * @argv: array of arguments
 *
 * Return: int
 */

int check_builtin(char *cmd, char **argv)
{
	int i = 0;
	builtin b_arr[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{NULL, NULL}
	};

	if (argv[0] == NULL)
		return (0);
	while (b_arr[i].name != NULL)
	{
		if (_strcmp(b_arr[i].name, argv[0]) == 0)
		{
			b_arr[i].f(cmd, argv);
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * exit_shell - exit from the shell
 * @cmd: command
 * @argv: argument variable
 *
 * Return: int
 */

int exit_shell(char *cmd, char **argv)
{
	if (argv[1] == NULL)
	{
		free_list_str(argv);
		free(cmd);
		exit(0);
	}
	return (1);
}

/**
 * print_env - prints environmental variable
 * @cmd: command
 * @argv: argument variable
 *
 * Return: 0
 */

int print_env(char *cmd, char **argv)
{
	int i = 0, len, j;

	(void)cmd, (void)argv;
	while (environ[i] != NULL)
	{
		len = _strlen(environ[i]);
		for (j = 0; j < len; j++)
		{
			_putchar(environ[i][j]);
		}
		_putchar('\n');
		i++;
	}
	return (0);
}
