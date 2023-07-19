#include "shell.h"

/**
 * main - main function
 * @argv: argument variable
 * @ac: argument count
 *
 * Return: int
 */

int main(int ac, char **argv)
{
	char *lineptr = NULL, *cmd, **cmd_arr;
	size_t n = 0;
	ssize_t line;
	int count = 0;

	(void)ac;
	while (1)
	{
		count++;
		signal(SIGINT, sig_cntrl);
		if (isatty(STDIN_FILENO))
			_puts("$ ");
		line = getline(&lineptr, &n, stdin);
		if (line == -1)
		{
			free(lineptr);
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			break;
		}
		lineptr = remove_leading_whitespaces(lineptr);
		if (lineptr == NULL)
			continue;
		cmd_arr = split_str(lineptr);
		if (check_builtin(lineptr, cmd_arr) == 0)
		{
			cmd = build_path(cmd_arr[0]);
			if (cmd == NULL)
			{
				print_err(count, cmd_arr[0], argv[0]);
				_putchar('\n');
			}
			else
			{
				exec_cmd(cmd, cmd_arr);
				if (cmd != cmd_arr[0])
					free(cmd);
			}
		}
		free_list_str(cmd_arr);
	}
	return (0);
}


/**
 * exec_cmd - execute command
 * @cmd: command full path
 * @argv: argument array
 *
 * Return: int
 */

int exec_cmd(char *cmd, char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("hsh: ");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(cmd, argv, environ) == -1)
		{
			perror("hsh: ");
			return (1);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}

/**
 * sig_cntrl - performs an action in response to a signal
 * @signal: signal recieved
 *
 * Return: void
 */

void sig_cntrl(int signal)
{
	if (signal == SIGINT)
		_puts("\n$ ");
}

/**
 * remove_leading_whitespaces - A function that removes leading
 * whitespaces from character array created from getline.
 * @lineptr: Character array initalized by getline.
 * Return: Null on error or the new string.
 */
char *remove_leading_whitespaces(char *lineptr)
{
	int len = _strlen(lineptr);
	char *new_lineptr;
	int j = 0, i = 0;
	/* Handle when the user press enter without input */
	if (lineptr[j] == '\n')
	{
		free(lineptr);
		return (NULL);
	}
	while (lineptr[j] == ' ')
	{
		len--;
		j++;
	}
	/* Handle spaces only */
	if (lineptr[j] == '\n')
	{
		free(lineptr);
		return (NULL);
	}
	/* Handle characters */ 
	if (lineptr[0] != ' ' && lineptr[0] != '\n')
		return (lineptr);
	/* Handle spaces then characters */
	if (lineptr[0] != ' ' || lineptr[0] != '\n')
		return (lineptr);
	new_lineptr = malloc(sizeof(char) * len + 1);
	if (new_lineptr == NULL)
		return (NULL);
	while (lineptr[j])
	{
		new_lineptr[i] = lineptr[j];
		j++;
	}
	new_lineptr[i] = '\0';
	free(lineptr);
	return (new_lineptr);
}
