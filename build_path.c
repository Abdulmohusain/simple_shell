#include "shell.h"

/**
 * build_path -  build full path from command
 * @cmd: command to build file path from
 *
 * Return: pointer to full path
 */

char *build_path(char *cmd)
{
	char *full_path, *path_cpy, *path, *token;
	int cmd_len, tok_len;
	struct stat buff;

	if (cmd == NULL)
		return (NULL);
	cmd_len = _strlen(cmd);
	/* get PATH variables and duplicate path variable */
	path = _getenv("PATH");
	path_cpy = _strdup(path);
	/* Break path_cpy using strtok, loop through path */
	token = strtok(path_cpy, ":");
	while (token != NULL)
	{
		tok_len = _strlen(token);
		full_path = malloc(sizeof(char) * (tok_len + cmd_len + 2));
		if (full_path == NULL)
			return (NULL);
		/* build full path and test with stat function */
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);
		if (stat(full_path, &buff) == 0)
		{
			free(path_cpy);
			return (full_path);
		}
		else
		{
			free(full_path);
			token = strtok(NULL, ":");
		}
	}
	if (stat(cmd, &buff) == 0)
	{
		free(path_cpy);
		return (cmd);
	}
	free(path_cpy);
	return (NULL);
}
