#include "shell.h"
/**
 * main - A Command Line interpreter.
 * Return: 0 on success, and -1 on failure.
 */
int main(void)
{
	char **argv, *str;
	int status;
	size_t n = 0;
	ssize_t lines;
	pid_t child_pid;
	/* Infinate loop */
	while (1)
	{
		argv = NULL;
		str = NULL;
		/* Print prompt */
		printf("$$ ");
		/* Wait for user to enter command */
		lines = getline(&str, &n, stdin);
		if (lines == -1)
		{
			/* freeing str when getline fails */
			free(str);
			printf("Error or EOF\n");
			return (-1);
		}
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
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				free_list_str(argv);
				free(str);
				perror("Error:");
				return (1);
			}
		}
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
