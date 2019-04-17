#include "shell.h"
/**
 * _strdup - create an array with special charcter.
 * @str: character value.
 *
 * Return: .
 */
char *_strdup(char *str)
{
	unsigned int i;
	char *s;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != 0; i++)
		;
	i = i + 1;
	s = malloc(sizeof(char) * i);
	if (s == NULL)
		return (NULL);
	if (s != NULL)
	{
		for (i = 0; str[i] != 0; i++)
			s[i] = str[i];
	}
	s[i] = '\0';
	return (s);
}

/**
 *handle - take the buffer input and tokenize that input.
 *@buffer: buffer input from main function.
 *
 *Return: array of string after tokenizing.
 */
char **handle(char *buffer)
{
	char *token;
	int i;
	int word = 1;
	int flag = 0, j = 0;
	char **arr;

	for (i = 0; buffer[i] && buffer[i + 1]; i++)
	{
		if (buffer[i] != ' ')
			flag = 1;
		if (buffer[i] == ' ')
			flag = 0;
		if (flag == 0 && buffer[i] == ' ' && buffer[i + 1] != ' ')
			word++;
	}
	arr = malloc(sizeof(char *) * (word + 1));
	if (!arr)
		return (NULL);
	token = strtok(buffer, " \t\n");
	if (!token)
	{
		free(arr);
		return (NULL);
	}
	while (token)
	{
		arr[j] = _strdup(token);
		token = strtok(NULL, " \t\n");
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
