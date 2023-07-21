#include "shell.h"

/**
 * _strcat - concatenate two strings
 * @dest: concatenated string
 * @src: the string to concatenate
 *
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int i, len;

	if (dest == NULL || src == NULL)
		return (NULL);
	len = _strlen(dest);
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: int
 */

int _strcmp(const char *s1, const char *s2)
{
	int slen1, slen2, len, strval, i;

	slen1 = _strlen(s1);
	slen2 = _strlen(s2);
	if (slen1 > slen2)
		len = slen1;
	else
		len = slen2;
	for (i = 0; i < len; i++)
	{
		strval = s1[i] - s2[i];
		if (strval != 0)
			return (strval);
	}
	return (strval);
}

/**
 * _atoi - covert a string to an integer
 * @nstr: string to convert to integer
 *
 * Return: integer
 */

int _atoi(const char *nstr)
{
	int count = 0, sign = 1, i = 0;

	if (nstr == NULL)
		return (0);
	while (nstr[i] != '\0')
	{
		if (nstr[i] == '-')
			sign *= -1;
		if (nstr[i] >= '0' && nstr[i] <= '9')
		{
			count =  count * 10 + (nstr[i] - '0');
		} else
		{
			return (0);
		}
		i++;
	}
		return (count * sign);
}

/**
 * print_num - print numbers
 * @num: number to ptint
 *
 * Return: void
 */

void print_num(int num)
{
	if (num / 10 != 0)
		print_num(num / 10);
	_putchar(num % 10 + '0');
}

/**
 * print_err - print error message in shell
 * @count: cout of execution
 * @cmd: command entered
 * @arg: command line argument 0
 *
 * Return: void
 */

void print_err(int count, char *cmd, char *arg)
{
	_puts(arg);
	_puts(": ");
	print_num(count);
	_puts(": ");
	_puts(cmd);
	_puts(": ");
	_puts("not found");
	_putchar('\n');
}
