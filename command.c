#include "shell.h"
/**
 * get_command - A function that gets command from standard input.
 * @lineptr: A buffer containing user input.
 * @n: Size of lineptr
 */
void get_command(char **lineptr, size_t *n)
{
	ssize_t lines;

	lines = getline(lineptr, n, stdin);
	if (lines == -1)
	{
		/* freeing lineptr when getline fails */
		free(*lineptr);
		_puts("Error or EOF\n");
		exit(-1);
	}
}
/**
 * execute_command - A function that execute commands from array argv.
 * @argv: An array of strings created by malloc and must be freed.
 * @str: string from getline function that must be freed if getline
 * fails to avoid memory errors.
 */
void execute_command(char **argv, char *str)
{
	if (execve(argv[0], argv, NULL) == -1)
	{
		free_list_str(argv);
		free(str);
		perror("Error:");
		exit(-1);
	}
}
