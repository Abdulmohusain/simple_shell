#include "shell.h"
/**
 * split_str - A a function that splits a string and returns an array
 * of each word of the string.
 * Note: The array is created using malloc and must be freed. A
 * function free_arr() can be used to free the array.
 * @strng: The string.
 * Return: Pointer to an array of strings or NULL if it fails.
 */
char **split_str(char *strng)
{
	char *delim = " \n";
	char *token, **arr, *strng_copy;
	int len, i;

	if (strng == NULL)
		return (NULL);
	/* Make copy of string because it will be destroyed strtok */
	strng_copy = _strdup(strng);
	/* Tokenize strng */
	token = strtok(strng, delim);
	len = 1;
	if (token == NULL)
	{
		_puts("Error: Could not tokenize string");
		return (NULL);
	}
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		len++;
	}
	arr = malloc(sizeof(char *) * len);
	if (!arr)
		return (NULL);
	token = strtok(strng_copy, delim);
	if (token == NULL)
	{
		_puts("Error: Could not tokenize string");
		return (NULL);
	}
	/** Loop to set value of each string in arr by copying token with strdup */
	for (i = 0; token != NULL; i++)
	{
		arr[i] = _strdup(token);
		token = strtok(NULL, delim);
	}
	free(strng_copy);
	arr[i] = NULL;
	return (arr);
}
/**
 * free_list_str - A function that frees a 2d array
 * of strings created by malloc.
 * @list: The malloc created list to be freed.
 */
void free_list_str(char **list)
{
	int i = 0;
	char **temp;

	temp = list;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(temp);
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

char *_strchr(const char *s, int c)
{
	size_t len, i;
	char copy;

	len = sizeof(s);
	len = len / sizeof(s[0]);
	while (s[i])
	{

	}
	printf("%ld\n", len);
	for (i = 0; i < len; i++)
	{
		if (copy[i] == c)
			break;
	}
	if (copy[i] == c)
	{
		return(copy+i);
	}

	
	return (NULL);
}
