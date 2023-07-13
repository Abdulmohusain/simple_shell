#include "shell.h"
/**
 * main - A Command Line interpreter.
 * Return: 0 on success, and -1 on failure.
 */
int main(void)
{
	char **argv, *str;
	int status, count = 0;
	size_t n = 0;
	pid_t child_pid;
	/* Infinate loop */
	while (1)
	{
		count++;
		argv = NULL;
		str = NULL;
		/* Print prompt */
		_puts("$$ ");
		/* Wait for user to enter command */
		get_command(&str, &n);
		/* Create an array in the heap. It must be freed */
		argv = split_str(str);
		/* Create a child process and handle error when it fails */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		/* Child process will run */
		if (child_pid == 0)
			execute_command(argv, str);
		/* Parent process will run */
		else
		{
			free_list_str(argv);
			free(str);
			wait(&status);
		}
	}
	return (0);
}
