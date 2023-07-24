#include "shell.h"

/**
 * _puts_err - print error message
 * @s: string to print
 *
 * Return: void
 */

void _puts_err(char *s)
{
	int len, i = 0;

	if (s != NULL)
	{
		len = _strlen(s);
		while (i < len)
		{
			_puterr(s[i]);
			i++;
		}
	}
}
