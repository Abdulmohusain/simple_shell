#include "shell.h"
/**
 * get_command - A function that gets command from standard input.
 * @lineptr: A buffer containing user input.
 * @n: Size of lineptr
 *
 * Return: int
 */
int get_command(char **lineptr, size_t *n)
{
	ssize_t lines;

	lines = getline(lineptr, n, stdin);
	if (lines == -1)
	{
		/* freeing lineptr when getline fails */
		free(*lineptr);
		_puts("Error or EOF\n");
		return (-1);
	}
	return (0);
}
/**
 * execute_command - A function that execute commands from array argv.
 * @argv: An array of strings created by malloc and must be freed.
 * @str: string from getline function that must be freed if getline
 * fails to avoid memory errors.
 * @cmd: full command path
 *
 * Return: void
 */
void execute_command(char **argv, char *str, char *cmd)
{
	if (execve(cmd, argv, environ) == -1)
	{
		free_list_str(argv);
		free(str);
		perror("Error:");
		exit(-1);
	}
}
