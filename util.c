#include "shell.h"

/**
 * _putchar - print a character
 * @c: character to print
 *
 * Return: int
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - count the length of a string
 * @s: string to count
 *
 * Return: int
 */

int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _puts - print string
 * @s: string to print
 *
 * Return: void
 */

void _puts(char *s)
{
	int len, i = 0;

	if (s != NULL)
	{
		len = _strlen(s);
		while (i < len)
		{
			_putchar(s[i]);
			i++;
		}
	}
}

/**
 * _strcpy - copies one string to another
 * @dest: destination string
 * @src: source string
 *
 * Return: a pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i++] = '\0';
	return (dest);
}
/* _strcpy is only to be used on strings not on pointers */

/**
 * _strdup - duplicate a pointer string
 * @src: source pointer string
 *
 * Return: new pointer string
 */

char *_strdup(const char *src)
{
	int len, i = 0;
	char *newstr;

	len = _strlen(src);
	newstr = malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		newstr[i] = src[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
