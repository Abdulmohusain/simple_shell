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
