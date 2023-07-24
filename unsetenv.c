#include "shell.h"
/**
 * _unsetenv - A function that unset an enviromental variable.
 * @name: name of enviromental variable
 * Return: zero on success, or -1 on error
 */
int _unsetenv(const char *name)
{
	int i = 0;
	char *env_copy, *token;

	while (environ[i])
	{
		env_copy = _strdup(environ[i]);
		token = _strtok(env_copy, "=");
		if (_strcmp(token, name) == 0)
		{
			while (environ[i])
			{
				if (environ[i + 1] == NULL)
				{
					environ[i] = NULL;
					break;
				}
				environ[i] = environ[i + 1];
				i++;
			}
			free(env_copy);
			break;
		}
		free(env_copy);
		i++;
	}
	return (0);
}
