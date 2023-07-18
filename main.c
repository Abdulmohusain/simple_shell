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
	char *lineptr = NULL, *cmd;
	char **cmd_arr;
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
			_putchar('\n');
			break;
		}
		if (_strcmp(lineptr, "\n") == 0)
		{
			/*_putchar('\n');*/
			continue;
		}
		cmd_arr = split_str(lineptr);
		if (check_builtin(lineptr, cmd_arr) == 0)
		{
			cmd = build_path(cmd_arr[0]);
			if (cmd == NULL)
			{
				print_err(count, cmd_arr[0], argv[0]);
				if (isatty(STDIN_FILENO))
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
