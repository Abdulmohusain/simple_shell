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
	while(current[i])
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
