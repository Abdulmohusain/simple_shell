#include "shell.h"
/**
 * _strtok - A function breaks a string into a sequence of zero
 * or more nonempty tokens.
 * @str: The string.
 * @delim: Delimiting characters.
 * Return: pointer to the next token.
 */
char *_strtok(char *str, const char *delim)
{
	static char *next;
	char *current;
	int i = 0, n;

	if (str != NULL)
		current = str;
	if (str == NULL && next == NULL)
		return (NULL);
	if (str == NULL && next != NULL)
		current = next;

	while (check_delim(current[i], delim) == 1)
	{
		i++;
	}
	current = &current[i];
	i = 0;
	while (current[i])
	{
		n = check_delim(current[i], delim);
		if (n == 1)
		{
			current[i] = '\0';
			if (check_delim(current[i + 1], delim) == 1)
			{
				i++;
				continue;
			} else
			{
				next = &current[i + 1];
				return (current);
			}
		}
	i++;
	}
	return (NULL);
}

/**
 * check_delim - A function that checks if a character is a
 * delimiter.
 * @a: The character.
 * @delim: The delimiting characters.
 * Return: 1 if delimiting character is found or -1 if not found.
 */
int check_delim(char a, const char *delim)
{
	int i = 0;

	while (delim[i])
	{
		if (a == delim[i])
			return (1);
		i++;
	}
	return (-1);

}
/**
 * build_path_and_execute - A funtion that builds path
 * then execute the command.
 * @cmd_arr: array of strings.
 * @argv: argument vector
 * @count: shell counter.
 * @ptr: lineptr
 *
 * Retrun: void
 */
void build_path_and_execute(char **cmd_arr, char **argv, int count, char *ptr)
{
	char *cmd;


	cmd = build_path(cmd_arr[0]);
	if (cmd == NULL)
	{
		print_err(count, cmd_arr[0], argv[0]);
		if (!isatty(STDIN_FILENO))
		{
			free(ptr);
			free_list_str(cmd_arr);
			exit(127);
		}
	}
	else
	{
		exec_cmd(cmd, cmd_arr);
		if (cmd != cmd_arr[0])
			free(cmd);
	}
}

/**
 * _setenv - A function that add an enviromental variable.
 * @name: name of env variable
 * @value: the corresponding value
 * @overwrite: set to non zero value if you want to overwrite
 * Return: 0 on success, or -1 on failure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0, found = 0, n, v;
	char *env_copy, *token;
	char *full_env;

	n = _strlen(name);
	v = _strlen(value);
	full_env = malloc(n * sizeof(char) + v * sizeof(char) + 2);
	if (full_env == NULL)
		return (-1);
	_strcpy(full_env, name);
	_strcat(full_env, "=");
	_strcat(full_env, value);
	while (environ[i])
	{
		env_copy = _strdup(environ[i]);
		token = _strtok(env_copy, "=");
		if (_strcmp(token, name) == 0)
		{
			found = 1;
			free(env_copy);
			break;
		}
		free(env_copy);
		i++;
	}
	if (found == 1 && overwrite != 0)
	{
		environ[i] = full_env;
	} else if (found == 0)
	{
		environ[i] = full_env;
		environ[i + 1] = NULL;
	}
	return (0);

}

/**
 * _puterr - prints to standard error
 * @c: character to write to stderr
 *
 * Return: int
 */

int _puterr(char c)
{
	return (write(2, &c, 1));
}
