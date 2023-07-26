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
	char *lineptr = NULL, **cmd_arr/* *new_line */;
	size_t n = 0;
	ssize_t line;
	int count = 0, k;

	err_no = 0;
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
		/* strchr code goes here */
		lineptr = remove_leading_whitespaces(lineptr);
		if (lineptr == NULL)
			continue;
		cmd_arr = split_str(lineptr);
		/*      */
		k = check_builtin(lineptr, cmd_arr, count, argv[0]);
		if (k == 0)
			build_path_and_execute(cmd_arr, argv, count, lineptr);
		else if (k == -1)
			print_err(count, cmd_arr[0], argv[0]);
		free_list_str(cmd_arr);
	}
	exit(err_no);
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
			perror("hsh");
			return (1);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
			err_no = WEXITSTATUS(status);
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
