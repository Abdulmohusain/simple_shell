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
