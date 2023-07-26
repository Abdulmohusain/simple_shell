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
 * @count: count
 * @executable_name: exec
 *
 * Return: int
 */

int check_builtin(char *cmd, char **argv, int count, char *executable_name)
{
	if (_strcmp("exit", argv[0]) == 0)
	{
		/**      */
		if (argv[1] == NULL)
			exit_shell(cmd, argv);
		if (argv[1] != NULL)
		{
			if (_atoi(argv[1]) == 0)
				print_err(count, argv[0], executable_name);
			if (_atoi(argv[1]) < 0)
				print_err(count, argv[0], executable_name);
			if (_atoi(argv[1]) > 0)
				exit_shell(cmd, argv);
		}
		return (1);
	}
	if (_strcmp("env", argv[0]) == 0)
	{
		print_env();
		return (1);
	}
	if (_strcmp("setenv", argv[0]) == 0)
	{
		if (argv[2] != NULL)
			_setenv(argv[1], argv[2], 0);
		return (1);
	}
	if (_strcmp("unsetenv", argv[0]) == 0)
	{
		if (argv[1] != NULL)
			_unsetenv(argv[1]);
		return (1);
	}
	return (0);
}

/**
 * exit_shell - exit from the shell
 * @cmd: command
 * @argv: argument variable
 *
 * Return: does not return on sucess, -1 on failure.
 */

int exit_shell(char *cmd, char **argv)
{
	int status;

	if (argv[1] == NULL)
	{
		free_list_str(argv);
		free(cmd);
		exit(0);
	}
	if (argv[1] != NULL && argv[2] == NULL)
	{

		status = _atoi(argv[1]);
		if (status == 0)
			return (-1);
		free_list_str(argv);
		free(cmd);
		exit(status);
	}
	return (1);
}

/**
 * print_env - prints environmental variable
 *
 * Return: 0
 */

int print_env(void)
{
	int i = 0, len, j;

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
