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
<<<<<<< HEAD
	char *lineptr = NULL, **cmd_arr;
=======
	char *lineptr = NULL, **cmd_arr/* *new_line */;
>>>>>>> 9a13a3f0f9121baa90c07fbbcb9ab3896d861388
	size_t n = 0;
	ssize_t line;
	int count = 0, k;

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
<<<<<<< HEAD
		/* strchr code goes here */
=======
		/*new_line = _strchr(lineptr, '\n');
		if (new_line == NULL)
		{
			free(lineptr);
			lineptr = NULL;
			_putchar('\n');
			continue;
		}*/
>>>>>>> 9a13a3f0f9121baa90c07fbbcb9ab3896d861388
		lineptr = remove_leading_whitespaces(lineptr);
		if (lineptr == NULL)
			continue;
		cmd_arr = split_str(lineptr);
<<<<<<< HEAD
		k = check_builtin(lineptr, cmd_arr);
		if (k == 0)
			build_path_and_execute(cmd_arr, argv, count);
		else if (k == -1)
			print_err(count, cmd_arr[0], argv[0]);
=======
		processor(count, cmd_arr, argv[0], lineptr);
>>>>>>> 9a13a3f0f9121baa90c07fbbcb9ab3896d861388
		free_list_str(cmd_arr);
	}
	exit(0);
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
 * processor - process commands
 * @count: cont
 * @cmd_arr: command array
 * @arg: argument 0
 * @lineptr: lineptr
 *
 * Return: void
 */

void processor(int count, char **cmd_arr, char *arg, char *lineptr)
{
	char *cmd;
	if (check_builtin(lineptr, cmd_arr) == 0)
	{
		cmd = build_path(cmd_arr[0]);
		if (cmd == NULL)
			print_err(count, cmd_arr[0], arg);
		else
		{
			exec_cmd(cmd, cmd_arr);
			if (cmd != cmd_arr[0])
				free(cmd);
		}
	}
}
