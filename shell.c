#include "shell.h"
/**
 * main - A Command Line interpreter.
 * Return: 0 on success, and -1 on failure.
 */
/*int main(void)
{
	char **argv, *str;
	char *cmd;
	int status, count = 0;
	size_t n = 0;
	pid_t child_pid;

	while (1)
	{
		count++;
		argv = NULL;
		str = NULL;
		if (isatty(STDIN_FILENO))
			_puts("$ ");
		if (get_command(&str, &n) == -1)
			break;*/
		/* Create an array in the heap. It must be freed */
		/*argv = split_str(str);
		if (check_builtin(str, argv) == 0)
		{
			cmd = build_path(argv[0]);
			if (cmd == NULL)
				print_err(count, argv[0]);
			else
			{
				child_pid = fork();
				if (child_pid == -1)
				{
					perror("Error:");
					return (1);
				}*/
				/* Child Process will run */
				/*if (child_pid == 0)
				{
					execute_command(argv, str, cmd);
				}*/
				/* Parent process will run */
				/*else
				{*/
					/*free_list_str(argv);
					free(str);*/
					/*wait(&status);
				}
			}
			if (cmd != argv[0])
				free(cmd);
		}
	}
	free_list_str(argv);
	return (0);
}*/
