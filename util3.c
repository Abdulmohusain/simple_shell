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
	static char *next = NULL;
	char *current;
	int i = 0, j = 1, n;

	if (str != NULL)
		current = str;
	if (str == NULL && next == NULL)
		return (NULL);
	if (str == NULL && next != NULL)
		current = next;
	while(current[i])
	{
		n = check_delim(current[i], delim);
		if (n == 1)
		{
			current[i] = '\0';
			while (current[i + j])
			{
				if (check_delim(current[i + j], delim) == 1)
				{
					current[i + j] = '\0';
					j++;
					continue;
				} else
					break;
			}
			if (current[0] == '\0')
			{
				current = &current[i + j];
				continue;
			}

			next = &current[i + j];
			return (current);
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
 * Return: 1 if character is found or -1 if not found.
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
